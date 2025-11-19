# C++中的dynamic-cast


## 一、`dynamic_cast` 是什么？

`dynamic_cast` 是 C++ 中**唯一在运行时进行类型检查的安全向下转型（downcasting）操作符**，专门用于**多态类型**（即包含至少一个虚函数的类）。

> ✅ 核心目的：**安全地将基类指针/引用转换为派生类指针/引用，并验证转换是否合法。**
>

## 二、为什么需要 `dynamic_cast`？

### 问题背景：

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[36px] sticky top-0 z-10 bg-primary"><div class="flex items-center h-[36px] px-3 text-12 align-middle border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-12 overflow-ellipsis whitespace-nowrap overflow-hidden text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-16 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-copy-line"></use></svg></span><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-moon-line"></use></svg></span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-up-line"></use></svg></span></div></div></div></div><pre class="sc-bRKDuR jCSJQZ"><code data-spm-anchor-id="5176.28103460.0.i16.cb2b7551XadKpz"><span class="token">class</span><span> </span><span class="token">Entity</span><span> </span><span class="token">{</span><span> </span><span class="token">/* 无虚函数 */</span><span> </span><span class="token">}</span><span class="token">;</span><span>
</span><span></span><span class="token">class</span><span> </span><span class="token">Player</span><span> </span><span class="token">:</span><span> </span><span class="token base-clause">public</span><span class="token base-clause"> </span><span class="token base-clause">Entity</span><span> </span><span class="token">{</span><span class="token">}</span><span class="token">;</span><span>
</span>
<span>Entity</span><span class="token">*</span><span> e </span><span class="token">=</span><span> </span><span class="token">new</span><span> </span><span class="token">Entity</span><span class="token">(</span><span class="token">)</span><span class="token">;</span><span>
</span><span>Player</span><span class="token">*</span><span> p </span><span class="token">=</span><span> </span><span class="token">(</span><span>Player</span><span class="token">*</span><span class="token">)</span><span>e</span><span class="token">;</span><span> </span><span class="token">// C 风格强制转换 → 编译通过！</span><span>
</span><span>p</span><span class="token">-></span><span class="token">somePlayerMethod</span><span class="token">(</span><span class="token">)</span><span class="token">;</span><span>  </span><span class="token">// 💥 未定义行为！程序可能崩溃</span></code></pre></div></div></pre>

* 编译器无法知道 `e` 实际指向的是 `Entity` 还是 `Player`
* 强制转换会“欺骗”编译器，但运行时访问非法内存 → **危险！**

### 解决方案：

使用 `dynamic_cast`，它会在**运行时检查对象的真实类型**，若不匹配则安全失败。


## 三、使用条件（必须同时满足）

1. **类必须是多态的**
   → 至少有一个 **虚函数**（通常为虚析构函数）
2. **只能用于指针或引用**
3. **仅适用于继承体系内的转换**

> ⚠️ 如果类没有虚函数，`dynamic_cast` 会**编译报错**！

---

## 四、行为规则


| 转换目标     | 成功时             | 失败时                   |
| ------------ | ------------------ | ------------------------ |
| **指针类型** | 返回有效派生类指针 | 返回`nullptr`            |
| **引用类型** | 返回有效派生类引用 | 抛出`std::bad_cast` 异常 |


## 五、完整可运行示例

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[36px] sticky top-0 z-10 bg-primary"><div class="flex items-center h-[36px] px-3 text-12 align-middle border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-12 overflow-ellipsis whitespace-nowrap overflow-hidden text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-16 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-copy-line"></use></svg></span><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-moon-line"></use></svg></span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-up-line"></use></svg></span></div></div></div></div><pre class="sc-bRKDuR jCSJQZ"><code><span class="token macro directive-hash">#</span><span class="token macro">include</span><span class="token macro"> </span><span class="token macro"><iostream></span><span>
</span><span></span><span class="token macro directive-hash">#</span><span class="token macro">include</span><span class="token macro"> </span><span class="token macro"><typeinfo></span><span>
</span>
<span></span><span class="token">// 基类必须有虚函数（启用多态）</span><span>
</span><span></span><span class="token">class</span><span> </span><span class="token">Entity</span><span> </span><span class="token">{</span><span>
</span><span></span><span class="token">public</span><span class="token">:</span><span>
</span><span>    </span><span class="token">virtual</span><span> </span><span class="token">~</span><span class="token">Entity</span><span class="token">(</span><span class="token">)</span><span> </span><span class="token">=</span><span> </span><span class="token">default</span><span class="token">;</span><span> </span><span class="token">// 虚析构函数（推荐）</span><span>
</span><span>    </span><span class="token">virtual</span><span> </span><span class="token">void</span><span> </span><span class="token">Print</span><span class="token">(</span><span class="token">)</span><span> </span><span class="token">{</span><span> std</span><span class="token double-colon">::</span><span>cout </span><span class="token"><<</span><span> </span><span class="token">"Entity\n"</span><span class="token">;</span><span> </span><span class="token">}</span><span>
</span><span></span><span class="token">}</span><span class="token">;</span><span>
</span>
<span></span><span class="token">class</span><span> </span><span class="token">Player</span><span> </span><span class="token">:</span><span> </span><span class="token base-clause">public</span><span class="token base-clause"> </span><span class="token base-clause">Entity</span><span> </span><span class="token">{</span><span>
</span><span></span><span class="token">public</span><span class="token">:</span><span>
</span><span>    </span><span class="token">void</span><span> </span><span class="token">Attack</span><span class="token">(</span><span class="token">)</span><span> </span><span class="token">{</span><span> std</span><span class="token double-colon">::</span><span>cout </span><span class="token"><<</span><span> </span><span class="token">"Player attacks!\n"</span><span class="token">;</span><span> </span><span class="token">}</span><span>
</span><span></span><span class="token">}</span><span class="token">;</span><span>
</span>
<span></span><span class="token">class</span><span> </span><span class="token">Enemy</span><span> </span><span class="token">:</span><span> </span><span class="token base-clause">public</span><span class="token base-clause"> </span><span class="token base-clause">Entity</span><span> </span><span class="token">{</span><span>
</span><span></span><span class="token">public</span><span class="token">:</span><span>
</span><span>    </span><span class="token">void</span><span> </span><span class="token">Defend</span><span class="token">(</span><span class="token">)</span><span> </span><span class="token">{</span><span> std</span><span class="token double-colon">::</span><span>cout </span><span class="token"><<</span><span> </span><span class="token">"Enemy defends!\n"</span><span class="token">;</span><span> </span><span class="token">}</span><span>
</span><span></span><span class="token">}</span><span class="token">;</span><span>
</span>
<span></span><span class="token">int</span><span> </span><span class="token">main</span><span class="token">(</span><span class="token">)</span><span> </span><span class="token">{</span><span>
</span><span>    </span><span class="token">// 情况1：实际是 Player</span><span>
</span><span>    Entity</span><span class="token">*</span><span> e1 </span><span class="token">=</span><span> </span><span class="token">new</span><span> </span><span class="token">Player</span><span class="token">(</span><span class="token">)</span><span class="token">;</span><span>
</span>  
<span>    Player</span><span class="token">*</span><span> p1 </span><span class="token">=</span><span> </span><span class="token generic-function">dynamic_cast</span><span class="token generic-function generic"><</span><span class="token generic-function generic">Player</span><span class="token generic-function generic">*</span><span class="token generic-function generic">></span><span class="token">(</span><span>e1</span><span class="token">)</span><span class="token">;</span><span>
</span><span>    </span><span class="token">if</span><span> </span><span class="token">(</span><span>p1</span><span class="token">)</span><span> </span><span class="token">{</span><span>
</span><span>        p1</span><span class="token">-></span><span class="token">Attack</span><span class="token">(</span><span class="token">)</span><span class="token">;</span><span> </span><span class="token">// 安全调用</span><span>
</span><span>    </span><span class="token">}</span><span>
</span>
<span>    </span><span class="token">// 情况2：实际是 Enemy，尝试转为 Player → 失败</span><span>
</span><span>    Entity</span><span class="token">*</span><span> e2 </span><span class="token">=</span><span> </span><span class="token">new</span><span> </span><span class="token">Enemy</span><span class="token">(</span><span class="token">)</span><span class="token">;</span><span>
</span>  
<span>    Player</span><span class="token">*</span><span> p2 </span><span class="token">=</span><span> </span><span class="token generic-function">dynamic_cast</span><span class="token generic-function generic"><</span><span class="token generic-function generic">Player</span><span class="token generic-function generic">*</span><span class="token generic-function generic">></span><span class="token">(</span><span>e2</span><span class="token">)</span><span class="token">;</span><span>
</span><span>    </span><span class="token">if</span><span> </span><span class="token">(</span><span class="token">!</span><span>p2</span><span class="token">)</span><span> </span><span class="token">{</span><span>
</span><span>        std</span><span class="token double-colon">::</span><span>cout </span><span class="token"><<</span><span> </span><span class="token">"Cast failed: e2 is not a Player!\n"</span><span class="token">;</span><span>
</span><span>    </span><span class="token">}</span><span>
</span>
<span>    </span><span class="token">// 情况3：引用转换（失败会抛异常）</span><span>
</span><span>    </span><span class="token">try</span><span> </span><span class="token">{</span><span>
</span><span>        Player</span><span class="token">&</span><span> p_ref </span><span class="token">=</span><span> </span><span class="token generic-function">dynamic_cast</span><span class="token generic-function generic"><</span><span class="token generic-function generic">Player</span><span class="token generic-function generic">&</span><span class="token generic-function generic">></span><span class="token">(</span><span class="token">*</span><span>e2</span><span class="token">)</span><span class="token">;</span><span>
</span><span>        p_ref</span><span class="token">.</span><span class="token">Attack</span><span class="token">(</span><span class="token">)</span><span class="token">;</span><span>
</span><span>    </span><span class="token">}</span><span> </span><span class="token">catch</span><span> </span><span class="token">(</span><span class="token">const</span><span> std</span><span class="token double-colon">::</span><span>bad_cast</span><span class="token">&</span><span> e</span><span class="token">)</span><span> </span><span class="token">{</span><span>
</span><span>        std</span><span class="token double-colon">::</span><span>cout </span><span class="token"><<</span><span> </span><span class="token">"Bad cast caught: "</span><span> </span><span class="token"><<</span><span> e</span><span class="token">.</span><span class="token">what</span><span class="token">(</span><span class="token">)</span><span> </span><span class="token"><<</span><span> </span><span class="token">"\n"</span><span class="token">;</span><span>
</span><span>    </span><span class="token">}</span><span>
</span>
<span>    </span><span class="token">delete</span><span> e1</span><span class="token">;</span><span>
</span><span>    </span><span class="token">delete</span><span> e2</span><span class="token">;</span><span>
</span><span>    </span><span class="token">return</span><span> </span><span class="token">0</span><span class="token">;</span><span>
</span><span></span><span class="token">}</span></code></pre></div></div></pre>

### ✅ 输出：

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[36px] sticky top-0 z-10 bg-primary"><div class="flex items-center h-[36px] px-3 text-12 align-middle border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-12 overflow-ellipsis whitespace-nowrap overflow-hidden text-[rgba(17,17,51,0.7)]">text</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-16 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-copy-line"></use></svg></span><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-moon-line"></use></svg></span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-up-line"></use></svg></span></div></div></div></div><pre class="sc-bRKDuR jCSJQZ"><code><span>Player attacks!
</span>Cast failed: e2 is not a Player!
Bad cast caught: std::bad_cast</code></pre></div></div></pre>


## 六、底层机制：RTTI（Run-Time Type Information）

* `dynamic_cast` 依赖 **RTTI**（运行时类型信息）
* 编译器为每个含虚函数的类生成类型元数据（存储在虚表附近）
* 转换时，运行时系统比对对象的实际类型与目标类型是否兼容

> ⚠️ 注意：
>
> * RTTI 默认开启，但可在编译器中关闭（如 MSVC 的 `/GR-`）
> * **关闭 RTTI 后，`dynamic_cast` 无法使用**（链接错误或运行时崩溃）

---

## 七、性能开销

* **有运行时成本**：需遍历继承树、查询类型信息
* **比 `static_cast` 慢得多**
* **不应在性能敏感路径（如游戏主循环）中频繁使用**

> 💡 Cherno 建议：
> “只在真正需要安全检查时使用 `dynamic_cast`。如果设计良好（如使用虚函数替代类型判断），甚至可以完全避免它。”
>



## 八、最佳实践与替代方案

### ✅ 推荐做法：

* 优先通过 **虚函数** 实现多态行为，而非类型判断
  <pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[36px] sticky top-0 z-10 bg-primary"><div class="flex items-center h-[36px] px-3 text-12 align-middle border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-12 overflow-ellipsis whitespace-nowrap overflow-hidden text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-16 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-copy-line"></use></svg></span><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-moon-line"></use></svg></span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon text-16 size-4"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#pcicon-up-line"></use></svg></span></div></div></div></div><pre class="sc-bRKDuR jCSJQZ"><code><span class="token">// 好：用虚函数</span><span>
  </span><span></span><span class="token">class</span><span> </span><span class="token">Entity</span><span> </span><span class="token">{</span><span> </span><span class="token">virtual</span><span> </span><span class="token">void</span><span> </span><span class="token">Update</span><span class="token">(</span><span class="token">)</span><span> </span><span class="token">=</span><span> </span><span class="token">0</span><span class="token">;</span><span> </span><span class="token">}</span><span class="token">;</span></code></pre></div></div></pre>
* 若必须类型判断，用 `dynamic_cast` + `if` 检查指针
* 确保基类有 **虚析构函数**（防止内存泄漏）

### ❌ 避免：

* 频繁使用 `dynamic_cast` 作为控制流（代码异味）
* 对非多态类型使用（编译失败）
* 忽略返回值（导致空指针解引用）


## 九、总结：关键要点


| 项目         | 说明                       |
| ------------ | -------------------------- |
| **用途**     | 安全的运行时向下转型       |
| **前提**     | 类必须是多态的（有虚函数） |
| **指针失败** | 返回`nullptr`              |
| **引用失败** | 抛出`std::bad_cast`        |
| **依赖**     | RTTI（运行时类型信息）     |
| **性能**     | 有开销，避免高频使用       |
| **替代方案** | 优先使用虚函数实现多态     |

---

## 💬 最后引用 Cherno 的观点：

> “`dynamic_cast` 是一把安全锤子，但如果你总需要用它砸开类型系统，
> 也许你的设计该重构了。”
>
