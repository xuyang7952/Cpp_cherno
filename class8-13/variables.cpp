// C++ 中的不同变量类型，打印变量的值 和size
#include <iostream>

int main() {
    // 整数类型
    int intVar = 42;
    std::cout << "int 值: " << intVar << ", 大小: " << sizeof(intVar) << " 字节" << std::endl;

    // 长整型
    long longVar = 123456789LL;
    std::cout << "long 值: " << longVar << ", 大小: " << sizeof(longVar) << " 字节" << std::endl;

    // 短整型
    short shortVar = 32767;
    std::cout << "short 值: " << shortVar << ", 大小: " << sizeof(shortVar) << " 字节" << std::endl;

    // 无符号整型
    unsigned int unsignedIntVar = 4294967295U;
    std::cout << "unsigned int 值: " << unsignedIntVar << ", 大小: " << sizeof(unsignedIntVar) << " 字节" << std::endl;

    // 浮点型
    float floatVar = 3.14f;
    std::cout << "float 值: " << floatVar << ", 大小: " << sizeof(floatVar) << " 字节" << std::endl;

    // 双精度浮点型
    double doubleVar = 3.1415926535;
    std::cout << "double 值: " << doubleVar << ", 大小: " << sizeof(doubleVar) << " 字节" << std::endl;

    // 字符型
    char charVar = 'A';
    std::cout << "char 值: " << charVar << ", 大小: " << sizeof(charVar) << " 字节" << std::endl;

    // 布尔型
    bool boolVar = true;
    std::cout << "bool 值: " << std::boolalpha << boolVar << ", 大小: " << sizeof(boolVar) << " 字节" << std::endl;

    // return 0;
}
