// 以下是 C++ 中函数的说明和代码案例

// 函数说明：
// 函数是一段完成特定任务的代码块，它可以接受输入参数，执行一系列操作，并返回一个结果。
// 函数的基本语法如下：
// 返回类型 函数名(参数列表) {
//     函数体
//     return 返回值;
// }

// 示例 1：无参数无返回值的函数
#include <iostream>

// 函数声明
void greet();

// 函数定义
void greet() {
    std::cout << "Hello, World!" << std::endl;
}

// 示例 2：有参数有返回值的函数
// 函数声明
int add(int a, int b);

// 函数定义
int add(int a, int b) {
    return a + b;
}

int main() {
    // 调用无参数无返回值的函数
    greet();

    // 调用有参数有返回值的函数
    int result = add(3, 5);
    std::cout << "3 + 5 = " << result << std::endl;

    return 0;
}
