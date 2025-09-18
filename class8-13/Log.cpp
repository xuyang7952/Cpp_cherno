// Log.cpp
// 实现log函数的具体功能

#include "Log.h"
#include <iostream>
#include <string>

// 基本log函数实现
void log(const std::string& message) {
    std::cout << "[LOG] " << message << std::endl;
}

// 信息日志函数
void logInfo(const std::string& message) {
    std::cout << "[INFO] " << message << std::endl;
}

// 警告日志函数
void logWarning(const std::string& message) {
    std::cout << "[WARNING] " << message << std::endl;
}

// 错误日志函数
void logError(const std::string& message) {
    std::cout << "[ERROR] " << message << std::endl;
}