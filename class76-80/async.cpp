// 编译时需要添加 -pthread 标志来链接POSIX线程库。请使用以下命令编译：g++ -std=c++17 -pthread async.cpp -o async

#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <chrono>
#include <algorithm>
#include <random>
#include <numeric>

// 模拟一个耗时的计算任务
int calculateSomething(int id, int value) {
    // 模拟耗时操作（实际中可能是复杂计算）
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    return id * value;
}

// 模拟一个需要加载的模型（独立任务）
std::string loadModel(int modelId) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    return "Model " + std::to_string(modelId) + " loaded!";
}

// 生成随机测试数据
std::vector<int> generateRandomData(size_t size) {
    std::vector<int> data(size);
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 100);
    
    for (auto& num : data) {
        num = dist(rng);
    }
    
    return data;
}

// 顺序执行（基准）
void sequentialProcessing(const std::vector<int>& data) {
    std::vector<int> results;
    for (int value : data) {
        results.push_back(calculateSomething(1, value));
    }
    // 仅用于演示，不实际使用结果
    std::cout << "Sequential processing done, result sum: " 
              << std::accumulate(results.begin(), results.end(), 0) << std::endl;
}

// 使用std::async并行处理
void parallelProcessing(const std::vector<int>& data) {
    std::vector<std::future<int>> futures;
    
    // 为每个数据项创建异步任务
    for (int value : data) {
        futures.push_back(std::async(std::launch::async, calculateSomething, 2, value));
    }
    
    // 等待所有任务完成并收集结果
    std::vector<int> results;
    for (auto& fut : futures) {
        results.push_back(fut.get());
    }
    
    std::cout << "Parallel processing done, result sum: " 
              << std::accumulate(results.begin(), results.end(), 0) << std::endl;
}

// 多线程加载模型示例
void loadModelsExample() {
    std::vector<std::string> modelPaths = {"model1.obj", "model2.obj", "model3.obj", "model4.obj", "model5.obj"};
    
    // 顺序加载
    auto start = std::chrono::high_resolution_clock::now();
    for (const auto& path : modelPaths) {
        std::cout << "Loading: " << path << std::endl;
        loadModel(0); // 0表示顺序加载
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto sequentialTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Sequential model loading took " << sequentialTime << " ms" << std::endl;
    
    // 并行加载
    start = std::chrono::high_resolution_clock::now();
    std::vector<std::future<std::string>> futures;
    for (int i = 0; i < modelPaths.size(); ++i) {
        futures.push_back(std::async(std::launch::async, loadModel, i));
    }
    
    // 获取结果
    for (auto& fut : futures) {
        std::cout << "Loaded: " << fut.get() << std::endl;
    }
    end = std::chrono::high_resolution_clock::now();
    auto parallelTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Parallel model loading took " << parallelTime << " ms" << std::endl;
    
    // 性能对比
    std::cout << "Parallel loading is " << static_cast<double>(sequentialTime) / parallelTime 
              << "x faster than sequential" << std::endl;
}

int main() {
    // 生成测试数据
    const size_t dataSize = 10;
    auto data = generateRandomData(dataSize);
    
    // 测试顺序 vs 并行处理
    std::cout << "Testing sequential vs parallel processing..." << std::endl;
    
    auto start = std::chrono::high_resolution_clock::now();
    sequentialProcessing(data);
    auto sequentialTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count();
    
    start = std::chrono::high_resolution_clock::now();
    parallelProcessing(data);
    auto parallelTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count();
    
    std::cout << "Sequential processing took " << sequentialTime << " ms" << std::endl;
    std::cout << "Parallel processing took " << parallelTime << " ms" << std::endl;
    std::cout << "Parallel processing is " << static_cast<double>(sequentialTime) / parallelTime 
              << "x faster" << std::endl;
    
    // 模型加载示例
    std::cout << "\nTesting model loading with std::async..." << std::endl;
    loadModelsExample();
    
    return 0;
}