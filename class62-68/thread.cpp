#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <functional>
#include <mutex>

// 全局变量：多个线程共享
int shared_counter = 0;
std::mutex counter_mutex;  // 保护 shared_counter 的互斥锁

// 示例 1：普通函数作为线程任务
void print_hello(int id) {
    for (int i = 0; i < 3; ++i) {
        std::cout << "Thread " << id << ": Hello " << i << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// 示例 2：带引用参数的函数（必须用 std::ref）
void increment_counter(int times) {
    for (int i = 0; i < times; ++i) {
        // 加锁保证原子性
        std::lock_guard<std::mutex> lock(counter_mutex);
        ++shared_counter;
        std::cout << "Thread " << std::this_thread::get_id()
                  << " incremented counter to " << shared_counter << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

// 示例 3：Lambda 表达式作为线程任务
auto lambda_task = [](const std::string& name) {
    for (int i = 0; i < 2; ++i) {
        std::cout << "[Lambda] " << name << " - Step " << i << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
};

int main() {
    std::cout << "=== 主线程 ID: " << std::this_thread::get_id() << " ===\n\n";

    std::vector<std::thread> threads;

    // 1. 创建多个线程执行普通函数
    for (int i = 0; i < 3; ++i) {
        threads.emplace_back(print_hello, i + 1);  // 自动推导参数类型
    }

    // 2. 创建线程执行 lambda
    threads.emplace_back(lambda_task, "Worker A");
    threads.emplace_back(lambda_task, "Worker B");

    // 3. 创建线程修改共享变量（演示数据竞争防护）
    for (int i = 0; i < 2; ++i) {
        threads.emplace_back(increment_counter, 3);
    }

    // 4. 等待所有线程完成
    std::cout << "\n等待所有线程完成...\n";
    for (auto& t : threads) {
        if (t.joinable()) {  // 检查是否可 join
            t.join();
        }
    }

    std::cout << "\n✅ 所有线程已完成。\n";
    std::cout << "最终 shared_counter 值: " << shared_counter << "\n";

    // 5. 演示 detach：分离线程（谨慎使用）
    std::thread detached_thread([]() {
        std::cout << "\n--- 分离线程开始 ---\n";
        for (int i = 0; i < 3; ++i) {
            std::cout << "Detached thread: " << i << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
        std::cout << "--- 分离线程结束 ---\n";
    });

    detached_thread.detach();  // 分离，不再等待

    // 主线程休眠一会儿，确保能看到输出
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "\n🎉 主函数结束，程序退出。\n";
    return 0;
}