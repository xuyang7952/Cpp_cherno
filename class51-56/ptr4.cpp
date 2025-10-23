#include <iostream>

struct Test {
    int* ptr1;
    int* ptr2;
    char ch;
    // 由于内存对齐，这个结构体大小可能让你惊讶
};

int main() {
    std::cout << "指针大小(64位系统): " << sizeof(int*) << " 字节" << std::endl;
    std::cout << "指针大小(32位系统): " << sizeof(void*)*8 << " 位" << std::endl;
    
    Test t;
    std::cout << "包含两个指针的结构体大小: " << sizeof(Test) << " 字节" << std::endl;
    
    // 演示指针数组的内存占用
    int* ptr_array[10];
    std::cout << "10个指针的数组大小: " << sizeof(ptr_array) << " 字节" << std::endl;
    
    return 0;
}