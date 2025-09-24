#include <iostream>

class Log{
public:
    enum LogLevel{
        LOG_LEVEL_ERROR = 0,
        LOG_LEVEL_WARN = 1,
        LOG_LEVEL_INFO = 2
    };
private:
    int logLevel;
public:
    void SetLevel(LogLevel level){
        logLevel = level;
    };
    void Warn(const char* msg){
        if (logLevel >= LogLevel::LOG_LEVEL_WARN)
            std::cout << "Warning: " << msg << std::endl;
    };
    void Error(const char* msg){    
        if (logLevel >= LogLevel::LOG_LEVEL_ERROR)
            std::cout << "Error: " << msg << std::endl;
    };
    void Info(const char* msg){
        if (logLevel >= LogLevel::LOG_LEVEL_INFO)
            std::cout << "Info: " << msg << std::endl;
    };
};

int main ()
{
    Log log;
    log.SetLevel(Log::LogLevel::LOG_LEVEL_INFO);  
    log.Warn("hello Warn");
    log.Error("hello Error");
    log.Info("hello Info");
    // std::cout << "Hello World!" << std::endl;
    return 0;
}