#include <iostream>
#include <memory>
#include <string>
#include <cstdint>

// 内存分配统计结构体
struct AllocationMetrics {
    std::uint32_t TotalAllocated = 0;
    std::uint32_t TotalFreed = 0;
    
    // 当前内存使用量
    std::uint32_t CurrentUsage() const {
        return TotalAllocated - TotalFreed;
    }
    
    // 重置统计
    void Reset() {
        TotalAllocated = 0;
        TotalFreed = 0;
    }
};

// 全局内存统计对象
static AllocationMetrics s_AllocationMetrics;

// 重载全局 operator new
void* operator new(std::size_t size) {
    s_AllocationMetrics.TotalAllocated += static_cast<std::uint32_t>(size);
    std::cout << "[ALLOC] Allocating " << size << " bytes\n";
    return malloc(size);
}

// 重载全局 operator delete
void operator delete(void* memory, std::size_t size) noexcept {
    s_AllocationMetrics.TotalFreed += static_cast<std::uint32_t>(size);
    std::cout << "[FREE] Freeing " << size << " bytes\n";
    free(memory);
}

// 重载无大小信息的 delete（C++14+ 兼容）
void operator delete(void* memory) noexcept {
    free(memory);
}

// 打印当前内存使用情况
void PrintMemoryUsage() {
    std::cout << "\n=== Memory Usage ===\n";
    std::cout << "Total Allocated: " << s_AllocationMetrics.TotalAllocated << " bytes\n";
    std::cout << "Total Freed: " << s_AllocationMetrics.TotalFreed << " bytes\n";
    std::cout << "Current Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
    std::cout << "====================\n\n";
}

// 测试用的简单结构体
struct Object {
    int x, y, z;
    
    Object(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {
        std::cout << "Object constructed\n";
    }
    
    ~Object() {
        std::cout << "Object destructed\n";
    }
};

// 模拟内存密集型操作
void SimulateMemoryOperations() {
    std::cout << "\n--- Direct new/delete ---\n";
    Object* obj1 = new Object(1, 2, 3);
    delete obj1;
    
    std::cout << "\n--- std::unique_ptr with make_unique ---\n";
    auto obj2 = std::make_unique<Object>(4, 5, 6);
    // obj2 自动析构
    
    std::cout << "\n--- std::string operations ---\n";
    std::string str = "Hello, Cherno!";
    str += " This is a longer string that might trigger allocation.";
}


int main() {
    std::cout << "C++ Memory Allocation Tracker Demo\n";
    std::cout << "==================================\n";
    
    // 初始内存状态
    PrintMemoryUsage();
    
    // 测试基本分配
    SimulateMemoryOperations();
    PrintMemoryUsage();
    
    // 测试作用域内的分配和释放
    {
        std::cout << "\n--- Scoped allocations ---\n";
        auto obj3 = std::make_unique<Object>(7, 8, 9);
        std::string tempStr = "Temporary string";
        
        PrintMemoryUsage(); // 显示当前使用量
    } // obj3 和 tempStr 在这里被销毁
    
    PrintMemoryUsage(); // 应该显示释放后的状态
    
    // 验证所有内存都被正确释放
    if (s_AllocationMetrics.CurrentUsage() == 0) {
        std::cout << "✅ All memory properly deallocated!\n";
    } else {
        std::cout << "⚠️  Possible memory leak detected!\n";
        std::cout << "   Unfreed memory: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
    }
    
    return 0;
}