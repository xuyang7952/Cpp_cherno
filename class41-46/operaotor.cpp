#include <iostream>

struct Vector2 {
    float x, y;
    
    Vector2(float x = 0, float y = 0) : x(x), y(y) {}
    
    // 运算符重载
    // 第一个const ： const Vector2& other - 作用 ：修饰参数 other ，确保在函数内部 不会修改传入的参数对象
    // 第二个const ：函数末尾的 const 作用 ：修饰 this 指针，确保函数 不会修改调用该函数的对象 （即左操作数）
    // 成员函数末尾的 const 关键字是类（class）和结构体（struct）成员函数特有的语法，它的核心作用是 修饰 this 指针 ，确保该成员函数不会修改调用对象的状态。
    // 末尾 const 的作用 ：当在成员函数声明末尾添加 const 关键字时， this 指针的类型会变为 const 类名* const （指向常量对象的常量指针），这意味着：
    // - 函数内部 不能修改 调用对象的任何非 mutable 成员变量
    // - 函数内部 只能调用 其他 const 成员函数（避免通过其他函数间接修改对象）

    Vector2 operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }
    
    Vector2 operator*(const Vector2& other) const {
        return Vector2(x * other.x, y * other.y);
    }
    
    bool operator==(const Vector2& other) const {
        return x == other.x && y == other.y;
    }
    
    bool operator!=(const Vector2& other) const {
        return !(*this == other);
    }
};

// 全局输出流重载
std::ostream& operator<<(std::ostream& stream, const Vector2& other) {
    stream << "(" << other.x << ", " << other.y << ")";
    return stream;
}

int main() {
    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f);
    
    Vector2 result = position + speed * powerup;
    std::cout << "Result: " << result << std::endl;
    std::cout << "Position: " << position.x << std::endl;
    
    return 0;
}