// 演示 Java 中的参数传递机制
public class ParamPassingDemo {
    
    // 基本数据类型的值传递
    public static void pointerTest(int p) {
        System.out.println("PointerTest:");
        System.out.println("  传入值: " + p);
        System.out.println("  传入参数的内存地址（由于是基本类型，这里只是示意栈内存）: " + System.identityHashCode(Integer.valueOf(p)));
        p = 999;  // 修改局部变量
        System.out.println("  修改后值: " + p);
        System.out.println("  修改后参数的内存地址（由于是基本类型，这里只是示意栈内存）: " + System.identityHashCode(Integer.valueOf(p)));
    }
    
    // 对象的引用值传递
    public static void referenceTest(MyObject obj) {
        System.out.println("ReferenceTest:");
        System.out.println("  传入对象的值: " + obj.getValue());
        System.out.println("  传入对象的内存地址: " + System.identityHashCode(obj));
        obj.setValue(999);  // 修改对象内容
        System.out.println("  修改对象内容后的值: " + obj.getValue());
        System.out.println("  修改对象内容后的内存地址: " + System.identityHashCode(obj));
        obj = new MyObject(888);  // 创建新对象（不影响外部引用）
        System.out.println("  创建新对象后的值: " + obj.getValue());
        System.out.println("  创建新对象后的内存地址: " + System.identityHashCode(obj));
    }
    
    // 包装类（不可变对象）的传递
    public static void immutableObjectTest(Integer num) {
        System.out.println("ImmutableObjectTest:");
        System.out.println("  传入值: " + num);
        System.out.println("  传入对象的内存地址: " + System.identityHashCode(num));
        num = 777;  // 实际上创建新对象
        System.out.println("  修改后值: " + num);
        System.out.println("  修改后对象的内存地址: " + System.identityHashCode(num));
    }
    
    public static void main(String[] args) {
        // 测试基本数据类型
        int num = 10;
        System.out.println("初始num: " + num);
        System.out.println("初始num的内存地址（由于是基本类型，这里只是示意栈内存）: " + System.identityHashCode(Integer.valueOf(num)));
        pointerTest(num);
        System.out.println("调用后num: " + num);
        System.out.println("调用后num的内存地址（由于是基本类型，这里只是示意栈内存）: " + System.identityHashCode(Integer.valueOf(num)) + "\n");
        
        // 测试引用数据类型
        MyObject obj = new MyObject(20);
        System.out.println("初始obj值: " + obj.getValue());
        System.out.println("初始obj的内存地址: " + System.identityHashCode(obj));
        referenceTest(obj);
        System.out.println("调用后obj值: " + obj.getValue());
        System.out.println("调用后obj的内存地址: " + System.identityHashCode(obj) + "\n");
        
        // 测试不可变对象
        Integer immutableNum = 30;
        System.out.println("初始immutableNum: " + immutableNum);
        System.out.println("初始immutableNum的内存地址: " + System.identityHashCode(immutableNum));
        immutableObjectTest(immutableNum);
        System.out.println("调用后immutableNum: " + immutableNum);
        System.out.println("调用后immutableNum的内存地址: " + System.identityHashCode(immutableNum));
    }
}

// 辅助类
class MyObject {
    private int value;
    
    public MyObject(int value) {
        this.value = value;
    }
    
    public int getValue() {
        return value;
    }
    
    public void setValue(int value) {
        this.value = value;
    }
}

// cd "/root/xuyang/Cpp_cherno/class41-46/" && javac ParamPassingDemo.java && java ParamPassingDemo

/*
初始num: 10
初始num的内存地址（由于是基本类型，这里只是示意栈内存）: 498931366
PointerTest:
  传入值: 10
  传入参数的内存地址（由于是基本类型，这里只是示意栈内存）: 498931366
  修改后值: 999
  修改后参数的内存地址（由于是基本类型，这里只是示意栈内存）: 2060468723
调用后num: 10
调用后num的内存地址（由于是基本类型，这里只是示意栈内存）: 498931366

初始obj值: 20
初始obj的内存地址: 1933863327
ReferenceTest:
  传入对象的值: 20
  传入对象的内存地址: 1933863327
  修改对象内容后的值: 999
  修改对象内容后的内存地址: 1933863327
  创建新对象后的值: 888
  创建新对象后的内存地址: 112810359
调用后obj值: 999
调用后obj的内存地址: 1933863327

初始immutableNum: 30
初始immutableNum的内存地址: 146589023
ImmutableObjectTest:
  传入值: 30
  传入对象的内存地址: 146589023
  修改后值: 777
  修改后对象的内存地址: 1482968390
调用后immutableNum: 30
调用后immutableNum的内存地址: 146589023
 */