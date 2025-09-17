// log，输入字符串、输出字符串
#include <iostream>
#include <string>
#include "Log.h"

void log(const std::string& message) {
    std::cout << "log: " << message << std::endl;
}

void InitLog() {
    log("InitLog");
}
