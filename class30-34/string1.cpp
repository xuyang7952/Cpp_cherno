#include <iostream>
#include <string>
#include <cstring>

// 使用引用，避免拷贝，提高效率，const 表示不会修改 str
void printString(const std::string& str)
{
    std::cout << "str:" << str << std::endl;
}

int main()
{
    // 定义一个指向常量字符串的指针，字符串 "xu" 末尾自动包含 '\0'
    const char* name = "xu";
    // 定义一个字符数组，仅包含 'x' 和 'u'，缺少字符串结束符 '\0'
    char name2[2] ={'x','u'};
    // 同样是定义字符数组，使用 0 表示字符串结束符
    // char name3[3] ={'x','u',0};
    // 定义一个字符数组，包含 'x'、'u' 和字符串结束符 '\0'
    char name3[3] ={'x','u','\0'};
    // 输出指向常量字符串的指针内容，正常输出 "xu"
    std::cout << name << std::endl;
    // 碰到0才会结束
    // 警告：name2 缺少字符串结束符 '\0'，输出时会产生未定义行为
    std::cout << name2 << std::endl;
    // 输出字符数组 name3 的内容，正常输出 "xu"
    std::cout << name3 << std::endl;
    // 计算长度，sizeof 作用于指针时，返回的是指针本身的长度，而非字符串长度
    std::cout << sizeof(name) << std::endl;
    // 打印字符数组 name2 的长度，sizeof 会返回数组的总大小，包括 '\0'
    std::cout << sizeof(name2) << std::endl;
    // 打印字符数组 name3 的长度，sizeof 会返回数组的总大小，包括 '\0'
    std::cout << sizeof(name3) << std::endl;
    
    // 打印字符串 name 的长度，strlen 会统计到 '\0' 前的字符数量
    std::cout << strlen(name) << std::endl;

    // 打印字符数组 name2 的长度，strlen 会统计到 '\0' 前的字符数量
    std::cout << strlen(name2) << std::endl;
    // 打印字符数组 name3 的长度，strlen 会统计到 '\0' 前的字符数量
    std::cout << strlen(name3) << std::endl;


    std::string name4 = "xu" + std::string("yang");
    // find的用法，查找子字符串 "yang" 在 name4 中的位置
    bool flag = name4.find("no")!= std::string::npos;
    std::cout << "flag:" << flag << std::endl;
    // 查找子字符串 "yang" 在 name4 中的位置
    std::cout << "yang的位置:" << name4.find("yang") << std::endl;      
    std::cout << name4.size() << std::endl;
    std::cout << name4 << std::endl;
    // 调用 printString 函数，输出 name4 的内容
    printString(name4);


    // char name5[] = "xu\0yang"; 
    char name5[] = "xuyang"; 
    name5[2] = 'a';
    std::cout << "name5xu\\0yang:" << name5 << std::endl;
    // 打印 name5 的长度，strlen 会统计到 '\0' 前的字符数量
    std::cout << "name5的长度:" << strlen(name5) << std::endl;

    // 字符串字面量存储在只读内存区 字符串字面量 "xuyang" 实际上存储在程序的 只读内存区域 （通常是常量区），用于防止程序意外修改这些字面量。
    const char * name6 = "xuyang"; // 指向常量字符串的指针,最好要用const 修饰
    // name6[2] = 'a'; // 警告：指向常量字符串的指针不能修改其指向的内容
    std::cout << "name6:" << name6 << std::endl;
    return 0;
}