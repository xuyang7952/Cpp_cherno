#include <iostream>
#include <vector>
#include <string>

// 结构体定义
struct Vertex {
    float x, y, z;

    // 构造函数（可选）
    Vertex(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    // 重载输出操作符
    friend std::ostream& operator<<(std::ostream& os, const Vertex& v) {
        os << v.x << "," << v.y << "," << v.z;
        return os;
    }
};

// 示例函数：通过引用传递 vector
void printVertices(const std::vector<Vertex>& vertices) {
    std::cout << "Vertices: ";
    for (const Vertex& v : vertices) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main() {
    // 1. 创建 vector
    std::vector<Vertex> vertices;

    // 2. 添加元素
    vertices.push_back({1, 2, 3});
    vertices.push_back({4, 5, 6});

    // 3. 打印所有元素
    printVertices(vertices);

    // 4. 使用范围 for 遍历（推荐）
    std::cout << "Using range-based for loop:" << std::endl;
    for (Vertex& v : vertices) {
        std::cout << v << std::endl;
    }

    // 5. 删除第二个元素（索引1）
    vertices.erase(vertices.begin() + 1);
    std::cout << "\nAfter erasing index 1:" << std::endl;
    printVertices(vertices);

    // 6. 清空 vector
    vertices.clear();
    std::cout << "\nAfter clear(): size = " << vertices.size() << std::endl;

    // 7. 再次添加元素
    vertices.push_back({7, 8, 9});
    printVertices(vertices);

    return 0;
}