# C++ 中的计时（Timing / Timer）说明与总结


## 一、为什么要进行计时？

在性能分析、游戏开发、算法优化等场景中，我们经常需要知道某段代码执行了多久。例如：

* 这个排序算法用了多少毫秒？
* 渲染一帧花了多长时间？
* 网络请求是否超时？

C++ 提供了高精度的计时工具 —— `std::chrono` 库（C++11 引入），它是现代 C++ 推荐的标准方式。


## 二、核心组件：`std::chrono`

头文件：`#include <chrono>`

主要三大概念：


| 组件             | 说明                                                              |
| ---------------- | ----------------------------------------------------------------- |
| **`time_point`** | 时间轴上的一个点（如“程序开始时刻”）                            |
| **`duration`**   | 两个时间点之间的间隔（如“耗时 5.2 秒”）                         |
| **`clock`**      | 时钟源，提供当前时间（如`steady_clock`, `high_resolution_clock`） |


## 三、常用时钟类型


| 时钟                                 | 是否推荐                         | 特点                                             |
| ------------------------------------ | -------------------------------- | ------------------------------------------------ |
| `std::chrono::steady_clock`          | ✅**强烈推荐**                   | 单调递增，不受系统时间调整影响，适合测量时间间隔 |
| `std::chrono::high_resolution_clock` | ⚠️ 可能是`steady_clock` 的别名 | 最高分辨率，但某些平台可能不稳                   |
| `std::chrono::system_clock`          | ❌ 不推荐用于性能测试            | 表示真实世界时间，可被用户修改                   |

> 🔔 **结论：优先使用 `std::chrono::steady_clock`**
>


## 四、基本用法流程

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>auto</span><span> start = </span><span>std</span><span>::chrono::steady_clock::now(); </span><span>// 记录起始时间点</span><span>
</span>
<span></span><span>// --- 要测量的代码 ---</span><span>
</span>some_function();

<span></span><span>auto</span><span> end = </span><span>std</span><span>::chrono::steady_clock::now();   </span><span>// 记录结束时间点</span><span>
</span>
<span></span><span>// 计算耗时（duration）</span><span>
</span><span></span><span>auto</span><span> duration = end - start;
</span>
<span></span><span>// 转换为具体单位（微秒、毫秒等）</span><span>
</span><span></span><span>auto</span><span> microseconds = </span><span>std</span><span>::chrono::duration_cast<</span><span>std</span><span>::chrono::microseconds>(duration);
</span><span></span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"耗时: "</span><span> << microseconds.count() << </span><span>" 微秒\n"</span><span>;</span></code></pre></div></div></pre>


## 五、可运行完整代码示例

<pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">cpp</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>#</span>include<span> </span><iostream><span>
</span><span></span><span>#</span>include<span> </span><chrono><span>
</span><span></span><span>#</span>include<span> </span><thread><span>
</span><span></span><span>#</span>include<span> </span><vector><span>
</span><span></span><span>#</span>include<span> </span><algorithm><span>
</span><span></span><span>#</span>include<span> </span><random><span>
</span>
<span></span><span>// 工具函数：打印持续时间</span><span>
</span><span></span>template<typename T>
void print_duration(const T& dur, const std::string& unit) <span>{
</span><span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"耗时: "</span><span> << dur.count() << </span><span>" "</span><span> << unit << </span><span>"\n"</span><span>;
</span>}

<span></span><span>// 模拟一个耗时操作</span><span>
</span><span></span>void heavy_computation(int n) <span>{
</span><span>    </span>std::vector<int> data(n)<span>;
</span><span>    </span><span>std</span><span>::random_device rd;
</span><span>    </span>std::mt19937 gen(rd())<span>;
</span><span>    </span><span>std</span><span>::uniform_int_distribution<> dis(</span>1<span>, </span>1000<span>);
</span>
<span>    </span><span>for</span><span> (</span><span>int</span><span> i = </span>0<span>; i < n; ++i) {
</span>        data[i] = dis(gen);
    }

<span>    </span><span>// 排序</span><span>
</span><span>    </span><span>std</span><span>::sort(data.begin(), data.end());
</span>
<span>    </span><span>// 简单处理</span><span>
</span><span>    </span><span>volatile</span><span> </span><span>long</span><span> sum = </span>0<span>; </span><span>// volatile 防止被编译器优化掉</span><span>
</span><span>    </span><span>for</span><span> (</span><span>int</span><span> x : data) {
</span>        sum += x * x;
    }
}

<span></span>int main() <span>{
</span><span>    </span><span>using</span><span> </span><span>namespace</span><span> </span><span>std</span><span>::chrono;
</span>
<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"=== C++ 计时演示 ===\n\n"</span><span>;
</span>
<span>    </span><span>// -----------------------------</span><span>
</span><span>    </span><span>// 示例 1：测量函数执行时间</span><span>
</span><span>    </span><span>// -----------------------------</span><span>
</span><span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"1. 测量 heavy_computation(100000) 的执行时间\n"</span><span>;
</span><span>    </span><span>auto</span><span> start = steady_clock::now();
</span>
<span>    heavy_computation(</span>100000<span>);
</span>
<span>    </span><span>auto</span><span> end = steady_clock::now();
</span><span>    </span><span>auto</span><span> duration = end - start;
</span>
<span>    </span><span>// 分别以不同单位输出</span><span>
</span><span>    print_duration(duration, </span><span>"纳秒"</span><span>);
</span><span>    print_duration(duration_cast<microseconds>(duration), </span><span>"微秒"</span><span>);
</span><span>    print_duration(duration_cast<milliseconds>(duration), </span><span>"毫秒"</span><span>);
</span><span>    print_duration(duration_cast<seconds>(duration), </span><span>"秒"</span><span>);
</span>
<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"\n"</span><span>;
</span>
<span>    </span><span>// -----------------------------</span><span>
</span><span>    </span><span>// 示例 2：手动实现一个简单的 Timer 类</span><span>
</span><span>    </span><span>// -----------------------------</span><span>
</span><span>    </span>struct Timer {<span>
</span><span>        </span><span>using</span><span> </span><span>clock_t</span><span> = steady_clock;
</span><span>        </span><span>using</span><span> microseconds = </span><span>std</span><span>::chrono::microseconds;
</span>
<span>        Timer() : start_(</span><span>clock_t</span><span>::now()) {}
</span>
<span>        </span>void reset() <span>{
</span><span>            start_ = </span><span>clock_t</span><span>::now();
</span>        }

<span>        </span>int64_t elapsed_microseconds() const <span>{
</span><span>            </span><span>return</span><span> duration_cast<microseconds>(</span><span>clock_t</span><span>::now() - start_).count();
</span>        }

<span>        </span>double elapsed_milliseconds() const <span>{
</span><span>            </span><span>return</span><span> elapsed_microseconds() / </span>1000.0<span>;
</span>        }

<span>        </span>double elapsed_seconds() const <span>{
</span><span>            </span><span>return</span><span> elapsed_microseconds() / </span>1'000'000.0<span>;
</span>        }

<span>    </span><span>private</span><span>:
</span><span>        time_point<</span><span>clock_t</span><span>> start_;
</span>    };

<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"2. 使用 Timer 类测量 sleep_for(100ms)\n"</span><span>;
</span>    Timer timer;
<span>    </span><span>std</span><span>::this_thread::sleep_for(</span><span>std</span><span>::chrono::milliseconds(</span>100<span>));
</span><span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"实际睡眠约: "</span><span> << timer.elapsed_milliseconds() << </span><span>" 毫秒\n\n"</span><span>;
</span>
<span>    </span><span>// -----------------------------</span><span>
</span><span>    </span><span>// 示例 3：测量多次运行的平均时间</span><span>
</span><span>    </span><span>// -----------------------------</span><span>
</span><span>    </span><span>const</span><span> </span><span>int</span><span> runs = </span>5<span>;
</span><span>    </span><span>std</span><span>::</span><span>vector</span><span><</span><span>int64_t</span><span>> times;
</span>    Timer avg_timer;

<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"3. 测量 "</span><span> << runs << </span><span>" 次 heavy_computation(50000) 的平均耗时\n"</span><span>;
</span>
<span>    </span><span>for</span><span> (</span><span>int</span><span> i = </span>0<span>; i < runs; ++i) {
</span>        avg_timer.reset();
<span>        heavy_computation(</span>50000<span>);
</span>        times.push_back(avg_timer.elapsed_microseconds());
    }

<span>    </span><span>int64_t</span><span> total = </span>0<span>;
</span><span>    </span><span>for</span><span> (</span><span>auto</span><span> t : times) {
</span><span>        </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"第"</span><span> << (i+</span>1<span>) << </span><span>"次: "</span><span> << t << </span><span>" 微秒\n"</span><span>;
</span>        total += t;
    }
<span>    </span><span>std</span><span>::</span><span>cout</span><span> << </span><span>"平均耗时: "</span><span> << (total / runs) << </span><span>" 微秒 ("</span><span> 
</span><span>              << (total / runs) / </span>1000.0<span> << </span><span>" 毫秒)\n"</span><span>;
</span>
<span>    </span><span>return</span><span> </span>0<span>;
</span>}</code></pre></div></div></pre>


## 八、最佳实践建议


| 建议                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| ✅ 使用`steady_clock`         | 它不会倒退或跳变，适合做性能测量     |
| ✅ 用`duration_cast` 转换单位 | 显式控制精度                         |
| ✅ 多次测量取平均             | 单次测量受系统调度影响大             |
| ✅ 避免测量太短的操作         | 建议至少 >1ms，否则误差大            |
| ✅ 不要忘记`volatile`         | 防止编译器把“无副作用”的循环优化掉 |
| ✅ 在 Release 模式下测试      | Debug 模式性能失真                   |


## 十、总结


| 特性           | 说明                              |
| -------------- | --------------------------------- |
| **标准库支持** | `#include <chrono>`，无需第三方库 |
| **高精度**     | 支持纳秒级计时（取决于硬件）      |
| **类型安全**   | 不同单位不能直接比较，避免错误    |
| **易于封装**   | 可轻松写出`Timer` 类自动计算耗时  |
| **跨平台**     | 所有现代编译器都支持              |

> 💡 **给 Python 工程师的类比**：
>
> <pre><div class="contain-layout-style rounded-12 bg-capsule relative flex min-h-[2em] flex-col"><div class="rounded-[12px] bg-[#fff]"><div class="h-[42px] sticky top-0 z-10 bg-capsule"><div class="flex items-center h-[42px] p-3 text-[14px] border border-[var(--ty-line-border)]"><span class="font-medium mr-auto first-letter:uppercase text-[rgba(17,17,51,0.7)]">python</span><div class="flex items-center gap-4"><div class="flex items-center justify-center gap-[2px] cursor-pointer text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon size-4 cursor-pointer"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-editingTools-line"></use></svg></span><span class="mt-[2px] text-[12px]">编辑</span></div><div class="flex cursor-pointer gap-1 text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><span role="img" class="anticon"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-sun-line"></use></svg></span></div><span role="img" tabindex="-1" class="anticon flex cursor-pointer items-center text-[rgba(17,17,51,0.7)] hover:text-[#4433ff]"><svg width="1em" height="1em" fill="currentColor" aria-hidden="true" focusable="false" class=""><use xlink:href="#appicon-copy-line"></use></svg></span></div></div></div><pre><code><span>import</span><span> time
> </span>
> <span>start = time.perf_counter()  </span><span># 对应 std::chrono::steady_clock::now()</span><span>
> </span><span></span><span># ... code ...</span><span>
> </span>end = time.perf_counter()
> <span></span><span>print</span><span>(</span><span>f"耗时: </span>{end - start:.6f}<span> 秒"</span><span>)</span></code></pre></div></div></pre>
>
> `std::chrono` 就是 C++ 版的 `time.perf_counter()`，但更强大、更类型安全。
>
