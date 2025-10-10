#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <memory>
  // 用于malloc和free

// 简单的日志宏
#define LOG(x) std::cout << x << std::endl

// Entity类定义（对应图片中的Entity）
class Entity {
private:
    std::string m_Name;
public:
    // 默认构造函数
    Entity() : m_Name("Unknown") {
        LOG("Entity默认构造函数被调用");
    }
    
    // 带参数构造函数
    Entity(const std::string& name) : m_Name(name) {
        LOG("Entity带参构造函数被调用: " << name);
    }
    
    // 析构函数
    ~Entity() {
        LOG("Entity析构函数被调用: " << m_Name);
    }
    
    const std::string& GetName() const { 
        return m_Name; 
    }
};

// 演示new的基本用法（对应图片1）
void basicNewDemo() {
    LOG("\n=== 1. new关键字基本用法 ===");
    
    // 基本类型分配
    int* singleInt = new int;           // 分配4字节（对应图片中的new int）
    *singleInt = 42;
    LOG("单个int值: " << *singleInt);
    delete singleInt;                   // 必须释放！
    
    // 数组分配（对应图片中的new int[50]）
    int* intArray = new int[50];        // 分配200字节（50 * 4）
    intArray[0] = 10;
    LOG("数组第一个元素: " << intArray[0]);
    delete[] intArray;                  // 必须用delete[]
    
    // 对象分配（对应图片中的new Entity()）
    Entity* entity = new Entity("Cherno");
    LOG("Entity名称: " << entity->GetName());
    delete entity;                      // 释放对象
}

// 演示new与malloc的区别（对应图片1底部对比）
void newVsMallocDemo() {
    LOG("\n=== 2. new vs malloc 区别演示 ===");
    
    // (1) C++风格：new（推荐）
    LOG("(1) 使用new（调用构造函数）:");
    Entity* e1 = new Entity("NewObject");
    
    // (2) C风格：malloc（不推荐，对应图片中的对比）
    LOG("(2) 使用malloc（不调用构造函数）:");
    Entity* e2 = (Entity*)malloc(sizeof(Entity));  // 仅分配内存
    
    // 验证区别
    LOG("e1名称: " << e1->GetName());  // 正常，因为调用了构造函数
    // LOG("e2名称: " << e2->GetName());  // ❌ 危险：未初始化！
    
    // 正确释放
    delete e1;     // 调用析构函数 + 释放内存
    free(e2);      // 仅释放内存（无析构函数调用）
}

// 演示delete的重要性（对应图片2的内存泄漏警告）
void memoryManagementDemo() {
    LOG("\n=== 3. 内存管理演示 ===");
    
    // 正确做法：分配后立即使用并释放
    LOG("正确做法演示:");
    Entity* temp = new Entity("TempObject");
    LOG("使用对象: " << temp->GetName());
    delete temp;  // ✅ 及时释放
    temp = nullptr;
    
    // 内存泄漏示例（对应图片2的警告）
    LOG("内存泄漏风险演示:");
    Entity* leaky = new Entity("LeakyObject");
    LOG("创建了对象但忘记delete...");
    // 故意不调用delete → 内存泄漏！
    // 实际项目中应该避免这种情况
}

// 演示数组的new[]和delete[]配对（对应图片2注意事项1）
void arrayNewDeleteDemo() {
    LOG("\n=== 4. 数组new[]和delete[]配对 ===");
    
    // ✅ 正确：new[] 对应 delete[]
    int* arr = new int[5]{1, 2, 3, 4, 5};
    LOG("数组元素: " << arr[0] << "," << arr[1] << "," << arr[2]);
    delete[] arr;  // 必须使用delete[]
    
    // ❌ 错误演示（注释掉避免崩溃）
    // int* wrongArr = new int[5];
    // delete wrongArr;  // 错误！应该用delete[]
    // 这会导致未定义行为（可能崩溃）
}

// 演示placement new（对应图片2注意事项2）
void placementNewDemo() {
    LOG("\n=== 5. Placement New演示 ===");
    
    // 先分配原始内存
    void* memoryPool = malloc(sizeof(Entity));
    LOG("分配了" << sizeof(Entity) << "字节内存池");
    
    // 使用placement new在指定内存构造对象
    Entity* e = new(memoryPool) Entity("PlacementObject");
    LOG("在指定内存构造的对象: " << e->GetName());
    
    // 手动调用析构函数（placement new的特殊要求）
    e->~Entity();
    
    // 释放原始内存
    free(memoryPool);
    LOG("内存池已释放");
}

// 演示现代C++的替代方案（最佳实践）
void modernAlternativesDemo() {
    LOG("\n=== 6. 现代C++替代方案（推荐） ===");
    
    // 使用智能指针避免手动管理
    LOG("使用std::unique_ptr（自动管理）:");
    std::unique_ptr<Entity> smartEntity = std::make_unique<Entity>("SmartObject");
    LOG("智能指针对象: " << smartEntity->GetName());
    // 无需手动delete，离开作用域自动释放
    
    LOG("使用std::vector替代数组:");
    std::vector<int> vec = {1, 2, 3, 4, 5};
    LOG("vector大小: " << vec.size());
    // 自动管理内存，无需手动释放
}

int main() {
    LOG("=== C++ new关键字完整演示 ===");
    LOG("对应图片1和图片2的所有内容");
    
    // 运行所有演示
    basicNewDemo();
    newVsMallocDemo();
    memoryManagementDemo();
    arrayNewDeleteDemo();
    placementNewDemo();
    modernAlternativesDemo();
    
    LOG("\n=== 演示完成 ===");
    LOG("按Enter键退出...");
    std::cin.get();
    
    return 0;
}