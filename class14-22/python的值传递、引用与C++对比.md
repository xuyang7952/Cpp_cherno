# C++中的引用，和Python中的变量引用的对比

## ✅ 一、基本概念对比


| 特性           | C++ 引用（Reference）                            | Python 变量（“引用”）                           |
| -------------- | ------------------------------------------------ | ------------------------------------------------- |
| 本质           | 别名（alias）                                    | 指向对象的标签（name binding）                    |
| 是否可变       | 绑定后不能改变（必须初始化且不能重新绑定）       | 可以重新绑定到不同对象                            |
| 是否有内存地址 | 是，引用本身不占额外空间（通常编译器实现为指针） | 变量名是符号，对象有地址，变量本身不占运行时存储  |
| 是否独立存在   | 否，必须绑定到一个已存在的变量                   | 是，变量名存在于命名空间中（如局部/全局命名空间） |

## ✅ 二、语法与使用方式

### 1. C++ 引用

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">cpp</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span>int</span><span> a = </span>10<span>;
</span><span></span><span>int</span><span>& ref = a;  </span><span>// ref 是 a 的别名</span><span>
</span><span>ref = </span>20<span>;      </span><span>// 相当于 a = 20</span></code></pre></div></div></pre>

* 必须在声明时初始化。
* 一旦绑定，不能再指向其他变量。
* 对 `ref` 的操作就是对 `a` 的操作。

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">cpp</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span>int</span><span> b = </span>30<span>;
</span><span>ref = b;  </span><span>// ❌ 不是让 ref 指向 b，而是把 b 的值赋给 ref（也就是 a）！a 变成 30</span></code></pre></div></div></pre>

> ⚠️ 注意：`ref = b;` 是赋值，不是重新绑定！

### 2. Python 变量

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span>a = [</span>1<span>, </span>2<span>, </span>3<span>]
</span><span>b = a           </span><span># b 指向同一个列表对象</span><span>
</span><span>b.append(</span>4<span>)
</span><span></span><span>print</span><span>(a)        </span><span># 输出 [1, 2, 3, 4]，说明 a 和 b 共享对象</span></code></pre></div></div></pre>

* `a` 和 `b` 是同一个对象的两个“名字”。
* 可以随时重新绑定：

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span>b = [</span>5<span>, </span>6<span>]     </span><span># b 现在指向新对象，a 不受影响</span></code></pre></div></div></pre>

## ✅ 三、内存模型对比

### C++：栈上变量 + 显式引用

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">cpp</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span>int</span><span> x = </span>10<span>;
</span><span></span><span>int</span><span>& r = x;  </span><span>// r 是 x 的别名，没有独立内存</span></code></pre></div></div></pre>

* `r` 和 `x` 是同一个内存位置的两个名字。
* 编译器通常将引用实现为“隐式指针”，但对程序员透明。

### Python：一切是对象，变量是名字

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span>a = </span>10<span>
</span>b = a</code></pre></div></div></pre>

内存模型：

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang"></span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span>名字空间:
</span>a ───┐
b ───┼──> 整数对象 10（在堆上）
     └── 引用计数：2</code></pre></div></div></pre>

* 所有数据都是堆上对象。
* 变量是名字到对象的绑定。
* 多个名字可以指向同一个对象（共享）。
* 使用引用计数 + 垃圾回收管理内存。

## ✅ 四、可变性与重新绑定


| 行为              | C++ 引用                                     | Python 变量                 |
| ----------------- | -------------------------------------------- | --------------------------- |
| 是否可重新绑定    | ❌ 不可重新绑定                              | ✅ 可以重新赋值绑定到新对象 |
| 是否可为`nullptr` | ❌ 必须绑定有效对象（除非是`T&` 的函数参数） | ✅ 可以赋值为`None`         |

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">cpp</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span>// C++：无法重新绑定</span><span>
</span><span></span><span>int</span><span> x = </span>1<span>, y = </span>2<span>;
</span><span></span><span>int</span><span>& r = x;
</span><span>r = y;     </span><span>// x = 2，r 仍然绑定 x</span><span>
</span><span></span><span>// r = z;  // 不能让 r 绑定 z</span></code></pre></div></div></pre>

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span># Python：可以重新绑定</span><span>
</span><span>a = [</span>1<span>]
</span>b = a
<span>b = [</span>2<span>]   </span><span># b 现在指向新列表，a 仍是 [1]</span></code></pre></div></div></pre>

## ✅ 五、函数参数传递对比

### C++：引用传递（避免拷贝）

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">cpp</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code>void func(int& x) <span>{
</span><span>    x = </span>100<span>;  </span><span>// 修改原变量</span><span>
</span>}

<span></span><span>int</span><span> a = </span>10<span>;
</span><span></span><span>func</span><span>(a);  </span><span>// a 变成 100</span></code></pre></div></div></pre>

* 真正的“传引用”，可以直接修改实参。

### Python：名字传递（“传对象引用”，但不可变对象无法修改）

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code>def func(lst):<span>
</span><span>    lst.append(</span>4<span>)  </span><span># 修改对象内容</span><span>
</span>
<span>mylist = [</span>1<span>, </span>2<span>, </span>3<span>]
</span>func(mylist)
<span></span><span>print</span><span>(mylist)  </span><span># [1, 2, 3, 4]</span></code></pre></div></div></pre>

但：

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn" data-spm-anchor-id="5176.28103460.0.i14.77b42e317eSNtq"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code data-spm-anchor-id="5176.28103460.0.i12.77b42e317eSNtq">def func(lst):<span>
</span><span>    lst = [</span>4<span>, </span>5<span>, </span>6<span>]  </span><span># 重新绑定局部变量，不影响外面</span><span>
</span>
<span>mylist = [</span>1<span>, </span>2<span>, </span>3<span>]
</span>func(mylist)
<span></span><span>print</span><span>(mylist)  </span><span># 仍然是 [1, 2, 3]</span></code></pre></div></div></pre>

> Python 的参数传递常被称为 **“传对象引用（pass-by-object-reference）”** 或 **“传共享调用（call-by-sharing）”**。

## ✅ 七、类比理解

* **C++ 引用**：就像给一个人起个别名，比如“小明”和“明明”是同一个人，改名不影响身份。
* **Python 变量**：就像标签贴在物体上，多个标签可以贴在同一物体上，也可以撕下贴到别的物体上。

---

## ✅ 结论


| 场景        | 推荐理解方式                                                                 |
| ----------- | ---------------------------------------------------------------------------- |
| C++ 引用    | 是**变量的别名**，安全、高效，用于避免拷贝和实现函数双向通信                 |
| Python 变量 | 是**对象的引用（标签）**，所有变量都是“引用类型”，但行为取决于对象是否可变 |

> 🔔 关键区别：**C++ 引用是编译时的别名机制，Python 变量是运行时的名字绑定机制**。

---

如果你从 C++ 转向 Python，记住一句话：

> “在 Python 中，**变量是名字，不是盒子**；你不是把对象放进变量，而是把名字贴在对象上。”

## ✅ 六、总结对比表


| 特性               | C++ 引用           | Python 变量                    |
| ------------------ | ------------------ | ------------------------------ |
| 本质               | 变量的别名         | 名字到对象的绑定               |
| 是否可重新绑定     | 否                 | 是                             |
| 是否必须初始化     | 是                 | 否（但使用前必须赋值）         |
| 是否可为空         | 否（除非是`T*`）   | 是（可为`None`）               |
| 内存位置           | 与原变量相同       | 名字在命名空间，对象在堆       |
| 修改是否影响原变量 | 是（直接修改）     | 取决于对象是否可变             |
| 函数参数           | 可实现双向传递     | 只能通过可变对象间接影响       |
| 实现方式           | 编译器隐式使用指针 | 运行时字典映射（如`locals()`） |

# **Python 中一切都是对象，所以传递的是引用的复制**

## ✅ 一、Python 的基石：一切皆对象（Everything is an object）

在 Python 中：

* 整数 `42` 是对象
* 字符串 `"hello"` 是对象
* 列表 `[1, 2, 3]` 是对象
* 函数 `def func(): ...` 是对象
* 类 `class MyClass:` 也是对象

所有变量都只是 **指向对象的“名字”（name）或“标签”（label）**。

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span>a = </span>42</code></pre></div></div></pre>

这行代码的意思是：

* 创建一个整数对象 `42`
* 把名字 `a` 绑定到这个对象上

你可以用 `id(a)` 看到这个对象的内存地址。

---

## ✅ 二、既然一切都是对象，那“传参”传的是什么？

当你调用一个函数：

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code>def func(x):<span>
</span><span>    </span><span>pass</span><span>
</span>
<span>a = [</span>1<span>, </span>2<span>, </span>3<span>]
</span>func(a)</code></pre></div></div></pre>

Python 不可能把整个 `[1, 2, 3]` 拷贝一份传进去（效率太低），也不会像 C++ 那样传变量的“别名”。

它传的是：

> **这个对象的引用（reference）—— 也就是对象的内存地址。**

但关键来了：

### 🎯 这个“引用”是怎么传的？是“按引用传递”吗？

❌ **不是！**

Python 传的是 **“引用的副本”（a copy of the reference）**

## ✅ 三、什么是“引用的副本”？

我们用一个比喻：

* 对象 = 一个箱子（比如装着 `[1,2,3]`）
* 引用 = 指向箱子的“指针”或“标签”
* 外部变量 `a` = 一个标签贴在箱子上
* 函数参数 `x` = Python **复制了一个同样的标签**，也贴在同一个箱子上

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang"></span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span>a ───┐
</span>     ├──→ [1, 2, 3] ←── x（函数内）
     └───（两个标签，同一个箱子）</code></pre></div></div></pre>

* `a` 和 `x` 是两个不同的“名字”，但指向同一个对象。
* 这个 `x` 拿到的，是 `a` 所指向的“引用”的一个**副本**。

## ✅ 四、为什么是“副本”？代码验证

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code>def func(x):<span>
</span><span>    </span><span>print</span><span>(</span><span>f"x 的 id（指向的对象）: </span><span>{</span><span>id</span><span>(x)}</span><span>"</span><span>)
</span><span>    x = [</span>4<span>, </span>5<span>, </span>6<span>]  </span><span># 重新绑定</span><span>
</span><span>    </span><span>print</span><span>(</span><span>f"x 重新赋值后 id: </span><span>{</span><span>id</span><span>(x)}</span><span>"</span><span>)
</span>
<span>a = [</span>1<span>, </span>2<span>, </span>3<span>]
</span><span></span><span>print</span><span>(</span><span>f"a 的 id: </span><span>{</span><span>id</span><span>(a)}</span><span>"</span><span>)  </span><span># 比如 0x1000</span><span>
</span>func(a)
<span></span><span># 输出：</span><span>
</span><span></span><span># a 的 id: 0x1000</span><span>
</span><span></span><span># x 的 id（指向的对象）: 0x1000      ← 初始时，x 和 a 指向同一对象</span><span>
</span><span></span><span># x 重新赋值后 id: 0x2000            ← x 现在指向新对象</span></code></pre></div></div></pre>

* 初始时，`x` 和 `a` 的 `id()` 相同 → 说明指向同一对象。
* 但 `x = [4,5,6]` 后，`x` 的 `id()` 变了 → 说明 `x` 被重新绑定。
* 而 `a` 的 `id()` 没变 → 外部不受影响。

👉 这证明：`x` 拿到的是“引用的副本”，不是 `a` 本身。

## ✅ 五、为什么设计成“引用的副本”？

### 1. 效率高

* 不需要拷贝整个对象（尤其是大列表、大字典）。
* 只传一个“指针”（引用）的副本，非常快。

### 2. 安全性

* 函数不能意外修改外部变量的绑定。
* 你必须通过 `return` 显式返回新值，才能改变外部变量。

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code>def func(lst):<span>
</span><span>    lst = [</span>4<span>,</span>5<span>,</span>6<span>]  </span><span># 不会影响外面，安全</span><span>
</span>
<span>a = [</span>1<span>,</span>2<span>,</span>3<span>]
</span>func(a)
<span></span><span># a 仍然是 [1,2,3]，不会被意外“替换”</span></code></pre></div></div></pre>

### 3. 统一模型

* 无论是 `int`、`str`、`list`、`dict`，所有参数传递都遵循同一规则：
  > **“传对象的引用，但引用是按值传递（即副本）”**
  >

## ✅ 六、总结：一句话说透

> ✅ **正是因为 Python 中“一切皆对象”，所以变量只是名字，对象在堆上。**
>
> ✅ **函数传参时，不可能传整个对象（太慢），也不可能传变量本身（Python 没有“变量地址”概念）。**
>
> ✅ **所以 Python 选择：传“对象的引用”，但这个引用是“副本”——即“传引用的副本”。**

### 最终结论：

> **“传递的是引用的复制”** —— 这句话 **完全正确**，并且是理解 Python 参数传递的**钥匙**。

---

### 🧠 补充：术语对照


| 说法                         | 含义                                       |
| ---------------------------- | ------------------------------------------ |
| “传对象引用”               | 传的是对象的内存地址                       |
| “引用是按值传递”           | 这个地址是副本，函数不能改变外部变量的绑定 |
| “传引用的复制”             | 和上面等价，更直白                         |
| “call-by-object-reference” | 官方术语，指这种“传引用副本”的机制       |

---

现在你应该可以自信地说：

> “Python 传参，传的是 **引用的副本**，所以能改对象内容（如果可变），但不能换外部变量的绑定。”

# 可以理解为新建了个变量名，b=a,把b传进去？

✅ **答案是：是的，这个理解在语义上非常接近，甚至可以说是一个非常好的“心智模型”（mental model）来帮助你理解 Python 的参数传递机制。**

我们来深入分析一下。

---

## ✅ 一、你的理解：`b = a`，然后把 `b` 传进函数

你设想的是：

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span>a = [</span>1<span>, </span>2<span>, </span>3<span>]
</span>
<span></span><span># 你想象 Python 在调用函数时，先做了这一步：</span><span>
</span><span>b = a          </span><span># b 是 a 的一个“副本引用”</span><span>
</span><span>func(b)        </span><span># 然后把 b 传给函数</span></code></pre></div></div></pre>

而函数内部的参数 `x` 就相当于这个 `b`。

👉 **这个类比非常准确！**

---

## ✅ 二、为什么这个类比成立？

### 1. `b = a` 发生了什么？

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span>a = [</span>1<span>, </span>2<span>, </span>3<span>]
</span>b = a</code></pre></div></div></pre>

* `a` 和 `b` 都指向同一个列表对象。
* 它们是两个不同的“名字”，但绑定到同一个对象。
* `id(a) == id(b)` → True

这和函数传参时的行为**完全一致**：

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code>def func(x):<span>   </span><span># x 就像 b</span><span>
</span><span>    </span><span>pass</span><span>
</span>
<span>func(a)        </span><span># x = a（隐式地）</span></code></pre></div></div></pre>

* `x` 和 `a` 指向同一个对象。
* `x` 是 `a` 所指向对象的“引用”的一个副本。

---

### 2. 验证：`b = a` 和函数传参行为一致

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code>def func(x):<span>
</span><span>    x.append(</span>4<span>)
</span><span>    </span><span>print</span><span>(</span><span>f"x 内: </span><span>{x}</span><span>"</span><span>)  </span><span># [1,2,3,4]</span><span>
</span>
<span>a = [</span>1<span>, </span>2<span>, </span>3<span>]
</span>b = a
func(a)
<span></span><span>print</span><span>(</span><span>f"a 外: </span><span>{a}</span><span>"</span><span>)      </span><span># [1,2,3,4]</span><span>
</span><span></span><span>print</span><span>(</span><span>f"b 外: </span><span>{b}</span><span>"</span><span>)      </span><span># [1,2,3,4]</span></code></pre></div></div></pre>

输出：

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang"></span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span>x 内: [1, 2, 3, 4]
</span>a 外: [1, 2, 3, 4]
b 外: [1, 2, 3, 4]</code></pre></div></div></pre>

✅ 三者都看到了修改，因为 `a`、`b`、`x` 都指向同一个对象。

## ✅ 三、再验证：重新绑定时也不影响外部

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code>def func(x):<span>
</span><span>    x = [</span>4<span>, </span>5<span>, </span>6<span>]        </span><span># x 重新绑定</span><span>
</span><span>    </span><span>print</span><span>(</span><span>f"x 内: </span><span>{x}</span><span>"</span><span>)   </span><span># [4,5,6]</span><span>
</span>
<span>a = [</span>1<span>, </span>2<span>, </span>3<span>]
</span>b = a
func(a)
<span></span><span>print</span><span>(</span><span>f"a 外: </span><span>{a}</span><span>"</span><span>)      </span><span># [1,2,3] —— 没变</span><span>
</span><span></span><span>print</span><span>(</span><span>f"b 外: </span><span>{b}</span><span>"</span><span>)      </span><span># [1,2,3] —— 没变</span></code></pre></div></div></pre>

✅ 即使在函数内 `x` 换了对象，`a` 和 `b` 依然指向原对象。

这和 `b = a` 后 `b = [4,5,6]` 不影响 `a` 的行为**完全一致**。

---

## ✅ 四、所以，你的理解可以这样总结：


| 你的类比                 | 实际机制                        |
| ------------------------ | ------------------------------- |
| `b = a`                  | 函数参数`x` 得到 `a` 的引用副本 |
| `b` 是一个新名字         | `x` 是一个局部名字              |
| `b` 和 `a` 指向同一对象  | `x` 和 `a` 指向同一对象         |
| `b = new_obj` 不影响 `a` | `x = new_obj` 不影响 `a`        |
| `b.append()` 影响原对象  | `x.append()` 影响原对象         |

🎯 **完全对等！**

## ✅ 五、更精确的说法（进阶）

虽然 `b = a` 是一个极好的类比，但严格来说：

* Python **不会真的创建一个叫 `b` 的变量**。
* 而是在函数调用时，**在函数的局部命名空间中创建参数变量 `x`，并将其绑定到 `a` 所指向的对象**。

这相当于：

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span># 伪代码：函数调用时的隐式操作</span><span>
</span><span>x = a  </span><span># 把实参 a 的引用赋值给形参 x</span></code></pre></div></div></pre>

所以你完全可以把函数参数想象成：

> **“Python 在函数内部自动执行了一次 `x = a`”**

## ✅ 六、结论：你可以这样理解 ✅

> 当你写：
>
> <pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span>func(a)</span></code></pre></div></div></pre>
>
> 可以理解为：
>
> 1. Python 在函数内部**新建了一个局部变量名**（比如叫 `x`）。
> 2. 执行了 `x = a` —— 即让 `x` 指向 `a` 所指向的同一个对象。
> 3. 然后运行函数体。
>
> 这个 `x` 就像你手动写的 `b = a` 中的 `b`。

---

### 🎯 最终口诀（你可以记住）：

> **“函数参数 = 自动帮你写了一个 `x = a`”**

只要记住这一点，你就掌握了 Python 参数传递的**灵魂**

# 不同语言的参数传递

## 一、核心概念澄清：什么是“值传递” vs “引用传递”？


| 术语                                         | 含义                           | 关键特征                                   |
| -------------------------------------------- | ------------------------------ | ------------------------------------------ |
| **值传递**（Pass by Value）                  | 传递的是变量的**副本**         | 函数内部修改不影响外部                     |
| **引用传递**（Pass by Reference）            | 传递的是变量的**别名**         | 函数内部修改直接影响外部                   |
| **对象引用传递**（Pass by Object Reference） | 传递的是**对象的引用（指针）** | 对可变对象的修改影响外部，但重新赋值不影响 |

> ⚠️ 注意：很多说法（如“Java 是引用传递”）其实是**不准确的**。准确的说法是：
>
> * **C/C++/Java/Python 都是“值传递”**，但“值”的内容不同

## 二、四语言参数传递对比表


| 语言       | 基本类型（int, double）              | 复合类型（数组、对象、结构体）                       | 总结                                       |
| ---------- | ------------------------------------ | ---------------------------------------------------- | ------------------------------------------ |
| **C**      | ✅ 值传递（拷贝）<br>❌ 无法直接引用 | ✅ 值传递（拷贝整个结构体）<br>✅ 用指针模拟引用     | **纯值传递**，引用靠指针                   |
| **C++**    | ✅ 值传递<br>✅ `&` 引用传递（可选） | ✅ 值传递<br>✅ `&` 引用传递<br>✅ 指针              | **可选值 or 引用传递**                     |
| **Java**   | ✅ 值传递                            | ✅**对象引用的值传递**<br>（常被误称为“引用传递”） | **所有都是值传递**，但对象传的是引用的拷贝 |
| **Python** | ✅ 对象引用的值传递                  | ✅ 对象引用的值传递<br>（一切皆对象）                | **一切皆对象引用传递**（语义上）           |

## 三、逐语言详解

### 1. **C 语言：纯值传递 + 指针模拟引用**

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">c</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code>void modify(int x) <span>{
</span><span>    x = </span>10<span>;  </span><span>// 只修改副本</span><span>
</span>}

<span></span>void modify_ptr(int *x) <span>{
</span><span>    *x = </span>10<span>;  </span><span>// 通过指针修改原变量</span><span>
</span>}

<span></span>int main() <span>{
</span><span>    </span><span>int</span><span> a = </span>5<span>;
</span><span>    modify(a);        </span><span>// a 不变</span><span>
</span><span>    modify_ptr(&a);   </span><span>// a 变为 10</span><span>
</span>}</code></pre></div></div></pre>

* ✅ **所有参数都是值传递**。
* ❌ 没有引用语法，必须用指针（`*`）和取地址（`&`）。
* 🔒 指针可以为空，不安全。

> 💡 类比 Python：就像你必须手动传一个“内存地址”才能修改原值。

### 2. **C++：值传递 + 引用传递（语法支持）**

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">cpp</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code>void modify_value(int x) <span>{
</span><span>    x = </span>10<span>;  </span><span>// 不影响外部</span><span>
</span>}

<span></span>void modify_ref(int &x) <span>{  </span><span>// x 是别名</span><span>
</span><span>    x = </span>10<span>;  </span><span>// 直接修改外部</span><span>
</span>}

<span></span>int main() <span>{
</span><span>    </span><span>int</span><span> a = </span>5<span>;
</span><span>    </span><span>modify_value</span><span>(a);  </span><span>// a 不变</span><span>
</span><span>    </span><span>modify_ref</span><span>(a);    </span><span>// a 变为 10</span><span>
</span>}</code></pre></div></div></pre>

* ✅ 支持两种方式：
  * `void f(int x)`：值传递（拷贝）
  * `void f(int &x)`：引用传递（别名）
* ✅ 安全、高效、语法简洁。
* ✅ 可用于函数返回、STL 容器等。

> 💡 类比 Python：`int &x` 就像 Python 中对可变对象的修改，但 C++ 让你对 `int` 也能这样控制。

### 3. **Java：一切都是值传递，但对象传的是“引用的拷贝”**

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">java</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code>void modifyBasic(int x) <span>{
</span><span>    x = </span>10<span>;  </span><span>// 不影响外部</span><span>
</span>}

<span></span>void modifyObject(List<Integer> list) <span>{
</span><span>    list.add(</span>1<span>);     </span><span>// 修改原对象 ✅</span><span>
</span><span>    list = </span><span>new</span><span> ArrayList<>();  </span><span>// 重新赋值，不影响外部 ❌</span><span>
</span>}

<span></span>public static void main(String[] args) <span>{
</span><span>    </span><span>int</span><span> a = </span>5<span>;
</span><span>    List<Integer> lst = </span><span>new</span><span> ArrayList<>();
</span>  
<span>    modifyBasic(a);      </span><span>// a 不变</span><span>
</span><span>    modifyObject(lst);   </span><span>// lst 被修改（add 生效）</span><span>
</span>}</code></pre></div></div></pre>

* ✅ **Java 所有参数都是值传递**！
* ❌ 但对象参数传递的是“**对象引用的拷贝**”（即指针的拷贝）。
  * 修改对象内容（如 `list.add()`）→ 影响外部 ✅
  * 重新赋值（`list = new ...`）→ 不影响外部 ❌

> 💡 类比 Python：**Java 的对象传递机制和 Python 几乎一样！**

### 4. **Python：一切皆对象，传递“对象引用”**

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code>def modify_int(x):<span>
</span><span>    x = </span>10<span>  </span><span># 重新绑定，不影响外部</span><span>
</span>
<span></span>def modify_list(lst):<span>
</span><span>    lst.append(</span>1<span>)      </span><span># 修改可变对象 → 影响外部 ✅</span><span>
</span><span>    lst = [</span>1<span>, </span>2<span>, </span>3<span>]    </span><span># 重新赋值 → 不影响外部 ❌</span><span>
</span>
<span>a = </span>5<span>
</span><span>my_list = [</span>1<span>, </span>2<span>]
</span>
<span>modify_int(a)      </span><span># a 仍是 5</span><span>
</span><span>modify_list(my_list)  </span><span># my_list 变为 [1,2,1]</span></code></pre></div></div></pre>

* ✅ Python 没有“值类型”和“引用类型”之分。
* ✅ 所有变量都是对象的引用。
* ✅ 参数传递是“**对象引用的值传递**”：
  * 对可变对象（list, dict）的修改 → 影响外部
  * 重新赋值 → 不影响外部

> 💡 类比 Java：**Python 和 Java 在参数传递语义上非常相似**，只是 Python 更统一（一切皆对象）。

## 四、终极总结：一句话看懂


| 语言       | 实际机制                               | 通俗理解                                       |
| ---------- | -------------------------------------- | ---------------------------------------------- |
| **C**      | 值传递（基本/复合类型都拷贝）          | 想改外面？必须传指针！                         |
| **C++**    | **可选**：值传递 或 引用传递（`&`）    | 我想拷贝就拷贝，想别名就别名                   |
| **Java**   | 值传递（基本类型拷贝值，对象拷贝引用） | 对象传的是“引用的拷贝”，能改内容但不能改引用 |
| **Python** | 值传递（传的是对象引用）               | 一切皆对象，可变对象能改，重新赋值不能改       |

## 五、常见误区澄清

### ❌ 误区1：“Java 是引用传递”

* **错**！Java 是**值传递**，传递的是“对象引用的值”（即指针的拷贝）。
* 正确说法：**Java 是“对象引用的值传递”**。

### ❌ 误区2：“Python 是值传递”

* **不准确**。Python 是“**对象引用传递**”（语义上），但底层是“引用的值传递”。

### ❌ 误区3：“C++ 引用就是指针”

* **错**。引用是别名，不能为空，不能重新绑定；指针可以为空，可以指向其他地址。

## 总结：一句话记住

> **C 是“纯值传递”，C++ 是“可选值或引用”，Java 和 Python 都是“对象引用的值传递”——但 Python 更统一，Java 区分基本类型。**

# 值、引用、指针

## 一、先搞清三个概念：值、引用、指针


| 概念                  | 含义                                  | 类比                                    |
| --------------------- | ------------------------------------- | --------------------------------------- |
| **值**（Value）       | 变量存储的实际数据，如`42`、`"hello"` | 一本书的内容                            |
| **引用**（Reference） | 指向对象的“别名”或“连接”          | 图书馆里这本书的“索书号”              |
| **指针**（Pointer）   | 存储内存地址的变量（C/C++ 中）        | 索书号的物理卡片，上面写着“3楼A区5排” |

> 💡 在 Java/Python 中，“引用”本质上是一个**指向对象的指针**，但你不能直接操作地址。

## 二、核心结论：所有语言都是“值传递”，但“值”的内容不同

> ✅ **Java 和 Python 的参数传递机制是：****“传递的是‘引用的拷贝’”**，也就是“**引用的值传递**”。

我们用一个**图书馆借书**的比喻来彻底理解：

## 三、图书馆比喻：理解“引用的值传递”

### 场景设定：

* 你有一本书《算法导论》，放在图书馆的 **3楼A区5排**（这是它的“内存地址”）。
* 你有一个“索书号”：`CS101`（这就是“引用”或“指针”）。
* 你把 `CS101` 告诉朋友，让他去修改书的内容。

### 1. **Java/Python 的参数传递过程**

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">java</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span>// Java</span><span>
</span><span></span>void modify(Book book) <span>{  </span><span>// book 是“索书号”的一个拷贝</span><span>
</span><span>    book.addNote(</span><span>"重要！"</span><span>);  </span><span>// 用拷贝的索书号找到书，修改内容 ✅</span><span>
</span><span>    book = </span><span>new</span><span> Book();     </span><span>// 把自己的索书号换成另一本书 ❌（不影响你）</span><span>
</span>}</code></pre></div></div></pre>

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span># Python</span><span>
</span><span></span>def modify(book):<span>
</span><span>    book.add_note(</span><span>"重要！"</span><span>)   </span><span># 修改原书内容 ✅</span><span>
</span><span>    book = Book()            </span><span># 把自己的“索书号”换成新书 ❌（不影响你）</span></code></pre></div></div></pre>

#### 过程分解：


| 步骤 | 操作                                     | 是否影响你？      | 为什么？                           |
| ---- | ---------------------------------------- | ----------------- | ---------------------------------- |
| 1    | 你把`CS101` 告诉朋友                     | ✅ 朋友知道书在哪 | 你传递的是“引用”                 |
| 2    | 朋友用`CS101` 找到书，写批注             | ✅ 你看到批注     | 你们指向同一个对象                 |
| 3    | 朋友把自己的`CS101` 换成 `CS102`（新书） | ❌ 你的书不变     | 他改的是“自己的索书号”，不是你的 |

🎯 **关键点**：
你传给函数的不是书本身（值传递对象内容），也不是书的别名（引用传递），而是\*\*“索书号的复印件”\*\*。
这个“复印件”也能找到书，但朋友涂改“复印件”不会影响你的原件；相当于另外一个变量；

## 四、“引用的值传递” vs “真正的引用传递”（C++）

我们对比 C++ 的引用传递：

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">cpp</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span>// C++</span><span>
</span><span></span>void modify(Book& book) <span>{  </span><span>// book 是你书的“别名”</span><span>
</span><span>    book.</span><span>addNote</span><span>(</span><span>"重要！"</span><span>);  </span><span>// 修改原书 ✅</span><span>
</span><span>    book = anotherBook;     </span><span>// 把你的书换成另一本 ✅（影响你！）</span><span>
</span>}</code></pre></div></div></pre>


| 语言            | 传递的是什么                     | 能否修改对象内容 | 能否重新绑定对象 |
| --------------- | -------------------------------- | ---------------- | ---------------- |
| **Java/Python** | 引用的拷贝（“索书号复印件”）   | ✅               | ❌               |
| **C++ 引用**    | 对象的别名（“你的书直接借走”） | ✅               | ✅               |

> ✅ 所以：
>
> * Java/Python：传的是“**引用的值**” → **值传递**
> * C++ `&`：传的是“**对象的别名**” → **引用传递**

## 五、代码实操：验证“引用的值传递”

### Python 示例：

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code>def modify_list(lst):<span>
</span><span>    </span><span>print</span><span>(</span><span>f"函数内: lst 的 id = </span><span>{</span><span>id</span><span>(lst)}</span><span>"</span><span>)
</span><span>    lst.append(</span>1<span>)           </span><span># 修改对象内容 → 影响外部</span><span>
</span><span>    lst = [</span>4<span>, </span>5<span>, </span>6<span>]         </span><span># 重新赋值 → 不影响外部</span><span>
</span><span>    </span><span>print</span><span>(</span><span>f"函数内重新赋值后: lst 的 id = </span><span>{</span><span>id</span><span>(lst)}</span><span>"</span><span>)
</span>
<span>my_list = [</span>1<span>, </span>2<span>, </span>3<span>]
</span><span></span><span>print</span><span>(</span><span>f"函数外: my_list 的 id = </span><span>{</span><span>id</span><span>(my_list)}</span><span>"</span><span>)
</span>modify_list(my_list)
<span></span><span>print</span><span>(</span><span>f"函数后: my_list = </span><span>{my_list}</span><span>"</span><span>)  </span><span># 输出: [1, 2, 3, 1]</span></code></pre></div></div></pre>

**输出：**

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang"></span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span>函数外: my_list 的 id = 140234567890
</span>函数内: lst 的 id = 140234567890        ← 同一个对象
函数内重新赋值后: lst 的 id = 140234567999  ← 新对象
函数后: my_list = [1, 2, 3, 1]          ← 外部只看到 append 的效果</code></pre></div></div></pre>

> 🔍 看到了吗？
>
> * `lst` 和 `my_list` 初始 `id` 相同 → 指向同一对象
> * `lst = [4,5,6]` 后 `id` 变了 → 创建新对象，`lst` 指向新对象
> * `my_list` 的 `id` 始终不变 → 外部不受影响

---

### Java 示例（类似）：

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">java</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code>void modifyList(List<Integer> list) <span>{
</span><span>    System.out.println(</span><span>"函数内 list: "</span><span> + System.identityHashCode(list));
</span><span>    list.add(</span>1<span>);                    </span><span>// 修改内容 → 影响外部</span><span>
</span><span>    list = </span><span>new</span><span> ArrayList<>();       </span><span>// 重新赋值 → 不影响外部</span><span>
</span><span>    System.out.println(</span><span>"重新赋值后 list: "</span><span> + System.identityHashCode(list));
</span>}</code></pre></div></div></pre>

输出类似 Python，`list` 的哈希码（类似 `id`）在重新赋值后改变。

## 六、总结：“引用的值传递”到底是什么？


| 术语                      | 含义                                     | 关键特征                                                                                         |
| ------------------------- | ---------------------------------------- | ------------------------------------------------------------------------------------------------ |
| **引用的值传递**          | 传递的是“指向对象的引用（指针）的拷贝” | - 函数拿到的是“引用的副本”<br>- 能通过副本修改对象内容<br>- 不能通过副本改变外部变量的引用目标 |
| **真正的引用传递**（C++） | 传递的是变量的“别名”                   | - 函数操作的就是原变量<br>- 能修改内容，也能重新绑定                                             |

> ✅ **所以：**
>
> * **Java 和 Python 的参数传递，本质上是“值传递”，但“值”是一个“引用”（指针）**。
> * 这导致它们在**修改可变对象时表现像“引用传递”**，但在**重新赋值时不改变外部**。

# 只有C++有引用传递，其他都是“值传递”


> **只有 C++ 的 `&` 语法提供了真正的“引用传递”（pass by reference）；而 C、Java、Python 等语言，本质上都是“值传递”（pass by value），只是“值”的内容不同：**
>
> * **C**：传递的是变量的值（或指针的值）
> * **Java/Python**：传递的是“对象引用的值”（即指针的拷贝）



## 一、彻底厘清：什么是“真正的引用传递”？

### ✅ C++ 的引用传递（`int &x`）是“真·别名”

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">cpp</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code>void modify(int &x) <span>{
</span><span>    x = </span>10<span>;  </span><span>// 直接操作外部变量 a</span><span>
</span>}

<span></span><span>int</span><span> a = </span>5<span>;
</span><span></span><span>modify</span><span>(a);  </span><span>// a 变成 10</span></code></pre></div></div></pre>

* `x` 不是 `a` 的副本，也不是指向 `a` 的指针。
* `x` 就是 `a` 的**另一个名字**（alias）。
* 编译器保证 `x` 和 `a` 是同一个东西，底层可能优化为直接访问 `a` 的内存地址。

> 🔑 **关键特征**：
>
> * 不能为 `null`
> * 必须初始化
> * 不能重新绑定（`x` 始终是 `a` 的别名）
> * 函数内部修改 `x`，就是修改 `a`

这就是**真正的引用传递**。


## 二、其他语言为什么不是“真正的引用传递”？

### 1. **C：指针的值传递**

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">c</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code>void modify(int *p) <span>{
</span><span>    *p = </span>10<span>;      </span><span>// 修改 p 指向的内容 ✅</span><span>
</span><span>    p = </span><span>NULL</span><span>;     </span><span>// 把 p 设为 NULL ❌（不影响外部指针）</span><span>
</span>}

<span></span><span>int</span><span> a = </span>5<span>;
</span><span></span><span>int</span><span> *ptr = &a;
</span><span>modify(ptr);  </span><span>// a 变成 10，但 ptr 仍指向 a</span></code></pre></div></div></pre>

* 你传给函数的是 `ptr` 的**值**（即地址 `&a`）。
* 函数拿到的是一个**指针的副本**。
* 修改 `*p` → 修改原数据 ✅
* 修改 `p` 本身 → 不影响外部 ❌

> 📌 所以：C 是“**指针的值传递**”，不是引用传递。



### 2. **Java：对象引用的值传递**

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">java</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code>void modify(List<Integer> list) <span>{
</span><span>    list.add(</span>1<span>);        </span><span>// 修改对象内容 ✅</span><span>
</span><span>    list = </span><span>new</span><span> ArrayList<>();  </span><span>// 重新赋值 ❌（不影响外部）</span><span>
</span>}</code></pre></div></div></pre>

* `list` 是一个“引用”（本质是指针）。
* 你传的是这个引用的**拷贝**。
* 函数可以通过拷贝的引用修改对象内容 ✅
* 但修改引用本身（指向新对象）不影响外部 ❌

> 📌 Java 官方文档明确说：“**Java is always pass-by-value**”。
> 只不过对对象来说，这个“值”是一个引用。


### 3. **Python：对象引用的值传递**

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">python</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code>def modify(lst):<span>
</span><span>    lst.append(</span>1<span>)     </span><span># 修改可变对象内容 ✅</span><span>
</span><span>    lst = [</span>4<span>,</span>5<span>,</span>6<span>]     </span><span># 重新绑定局部变量 ❌（不影响外部）</span><span>
</span>
<span>my_list = [</span>1<span>,</span>2<span>,</span>3<span>]
</span>modify(my_list)
<span></span><span>print</span><span>(my_list)  </span><span># [1,2,3,1] —— 只有 append 生效</span></code></pre></div></div></pre>

* `lst` 是 `my_list` 的引用（指向同一对象）。
* 函数拿到的是这个引用的**副本**。
* `append` 操作通过副本找到对象并修改 ✅
* `lst = [...]` 是让局部变量 `lst` 指向新对象，不影响 `my_list` ❌

> 📌 Python 社区常说“传对象引用”，但底层机制仍是“**引用的值传递**”。



## 三、终极对比表


| 语言                | 传递机制         | 能否修改对象内容 | 能否改变外部变量的引用目标 | 是否真正的引用传递 |
| ------------------- | ---------------- | ---------------- | -------------------------- | ------------------ |
| **C++ (`int &x`)**  | 引用传递（别名） | ✅               | ✅（如`x = y`）            | ✅**是**           |
| **C (`int *p`)**    | 指针的值传递     | ✅（`*p`）       | ❌                         | ❌                 |
| **Java (`List l`)** | 对象引用的值传递 | ✅（改内容）     | ❌（不能改引用）           | ❌                 |
| **Python (`lst`)**  | 对象引用的值传递 | ✅（改可变对象） | ❌（不能改引用）           | ❌                 |

---

## 🎯 四、为什么 C++ 的引用更强大？

C++ 的引用传递允许你**像操作原变量一样操作参数**，这在以下场景非常有用：

### 1. **修改多个返回值**

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">cpp</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code>void divide(int a, int b, int &quotient, int &remainder) <span>{
</span>    quotient = a / b;
    remainder = a % b;
}</code></pre></div></div></pre>

### 2. **避免大对象拷贝**

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">cpp</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code>void process(const vector<int>& data) <span>{  </span><span>// 避免拷贝整个 vector</span><span>
</span><span>    </span><span>// ...</span><span>
</span>}</code></pre></div></div></pre>

### 3. **运算符重载**

<pre><div class="tongyi-design-highlighter global-dark-theme"><span class="tongyi-design-highlighter-header"><span class="tongyi-design-highlighter-lang">cpp</span><div class="tongyi-design-highlighter-right-actions"><div class="tongyi-design-highlighter-theme-changer"><div class="tongyi-design-highlighter-theme-changer-btn"><span>深色版本</span><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#tongyi-down-line"></use></svg></span></div></div><svg width="12" height="12" viewBox="0 0 11.199999809265137 11.199999809265137" class="cursor-pointer flex items-center tongyi-design-highlighter-copy-btn"><g><path d="M11.2,1.6C11.2,0.716344,10.4837,0,9.6,0L4.8,0C3.91634,0,3.2,0.716344,3.2,1.6L4.16,1.6Q4.16,1.3349,4.34745,1.14745Q4.5349,0.96,4.8,0.96L9.6,0.96Q9.8651,0.96,10.0525,1.14745Q10.24,1.3349,10.24,1.6L10.24,6.4Q10.24,6.6651,10.0525,6.85255Q9.8651,7.04,9.6,7.04L9.6,8C10.4837,8,11.2,7.28366,11.2,6.4L11.2,1.6ZM0,4L0,9.6C0,10.4837,0.716344,11.2,1.6,11.2L7.2,11.2C8.08366,11.2,8.8,10.4837,8.8,9.6L8.8,4C8.8,3.11634,8.08366,2.4,7.2,2.4L1.6,2.4C0.716344,2.4,0,3.11634,0,4ZM1.14745,10.0525Q0.96,9.8651,0.96,9.6L0.96,4Q0.96,3.7349,1.14745,3.54745Q1.3349,3.36,1.6,3.36L7.2,3.36Q7.4651,3.36,7.65255,3.54745Q7.84,3.7349,7.84,4L7.84,9.6Q7.84,9.8651,7.65255,10.0525Q7.4651,10.24,7.2,10.24L1.6,10.24Q1.3349,10.24,1.14745,10.0525Z"></path></g></svg></div></span><div><pre><code><span>Matrix& </span><span>operator</span><span>=(</span><span>const</span><span> Matrix& other) {  </span><span>// 返回引用，支持链式赋值</span><span>
</span><span>    </span><span>// ...</span><span>
</span><span>    </span><span>return</span><span> *</span><span>this</span><span>;
</span>}</code></pre></div></div></pre>

这些在 C/Java/Python 中要么做不到，要么很麻烦。


## 五、总结：你的理解完全正确！

> **✅ 只有 C++ 的 `&` 提供了真正的“引用传递”语义。**
>
> **❌ C、Java、Python 都是“值传递”，但“值”的内容是：**
>
> * C：基本类型的值 或 指针的值
> * Java/Python：对象引用的值（即指针的拷贝）
