#include <iostream>

int global_value = 100;           // 全局数据区
int* global_ptr = &global_value;   // global_ptr本身在全局数据区

int main() {
    int local_value = 200;        // 栈上
    int* stack_ptr = &local_value; // stack_ptr本身在栈上
    
    int* heap_ptr = new int(300);  // heap_ptr在栈上，但它指向堆内存
    
    // 验证指针本身的内存位置
    std::cout << "全局指针地址: " << &global_ptr << " (全局数据区)" << std::endl;
    std::cout << "栈上指针地址: " << &stack_ptr << " (栈上)" << std::endl;
    std::cout << "堆指针变量地址: " << &heap_ptr << " (栈上)" << std::endl;
    
    std::cout << "指针指向的地址: " << heap_ptr << " (堆内存)" << std::endl;
    std::cout << "指针指向的值: " << *heap_ptr << std::endl;
    
    delete heap_ptr;
    return 0;
}