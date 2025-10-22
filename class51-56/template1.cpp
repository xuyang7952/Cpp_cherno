#include <iostream>
#include <string>

// ==================== 1. 函数模板 ====================
template <typename T>
void Print(T value) {
    std::cout << value << std::endl;
}

// ==================== 2. 类模板 - 通用数组 ====================
template <typename T, int N>
class Array {
private:
    T m_Array[N];
public:
    int GetSize() const {
        return N;
    }

    T& operator[](int index) {
        return m_Array[index];
    }
};

// ==================== 3. 类模板 - 固定缓冲区 ====================
template <int N>
class FixedBuffer {
private:
    char buffer[N];
public:
    void Set(char c) {
        for (int i = 0; i < N; ++i)
            buffer[i] = c;
    }
    int Size() const { return N; }
};

// ==================== 主函数测试 ====================
int main() {
    std::cout << "=== 函数模板 ===" << std::endl;
    Print(5);
    Print("Hello");
    Print(3.14f);

    std::cout << "\n=== 类模板：Array ===" << std::endl;
    Array<int, 5> intArray;
    Array<std::string, 3> strArray;

    std::cout << "intArray size: " << intArray.GetSize() << std::endl;
    std::cout << "strArray size: " << strArray.GetSize() << std::endl;

    intArray[0] = 42;
    strArray[0] = "World";
    std::cout << intArray[0] << ", " << strArray[0] << std::endl;

    std::cout << "\n=== 类模板：FixedBuffer ===" << std::endl;
    FixedBuffer<8> smallBuf;
    FixedBuffer<64> largeBuf;

    std::cout << "smallBuf size: " << smallBuf.Size() << std::endl;  // 8
    std::cout << "largeBuf size: " << largeBuf.Size() << std::endl;  // 64

    return 0;
}