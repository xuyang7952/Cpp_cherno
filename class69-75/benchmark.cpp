#include <iostream>
#include <vector>
#include <chrono>

// 作用域计时器
class Timer {
public:
    Timer(const char* name) : m_Name(name) {
        m_Start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - m_Start);
        std::cout << "[" << m_Name << "] Elapsed: " 
                  << duration.count() << " µs\n";
    }

private:
    const char* m_Name;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
};

// 防止编译器优化：声明为 volatile 或输出结果
template<typename T>
void doNotOptimizeAway(T&& value) {
    // 简单方案：输出到 cerr（不影响 stdout）
    static_cast<void>(value); // 防止 warning
    // 更严谨可用 Google Benchmark 的 DoNotOptimize
}

int main() {
    constexpr int N = 1000000;

    std::cout << "=== 测试1：简单累加 ===\n";
    {
        Timer t("Accumulate");
        volatile long long sum = 0; // volatile 防止优化
        for (int i = 0; i < N; ++i) {
            sum += i;
        }
        doNotOptimizeAway(sum); // 确保 sum 被“使用”
    }

    std::cout << "\n=== 测试2：std::vector push_back ===\n";
    {
        Timer t("Vector Push");
        std::vector<int> vec;
        vec.reserve(N); // 避免重复分配
        for (int i = 0; i < N; ++i) {
            vec.push_back(i);
        }
        doNotOptimizeAway(vec.size());
    }

    std::cout << "\n=== 测试3：未 reserve 的 vector ===\n";
    {
        Timer t("Vector No Reserve");
        std::vector<int> vec;
        for (int i = 0; i < N; ++i) {
            vec.push_back(i);
        }
        doNotOptimizeAway(vec.size());
    }

    return 0;
}