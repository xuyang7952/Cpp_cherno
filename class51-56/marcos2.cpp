#include <iostream>

// ==================== 1. 调试日志宏 ====================
#define PR_DEBUG 1

#if PR_DEBUG == 1
    #define LOG(x) std::cout << "[DEBUG] " << x << std::endl;
#elif defined(PR_RELEASE)
    #define LOG(x)
#else
    #define LOG(x)
#endif

// ==================== 2. 多行日志宏 ====================
#define LOG_INFO(x, func) \
    std::cout << "File: " << __FILE__ << ", " \
              << "Line: " << __LINE__ << ", " \
              << "Var " << #x << " = " << x << ", " \
              << "Func: " << func << std::endl

// ==================== 3. 简单宏 ====================
#define PI 3.14159
#define SQUARE(x) ((x) * (x))

// ==================== 4. 平台检测 ====================
#ifdef _WIN32
    #define PLATFORM "Windows"
#elif defined(__linux__)
    #define PLATFORM "Linux"
#elif defined(__APPLE__)
    #define PLATFORM "macOS"
#else
    #define PLATFORM "Unknown"
#endif

// ==================== 主函数测试 ====================
int main() {
    LOG("程序开始");

    double radius = 5.0;
    double area = PI * SQUARE(radius);
    LOG("圆面积: " << area);

    int value = 42;
    LOG_INFO(value, "main");

    LOG("运行平台: " << PLATFORM);

    LOG("程序结束");
    return 0;
}