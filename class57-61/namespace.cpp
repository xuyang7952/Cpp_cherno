// ======================
// 示例：自定义命名空间
// ======================

#include <iostream>
#include <string>

// 定义两个命名空间，模拟不同模块
namespace Graphics {
    void render() {
        std::cout << "[Graphics] Rendering scene...\n";
    }

    class Renderer {
    public:
        void init() { std::cout << "Initializing OpenGL\n"; }
    };
} // namespace Graphics

namespace Audio {
    void render() {  // 同名函数，但不会冲突
        std::cout << "[Audio] Playing sound...\n";
    }

    class Renderer {
    public:
        void init() { std::cout << "Initializing OpenAL\n"; }
    };
} // namespace Audio

// ======================
// 示例：匿名命名空间（替代 static）
// ======================

namespace {
    // 这些只在当前文件可见，等价于加了 static
    void helper_function() {
        std::cout << "This is a private helper function.\n";
    }

    int file_local_counter = 0;
} // anonymous namespace

// ======================
// 示例：内联命名空间（C++11）
// ======================

namespace App {
    inline namespace v1_0 {
        void start() {
            std::cout << "App v1.0 starting...\n";
        }
    }

    namespace v1_1 {
        void start() {
            std::cout << "App v1.1 starting...\n";
        }
    }
} // namespace App

// ======================
// 主函数演示各种用法
// ======================

int main() {
    std::cout << "=== 1. 使用作用域解析符 ===\n";
    Graphics::render();
    Audio::render();

    Graphics::Renderer gfx;
    gfx.init();

    Audio::Renderer audio;
    audio.init();

    std::cout << "\n=== 2. using 声明（推荐）===\n";
    using std::cout;
    using std::string;

    cout << "Now I can use 'cout' directly!\n";

    string name = "World";
    cout << "Hello, " << name << "\n";

    std::cout << "\n=== 3. using namespace 局部使用（仅限 .cpp）===\n";
    {
        using namespace Graphics;
        render(); // OK，但在小范围内使用
    }

    std::cout << "\n=== 4. 匿名命名空间测试 ===\n";
    helper_function(); // OK: 当前文件可用
    file_local_counter++;
    std::cout << "Counter: " << file_local_counter << "\n";

    std::cout << "\n=== 5. 内联命名空间默认访问 ===\n";
    App::start(); // 默认调用 v1_0 的版本

    App::v1_1::start(); // 显式调用 v1.1

    return 0;
}