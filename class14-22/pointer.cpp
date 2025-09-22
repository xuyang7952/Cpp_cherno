#include <iostream>
#include <cstring>

int main ()
{
    int a = 8;
    // void* ptr = &a; // 和下面的一样,但没格式，
    int* ptr = &a;
    std::cout << "a = " << a << std::endl;
    std::cout << "ptr = " << ptr << std::endl;
    *ptr = 10;
    std::cout << "a = " << a << std::endl;
    std::cout << "ptr = " << ptr << std::endl;
    std::cout << "sizeof(ptr) = " << sizeof(ptr) << std::endl;

    char* buffer = new char[10];
    memset(buffer,90,10);
    // C++ 的 std::cout对 char*类型有特殊行为，它会​​自动将其视为 C 风格字符串​​（即以 '\0'结尾的字符数组），并打印其内容，而不是指针的地址。
    std::cout << "buffer = " << buffer << std::endl;
    // 需要​​强制转换 buffer为 void*​​：
    std::cout << "buffer address = " << static_cast<void*>(buffer) << std::endl;
    // buffer是一个 char*指针，sizeof(buffer)返回的是指针的大小（通常 4 字节或 8 字节，取决于系统），而不是分配的数组大小（10 字节）。
    // 如果你想知道分配的数组大小，C++ 的 new[]不会存储这个信息，你需要自己记住它（例如用 const size_t buffer_size = 10;）
    std::cout << "sizeof(buffer) = " << sizeof(buffer) << std::endl;
    char** ptr2 = &buffer;
    std::cout << "ptr2 = " << ptr2 << std::endl;
    std::cout << "sizeof(ptr2) = " << sizeof(ptr2) << std::endl;
    delete[] buffer;
    return 0;
}