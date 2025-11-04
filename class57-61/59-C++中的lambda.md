# C++ 中的 Lambda 表达式（Lambda）说明与总结

Lambda 是 **C++11 引入的一项强大特性**，它允许我们在代码中定义**匿名函数（即没有名字的函数）**，并可以立即使用或传递给其他函数。它是现代 C++ 编程的核心工具之一。

## 一、什么是 Lambda？

Lambda 是一种创建**内联匿名函数对象**的方式，语法如下：

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>[capture](parameters) -> return_type { body }</span></code></pre></div></div></pre>

其中：

* `[capture]`：**捕获列表**，决定如何从外部作用域获取变量（值捕获、引用捕获等）
* `(parameters)`：参数列表，和普通函数一样
* `-> return_type`：返回类型（可选，通常由编译器自动推导）
* `{ body }`：函数体

> 🔁 **本质**：Lambda 在底层被编译为一个**仿函数（functor）类的对象**，即带有 `operator()` 的类实例。

## 二、核心特点总结


| 特性                        | 说明                                                             |
| --------------------------- | ---------------------------------------------------------------- |
| **匿名性**                  | 不需要命名，适合一次性使用的逻辑                                 |
| **就地定义**                | 可以在调用处直接写逻辑，提高可读性                               |
| **支持捕获外部变量**        | 能“记住”周围作用域中的变量（通过值或引用）                     |
| **可作为回调传入 STL 算法** | 如`std::find_if`, `std::sort`, `std::for_each` 等                |
| **性能高**                  | 编译器通常会内联优化，无运行时开销                               |
| **类型是唯一的**            | 每个 lambda 有唯一类型，不能直接用普通函数指针接收（除非无捕获） |

## 三、捕获方式详解（Capture List）


| 写法      | 含义                               |
| --------- | ---------------------------------- |
| `[]`      | 不捕获任何变量                     |
| `[=]`     | 值捕获所有外部变量（复制一份）     |
| `[&]`     | 引用捕获所有外部变量（共享同一份） |
| `[a]`     | 值捕获变量`a`                      |
| `[&a]`    | 引用捕获变量`a`                    |
| `[a, &b]` | 混合捕获：`a` 值捕获，`b` 引用捕获 |
| `[&, a]`  | 默认引用捕获，但`a` 是值捕获       |
| `[=, &a]` | 默认值捕获，但`a` 是引用捕获       |

## 四、`mutable` 关键字

默认情况下，**值捕获的变量在 lambda 内是只读的**（相当于 `const`）。
如果想修改它们，需要加上 `mutable`：

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>int</span><span> x = </span>10<span>;
</span><span></span><span>auto</span><span> lambda = [=]() </span><span>mutable</span><span> {
</span><span>    x = </span>20<span>; </span><span>// 修改副本</span><span>
</span><span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"Inside: "</span><span> << x << </span><span>"\n"</span><span>;
</span>};
<span>lambda();           </span><span>// 输出: Inside: 20</span><span>
</span><span></span><span>std</span><span>::</span><span>cout</span><span> << x;     </span><span>// 输出: 10 (原变量未变)</span></code></pre></div></div></pre>

## 五、可运行完整代码示例

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>#</span>include<span> </span><iostream><span>
</span><span></span><span>#</span>include<span> </span><vector><span>
</span><span></span><span>#</span>include<span> </span><algorithm><span>
</span><span></span><span>#</span>include<span> </span><functional><span>  </span><span>// std::function</span><span>
</span><span></span><span>#</span>include<span> </span><string><span>
</span>
<span></span><span>// 通用遍历函数，接受 std::function 类型的回调</span><span>
</span><span></span>void ForEach(const std::vector<int>& values, const std::function<void(int)>& func) <span>{
</span><span>    </span><span>for</span><span> (</span><span>int</span><span> value : values) {
</span>        func(value);
    }
}

<span></span>int main() <span>{
</span><span>    </span><span>std</span><span>::</span><span>vector</span><span><</span><span>int</span><span>> values = {</span>1<span>, </span>5<span>, </span>4<span>, </span>2<span>, </span>3<span>};
</span><span>    </span><span>int</span><span> factor = </span>2<span>;
</span><span>    </span><span>std</span><span>::</span><span>string</span><span> prefix = </span><span>"Value: "</span><span>;
</span>
<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"=== 1. 最简单的 Lambda ===\n"</span><span>;
</span><span>    </span><span>std</span><span>::for_each(values.begin(), values.end(), [](</span><span>int</span><span> x) {
</span><span>        </span><span>std</span><span>::</span><span>cout</span><span> << x << </span><span>" "</span><span>;
</span>    });
<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"\n\n"</span><span>;
</span>
<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"=== 2. 使用捕获列表 [factor]（值捕获）===\n"</span><span>;
</span><span>    </span><span>std</span><span>::for_each(values.begin(), values.end(), [factor](</span><span>int</span><span> x) {
</span><span>        </span><span>std</span><span>::</span><span>cout</span><span> << x * factor << </span><span>" "</span><span>;  </span><span>// 使用外部变量</span><span>
</span>    });
<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"\n\n"</span><span>;
</span>
<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"=== 3. 引用捕获 [&prefix] 修改外部变量 ===\n"</span><span>;
</span><span>    </span><span>std</span><span>::for_each(values.begin(), values.end(), [&prefix](</span><span>int</span><span> x) {
</span><span>        </span><span>std</span><span>::</span><span>cout</span><span> << prefix << x << </span><span>"\n"</span><span>;
</span><span>        prefix += </span><span>"*"</span><span>;  </span><span>// 修改原始变量</span><span>
</span>    });
<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"After loop, prefix = '"</span><span> << prefix << </span><span>"'\n\n"</span><span>;
</span>
<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"=== 4. mutable：修改值捕获的副本 ===\n"</span><span>;
</span><span>    </span><span>int</span><span> counter = </span>0<span>;
</span><span>    </span><span>auto</span><span> lambda = [counter]() </span><span>mutable</span><span> {
</span>        counter++;
<span>        </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"Counter: "</span><span> << counter << </span><span>"\n"</span><span>;
</span>    };
<span>    lambda(); </span><span>// Counter: 1</span><span>
</span><span>    lambda(); </span><span>// Counter: 2</span><span>
</span><span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"Original counter: "</span><span> << counter << </span><span>" (unchanged)\n\n"</span><span>;
</span>
<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"=== 5. 使用 ForEach 函数传入 lambda ===\n"</span><span>;
</span><span>    ForEach(values, [](</span><span>int</span><span> value) {
</span><span>        </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"[Processed] "</span><span> << value << </span><span>"\n"</span><span>;
</span>    });

<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"\n=== 6. 用于 std::find_if 查找 >3 的第一个元素 ===\n"</span><span>;
</span><span>    </span><span>auto</span><span> it = </span><span>std</span><span>::find_if(values.begin(), values.end(), [](</span><span>int</span><span> value) {
</span><span>        </span><span>return</span><span> value > </span>3<span>;
</span>    });
<span>    </span><span>if</span><span> (it != values.end()) {
</span><span>        </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"First element > 3 is: "</span><span> << *it << </span><span>"\n"</span><span>;
</span>    }

<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"\n=== 7. 用于 std::sort 自定义排序 ===\n"</span><span>;
</span><span>    </span><span>std</span><span>::</span><span>vector</span><span><</span><span>std</span><span>::</span><span>string</span><span>> words = {</span><span>"banana"</span><span>, </span><span>"apple"</span><span>, </span><span>"cherry"</span><span>, </span><span>"date"</span><span>};
</span><span>    </span><span>std</span><span>::sort(words.begin(), words.end(), [](</span><span>const</span><span> </span><span>std</span><span>::</span><span>string</span><span>& a, </span><span>const</span><span> </span><span>std</span><span>::</span><span>string</span><span>& b) {
</span><span>        </span><span>return</span><span> a.length() < b.length();  </span><span>// 按长度升序排序</span><span>
</span>    });
<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"Sorted by length: "</span><span>;
</span><span>    </span><span>for</span><span> (</span><span>const</span><span> </span><span>auto</span><span>& w : words) {
</span><span>        </span><span>std</span><span>::</span><span>cout</span><span> << w << </span><span>"("</span><span> << w.length() << </span><span>") "</span><span>;
</span>    }
<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"\n"</span><span>;
</span>
<span>    </span><span>return</span><span> </span>0<span>;
</span>}</code></pre></div></div></pre>


## 八、最佳实践建议


| 推荐做法                        | 说明                           |
| ------------------------------- | ------------------------------ |
| ✅ 优先使用 lambda 替代手写函数 | 尤其是在`std::algorithm` 中    |
| ✅ 使用`auto` 存储 lambda       | 避免写出复杂类型               |
| ✅ 复杂逻辑仍应使用命名函数     | 保持清晰                       |
| ✅ 捕获尽量明确                 | 避免`[=]` 或 `[&]` 过度捕获    |
| ✅ 注意生命周期问题             | 引用捕获时确保变量不会提前销毁 |
| ✅ 性能敏感场景放心使用         | 编译器会高度优化               |


## 九、与 Python 的对比（给算法工程师）

如果你熟悉 Python，可以把 C++ lambda 看作是：


| Python                     | C++ Lambda                                    |
| -------------------------- | --------------------------------------------- |
| `lambda x: x * 2`          | `[](int x){ return x*2; }`                    |
| `map(lambda x: x+1, data)` | `std::transform(..., [](int x){return x+1;})` |
| 支持闭包                   | 支持，但需注意捕获方式                        |
| 动态类型                   | 静态类型，参数需声明                          |

> 👉 **思想完全一致！只是 C++ 更强调类型和性能控制。**


## 十、总结

Lambda 是现代 C++ 的**灵魂特性之一**，它让代码更简洁、更函数式、更易于表达意图。掌握它，你就掌握了 STL 算法库的钥匙！

> 🔑 **记住口诀**：
>
> * 就地写逻辑 → 用 lambda
> * 要用外部变量 → 看捕获 `[=]` or `[&]`
> * 想改副本 → 加 `mutable`
> * 传给函数 → 用 `std::function` 或模板
