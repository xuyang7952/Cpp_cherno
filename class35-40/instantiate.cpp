#include <iostream>
#include <string>

// 简单的日志宏（对应图片中的LOG）
#define LOG(x) std::cout << x << std::endl

// Entity类定义（对应图片1）
class Entity {
private:
    std::string m_Name;
public:
    // 默认构造函数
    Entity() : m_Name("Unknown") {
        LOG("默认构造函数被调用");
    }
    
    // 带参数构造函数
    Entity(const std::string& name) : m_Name(name) {
        LOG("带参构造函数被调用: " << name);
    }
    
    // 析构函数（用于观察对象销毁）
    ~Entity() {
        LOG("析构函数被调用: " << m_Name);
    }
    
    const std::string& GetName() const { 
        return m_Name; 
    }
};

// 函数作用域演示（对应图片2上半部分）
void Function() {
    LOG("\n=== 函数作用域演示 ===");
    Entity entity = Entity("Cherno");
    LOG("函数内实体名称: " << entity.GetName());
    // 函数结束时，entity自动销毁
}

// 栈上创建对象演示（对应图片1）
void StackAllocationDemo() {
    LOG("\n=== 栈上创建对象 ===");
    Entity entity1;  // 默认构造
    LOG("entity1名称: " << entity1.GetName());
    
    Entity entity2("StackObject");  // 带参构造
    LOG("entity2名称: " << entity2.GetName());
    
    // 离开函数时，entity1和entity2自动销毁
}

// 堆上创建对象演示（对应图片2下半部分和图片3）
void HeapAllocationDemo() {
    LOG("\n=== 堆上创建对象 ===");
    
    Entity* e = nullptr;  // 外部作用域指针（对应图片3）
    
    {
        LOG("进入内部作用域");
        // 堆上创建对象（对应图片2的new Entity）
        Entity* entity = new Entity("HeapObject");
        LOG("堆实体名称: " << entity->GetName());
        
        e = entity;  // 将地址赋给外部指针（对应图片3）
        LOG("e指针指向: " << e->GetName());
        
        LOG("离开内部作用域");
    } // entity指针超出作用域，但堆对象仍然存在
    
    // e仍然有效，指向堆上的对象（对应图片3说明）
    LOG("外部作用域 - e仍然指向: " << e->GetName());
    
    // 必须手动释放堆内存！（对应图片3的delete）
    LOG("准备手动delete e");
    delete e;
    e = nullptr;
    LOG("堆内存已释放");
}

// 内存泄漏演示（对应图片3的警告）
void MemoryLeakDemo() {
    LOG("\n=== 内存泄漏演示 ===");
    Entity* leakyEntity = new Entity("LeakyObject");
    LOG("创建了对象: " << leakyEntity->GetName());
    
    // 故意不调用delete → 内存泄漏！
    // delete leakyEntity;
    LOG("注意：这里故意没有调用delete，导致内存泄漏！");
}

int main() {
    LOG("程序开始");
    
    // 1. 栈上创建演示（图片1）
    StackAllocationDemo();
    
    // 2. 函数作用域演示（图片2上半部分）
    Function();
    
    // 3. 堆上创建演示（图片2下半部分 + 图片3）
    HeapAllocationDemo();
    
    // 4. 内存泄漏演示（图片3的警告）
    MemoryLeakDemo();
    
    
    LOG("程序结束");
    return 0;
}
