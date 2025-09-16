// hello 的demo
#include <iostream>

void log(const std::string& message);
int main() {
    // std::cout << "Hello, World!" << std::endl;
    log("hello world");
    return 0;
}
// hello.cpp 调用 log.cpp 中的 log 函数，一起编译：g++ hello.cpp log.cpp -o hello
