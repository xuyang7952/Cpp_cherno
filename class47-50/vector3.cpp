#include <iostream>
#include <vector>

struct Vertex {
    float x, y, z;

    Vertex(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {
        std::cout << "Constructed (" << x << "," << y << "," << z << ")" << std::endl;
    }

    // 复制构造函数
    Vertex(const Vertex& v) : x(v.x), y(v.y), z(v.z) {
        std::cout << "Copied! (" << x << "," << y << "," << z << ")" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vertex& v) {
        os << v.x << "," << v.y << "," << v.z;
        return os;
    }
};

int main() {
    std::vector<Vertex> vertices;
    // vertices.reserve(4);
    std::cout << "初始 size: " << vertices.size() << ", 容量: " << vertices.capacity() 
              << ", 地址: " << vertices.data() << std::endl;

    std::cout << "\n--- Adding first vertex ---" << std::endl;
    vertices.push_back({1, 2, 3});  // 容量 0→1
    std::cout << "添加后 size: " << vertices.size() << ", 容量: " << vertices.capacity() 
              << ", 地址: " << vertices.data() << std::endl;

    std::cout << "\n--- Adding second vertex ---" << std::endl;
    vertices.push_back({4, 5, 6});  // 容量 1→2，复制第一个元素
    std::cout << "添加后 size: " << vertices.size() << ", 容量: " << vertices.capacity() 
              << ", 地址: " << vertices.data() << std::endl;

    std::cout << "\n--- Adding third vertex ---" << std::endl;
    vertices.push_back({7, 8, 9});  // 容量 2→4，复制前两个元素
    std::cout << "添加后 size: " << vertices.size() << ", 容量: " << vertices.capacity() 
              << ", 地址: " << vertices.data() << std::endl;

    std::cout << "\nFinal vector: ";
    for (const auto& v : vertices) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}