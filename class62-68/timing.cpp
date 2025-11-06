#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>
#include <random>

// 工具函数：打印持续时间
template<typename T>
void print_duration(const T& dur, const std::string& unit) {
    std::cout << "耗时: " << dur.count() << " " << unit << "\n";
}

// 模拟一个耗时操作
void heavy_computation(int n) {
    std::vector<int> data(n);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000);

    for (int i = 0; i < n; ++i) {
        data[i] = dis(gen);
    }

    // 排序
    std::sort(data.begin(), data.end());

    // 简单处理
    volatile long sum = 0; // volatile 防止被编译器优化掉
    for (int x : data) {
        sum += x * x;
    }
}

int main() {
    using namespace std::chrono;

    std::cout << "=== C++ 计时演示 ===\n\n";

    // -----------------------------
    // 示例 1：测量函数执行时间
    // -----------------------------
    std::cout << "1. 测量 heavy_computation(100000) 的执行时间\n";
    auto start = steady_clock::now();

    heavy_computation(100000);

    auto end = steady_clock::now();
    auto duration = end - start;

    // 分别以不同单位输出
    print_duration(duration, "纳秒");
    print_duration(duration_cast<microseconds>(duration), "微秒");
    print_duration(duration_cast<milliseconds>(duration), "毫秒");
    print_duration(duration_cast<seconds>(duration), "秒");

    std::cout << "\n";

    // -----------------------------
    // 示例 2：手动实现一个简单的 Timer 类
    // -----------------------------
    struct Timer {
        using clock_t = steady_clock;
        using microseconds = std::chrono::microseconds;

        Timer() : start_(clock_t::now()) {}

        void reset() {
            start_ = clock_t::now();
        }

        int64_t elapsed_microseconds() const {
            return duration_cast<microseconds>(clock_t::now() - start_).count();
        }

        double elapsed_milliseconds() const {
            return elapsed_microseconds() / 1000.0;
        }

        double elapsed_seconds() const {
            return elapsed_microseconds() / 1'000'000.0;
        }

    private:
        time_point<clock_t> start_;
    };

    std::cout << "2. 使用 Timer 类测量 sleep_for(100ms)\n";
    Timer timer;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "实际睡眠约: " << timer.elapsed_milliseconds() << " 毫秒\n\n";

    // -----------------------------
    // 示例 3：测量多次运行的平均时间
    // -----------------------------
    const int runs = 5;
    std::vector<int64_t> times;
    Timer avg_timer;

    std::cout << "3. 测量 " << runs << " 次 heavy_computation(50000) 的平均耗时\n";

    for (int i = 0; i < runs; ++i) {
        avg_timer.reset();
        heavy_computation(50000);
        times.push_back(avg_timer.elapsed_microseconds());
    }

    int64_t total = 0;
    int i = 0;
    for (auto t : times) {
        std::cout << "第" << (i+1) << "次: " << t << " 微秒\n";
        total += t;
        i++;
    }
    std::cout << "平均耗时: " << (total / runs) << " 微秒 (" 
              << (total / runs) / 1000.0 << " 毫秒)\n";

    return 0;
}