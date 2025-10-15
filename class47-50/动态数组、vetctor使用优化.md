# C++中的动态数组vector

## 🎯 一、C++ 动态数组：`std::vector` 详解

### ✅ 什么是 `std::vector`？

`std::vector` 是 C++ 标准模板库（STL）中的一种 **动态数组容器**，它可以在运行时自动调整大小。

> 💡 它本质是一个“可以自动扩容的数组”，支持随机访问，内存连续。

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>#</span>include<span> </span><vector><span>
</span><span></span><span>std</span><span>::</span><span>vector</span><span><</span><span>int</span><span>> vec;  </span><span>// 存储整数的动态数组</span></code></pre></div></div></pre>

---

## 🔍 二、1. 基本用法与初始化

### 📌 图片中的例子：

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code>struct Vertex {<span>
</span><span>    </span><span>float</span><span> x, y, z;
</span>};

<span></span><span>std</span><span>::</span><span>vector</span><span><Vertex> vertices;  </span><span>// 定义一个存储 Vertex 对象的 vector</span><span>
</span><span>vertices.push_back({</span>1<span>, </span>2<span>, </span>3<span>}); </span><span>// 添加元素</span><span>
</span><span>vertices.push_back({</span>4<span>, </span>5<span>, </span>6<span>});</span></code></pre></div></div></pre>

### ✅ 特点：

* 不需要预先指定大小
* 自动管理内存（自动扩容）
* 支持任意类型（如 `int`, `float`, `struct`, `class`）

> ⚠️ 注意：`std::vector` 存储的是对象本身（不是指针），所以内存是连续的，性能更好！

## 三、2. 遍历 vector 的两种方式

### ✅ 方法一：传统索引循环

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>for</span><span> (</span><span>int</span><span> i = </span>0<span>; i < vertices.size(); ++i) {
</span><span>    </span><span>std</span><span>::</span><span>cout</span><span> << vertices[i] << </span><span>std</span><span>::</span><span>endl</span><span>;
</span>}</code></pre></div></div></pre>

### ✅ 方法二：范围 for 循环（C++11 引入）

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>for</span><span> (Vertex& v : vertices) {  </span><span>// 使用 & 可修改元素</span><span>
</span><span>    </span><span>std</span><span>::</span><span>cout</span><span> << v << </span><span>std</span><span>::</span><span>endl</span><span>;
</span>}</code></pre></div></div></pre>

> 💡 推荐使用范围 for，更简洁、安全、不易出错。

### 📌 关键说明：


| 写法                               | 说明                   |
| ---------------------------------- | ---------------------- |
| `for (Vertex& v : vertices)`       | 获取引用，可修改原数据 |
| `for (const Vertex& v : vertices)` | 常量引用，不可修改     |
| `for (Vertex v : vertices)`        | 复制每个元素，效率低   |

## 四、3. 添加和删除元素

### ✅ 添加元素

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>vertices.push_back({</span>1<span>, </span>2<span>, </span>3<span>});  </span><span>// 在末尾添加</span><span>
</span><span>vertices.emplace_back(</span>4<span>, </span>5<span>, </span>6<span>); </span><span>// 更高效，就地构造</span></code></pre></div></div></pre>

### ✅ 删除元素

#### （1）清空整个 vector

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>vertices.clear();  </span><span>// 大小变为 0，但保留容量</span></code></pre></div></div></pre>

#### （2）删除单个元素（需传迭代器）

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>vertices.erase(vertices.begin() + </span>1<span>);  </span><span>// 删除索引为1的元素</span></code></pre></div></div></pre>

> ⚠️ `erase()` 接受的是 **迭代器**，不是索引。所以要用 `begin() + n` 来定位。

## 五、4. 内存连续性与性能优化

### 📌 图片重点：

> “这里存储的对象而不是指针，主要考虑的是存储 Vertex 对象比存储指针在技术上更优。如果分配的是对象，你的内存分配将在一条直线上，动态数组是内存连续的数组……”

### ✅ 为什么重要？

* `std::vector` 的元素在内存中是**连续存储**的
* CPU 缓存友好（Cache-friendly）
* 遍历时性能高（无跳跃访问）

> ❌ 如果你用 `vector<Vertex*>`，则指针可能分散在内存各处，导致缓存命中率下降。

---

## 🔍 六、5. 函数参数传递：使用引用避免拷贝

### 📌 图片强调：

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code>void Function(const std::vector<Vertex>& vertices) <span>{}</span></code></pre></div></div></pre>

### ✅ 为什么要用引用？

* `std::vector` 可能很大（成千上万个元素）
* 如果直接传值，会触发**深拷贝**，性能极差
* 使用 `const &` 可以：
  * 避免拷贝
  * 保证不被修改
  * 提高性能

> ✅ 最佳实践：**永远不要传 `vector` 值，除非你真的想复制它**

---

## ✅ 七、完整可运行代码（整合所有知识点）

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>#</span>include<span> </span><iostream><span>
</span><span></span><span>#</span>include<span> </span><vector><span>
</span><span></span><span>#</span>include<span> </span><string><span>
</span>
<span></span><span>// 结构体定义</span><span>
</span><span></span>struct Vertex {<span>
</span><span>    </span><span>float</span><span> x, y, z;
</span>
<span>    </span><span>// 构造函数（可选）</span><span>
</span><span>    Vertex(</span><span>float</span><span> x = </span>0<span>, </span><span>float</span><span> y = </span>0<span>, </span><span>float</span><span> z = </span>0<span>) : x(x), y(y), z(z) {}
</span>
<span>    </span><span>// 重载输出操作符</span><span>
</span><span>    </span><span>friend</span><span> </span><span>std</span><span>::ostream& </span><span>operator</span><span><<(</span><span>std</span><span>::ostream& os, </span><span>const</span><span> Vertex& v) {
</span><span>        os << v.x << </span><span>","</span><span> << v.y << </span><span>","</span><span> << v.z;
</span><span>        </span><span>return</span><span> os;
</span>    }
};

<span></span><span>// 示例函数：通过引用传递 vector</span><span>
</span><span></span>void printVertices(const std::vector<Vertex>& vertices) <span>{
</span><span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"Vertices: "</span><span>;
</span><span>    </span><span>for</span><span> (</span><span>const</span><span> Vertex& v : vertices) {
</span><span>        </span><span>std</span><span>::</span><span>cout</span><span> << v << </span><span>" "</span><span>;
</span>    }
<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>std</span><span>::</span><span>endl</span><span>;
</span>}

<span></span>int main() <span>{
</span><span>    </span><span>// 1. 创建 vector</span><span>
</span><span>    </span><span>std</span><span>::</span><span>vector</span><span><Vertex> vertices;
</span>
<span>    </span><span>// 2. 添加元素</span><span>
</span><span>    vertices.push_back({</span>1<span>, </span>2<span>, </span>3<span>});
</span><span>    vertices.push_back({</span>4<span>, </span>5<span>, </span>6<span>});
</span>
<span>    </span><span>// 3. 打印所有元素</span><span>
</span>    printVertices(vertices);

<span>    </span><span>// 4. 使用范围 for 遍历（推荐）</span><span>
</span><span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"Using range-based for loop:"</span><span> << </span><span>std</span><span>::</span><span>endl</span><span>;
</span><span>    </span><span>for</span><span> (Vertex& v : vertices) {
</span><span>        </span><span>std</span><span>::</span><span>cout</span><span> << v << </span><span>std</span><span>::</span><span>endl</span><span>;
</span>    }

<span>    </span><span>// 5. 删除第二个元素（索引1）</span><span>
</span><span>    vertices.erase(vertices.begin() + </span>1<span>);
</span><span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"\nAfter erasing index 1:"</span><span> << </span><span>std</span><span>::</span><span>endl</span><span>;
</span>    printVertices(vertices);

<span>    </span><span>// 6. 清空 vector</span><span>
</span>    vertices.clear();
<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"\nAfter clear(): size = "</span><span> << vertices.size() << </span><span>std</span><span>::</span><span>endl</span><span>;
</span>
<span>    </span><span>// 7. 再次添加元素</span><span>
</span><span>    vertices.push_back({</span>7<span>, </span>8<span>, </span>9<span>});
</span>    printVertices(vertices);

<span>    </span><span>return</span><span> </span>0<span>;
</span>}</code></pre></div></div></pre>

---

## ✅ 八、输出结果

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">text</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>Vertices: </span>1<span>,</span>2<span>,</span>3<span> </span>4<span>,</span>5<span>,</span>6<span> 
</span><span>Using </span><span>range</span><span>-based </span><span>for</span><span> loop:
</span><span></span>1<span>,</span>2<span>,</span>3<span>
</span><span></span>4<span>,</span>5<span>,</span>6<span>
</span>
<span>After erasing index </span>1<span>:
</span><span>Vertices: </span>1<span>,</span>2<span>,</span>3<span> 
</span>
<span>After clear(): size = </span>0<span>
</span><span>Vertices: </span>7<span>,</span>8<span>,</span>9<span> </span></code></pre></div></div></pre>

---

## ✅ 九、关键总结图解


| 功能                | 说明                     |
| ------------------- | ------------------------ |
| `std::vector<T>`    | 动态数组，自动扩容       |
| `push_back()`       | 添加元素到末尾           |
| `size()`            | 获取当前元素个数         |
| `clear()`           | 清空所有元素，大小为0    |
| `erase(it)`         | 删除指定迭代器指向的元素 |
| `begin()` / `end()` | 获取迭代器               |
| `range-based for`   | 遍历更简洁，推荐使用     |
| `const &` 传递      | 避免拷贝，提升性能       |

## 十、常见误区提醒


| 误区                         | 正确做法                                     |
| ---------------------------- | -------------------------------------------- |
| `vector<int> v; v[10] = 5;`  | ❌ 越界！应先`v.resize(11)` 或用 `push_back` |
| `function(v)` 直接传值       | ❌ 会拷贝整个 vector，改用`function(v)`      |
| 用`vector<Pointer>` 存储对象 | ❌ 性能差，建议用`vector<Object>`            |
| 忘记`#include <vector>`      | ❌ 编译错误                                  |


# C++中的vector的优化使用


## 🎯 一、C++ 中 `std::vector` 的性能问题：为什么慢？

### ✅ 核心问题：**频繁的内存分配与复制**

当你使用 `push_back()` 添加元素时，如果 vector 容量不足，它会：

1. 分配一块更大的内存（通常是当前容量的 1.5\~2 倍）
2. 将所有现有元素**复制**到新内存
3. 删除旧内存

> 🔥 每次扩容都导致 **O(n)** 的复制操作，连续插入 n 个元素可能总耗时 O(n²)

---

## 🔍 二、图片中的关键观察：复制发生了多少次？

### 📌 图片显示：

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>vertices.push_back({1, 2, 3});
</span>vertices.push_back({4, 5, 6});</code></pre></div></div></pre>

结果输出了 **3 次 "Copied!"**！

### ❓ 为什么会复制 6 次？

我们来分步分析：


| 步骤                      | 说明                                                                                                                |
| ------------------------- | ------------------------------------------------------------------------------------------------------------------- |
| 1️⃣`push_back({1,2,3})` | 创建临时`Vertex(1,2,3)` → 构造函数调用 → 输出 "Copied!"<br/>然后 `push_back` 调用复制构造函数 → 再一次 "Copied!" |
| 2️⃣`push_back({4,5,6})` | 同样：创建临时对象 → 构造 → 复制 → 共 2 次                                                                       |

👉 总共：**6 次复制**（每次 2 次）

> 💡 实际上是：
>
> * 临时对象构造 ×2
> * 复制构造 ×2
> * **但为什么是 6？** 因为 `push_back` 在内部可能还会触发扩容（如初始容量为0），导致复制现有元素。



## ✅ 三、优化策略 1：使用 `reserve()` 预留空间

### 📌 图片中的“优化2”：

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>vertices.reserve(3);</span></code></pre></div></div></pre>

### ✅ 作用：

* 提前告诉 vector：“我打算放 3 个元素”
* vector 一次性分配足够内存（避免扩容）
* **不再需要复制现有元素**

> ⚡ 效果：从 O(n²) 变成 O(n)，性能提升巨大！

---

## ✅ 四、优化策略 2：使用 `emplace_back()` 替代 `push_back()`

### 📌 图片中的“优化1”：

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>vertices.emplace_back(1, 2, 3);</span></code></pre></div></div></pre>

### ✅ 优势：

* 不创建临时对象
* 直接在 vector 内部内存中 **就地构造**（in-place construction）
* **避免了复制构造**

> 🎯 `emplace_back` 是 C++11 引入的高性能替代方案



## ✅ 五、终极优化组合：`reserve + emplace_back`

### ✅ 最佳实践：

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>std</span><span>::</span><span>vector</span><span><Vertex> vertices;
</span><span>vertices.reserve(</span>3<span>);                        </span><span>// 预留空间</span><span>
</span><span>vertices.emplace_back(</span>1<span>, </span>2<span>, </span>3<span>);            </span><span>// 就地构造</span><span>
</span><span>vertices.emplace_back(</span>4<span>, </span>5<span>, </span>6<span>);
</span><span>vertices.emplace_back(</span>7<span>, </span>8<span>, </span>9<span>);</span></code></pre></div></div></pre>

👉 结果：**零复制！**

---

## ✅ 六、完整可运行代码（对比三种方式）

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class="" data-spm-anchor-id="5176.28103460.0.i42.5e842e317tzBAH"><use xlink:href="#appicon-copy-line" data-spm-anchor-id="5176.28103460.0.i43.5e842e317tzBAH"></use></svg></span></div></div></div><pre><code><span>#</span>include<span> </span><iostream><span>
</span><span></span><span>#</span>include<span> </span><vector><span>
</span>
<span></span>struct Vertex {<span>
</span><span>    </span><span>float</span><span> x, y, z;
</span>
<span>    </span><span>// 默认构造函数</span><span>
</span><span>    Vertex(</span><span>float</span><span> x = </span>0<span>, </span><span>float</span><span> y = </span>0<span>, </span><span>float</span><span> z = </span>0<span>) : x(x), y(y), z(z) {}
</span>
<span>    </span><span>// 复制构造函数（打印日志）</span><span>
</span><span>    Vertex(</span><span>const</span><span> Vertex& v) : x(v.x), y(v.y), z(v.z) {
</span><span>        </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"Copied!"</span><span> << </span><span>std</span><span>::</span><span>endl</span><span>;
</span>    }

<span>    </span><span>// 重载输出操作符</span><span>
</span><span>    </span><span>friend</span><span> </span><span>std</span><span>::ostream& </span><span>operator</span><span><<(</span><span>std</span><span>::ostream& os, </span><span>const</span><span> Vertex& v) {
</span><span>        os << v.x << </span><span>","</span><span> << v.y << </span><span>","</span><span> << v.z;
</span><span>        </span><span>return</span><span> os;
</span>    }
};

<span></span><span>// 示例函数：打印 vector 内容</span><span>
</span><span></span>void printVector(const std::vector<Vertex>& v) <span>{
</span><span>    </span><span>for</span><span> (</span><span>const</span><span> </span><span>auto</span><span>& elem : v) {
</span><span>        </span><span>std</span><span>::</span><span>cout</span><span> << elem << </span><span>" "</span><span>;
</span>    }
<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>std</span><span>::</span><span>endl</span><span>;
</span>}

<span></span>int main() <span>{
</span><span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"=== 方法1: push_back({x,y,z}) ==="</span><span> << </span><span>std</span><span>::</span><span>endl</span><span>;
</span><span>    </span><span>std</span><span>::</span><span>vector</span><span><Vertex> v1;
</span><span>    v1.push_back({</span>1<span>, </span>2<span>, </span>3<span>});  </span><span>// 临时对象 + 复制</span><span>
</span><span>    v1.push_back({</span>4<span>, </span>5<span>, </span>6<span>});
</span>    printVector(v1);

<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"\n=== 方法2: push_back(Vertex(x,y,z)) ==="</span><span> << </span><span>std</span><span>::</span><span>endl</span><span>;
</span><span>    </span><span>std</span><span>::</span><span>vector</span><span><Vertex> v2;
</span><span>    v2.push_back(Vertex(</span>1<span>, </span>2<span>, </span>3<span>));  </span><span>// 显式构造临时对象</span><span>
</span><span>    v2.push_back(Vertex(</span>4<span>, </span>5<span>, </span>6<span>));
</span>    printVector(v2);

<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"\n=== 方法3: reserve + emplace_back ==="</span><span> << </span><span>std</span><span>::</span><span>endl</span><span>;
</span><span>    </span><span>std</span><span>::</span><span>vector</span><span><Vertex> v3;
</span><span>    v3.reserve(</span>3<span>);                    </span><span>// 预留空间</span><span>
</span><span>    v3.emplace_back(</span>1<span>, </span>2<span>, </span>3<span>);         </span><span>// 就地构造</span><span>
</span><span>    v3.emplace_back(</span>4<span>, </span>5<span>, </span>6<span>);
</span><span>    v3.emplace_back(</span>7<span>, </span>8<span>, </span>9<span>);
</span>    printVector(v3);

<span>    </span><span>return</span><span> </span>0<span>;
</span>}</code></pre></div></div></pre>

---

## ✅ 七、输出结果（关键信息）

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">text</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>=== 方法1: push_back({x,y,z}) ===
</span>Copied!
Copied!
Copied!
Copied!
1,2,3 4,5,6 

=== 方法2: push_back(Vertex(x,y,z)) ===
Copied!
Copied!
Copied!
Copied!
1,2,3 4,5,6 

=== 方法3: reserve + emplace_back ===
1,2,3 4,5,6 7,8,9 </code></pre></div></div></pre>

> 🔥 注意：方法3 **没有输出任何 "Copied!"**，说明完全避免了复制！

---

## ✅ 八、性能对比图解


| 方式                               | 是否复制 | 是否扩容 | 性能    |
| ---------------------------------- | -------- | -------- | ------- |
| `push_back({1,2,3})`               | ✅ 有    | ✅ 可能  | 慢      |
| `push_back(Vertex(1,2,3))`         | ✅ 有    | ✅ 可能  | 慢      |
| `reserve(n) + emplace_back(1,2,3)` | ❌ 无    | ❌ 无    | ✅ 快！ |


## ✅ 九、关键总结


| 优化点                     | 说明                                     |
| -------------------------- | ---------------------------------------- |
| `reserve(n)`               | 预先分配内存，避免扩容                   |
| `emplace_back(...)`        | 就地构造，避免临时对象和复制             |
| `push_back({x,y,z})`       | 会产生临时对象和复制                     |
| `push_back(Vertex(x,y,z))` | 显式构造，但仍需复制                     |
| `capacity()` vs `size()`   | `capacity` 是总空间，`size` 是已用元素数 |

---

## ✅ 十、最佳实践口诀

> **“知道要放几个，就 `reserve()`；****想直接构造，就 `emplace_back()`；****别用 `push_back({})`，那是性能杀手！”**

---

## ✅ 十一、扩展知识

### 1. `resize()` vs `reserve()`


| 函数         | 作用                       |
| ------------ | -------------------------- |
| `reserve(n)` | 分配内存，不改变`size`     |
| `resize(n)`  | 改变`size`，可能填充默认值 |

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>v.resize(</span>5<span>);   </span><span>// size=5, capacity≥5</span><span>
</span><span>v.reserve(</span>10<span>); </span><span>// capacity=10, size不变</span></code></pre></div></div></pre>

### 2. `emplace_back` 适用于任意类型

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>std</span><span>::</span><span>vector</span><span><</span><span>std</span><span>::</span><span>string</span><span>> vec;
</span><span>vec.emplace_back(</span><span>"hello"</span><span>);  </span><span>// 更高效</span><span>
</span><span>vec.push_back(</span><span>"world"</span><span>);     </span><span>// 低效</span></code></pre></div></div></pre>


# vector中的元素构造与复制分析


## 代码和暑促

```c++
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
输出是初始 size: 0, 容量: 0, 地址: 0

--- Adding first vertex ---
Constructed (1,2,3)
Copied! (1,2,3)
添加后 size: 1, 容量: 1, 地址: 0xf83ec0

--- Adding second vertex ---
Constructed (4,5,6)
Copied! (4,5,6)
Copied! (1,2,3)
添加后 size: 2, 容量: 2, 地址: 0xf83ee0

--- Adding third vertex ---
Constructed (7,8,9)
Copied! (7,8,9)
Copied! (1,2,3)
Copied! (4,5,6)
添加后 size: 3, 容量: 4, 地址: 0xf83f00

Final vector: 1,2,3 4,5,6 7,8,9 
结合这个分析复制的行为
```


## ✅ 一、完整输出回顾

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">text</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>初始 size: </span>0<span>, 容量: </span>0<span>, 地址: </span>0<span>
</span>
--- Adding first vertex ---
<span>Constructed (</span>1<span>,</span>2<span>,</span>3<span>)
</span><span>Copied! (</span>1<span>,</span>2<span>,</span>3<span>)
</span><span>添加后 size: </span>1<span>, 容量: </span>1<span>, 地址: </span>0xf83ec0<span>
</span>
--- Adding second vertex ---
<span>Constructed (</span>4<span>,</span>5<span>,</span>6<span>)
</span><span>Copied! (</span>4<span>,</span>5<span>,</span>6<span>)
</span><span>Copied! (</span>1<span>,</span>2<span>,</span>3<span>)
</span><span>添加后 size: </span>2<span>, 容量: </span>2<span>, 地址: </span>0xf83ee0<span>
</span>
--- Adding third vertex ---
<span>Constructed (</span>7<span>,</span>8<span>,</span>9<span>)
</span><span>Copied! (</span>7<span>,</span>8<span>,</span>9<span>)
</span><span>Copied! (</span>1<span>,</span>2<span>,</span>3<span>)
</span><span>Copied! (</span>4<span>,</span>5<span>,</span>6<span>)
</span><span>添加后 size: </span>3<span>, 容量: </span>4<span>, 地址: </span>0xf83f00<span>
</span>
<span>Final </span><span>vector</span><span>: </span>1<span>,</span>2<span>,</span>3<span> </span>4<span>,</span>5<span>,</span>6<span> </span>7<span>,</span>8<span>,</span>9<span> </span></code></pre></div></div></pre>

---

## 🔍 二、核心观察点


| 观察                           | 说明                               |
| ------------------------------ | ---------------------------------- |
| 📌 初始容量为 0                | `capacity=0`, `data()=0`（空指针） |
| 📌 每次扩容，`data()` 地址改变 | 说明分配了新内存                   |
| 📌`capacity` 增长：1 → 2 → 4 | 典型的**2倍增长策略**              |
| 📌 复制次数：1 + 2 + 3 = 6 次  | 扩容导致旧元素被复制               |

---

## 🔍 三、逐阶段分析复制行为

### 🧱 阶段 0：初始状态

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>size: 0, capacity: 0, data(): 0x0</span></code></pre></div></div></pre>

* vector 未分配任何内存
* `data()` 返回空指针

---

### 🧱 阶段 1：添加第一个顶点 `{1,2,3}`

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>--- Adding first vertex ---
</span>Constructed (1,2,3)
Copied! (1,2,3)
添加后 size: 1, 容量: 1, 地址: 0xf83ec0</code></pre></div></div></pre>

#### 发生了什么？

1. `push_back({1,2,3})`：
   * 构造临时对象 `Vertex(1,2,3)` → 调用构造函数 → `"Constructed (1,2,3)"`
   * 当前容量为 0，需要扩容 → 分配容量为 **1** 的内存（地址 `0xf83ec0`）
   * 将临时对象**复制**到新内存中 → 调用复制构造函数 → `"Copied! (1,2,3)"`
   * 临时对象析构

#### ✅ 总结：

* **扩容**：0 → 1
* **复制次数**：1（临时对象 → vector 内存）
* **新增元素**：1
* **总构造/复制调用**：2 次（1 构造 + 1 复制）

> ⚠️ 注意：虽然 `push_back({})` 是花括号初始化，但这里仍然触发了复制构造，说明**编译器没有进行复制省略（Copy Elision）**

---

### 🧱 阶段 2：添加第二个顶点 `{4,5,6}`

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>--- Adding second vertex ---
</span>Constructed (4,5,6)
Copied! (4,5,6)
Copied! (1,2,3)
添加后 size: 2, 容量: 2, 地址: 0xf83ee0</code></pre></div></div></pre>

#### 发生了什么？

1. 当前状态：`size=1`, `capacity=1`
2. `push_back({4,5,6})`：
   * 构造临时对象 `Vertex(4,5,6)` → `"Constructed (4,5,6)"`
   * 容量不足（1==1），需要扩容 → 新容量 = 1×2 = **2**
   * 分配新内存（地址 `0xf83ee0` ≠ 旧地址）
   * **将已有元素 `{1,2,3}` 从旧内存复制到新内存** → 调用复制构造函数 → `"Copied! (1,2,3)"`
   * 释放旧内存（`0xf83ec0`）
   * 将 `{4,5,6}` 复制到新内存的第二个位置 → `"Copied! (4,5,6)"`

#### ✅ 总结：

* **扩容**：1 → 2
* **复制次数**：2
  * 1 次：旧元素 `{1,2,3}` 被复制（因扩容）
  * 1 次：新元素 `{4,5,6}` 被复制进 vector
* **总复制构造调用**：2 次

---

### 🧱 阶段 3：添加第三个顶点 `{7,8,9}`

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>--- Adding third vertex ---
</span>Constructed (7,8,9)
Copied! (7,8,9)
Copied! (1,2,3)
Copied! (4,5,6)
添加后 size: 3, 容量: 4, 地址: 0xf83f00</code></pre></div></div></pre>

#### 发生了什么？

1. 当前状态：`size=2`, `capacity=2`
2. `push_back({7,8,9})`：
   * 构造临时对象 `Vertex(7,8,9)` → `"Constructed (7,8,9)"`
   * 容量不足（2==2），需要扩容 → 新容量 = 2×2 = **4**
   * 分配新内存（地址 `0xf83f00` ≠ 旧地址）
   * **将已有的 2 个元素 `{1,2,3}` 和 `{4,5,6}` 从旧内存复制到新内存**
     * → `"Copied! (1,2,3)"`
     * → `"Copied! (4,5,6)"`
   * 释放旧内存（`0xf83ee0`）
   * 将 `{7,8,9}` 复制到新内存的第三个位置 → `"Copied! (7,8,9)"`

#### ✅ 总结：

* **扩容**：2 → 4
* **复制次数**：3
  * 2 次：两个旧元素被复制（因扩容）
  * 1 次：新元素 `{7,8,9}` 被复制进 vector
* **总复制构造调用**：3 次

---

## ✅ 四、复制行为总览表


| 步骤     | 行为          | 构造次数 | 复制构造次数 | 说明                                 |
| -------- | ------------- | -------- | ------------ | ------------------------------------ |
| 1        | 添加`{1,2,3}` | 1        | 1            | 扩容 0→1，复制临时对象              |
| 2        | 添加`{4,5,6}` | 1        | 2            | 扩容 1→2，复制旧元素1个 + 新元素1个 |
| 3        | 添加`{7,8,9}` | 1        | 3            | 扩容 2→4，复制旧元素2个 + 新元素1个 |
| **总计** | ——          | **3**    | **6**        | ✅ 匹配输出                          |

---

## ✅ 五、关键结论：为什么复制这么频繁？

### 1. **动态扩容是主因**

* 每次 `size == capacity` 时，`push_back` 触发扩容
* 扩容必须：
  * 分配新内存
  * 将所有旧元素**逐个复制**到新内存
  * 释放旧内存
* 这些复制无法被编译器优化！

### 2. **`push_back({})` 的语义**

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>vertices.push_back({1,2,3});</span></code></pre></div></div></pre>

等价于：

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code>Vertex temp(1,2,3)<span>;           </span><span>// 构造</span><span>
</span><span>vertices.push_back(temp);     </span><span>// 复制构造</span></code></pre></div></div></pre>

即使使用花括号，如果类型不完全匹配，仍可能触发复制构造。

> 💡 在某些情况下，编译器会进行 **复制省略（Copy Elision）** 或 **移动优化**，但在这里**没有发生**，所以复制被完整执行。

---

## ✅ 六、如何避免这些复制？——终极优化方案

### ✅ 方案 1：使用 `reserve()` 预留空间

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>std</span><span>::</span><span>vector</span><span><Vertex> vertices;
</span><span>vertices.reserve(</span>3<span>);  </span><span>// 提前分配足够内存</span></code></pre></div></div></pre>

这样就不会扩容，也就不会复制旧元素。

### ✅ 方案 2：使用 `emplace_back()` 就地构造

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>vertices.emplace_back(</span>1<span>, </span>2<span>, </span>3<span>);  </span><span>// 直接在 vector 内存中构造</span></code></pre></div></div></pre>

避免临时对象和复制构造。

---

### ✅ 优化后的代码（零复制）

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>std</span><span>::</span><span>vector</span><span><Vertex> vertices;
</span><span>vertices.reserve(</span>3<span>);
</span><span>vertices.emplace_back(</span>1<span>, </span>2<span>, </span>3<span>);
</span><span>vertices.emplace_back(</span>4<span>, </span>5<span>, </span>6<span>);
</span><span>vertices.emplace_back(</span>7<span>, </span>8<span>, </span>9<span>);</span></code></pre></div></div></pre>

👉 输出：

* 只有 3 次 `"Constructed (...)"`
* **0 次 `"Copied!"`**

---

## ✅ 七、性能对比图解


| 方式                        | 是否扩容 | 是否复制旧元素 | 是否复制新元素 | 总复制次数 |
| --------------------------- | -------- | -------------- | -------------- | ---------- |
| `push_back` ×3             | ✅ 2 次  | ✅ 3 次（1+2） | ✅ 3 次        | **6**      |
| `reserve(3) + push_back`    | ❌       | ❌             | ✅ 3 次        | **3**      |
| `reserve(3) + emplace_back` | ❌       | ❌             | ❌             | **0** ✅   |
