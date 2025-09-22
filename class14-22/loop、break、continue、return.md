# bloop-循环

循环是编程中用于重复执行代码块的基本结构。C++提供了几种强大的循环语句，以满足不同的场景需求。

#### 1. `for`循环

`for`循环是**最常用**的循环之一，特别适用于**循环次数已知**的场景（如遍历数组）。

* **语法结构**：

  <pre class="ybc-pre-component ybc-pre-component_not-math"><div class="hyc-common-markdown__code"><div class="hyc-common-markdown__code__hd"></div><pre class="hyc-common-markdown__code-lan"><div class="hyc-code-scrollbar"><div class="hyc-code-scrollbar__view"><code class="language-cpp">for (初始化; 循环条件; 后续操作) {
      // 循环体
  }</code></div><div class="hyc-code-scrollbar__track"><div class="hyc-code-scrollbar__thumb"></div></div><div><div></div></div></div></pre></div></pre>

  * **初始化**：在循环开始前执行且只执行一次。通常用于声明并初始化一个循环计数器。
  * **循环条件**：在每次循环迭代**前**检查。如果条件为 `true`，则执行循环体；如果为 `false`，则终止循环。
  * **后续操作**：在每次循环体执行**后**执行。通常用于递增或递减循环计数器。
* **代码示例**：

  <pre class="ybc-pre-component ybc-pre-component_not-math"><div class="hyc-common-markdown__code"><div class="hyc-common-markdown__code__hd"></div><pre class="hyc-common-markdown__code-lan"><div class="hyc-code-scrollbar"><div class="hyc-code-scrollbar__view"><code class="language-cpp">// 打印数字 0 到 4
  for (int i = 0; i < 5; i++) {
      std::cout << i << std::endl;
  }</code></div><div class="hyc-code-scrollbar__track"><div class="hyc-code-scrollbar__thumb"></div></div><div><div></div></div></div></pre></div></pre>
* **等价逻辑**：

  幻灯片中展示了 `for`循环在底层可以等价于以下 `while`循环结构，这有助于理解其执行流程：

  <pre class="ybc-pre-component ybc-pre-component_not-math"><div class="hyc-common-markdown__code"><div class="hyc-common-markdown__code__hd"></div><pre class="hyc-common-markdown__code-lan"><div class="hyc-code-scrollbar"><div class="hyc-code-scrollbar__view"><code class="language-cpp">int i = 0;
  bool condition = true;
  for (; condition; ) {
      // 循环体代码...
      i++;
      if (!(i < 5)) {
          condition = false;
      }
  }</code></div><div class="hyc-code-scrollbar__track"><div class="hyc-code-scrollbar__thumb"></div></div><div><div></div></div></div></pre></div></pre>

#### 2. `while`循环

`while`循环在**给定条件为真**时重复执行代码块。它更适用于**循环次数不确定**，只需满足条件即可的场景。

* **语法结构**：

  <pre class="ybc-pre-component ybc-pre-component_not-math"><div class="hyc-common-markdown__code"><div class="hyc-common-markdown__code__hd"></div><pre class="hyc-common-markdown__code-lan"><div class="hyc-code-scrollbar"><div class="hyc-code-scrollbar__view"><code class="language-cpp">while (循环条件) {
      // 循环体
  }</code></div><div class="hyc-code-scrollbar__track"><div class="hyc-code-scrollbar__thumb"></div></div><div><div></div></div></div></pre></div></pre>

  * 循环条件在每次迭代**前**检查。
* **代码示例**：

  <pre class="ybc-pre-component ybc-pre-component_not-math"><div class="hyc-common-markdown__code"><div class="hyc-common-markdown__code__hd"></div><pre class="hyc-common-markdown__code-lan"><div class="hyc-code-scrollbar"><div class="hyc-code-scrollbar__view"><code class="language-cpp">// 假设 i 已提前声明和初始化
  while (i < 5) {
      std::cout << i << std::endl;
      i++; // 循环条件的改变需要在循环体内手动完成
  }</code></div><div class="hyc-code-scrollbar__track"><div class="hyc-code-scrollbar__thumb"></div></div><div><div></div></div></div></pre></div></pre>

#### 3. `do...while`循环

`do...while`循环与 `while`循环类似，但有一个关键区别：它会**先执行一次循环体**，然后再检查条件。这意味着循环体**至少会执行一次**。

* **语法结构**：

  <pre class="ybc-pre-component ybc-pre-component_not-math"><div class="hyc-common-markdown__code"><div class="hyc-common-markdown__code__hd"></div><pre class="hyc-common-markdown__code-lan"><div class="hyc-code-scrollbar"><div class="hyc-code-scrollbar__view"><code class="language-cpp">do {
      // 循环体
  } while (循环条件);</code></div><div class="hyc-code-scrollbar__track"><div class="hyc-code-scrollbar__thumb"></div></div><div><div></div></div></div></pre></div></pre>

  * 循环条件在每次迭代**后**检查。
* **适用场景**：

  适用于需要先执行操作，然后再检查条件的情况。例如，显示一个菜单并等待用户输入，直到用户选择退出。

#### 如何选择循环？

幻灯片提供了清晰的指导原则：

* **使用 `while`循环当**：

  * 你只需要一个条件来控制循环。
  * 不需要在每次循环时都刻意地改变一个计数器（条件的改变可能来自循环体内的其他操作或外部输入）。
  * 循环开始前不需要进行复杂的初始化。
* **使用 `for`循环当**：

  * 你需要**遍历一个大小已知的序列**（如数组、向量）。
  * 需要一个明确的**计数器**或**索引**（`i`）来访问元素。
  * 循环的初始化、条件和递增操作都集中在一个地方，使代码结构更紧凑、更易读。

### 总结对比表


| 循环类型         | 特点                                               | 最佳适用场景                                                   |
| ---------------- | -------------------------------------------------- | -------------------------------------------------------------- |
| **`for`**        | 结构紧凑，将初始化、条件判断和计数器更新集中管理。 | 已知循环次数、遍历数组、需要索引计数器。                       |
| **`while`**      | 只在条件为真时执行循环，条件判断在循环体之前。     | 循环次数不确定，只需满足某个条件（如：等待用户输入特定值）。   |
| **`do...while`** | 先执行循环体，后判断条件；**至少执行一次**。       | 需要至少执行一次，之后再根据条件决定是否继续（如：显示菜单）。 |

希望这份总结能帮助您更好地理解和运用C++中的循环语句！

# 控制语句continue break return



| 语句           | 作用范围                                      | 主要功能                                                                     | 常见用途                                                          |
| -------------- | --------------------------------------------- | ---------------------------------------------------------------------------- | ----------------------------------------------------------------- |
| **`continue`** | **仅能用于循环** (`for`, `while`, `do-while`) | **跳过**当前循环迭代中**剩余的代码**，**立即开始下一次**循环迭代。           | 跳过某些不需要处理的情况，继续检查下一个元素。                    |
| **`break`**    | 主要用于**循环**和 **`switch`** 语句          | **立即终止**它所在的**整个循环**或 `switch`语句，并执行后续代码。            | 在找到所需结果后提前退出循环，或处理完一个`case`后跳出 `switch`。 |
| **`return`**   | **函数**内部                                  | **立即退出当前函数**的执行，并将程序控制权返回给调用者。可以携带一个返回值。 | 函数执行完毕，返回结果；或在发生错误时提前终止函数。              |

---

### 1. `continue`语句

* **功能**：

  * 正如幻灯片所述：“**如果还能迭代的话直接进行下一次迭代，否则结束循环**”。
  * 当在循环体内遇到 `continue`时，它会**跳过本次循环中 `continue`之后的所有代码**，直接进行循环的“后续操作”（对于 `for`循环）或判断“循环条件”（对于 `while`/`do-while`循环），以决定是否开始下一次迭代。
* **代码示例（概念）**：

  <pre class="ybc-pre-component ybc-pre-component_not-math"><div class="hyc-common-markdown__code"><div class="hyc-common-markdown__code__hd"></div><pre class="hyc-common-markdown__code-lan"><div class="hyc-code-scrollbar"><div class="hyc-code-scrollbar__view"><code class="language-cpp">for (int i = 0; i < 10; i++) {
      if (i % 2 == 0) { // 如果是偶数
          continue; // 跳过后续代码，直接执行 i++，然后开始下一次循环
      }
      std::cout << i << " "; // 这行代码在 i 为偶数时会被跳过
  }
  // 输出：1 3 5 7 9</code></div><div class="hyc-code-scrollbar__track"><div class="hyc-code-scrollbar__thumb"></div></div><div><div></div></div></div></pre></div></pre>

### 2. `break`语句

* **功能**：

  * 幻灯片说明：“**跳出循环**”。
  * 当在循环或 `switch`语句中遇到 `break`时，它会**立即终止它所在的最内层循环或 `switch`语句**，程序将继续执行该循环或 `switch`语句之后的代码。
* **代码示例（概念）**：

  <pre class="ybc-pre-component ybc-pre-component_not-math"><div class="hyc-common-markdown__code"><div class="hyc-common-markdown__code__hd"></div><pre class="hyc-common-markdown__code-lan"><div class="hyc-code-scrollbar"><div class="hyc-code-scrollbar__view"><code class="language-cpp">int target = 5;
  for (int i = 0; i < 10; i++) {
      if (i == target) {
          std::cout << "Found it!";
          break; // 找到目标后立即退出整个循环
      }
  }
  // 循环之后的代码会继续执行</code></div><div class="hyc-code-scrollbar__track"><div class="hyc-code-scrollbar__thumb"></div></div><div><div></div></div></div></pre></div></pre>

### 3. `return`语句

* **功能**：

  * 幻灯片说明：“**完全退出函数**”。
  * 这是**最彻底**的退出。一旦执行 `return`，**当前函数将立即终止**，程序控制权返回给调用该函数的地方。
  * 如果函数声明的返回类型不是 `void`，则**必须**返回一个相应类型的值（例如 `return 42;`）。
  * 它不仅可以退出循环，而是退出整个函数。
* **代码示例（概念）**：

  <pre class="ybc-pre-component ybc-pre-component_not-math"><div class="hyc-common-markdown__code"><div class="hyc-common-markdown__code__hd"></div><pre class="hyc-common-markdown__code-lan"><div class="hyc-code-scrollbar"><div class="hyc-code-scrollbar__view"><code class="language-cpp">int findNumber(int[] array, int size, int target) {
      for (int i = 0; i < size; i++) {
          if (array[i] == target) {
              return i; // 1. 找到目标，立即返回其索引并退出整个函数
          }
      }
      return -1; // 2. 未找到目标，返回 -1 并退出函数
  }</code></div><div class="hyc-code-scrollbar__track"><div class="hyc-code-scrollbar__thumb"></div></div><div><div></div></div></div></pre></div></pre>

### 核心区别与记忆技巧


| 特性             | `continue`                       | `break`                          | `return`                       |
| ---------------- | -------------------------------- | -------------------------------- | ------------------------------ |
| **作用层级**     | **循环迭代**级别                 | **循环/switch**级别              | **函数**级别                   |
| **行为比喻**     | **“跳过这个”** (Skip this one) | **“停止循环”** (Stop the loop) | **“结束工作”** (Go back now) |
| **之后执行什么** | 下一次循环迭代                   | 循环体之后的代码                 | 函数调用之后的代码             |

**简单概括**：

* 想**跳过当前这一个**，用 `continue`。
* 想**结束整个这一圈**（循环），用 `break`。
* 想**直接下班回家**（退出整个函数），用 `return`。
