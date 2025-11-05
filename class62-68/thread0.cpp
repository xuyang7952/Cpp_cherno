#include <iostream>
#include <thread>
#include <chrono>

void do_work() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Working... " << i << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    std::cout << "启动线程...\n";

    // 👇 这一行执行时，新线程就已经开始运行了！
    std::thread worker(do_work);

    std::cout << "主线程继续做其他事...\n";

    // 👇 这里只是“等待”它完成，并不会启动它
    worker.join();

    std::cout << "工作完成。\n";
    return 0;
}