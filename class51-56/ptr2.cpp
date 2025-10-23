#include <iostream>

int main() {
    int value = 42;
    int* ptr = &value;
    
    // ptr本身是一个变量，需要内存存储地址值
    std::cout << "ptr变量的大小: " << sizeof(ptr) << " 字节" << std::endl;  // 通常是8字节(64位)
    std::cout << "ptr变量的地址: " << &ptr << std::endl;      // ptr本身在哪里
    std::cout << "ptr存储的值: " << ptr << std::endl;         // ptr指向哪里
    std::cout << "ptr指向的值: " << *ptr << std::endl;        // 解引用获取实际数据
    
    return 0;
}