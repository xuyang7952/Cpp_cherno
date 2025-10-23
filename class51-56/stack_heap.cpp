#include <iostream>
#include <memory>  // 智能指针头文件

// 简单的Vector3结构体（对应笔记中的示例）
struct Vector3 {
    float x, y, z;
    
    Vector3() : x(10.0f), y(11.0f), z(12.0f) {}
    
    void Print() const {
        std::cout << "Vector3(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};

// 内存地址查看辅助函数
template<typename T>
void PrintAddress(const char* name, const T& obj) {
    std::cout << name << " 地址: " << &obj << std::endl;
}

template<typename T>
void PrintHeapAddress(const char* name, const T* ptr) {
    std::cout << name << " 堆地址: " << ptr << std::endl;
}

int main() {
    std::cout << "=== C++栈与堆内存分配对比演示 ===" << std::endl;
    std::cout << "对应Cherno笔记第54节内容\n" << std::endl;
    
    // ============================================
    // 1. 栈上分配（快速、自动管理）
    // ============================================
    std::cout << "1. 栈上分配（自动管理）:" << std::endl;
    
    int value = 5;                    // 栈分配整数
    int array[5] = {1, 2, 3, 4, 5};  // 栈分配数组
    Vector3 vector;                  // 栈分配对象
    
    // 查看栈对象地址（相邻分布）
    PrintAddress("value", value);
    PrintAddress("array", array);
    PrintAddress("vector", vector);
    
    std::cout << "栈对象值: value=" << value << ", array[0]=" << array[0] << std::endl;
    vector.Print();
    
    std::cout << std::endl;
    
    // ============================================
    // 2. 堆上分配（手动管理）
    // ============================================
    std::cout << "2. 堆上分配（手动管理）:" << std::endl;
    
    int* hvalue = new int(5);                    // 堆分配整数
    int* harray = new int[5]{1, 2, 3, 4, 5};     // 堆分配数组
    Vector3* hvector = new Vector3();            // 堆分配对象
    
    // 查看堆对象地址（分散分布）
    PrintHeapAddress("hvalue", hvalue);
    PrintHeapAddress("harray", harray);
    PrintHeapAddress("hvector", hvector);
    
    std::cout << "堆对象值: *hvalue=" << *hvalue << ", harray[0]=" << harray[0] << std::endl;
    hvector->Print();
    
    std::cout << std::endl;
    
    // ============================================
    // 3. 作用域演示（栈自动释放 vs 堆手动释放）
    // ============================================
    std::cout << "3. 作用域生命周期演示:" << std::endl;
    
    {
        // 内部作用域
        int scopeValue = 100;                    // 栈分配
        int* heapValue = new int(200);          // 堆分配
        
        std::cout << "内部作用域 - scopeValue: " << scopeValue << std::endl;
        std::cout << "内部作用域 - *heapValue: " << *heapValue << std::endl;
        std::cout << "内部作用域结束..." << std::endl;
        
        // ❌ 危险：忘记delete会导致内存泄漏！
        // delete heapValue;  // 故意注释掉演示内存泄漏
    } // scopeValue自动释放，heapValue泄漏！
    
    std::cout << "外部作用域 - 栈对象已自动释放" << std::endl;
    std::cout << "外部作用域 - 堆对象未释放（内存泄漏！）" << std::endl;
    
    std::cout << std::endl;
    
    // ============================================
    // 4. 现代C++：智能指针（推荐）
    // ============================================
    std::cout << "4. 现代C++智能指针（自动堆管理）:" << std::endl;
    
    // unique_ptr（独占所有权）
    auto smartValue = std::make_unique<int>(300);
    auto smartVector = std::make_unique<Vector3>();
    
    // shared_ptr（共享所有权）
    auto sharedValue = std::make_shared<int>(400);
    std::shared_ptr<int> sharedCopy = sharedValue;  // 共享所有权
    
    std::cout << "智能指针值: *smartValue=" << *smartValue << std::endl;
    std::cout << "共享指针引用计数: " << sharedValue.use_count() << std::endl;
    smartVector->Print();
    
    std::cout << std::endl;
    
    // ============================================
    // 5. 内存使用对比总结
    // ============================================
    std::cout << "5. 内存布局对比:" << std::endl;
    std::cout << "栈对象地址相近（连续分配）:" << std::endl;
    std::cout << "  value地址:  " << &value << std::endl;
    std::cout << "  array地址: " << &array << " (相差: " 
              << (reinterpret_cast<char*>(&array) - reinterpret_cast<char*>(&value)) 
              << " 字节)" << std::endl;
    
    std::cout << "堆对象地址分散（随机分配）:" << std::endl;
    std::cout << "  hvalue地址:  " << hvalue << std::endl;
    std::cout << "  harray地址: " << harray << " (相差: " 
              << (reinterpret_cast<char*>(harray) - reinterpret_cast<char*>(hvalue)) 
              << " 字节)" << std::endl;
    
    std::cout << std::endl;
    
    // ============================================
    // 6. 清理堆内存（避免泄漏）
    // ============================================
    std::cout << "6. 手动清理堆内存:" << std::endl;
    
    delete hvalue;      // 释放单个对象
    delete[] harray;    // 释放数组（必须用delete[]）
    delete hvector;     // 释放对象
    
    // 智能指针自动释放，无需手动delete
    
    std::cout << "堆内存已释放，程序结束" << std::endl;
    
    return 0;
}