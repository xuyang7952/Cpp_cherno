#include <iostream>
#include <string>


class Entity {
private:
    int* m_Array; // 指向堆上数组的指针成员
public:
    static const int arraySize = 5;
    // C++ 11的std::array容器
    std::array<int, arraySize> m_Array;
    // 构造函数：在堆上分配内存并初始化数组
    Entity() {
        // m_Array = new int[arraySize]; // 在堆上分配200字节(50 * 4)内存
        // 初始化数组元素为连续值
        for (int i = 0; i < m_Array.size(); i++) {
            m_Array[i] = i; // 或类似的初始化操作
        }
    }

    // 析构函数（图中可能未显示，但实际应有）
    ~Entity() {
        delete[] m_Array; // 释放堆内存
    }
};

// 主函数，程序的入口点
int main()
{
    // 定义一个包含 5 个整数的数组，并初始化其元素
    int arr[5] = {1, 2, 3, 4, 5};
    // 修改数组的第一个元素为 0
    arr[0] = 0;
    // 越界访问数组，这是危险操作，可能导致程序崩溃或未定义行为
    arr[-1] = 0; 

    // 打印数组第一个元素的值
    std::cout << arr[0] << std::endl;
    // 使用解引用操作符打印数组首元素的值，与 arr[0] 等价
    std::cout << *arr << std::endl; 
    // 打印数组的首地址
    std::cout << arr << std::endl; 
    // 打印数组的第二个元素的值
    std::cout << arr[1] << std::endl;  
    // 使用指针算术运算打印数组第二个元素的值
    std::cout << *(arr + 1) << std::endl; 
    // 打印数组第二个元素的地址
    std::cout << arr + 1 << std::endl; 
    // 打印数组第二个元素的地址
    std::cout << &arr[1] << std::endl; 

    int* ptr = arr;
    arr[3] = 333;
    std::cout << arr[3] << std::endl;
    // int 指针，指向数组的第一个元素
    // 可以通过指针 arithmetic 来访问数组的其他元素
    *(ptr + 3) = 3333;
    std::cout << arr[3] << std::endl;
    // 可以将指针转换为 char* 类型，然后进行字节级别的访问
    // 这里将指针 ptr 转换为 char* 类型，然后将偏移量 12 个字节处的内存解释为 int 类型的指针
    // 并将其解引用，将 33333 写入该内存位置
    // 这样写，是33333 写入一个字节，而不是 4 个字节，溢出，最后为3381；
    *((char*)ptr + 12) = 33333; 
    std::cout << arr[3] << std::endl;
    // 正确的写法是将 33333 写入 4 个字节的内存位置
    *((int*)((char*)ptr + 12)) = 33333;
    std::cout << arr[3] << std::endl;

    // 修正拼写错误 std:: endl 为 std::endl
    // 遍历数组并打印每个元素的值
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << std::endl;
    }

    //
    int* arr2 = new int[5];
    // 获取数组的大小
    int size = sizeof(arr2) / sizeof(arr2[0]);
    // 释放动态分配的内存，避免内存泄漏
    for (int i = 0; i < 5; i++) {
        arr2[i] = i;   
    }
    delete[] arr2;

    // 实例化 Entity 类的对象 e
    Entity e;

    // 程序正常结束，返回 0
    return 0;
}