// Log.h 头文件
// 包含log函数的声明

// #ifndef LOG_H
// #define LOG_H
#pragma once
#include <string>

// log函数声明
extern void log(const std::string& message);

extern void logInfo(const std::string& message);
extern void logWarning(const std::string& message);
extern void logError(const std::string& message);

// #endif // LOG_H