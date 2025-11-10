#include <iostream>
#include <iomanip>
#include <cstring> // for memcpy

// 注意：std::variant需要C++17或更高版本
// 编译命令：g++ -std=c++17 unions.cpp -o unions

// ----------------------------
// 1. 基础联合体：类型双关
// ----------------------------
union FloatInt {
    float f;
    int i;
};

void demo_basic_union() {
    std::cout << "=== 1. 基础联合体：float/int 类型双关 ===\n";
    FloatInt u;
    u.f = 3.14159f;

    std::cout << "u.f = " << u.f << "\n";
    std::cout << "u.i (位表示) = 0x" << std::hex << u.i << std::dec << "\n";

    // 验证：用 memcpy 安全方式对比
    int safe_bits;
    std::memcpy(&safe_bits, &u.f, sizeof(u.f));
    std::cout << "memcpy 方式: 0x" << std::hex << safe_bits << std::dec << "\n\n";
}

// ----------------------------
// 2. 匿名联合体 + 嵌套结构体（Cherno 示例）
// ----------------------------
struct Vector2 {
    float x, y;
    friend std::ostream& operator<<(std::ostream& os, const Vector2& v) {
        return os << "(" << v.x << ", " << v.y << ")";
    }
};

struct Vector4 {
    union {
        struct { float x, y, z, w; };      // 匿名结构体1
        struct { Vector2 a, b; };          // 匿名结构体2：a=(x,y), b=(z,w)
    };

    Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
};

void demo_vector4_union() {
    std::cout << "=== 2. Vector4 联合体：多视图访问 ===\n";
    Vector4 v(1.0f, 2.0f, 3.0f, 4.0f);

    std::cout << "v.x, v.y, v.z, v.w = " << v.x << ", " << v.y << ", " << v.z << ", " << v.w << "\n";
    std::cout << "v.a = " << v.a << ", v.b = " << v.b << "\n";

    // 修改 v.z 会影响 v.b.x
    v.z = 500.0f;
    std::cout << "修改 v.z = 500 后:\n";
    std::cout << "v.b = " << v.b << "  // 注意：b.x 变为 500\n\n";
}

// ----------------------------
// 3. 手动管理非 POD 类型（C++11+）
// ----------------------------
#include <string>

struct StringOrInt {
    enum Type { STRING, INT } type;

    union {
        int i;
        std::string s; // C++11 允许，但需手动管理
    };

    // 构造函数
    StringOrInt(int value) : type(INT), i(value) {}
    StringOrInt(const char* str) : type(STRING) {
        new(&s) std::string(str); // placement new
    }

    // 析构函数（必须显式调用 string 的析构）
    ~StringOrInt() {
        if (type == STRING) {
            s.~basic_string(); // 显式析构
        }
    }

    void print() const {
        if (type == INT) {
            std::cout << "int: " << i;
        } else {
            std::cout << "string: \"" << s << "\"";
        }
    }
};

void demo_non_pod_union() {
    std::cout << "=== 3. 手动管理非 POD 联合体 ===\n";
    {
        StringOrInt a(42);
        StringOrInt b("Hello Union!");

        a.print(); std::cout << "\n";
        b.print(); std::cout << "\n";
    } // 析构函数自动调用，安全释放
    std::cout << "\n";
}

// ----------------------------
// 4. 对比：现代替代方案 std::variant（推荐）
// ----------------------------
/* 以下代码需要C++17或更高版本
#include <variant>

void demo_std_variant() {
    std::cout << "=== 4. 现代替代：std::variant（安全！）===\n";
    std::variant<int, std::string> v = "Hello Variant!";
    
    if (std::holds_alternative<std::string>(v)) {
        std::cout << "Variant contains: " << std::get<std::string>(v) << "\n";
    }

    v = 100;
    std::cout << "Now contains: " << std::get<int>(v) << "\n\n";
}
*/

// ----------------------------
// 主函数
// ----------------------------
int main() {
    demo_basic_union();
    demo_vector4_union();
    demo_non_pod_union();
    // demo_std_variant();

    return 0;
}