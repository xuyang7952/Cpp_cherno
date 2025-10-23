#include <iostream>

int main() {
    int data = 999;
    
    int* ptr1 = &data;        // 一级指针：存储data的地址
    int** ptr2 = &ptr1;       // 二级指针：存储ptr1的地址  
    int*** ptr3 = &ptr2;      // 三级指针：存储ptr2的地址
    
    std::cout << "data的值: " << data << " 地址: " << &data << std::endl;
    std::cout << "ptr1的值: " << ptr1 << " ptr1自己的地址: " << &ptr1 << std::endl;
    std::cout << "ptr2的值: " << ptr2 << " ptr2自己的地址: " << &ptr2 << std::endl;
    std::cout << "ptr3的值: " << ptr3 << " ptr3自己的地址: " << &ptr3 << std::endl;
    
    // 通过多级指针访问data
    std::cout << "***ptr3 = " << ***ptr3 << std::endl;  // 输出: 999
    
    return 0;
}