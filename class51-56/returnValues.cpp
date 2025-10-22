#include <iostream>
#include <string>
#include <tuple>
#include <array>
#include <vector>

// 方法1：引用返回
void returnWithReference(std::string& str, int& num) {
    str = "Hello";
    num = 42;
}

// 方法2：array 和 vector
std::array<int, 2> returnWithArray() {
    return {42, 56};
}

std::vector<int> returnWithVector() {
    return {42, 56};
}

// 方法3：tuple 和 pair
std::tuple<std::string, int> returnWithTuple() {
    return std::make_tuple("Hello", 42);
}

std::pair<std::string, int> returnWithPair() {
    return std::make_pair("Hello", 42);
}

// 方法4：结构体（推荐）
struct Result {
    std::string str;
    int num;
};

Result returnWithStruct() {
    return {"Hello", 42};
}

int main() {
    std::cout << "=== 方法1：引用 ===" << std::endl;
    std::string str;
    int num;
    returnWithReference(str, num);
    std::cout << str << ", " << num << std::endl;

    std::cout << "\n=== 方法2：array/vector ===" << std::endl;
    auto arr = returnWithArray();
    auto vec = returnWithVector();
    std::cout << "Array: " << arr[0] << ", " << arr[1] << std::endl;
    std::cout << "Vector: " << vec[0] << ", " << vec[1] << std::endl;

    std::cout << "\n=== 方法3：tuple/pair ===" << std::endl;
    auto tupleResult = returnWithTuple();
    auto pairResult = returnWithPair();
    std::cout << "Tuple: " << std::get<0>(tupleResult) << ", " << std::get<1>(tupleResult) << std::endl;
    std::cout << "Pair: " << pairResult.first << ", " << pairResult.second << std::endl;

    std::cout << "\n=== 方法4：struct（推荐）===" << std::endl;
    Result result = returnWithStruct();
    std::cout << result.str << ", " << result.num << std::endl;

    // C++17 结构化绑定
    std::cout << "\n=== 结构化绑定（C++17）===" << std::endl;
    auto [text, value] = returnWithStruct();
    std::cout << text << ", " << value << std::endl;

    return 0;
}