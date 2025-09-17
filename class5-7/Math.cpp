// #define INTEGER Cherno
#include<iostream>
#include<string>
#include "Log.h"

#if 1  // #if 1 参与编译,0 不参与

// void log(const std::string& message) {
//     std::cout << message << std::endl;
// }   

int mul(int a, int b) {
    return a * b;
#include "EndBrace.h" // 里面就是}，编译器会做内容替换
// }

int main() {
    log("mul");
    mul(2, 3);
    return 0;
}
#endif
// 编译命令g++ -c Math.cpp -o Math.o
//  只执行预处理阶段，不进行编译、汇编和链接:g++ -E Math.cpp -o Math.i
// 只执行编译阶段（生成汇编代码），不进行汇编和链接:g++ -S Math.cpp -o Math.s

// g++ -g -O0 -DDEBUG  - -g : 生成调试信息，允许调试器如 gdb 进行源码级调试
// - -O0 : 关闭所有优化（大写字母 O 后跟数字 0）
// - -DDEBUG : 定义 DEBUG 宏，可以在代码中使用 #ifdef DEBUG 等预处理指令来添加调试特定的代码
// g++ -S -O0 -DDBUG Math.cpp -o Math.s

// g++ -O2 -DNDEBUG
// - -O2 : 启用中等程度的优化（也可以使用 -O3 进行更高级优化，但可能会增加程序大小）
// - -DNDEBUG : 定义 NDEBUG 宏，会禁用 assert() 断言