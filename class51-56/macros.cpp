#include <iostream>

// 模拟编译器定义（实际中通过编译选项设置）
#define PR_DEBUG 0

#if PR_DEBUG == 1
    #define LOG(x) std::cout << "[DEBUG] " << x << std::endl;
#elif defined(PR_RELEASE)
    #define LOG(x)
#else
    #define LOG(x)
#endif

int main() {
    LOG("程序启动");
    int value = 42;
    LOG("当前值: " << value);
    LOG("程序结束");

    return 0;
}