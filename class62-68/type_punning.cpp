#include <iostream>
#include <cstring>   // for memcpy
#include <bit>       // for std::bit_cast (C++20)
#include <iomanip>

// 方法1：危险的 C 风格转换（不推荐）
float type_pun_dangerous(int bits) {
    return *(float*)(&bits); // UB! Strict aliasing violation
}

// 方法2：使用 memcpy（安全，兼容旧标准）
float type_pun_memcpy(int bits) {
    float result;
    std::memcpy(&result, &bits, sizeof(result));
    return result;
}

// 方法3：C++20 std::bit_cast（推荐）
#ifdef __cpp_lib_bit_cast
float type_pun_bitcast(int bits) {
    return std::bit_cast<float>(bits);
}
#endif

// 方法4：Union（不标准，仅作演示）
float type_pun_union(int bits) {
    union { int i; float f; } converter;
    converter.i = bits;
    return converter.f; // technically UB in C++, but works in practice
}

int main() {
    // IEEE 754: float 25.0 的二进制表示为 0x41C80000
    int bits = 0x41C80000;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "原始整数 (十六进制): 0x" << std::hex << bits << std::dec << "\n\n";

    // 1. 危险方式（可能被优化掉或出错）
    std::cout << "1. C风格转换 (危险): " << type_pun_dangerous(bits) << "\n";

    // 2. memcpy（安全可靠）
    std::cout << "2. memcpy (安全):     " << type_pun_memcpy(bits) << "\n";

    // 3. std::bit_cast（C++20）
#ifdef __cpp_lib_bit_cast
    std::cout << "3. std::bit_cast (C++20): " << type_pun_bitcast(bits) << "\n";
#else
    std::cout << "3. std::bit_cast: 不可用（需 C++20）\n";
#endif

    // 4. Union（非标准）
    std::cout << "4. Union (非标准):    " << type_pun_union(bits) << "\n";

    // ==============================
    // 实际应用：结构体序列化为字节
    // ==============================
    struct Entity {
        int x = 123;
        int y = 456;
    };

    Entity e;
    unsigned char* bytes = reinterpret_cast<unsigned char*>(&e);

    std::cout << "\n=== 结构体类型双关：序列化为字节 ===\n";
    std::cout << "Entity: (" << e.x << ", " << e.y << ")\n";
    std::cout << "前8字节（小端序）:\n";
    for (size_t i = 0; i < sizeof(Entity); ++i) {
        std::cout << "byte[" << i << "] = 0x"
                  << std::hex << std::setfill('0') << std::setw(2)
                  << static_cast<int>(bytes[i]) << std::dec << "\n";
    }

    // 注意：这种 reinterpret_cast 用于 POD 类型是安全的，
    // 但前提是结构体没有虚函数、继承、非平凡构造等。

    return 0;
}