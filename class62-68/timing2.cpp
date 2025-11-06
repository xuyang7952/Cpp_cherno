#include <iostream>
#include <chrono>
#include <thread>


struct Timer
{
    // std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;
    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        std::cout << "Timer took " << ms << " ms" << std::endl;
    }
};

void Function()
{
    Timer timer;  // 利用构造和析构函数来计时
    for (int i = 0; i < 100; i++)
        // std::cout << "Hello" << std::endl; //想要计算这些cout代码运行需要的时间
        std::cout << "Hello\t" ; //想要计算这些cout代码运行需要的时间
}

int main()
{
    Function();

    // std::cin.get();
}