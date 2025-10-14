#include <iostream>
#include <cstring>

class String {
private:
    char* m_Buffer;
    unsigned int m_Size;

public:
    // 构造函数
    String(const char* string) {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];  // +1 为 '\0'
        memcpy(m_Buffer, string, m_Size + 1);
    }

    // 拷贝构造函数（深拷贝）
    String(const String& other)
        : m_Size(other.m_Size)
    {
        std::cout << "Copy constructor" << std::endl;
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }

    // // 是移动构造函数，但实现有误。正确的移动构造函数应如下
    // // 移动构造函数会接管传入对象的资源，避免深拷贝
    // String(String&& other) noexcept
    //     : m_Size(other.m_Size),  m_Buffer(other.m_Buffer) {
    //     other.m_Size = 0;
    //     other.m_Buffer = nullptr;
    // }

    // 析构函数
    ~String() {
        delete[] m_Buffer;
    }

    // 重载输出运算符
    friend std::ostream& operator<<(std::ostream& stream, const String& string) {
        stream << string.m_Buffer;
        return stream;
    }

    // 重载 [] 操作符
    char& operator[](unsigned int index) {
        return m_Buffer[index];
    }
};

// 打印函数：使用 const 引用避免拷贝
// 参数不引用的，会触发拷贝构造函数
// void PrintString(const String& string) {
void PrintString(const String& string) {
    std::cout << string << std::endl;
}

int main() {
    String string = "Cherno";
    std::cout << "string: " << string << std::endl;
    String second = string;  // 调用拷贝构造函数（深拷贝）
    std::cout << "second: " << second << std::endl;

    second[2] = 'a';  // 修改 second，不影响 string

    PrintString(string);  // 输出: Cherno
    PrintString(second); // 输出: Charo

    // std::cin.get();  // 等待输入
    return 0;
}