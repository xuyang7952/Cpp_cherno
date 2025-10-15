#include <iostream>
#include <vector>

struct Vertex {
    float x, y, z;

    // 默认构造函数
    Vertex(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    // 复制构造函数（打印日志）
    Vertex(const Vertex& v) : x(v.x), y(v.y), z(v.z) {
        std::cout << "Copied!" << std::endl;
    }

    // 重载输出操作符
    friend std::ostream& operator<<(std::ostream& os, const Vertex& v) {
        os << v.x << "," << v.y << "," << v.z;
        return os;
    }
};

// 示例函数：打印 vector 内容
void printVector(const std::vector<Vertex>& v) {
    for (const auto& elem : v) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "=== 方法1: push_back({x,y,z}) ===" << std::endl;
    std::vector<Vertex> v1;
    v1.reserve(2);                    // 预留空间
    v1.push_back({1, 2, 3});  // 临时对象 + 复制
    // v1.push_back({4, 5, 6});
    printVector(v1);

    std::cout << "\n=== 方法2: push_back(Vertex(x,y,z)) ===" << std::endl;
    std::vector<Vertex> v2;
    v2.push_back(Vertex(1, 2, 3));  // 显式构造临时对象
    v2.push_back(Vertex(4, 5, 6));
    v2.push_back(Vertex(4, 5, 6));
    printVector(v2);

    std::cout << "\n=== 方法3: reserve + emplace_back ===" << std::endl;
    std::vector<Vertex> v3;
    v3.reserve(3);                    // 预留空间
    v3.emplace_back(1, 2, 3);         // 就地构造
    v3.emplace_back(4, 5, 6);
    v3.emplace_back(7, 8, 9);
    printVector(v3);

    return 0;
}