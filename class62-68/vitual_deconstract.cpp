#include <iostream>
#include <memory>

// ========================================
// 情况1：没有虚析构函数 → 内存泄漏！
// ========================================
class BaseBad {
public:
    BaseBad() { std::cout << "BaseBad 构造\n"; }
    ~BaseBad() { std::cout << "BaseBad 析构\n"; } // ❌ 非虚析构
};

class DerivedBad : public BaseBad {
private:
    int* data;
public:
    DerivedBad() {
        data = new int[100]; // 分配资源
        std::cout << "DerivedBad 构造（分配了内存）\n";
    }
    ~DerivedBad() {
        delete[] data; // 释放资源
        std::cout << "DerivedBad 析构（释放了内存）\n";
    }
};

// ========================================
// 情况2：有虚析构函数 → 安全！
// ========================================
class BaseGood {
public:
    BaseGood() { std::cout << "BaseGood 构造\n"; }
    virtual ~BaseGood() { std::cout << "BaseGood 析构\n"; } // ✅ 虚析构
};

class DerivedGood : public BaseGood {
private:
    int* data;
public:
    DerivedGood() {
        data = new int[100];
        std::cout << "DerivedGood 构造（分配了内存）\n";
    }
    ~DerivedGood() {
        delete[] data;
        std::cout << "DerivedGood 析构（释放了内存）\n";
    }
};

// ========================================
// 主函数演示
// ========================================
int main() {
    std::cout << "========== 情况1：无虚析构（危险！）==========\n";
    {
        BaseBad* ptr = new DerivedBad();
        delete ptr; // ❌ 只调用 BaseBad::~BaseBad()
        // DerivedBad::~DerivedBad() 未被调用 → 内存泄漏！
    }
    std::cout << "\n";

    std::cout << "========== 情况2：有虚析构（安全！）==========\n";
    {
        BaseGood* ptr = new DerivedGood();
        delete ptr; // ✅ 先调用 DerivedGood::~DerivedGood()，再调用 BaseGood::~BaseGood()
    }
    std::cout << "\n";

    std::cout << "========== 使用智能指针（推荐实践）==========\n";
    {
        // 即使使用 unique_ptr，基类仍需虚析构！
        std::unique_ptr<BaseGood> smart_ptr = std::make_unique<DerivedGood>();
        // 自动 delete，且正确调用两个析构函数
    }

    return 0;
}