# 演示 Python 中的参数传递机制

def pointer_test(p):
    print("PointerTest:")
    print(f"  传入对象的 id: {id(p)}")
    p = 15  # 尝试修改引用指向
    print(f"  修改后对象的 id: {id(p)}")

def reference_test(p_ref):
    print("ReferenceTest:")
    print(f"  传入对象的 id: {id(p_ref)}")
    p_ref = None  # 尝试修改引用指向
    print(f"  修改后对象的 id: {id(p_ref)}")

def mutable_object_test(list_ref):
    print("MutableObjectTest:")
    print(f"  传入列表的 id: {id(list_ref)}")
    list_ref.append(999)  # 修改列表内容
    print(f"  修改后列表的 id: {id(list_ref)}")  # id 不变
    list_ref = [1, 2, 3]  # 重新赋值
    print(f"  重新赋值后列表的 id: {id(list_ref)}")  # id 改变

# 主程序

### Python 的参数传递
# Python 的参数传递机制被称为 "对象引用传递" （更准确地说，是 传递对象引用的值 ）：
# - 对于可变对象（列表、字典、集合等）：函数内修改会影响原始对象
# - 对于不可变对象（整数、字符串、元组等）：函数内无法修改原始对象
if __name__ == "__main__":
    # 演示不可变对象（整数）的传递
    num = 10
    print(f"初始num的id: {id(num)}")
    pointer_test(num)
    print(f"调用后num的值: {num}")
    print(f"调用后num的id: {id(num)}\n")
    
    # 演示可变对象（列表）的传递
    lst = [1, 2, 3]
    print(f"初始lst的id: {id(lst)}")
    mutable_object_test(lst)
    print(f"调用后lst的内容: {lst}")
    print(f"调用后lst的id: {id(lst)}")

"""
初始num的id: 9821448
PointerTest:
传入对象的 id: 9821448
修改后对象的 id: 9821608
调用后num的值: 10
调用后num的id: 9821448

初始lst的id: 140305599138240
MutableObjectTest:
传入列表的 id: 140305599138240
修改后列表的 id: 140305599138240
重新赋值后列表的 id: 140305599140032
调用后lst的内容: [1, 2, 3, 999]
调用后lst的id: 140305599138240
"""