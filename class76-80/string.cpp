// 编译时需要添加C++17标准： g++ -std=c++17 string.cpp -o string
#include <iostream>
#include <string>
#include <string_view>
#include <chrono>
#include <vector>

// 全局计数器：跟踪内存分配次数
static uint32_t s_AllocCount = 0;

// 重载 new 操作符以监控内存分配
void* operator new(size_t size) {
    s_AllocCount++;
    std::cout << "Allocating " << size << " bytes\n";
    return malloc(size);
}

void operator delete(void* ptr) noexcept {
    free(ptr);
}

// 传统方式：使用 const std::string&
void PrintName_StdString(const std::string& name) {
    std::cout << "[std::string] Name: " << name << "\n";
}

// 新方式：使用 std::string_view
void PrintName_StringView(std::string_view name) {
    std::cout << "[string_view] Name: " << name << "\n";
}

// 性能测试：大量字符串操作
void PerformanceTest() {
    const std::string baseName = "Alexander Chernikov";
    
    // 测试 1: 直接传递字面量
    std::cout << "\n=== Test 1: Literal string ===\n";
    s_AllocCount = 0;
    PrintName_StdString("Yan Chernikov");  // 触发一次分配！
    std::cout << "std::string allocations: " << s_AllocCount << "\n";
    
    s_AllocCount = 0;
    PrintName_StringView("Yan Chernikov"); // 零分配！
    std::cout << "string_view allocations: " << s_AllocCount << "\n";
    
    // 测试 2: 子串操作
    std::cout << "\n=== Test 2: Substring operations ===\n";
    s_AllocCount = 0;
    {
        std::string firstName = baseName.substr(0, 9);   // 分配
        std::string lastName = baseName.substr(10, 9);   // 分配
        PrintName_StdString(firstName);
        PrintName_StdString(lastName);
    }
    std::cout << "std::string substr allocations: " << s_AllocCount << "\n";
    
    s_AllocCount = 0;
    {
        std::string_view firstName(baseName.data(), 9);
        std::string_view lastName(baseName.data() + 10, 9);
        PrintName_StringView(firstName);
        PrintName_StringView(lastName);
    }
    std::cout << "string_view substr allocations: " << s_AllocCount << "\n";
}

// 大规模性能基准测试
void Benchmark() {
    const int N = 100000;
    std::vector<std::string> names(N, "Performance Test String");
    
    // std::string 版本
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        PrintName_StdString(names[i]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration_std = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    // std::string_view 版本
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        PrintName_StringView(names[i]); // 自动转换为 string_view
    }
    end = std::chrono::high_resolution_clock::now();
    auto duration_view = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << "\n=== Benchmark Results (" << N << " iterations) ===\n";
    std::cout << "std::string time: " << duration_std.count() << " ms\n";
    std::cout << "string_view time: " << duration_view.count() << " ms\n";
    std::cout << "Speedup: " << static_cast<double>(duration_std.count()) / duration_view.count() << "x\n";
}

// 安全注意事项：string_view 不拥有数据
void SafetyWarning() {
    std::cout << "\n=== Safety Warning ===\n";
    
    // 危险！临时 string 被销毁后，string_view 指向无效内存
    // std::string_view bad_view = std::string("temporary").substr(0, 5); // DON'T DO THIS!
    
    // 正确做法：确保底层数据生命周期足够长
    std::string persistent = "persistent data";
    std::string_view good_view(persistent.data(), 5);
    std::cout << "Safe string_view: " << good_view << "\n";
}

int main() {
    std::cout << "C++ String Performance Optimization Demo\n";
    std::cout << "========================================\n";
    
    PerformanceTest();
    // Benchmark();
    SafetyWarning();
    
    return 0;
}