// main.cpp
// 主函数，使用log函数

#include "Log.h"
#include <string>

int main() {
    // 使用基本log函数
    log("这是一条基本日志消息");
    
    // 使用信息日志函数
    logInfo("程序已启动");
    
    // 使用警告日志函数
    logWarning("系统资源不足");
    
    // 使用错误日志函数
    logError("无法打开配置文件");
    
    // 演示不同类型的消息
    std::string user = "admin";
    logInfo("用户 " + user + " 已登录");
    
    log("程序执行完毕");
    // 编译命令g++ Log.cpp main.cpp -o log_example   ./log_example
    
    bool flag = "a"=='b';
    if(flag){
        logInfo("a和b相等");
    }
    

    return 0;
}