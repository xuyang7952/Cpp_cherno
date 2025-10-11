#include <iostream>

void PointerTest(int* p) {
    std::cout << "PointerTest:\n";
    std::cout << "  传入指针指向的地址: " << p << std::endl;
    std::cout << "  传入指针本身的地址: " << &p << std::endl;
    p = nullptr;
    std::cout << "  修改后指针指向的地址: " << p << std::endl;
    std::cout << "  修改后指针本身的地址: " << &p << std::endl;
}

void ReferenceTest(int*& pRef) {
    std::cout << "ReferenceTest:\n";
    std::cout << "  传入指针指向的地址: " << pRef << std::endl;
    std::cout << "  传入指针本身的地址: " << &pRef << std::endl;
    pRef = nullptr;
    std::cout << "  修改后指针指向的地址: " << pRef << std::endl;
    std::cout << "  修改后指针本身的地址: " << &pRef << std::endl;
}

int main() {
    int* ptr1 = new int(10);
    int* ptr2 = new int(20);
    
    std::cout << "初始ptr1指向的地址: " << ptr1 << std::endl;
    std::cout << "初始ptr1本身的地址: " << &ptr1 << std::endl;
    PointerTest(ptr1);
    std::cout << "调用后ptr1指向的地址: " << ptr1 << std::endl;
    std::cout << "调用后ptr1本身的地址: " << &ptr1 << "\n\n";
    
    std::cout << "初始ptr2指向的地址: " << ptr2 << std::endl;
    std::cout << "初始ptr2本身的地址: " << &ptr2 << std::endl;
    ReferenceTest(ptr2);
    std::cout << "调用后ptr2指向的地址: " << ptr2 << std::endl;
    std::cout << "调用后ptr2本身的地址: " << &ptr2 << std::endl;
    
    delete ptr1;  // ptr1仍指向原内存
    // ptr2已被设为nullptr，无需delete
}

/*
初始ptr1指向的地址: 0xb4aeb0
初始ptr1本身的地址: 0x7ffe17fa2cc8
PointerTest:
传入指针指向的地址: 0xb4aeb0
传入指针本身的地址: 0x7ffe17fa2ca8
修改后指针指向的地址: 0
修改后指针本身的地址: 0x7ffe17fa2ca8
调用后ptr1指向的地址: 0xb4aeb0
调用后ptr1本身的地址: 0x7ffe17fa2cc8

初始ptr2指向的地址: 0xb4aed0
初始ptr2本身的地址: 0x7ffe17fa2cc0
ReferenceTest:
传入指针指向的地址: 0xb4aed0
传入指针本身的地址: 0x7ffe17fa2cc0
修改后指针指向的地址: 0
修改后指针本身的地址: 0x7ffe17fa2cc0
调用后ptr2指向的地址: 0
调用后ptr2本身的地址: 0x7ffe17fa2cc0
*/