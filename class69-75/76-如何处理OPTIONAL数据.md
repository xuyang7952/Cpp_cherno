# C++ 中的 `std::optional`


## 一、什么是“可选数据”（Optional Data）？

在编程中，**某些函数可能无法总是返回有效值**，例如：

* 读取不存在的文件
* 在容器中查找不存在的元素
* 解析无效字符串

传统做法（如返回空字符串、-1、`nullptr`）存在严重问题：

* **语义模糊**：空字符串可能是合法结果（如配置项为空）
* **易出错**：调用者可能忘记检查，导致未定义行为

> 💡 Cherno 指出：**我们需要一种方式明确表达“这个值可能存在，也可能不存在”**。
>


## 二、解决方案：`std::optional<T>`（C++17 引入）

`std::optional<T>` 是一个**模板类**，用于封装一个**可能不存在的值**。它本质上是一个“带存在性标志的容器”。

### ✅ 核心优势：

* **类型安全**：编译器强制你检查值是否存在
* **语义清晰**：函数签名直接表明“可能无值”
* **零开销抽象**：通常只比原始类型多一个 `bool` 标志位


## 三、基本用法与 API

### 1. 包含头文件

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[36px] sticky top-0 z-10 bg-primary"><div class="flex items-center h-[36px] px-3 text-12 align-middle border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-12 overflow-ellipsis whitespace-nowrap overflow-hidden text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-16 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-copy-line"></use></svg></span><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-moon-line"></use></svg></span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-up-line"></use></svg></span></div></div></div></div><pre class="sc-bRKDuR jCSJQZ"><code><span class="token macro directive-hash">#</span><span class="token macro">include</span><span class="token macro"> </span><span class="token macro"><optional></span></code></pre></div></div></pre>

### 2. 声明与初始化

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[36px] sticky top-0 z-10 bg-primary"><div class="flex items-center h-[36px] px-3 text-12 align-middle border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-12 overflow-ellipsis whitespace-nowrap overflow-hidden text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-16 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-copy-line"></use></svg></span><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-moon-line"></use></svg></span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-up-line"></use></svg></span></div></div></div></div><pre class="sc-bRKDuR jCSJQZ"><code><span>std</span><span class="token double-colon">::</span><span>optional</span><span class="token"><</span><span class="token">int</span><span class="token">></span><span> maybeNumber</span><span class="token">;</span><span>        </span><span class="token">// 空（nullopt）</span><span>
</span><span>std</span><span class="token double-colon">::</span><span>optional</span><span class="token"><</span><span>std</span><span class="token double-colon">::</span><span>string</span><span class="token">></span><span> maybeText </span><span class="token">=</span><span> </span><span class="token">"Hello"</span><span class="token">;</span><span> </span><span class="token">// 有值</span></code></pre></div></div></pre>

### 3. 检查是否存在值

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[36px] sticky top-0 z-10 bg-primary"><div class="flex items-center h-[36px] px-3 text-12 align-middle border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-12 overflow-ellipsis whitespace-nowrap overflow-hidden text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-16 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-copy-line"></use></svg></span><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-moon-line"></use></svg></span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-up-line"></use></svg></span></div></div></div></div><pre class="sc-bRKDuR jCSJQZ"><code><span class="token">if</span><span> </span><span class="token">(</span><span>maybeNumber</span><span class="token">)</span><span> </span><span class="token">{</span><span>
</span><span>    </span><span class="token">// 有值</span><span>
</span><span></span><span class="token">}</span><span>
</span><span></span><span class="token">// 或显式调用</span><span>
</span><span></span><span class="token">if</span><span> </span><span class="token">(</span><span>maybeNumber</span><span class="token">.</span><span class="token">has_value</span><span class="token">(</span><span class="token">)</span><span class="token">)</span><span> </span><span class="token">{</span><span> </span><span class="token">.</span><span class="token">.</span><span class="token">.</span><span> </span><span class="token">}</span></code></pre></div></div></pre>

### 4. 获取值（安全方式）

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[36px] sticky top-0 z-10 bg-primary"><div class="flex items-center h-[36px] px-3 text-12 align-middle border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-12 overflow-ellipsis whitespace-nowrap overflow-hidden text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-16 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-copy-line"></use></svg></span><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-moon-line"></use></svg></span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-up-line"></use></svg></span></div></div></div></div><pre class="sc-bRKDuR jCSJQZ"><code><span class="token">// 方式1：使用 value()（无值时抛 std::bad_optional_access）</span><span>
</span><span></span><span class="token">int</span><span> n </span><span class="token">=</span><span> maybeNumber</span><span class="token">.</span><span class="token">value</span><span class="token">(</span><span class="token">)</span><span class="token">;</span><span>
</span>
<span></span><span class="token">// 方式2：使用 operator*（类似指针，但无边界检查）</span><span>
</span><span></span><span class="token">int</span><span> n </span><span class="token">=</span><span> </span><span class="token">*</span><span>maybeNumber</span><span class="token">;</span><span> </span><span class="token">// ⚠️ 仅在确定有值时使用！</span><span>
</span>
<span></span><span class="token">// 方式3：提供默认值（推荐！）</span><span>
</span><span></span><span class="token">int</span><span> n </span><span class="token">=</span><span> maybeNumber</span><span class="token">.</span><span class="token">value_or</span><span class="token">(</span><span class="token">0</span><span class="token">)</span><span class="token">;</span><span> </span><span class="token">// 无值时返回 0</span></code></pre></div></div></pre>


## 四、完整可运行示例（来自 Cherno 课程）

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[36px] sticky top-0 z-10 bg-primary"><div class="flex items-center h-[36px] px-3 text-12 align-middle border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-12 overflow-ellipsis whitespace-nowrap overflow-hidden text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-16 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-copy-line"></use></svg></span><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-moon-line"></use></svg></span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-up-line"></use></svg></span></div></div></div></div><pre class="sc-bRKDuR jCSJQZ" data-spm-anchor-id="5176.28103460.0.i36.cb2b7551HDZ7Ni"><code><span class="token macro directive-hash">#</span><span class="token macro">include</span><span class="token macro"> </span><span class="token macro"><iostream></span><span>
</span><span></span><span class="token macro directive-hash">#</span><span class="token macro">include</span><span class="token macro"> </span><span class="token macro"><fstream></span><span>
</span><span></span><span class="token macro directive-hash">#</span><span class="token macro">include</span><span class="token macro"> </span><span class="token macro"><string></span><span>
</span><span></span><span class="token macro directive-hash">#</span><span class="token macro">include</span><span class="token macro"> </span><span class="token macro"><optional></span><span>
</span>
<span></span><span class="token">// 安全地读取文件内容：成功返回内容，失败返回空 optional</span><span>
</span><span>std</span><span class="token double-colon">::</span><span>optional</span><span class="token"><</span><span>std</span><span class="token double-colon">::</span><span>string</span><span class="token">></span><span> </span><span class="token">ReadFileAsString</span><span class="token">(</span><span class="token">const</span><span> std</span><span class="token double-colon">::</span><span>string</span><span class="token">&</span><span> filepath</span><span class="token">)</span><span> </span><span class="token">{</span><span>
</span><span>    std</span><span class="token double-colon">::</span><span>ifstream </span><span class="token">stream</span><span class="token">(</span><span>filepath</span><span class="token">)</span><span class="token">;</span><span>
</span><span>    </span><span class="token">if</span><span> </span><span class="token">(</span><span class="token">!</span><span>stream</span><span class="token">.</span><span class="token">is_open</span><span class="token">(</span><span class="token">)</span><span class="token">)</span><span> </span><span class="token">{</span><span>
</span><span>        </span><span class="token">return</span><span> </span><span class="token">{</span><span class="token">}</span><span class="token">;</span><span> </span><span class="token">// 等价于 std::nullopt</span><span>
</span><span>    </span><span class="token">}</span><span>
</span>
<span>    std</span><span class="token double-colon">::</span><span>string </span><span class="token">result</span><span class="token">(</span><span>
</span><span>        std</span><span class="token double-colon">::</span><span class="token generic-function">istreambuf_iterator</span><span class="token generic-function generic"><</span><span class="token generic-function generic">char</span><span class="token generic-function generic">></span><span class="token">(</span><span>stream</span><span class="token">)</span><span class="token">,</span><span>
</span><span>        std</span><span class="token double-colon">::</span><span class="token generic-function">istreambuf_iterator</span><span class="token generic-function generic"><</span><span class="token generic-function generic">char</span><span class="token generic-function generic">></span><span class="token">(</span><span class="token">)</span><span>
</span><span>    </span><span class="token">)</span><span class="token">;</span><span>
</span><span>    </span><span class="token">return</span><span> result</span><span class="token">;</span><span> </span><span class="token">// 自动构造 optional<string></span><span>
</span><span></span><span class="token">}</span><span>
</span>
<span></span><span class="token">int</span><span> </span><span class="token">main</span><span class="token">(</span><span class="token">)</span><span> </span><span class="token">{</span><span>
</span><span>    </span><span class="token">auto</span><span> data </span><span class="token">=</span><span> </span><span class="token">ReadFileAsString</span><span class="token">(</span><span class="token">"data.txt"</span><span class="token">)</span><span class="token">;</span><span>
</span>
<span>    </span><span class="token">// 方法1：显式检查</span><span>
</span><span>    </span><span class="token">if</span><span> </span><span class="token">(</span><span>data</span><span class="token">)</span><span> </span><span class="token">{</span><span>
</span><span>        std</span><span class="token double-colon">::</span><span>cout </span><span class="token"><<</span><span> </span><span class="token">"File read successfully!\n"</span><span class="token">;</span><span>
</span><span>        std</span><span class="token double-colon">::</span><span>cout </span><span class="token"><<</span><span> </span><span class="token">"Content: "</span><span> </span><span class="token"><<</span><span> </span><span class="token">*</span><span>data </span><span class="token"><<</span><span> </span><span class="token">"\n"</span><span class="token">;</span><span>
</span><span>    </span><span class="token">}</span><span> </span><span class="token">else</span><span> </span><span class="token">{</span><span>
</span><span>        std</span><span class="token double-colon">::</span><span>cout </span><span class="token"><<</span><span> </span><span class="token">"Failed to read file.\n"</span><span class="token">;</span><span>
</span><span>    </span><span class="token">}</span><span>
</span>
<span>    </span><span class="token">// 方法2：使用 value_or 提供默认值</span><span>
</span><span>    std</span><span class="token double-colon">::</span><span>string content </span><span class="token">=</span><span> data</span><span class="token">.</span><span class="token">value_or</span><span class="token">(</span><span class="token">"File not found or empty"</span><span class="token">)</span><span class="token">;</span><span>
</span><span>    std</span><span class="token double-colon">::</span><span>cout </span><span class="token"><<</span><span> </span><span class="token">"Final content: "</span><span> </span><span class="token"><<</span><span> content </span><span class="token"><<</span><span> </span><span class="token">"\n"</span><span class="token">;</span><span>
</span>
<span>    </span><span class="token">return</span><span> </span><span class="token">0</span><span class="token">;</span><span>
</span><span></span><span class="token">}</span></code></pre></div></div></pre>

> 📌 注意：`return {};` 在返回 `std::optional` 时，会构造一个**空的 optional 对象**。


## 五、为什么比传统方法更好？


| 方法                                | 问题                                 | `std::optional` 优势                      |
| ----------------------------------- | ------------------------------------ | ----------------------------------------- |
| 返回空字符串`""`                    | 无法区分“文件为空”和“文件不存在” | 明确区分“无值” vs “空值”              |
| 使用输出参数`bool& success`         | 接口笨重，易忽略检查                 | 返回值自带状态，强制处理                  |
| 返回`nullptr`（对非指针类型不适用） | 仅适用于指针                         | 适用于任意类型（int, string, 自定义类等） |

> 💬 Cherno 强调：
> “`std::optional` 让接口契约变得清晰——调用者一眼就知道这个函数可能失败。”


## 六、使用场景总结

✅ 推荐使用 `std::optional` 的情况：

* 函数可能无有效返回值（如查找、解析、IO 操作）
* 配置项可能未设置
* 可选参数或可选成员字段（替代指针或特殊值）

❌ 不适用场景：

* 性能极度敏感且不能接受额外 `bool` 开销（极少见）
* 错误是“异常情况”而非“正常控制流” → 应使用异常



## 七、最佳实践


| 建议                                    | 说明                   |
| --------------------------------------- | ---------------------- |
| ✅ 优先使用`value_or(default)`          | 避免崩溃，代码更简洁   |
| ✅ 用`if (opt)` 检查存在性              | 比`has_value()` 更惯用 |
| ❌ 避免直接解引用（`*opt`）除非确定有值 | 否则行为未定义         |
| ✅ 在函数返回类型中使用                 | 清晰表达“可能无值”   |

---

## 八、总结

* `std::optional<T>` 是 C++17 引入的**安全、高效、类型安全的可选值表示方式**
* 它解决了传统“魔数”（如 -1、空字符串、nullptr）的语义模糊问题
* 通过强制检查存在性，显著提升代码健壮性
* **适用于任何“可能不存在”的值场景**
