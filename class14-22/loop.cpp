// 以下代码展示了 C++ 中三种常见的循环结构：for 循环、while 循环和 do-while 循环

#include <iostream>

int main() {
    // for 循环示例：常用于已知循环次数的场景
    std::cout << "for 循环输出 0 到 4:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << i << std::endl;
    }

    // while 循环示例：常用于未知循环次数，根据条件判断是否继续循环
    std::cout << "\nwhile 循环输出 0 到 4:" << std::endl;
    int j = 0;
    while (j < 5) {
        std::cout << j << std::endl;
        ++j;
    }

    // do-while 循环示例：至少执行一次循环体，再根据条件判断是否继续循环
    std::cout << "\ndo-while 循环输出 0 到 4:" << std::endl;
    int k = 0;
    do {
        std::cout << k << std::endl;
        ++k;
    } while (k < 5);

    return 0;
}
