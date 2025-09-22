# 变量

C++中变量的核心区别在于其**类型（Type）**，而类型决定了变量在内存中占用的空间大小（Size）以及可以进行的操作。

---

#### 1. 变量的本质：内存与大小 (Size)

* **核心概念**：变量是一块命名的内存空间。不同类型的变量，其根本区别在于它**占用内存的大小（Size）不同**。
* **单位**：内存的基本单位是字节（Byte），1 Byte = 8 bits。
* **编译器依赖**：数据类型的具体大小（例如 `int`是 4 字节）由 C++ 标准建议，但最终**取决于具体的编译器实现**。这意味着在不同平台或编译器下，类型的大小可能略有差异。

#### 2. 基本数据类型及其大小

以下是幻灯片中提到的常见基本数据类型及其典型大小：


| 数据类型    | 中文含义     | 典型大小 | 说明                                         |
| ----------- | ------------ | -------- | -------------------------------------------- |
| `bool`      | 布尔型       | 1 Byte   | 值为`true`(非0) 或 `false`(0)                |
| `char`      | 字符型       | 1 Byte   | 用于存储单个字符（如 'A'）                   |
| `short`     | 短整型       | 2 Bytes  | -                                            |
| `int`       | 整型         | 4 Bytes  | 存储整数，范围约为 ±21亿                    |
| `long`      | 长整型       | 4 Bytes  | 通常与`int`相同                              |
| `long long` | 长整型       | 8 Bytes  | 存储更大范围的整数                           |
| `float`     | 单精度浮点数 | 4 Bytes  | 存储小数，声明时加`F`或 `f`后缀（如 `8.5F`） |
| `double`    | 双精度浮点数 | 8 Bytes  | 存储小数，精度比`float`更高                  |

#### 3. 有符号 (Signed) 与无符号 (Unsigned)

* 对于整数类型（`char`, `int`, `short`, `long`等），可以指定其为无符号数。
* **有符号 (Signed，默认)**：最高位是符号位，用于表示正负，因此表示的正数范围会减半。例如，4字节的 `int`范围是 **-2,147,483,648 到 2,147,483,647**。
* **无符号 (Unsigned)**：所有位都用于表示数值，因此只能表示非负数（0和正数），但正数范围更大。例如，`unsigned int`的范围是 **0 到 4,294,967,295**。
* **用法**：在变量声明前加上 `unsigned`关键字，如 `unsigned int count;`。

#### 4. 特殊类型详解

* **布尔类型 (bool)**：

  * 仅有两个值：`true`(真) 和 `false`(假)。
  * 在底层，`false`存储为 `0`，`true`存储为 `1`（或任何非零值）。
  * 虽然理论上只需1 bit，但**内存寻址以字节为单位**，因此它占用 **1 Byte**。为了节省空间，可以通过位操作将多个布尔值打包到一个字节中。
* **浮点类型 (float & double)**：

  * 用于存储小数。
  * `float`是单精度浮点数，占用 **4 Bytes**。为了明确指定一个常量为 `float`类型，需要在数字后加 `F`或 `f`后缀（例如 `3.14f`）。
  * `double`是双精度浮点数，占用 **8 Bytes**，具有更高的精度和范围，是默认的浮点数类型。

#### 5. 查看类型大小：`sizeof`操作符

* 可以使用 `sizeof`操作符来查看某个类型或变量在内存中占用的字节数。
* **示例**：

  <pre class="ybc-pre-component ybc-pre-component_not-math"><div class="hyc-common-markdown__code"><div class="hyc-common-markdown__code__hd"></div><pre class="hyc-common-markdown__code-lan"><div class="hyc-code-scrollbar"><div class="hyc-code-scrollbar__view"><code class="language-cpp">std::cout << sizeof(bool) << std::endl;    // 输出 1
  std::cout << sizeof(float) << std::endl;   // 输出 4
  std::cout << sizeof(double) << std::endl;  // 输出 8</code></div><div class="hyc-code-scrollbar__track"><div class="hyc-code-scrollbar__thumb"></div></div><div><div></div></div></div></pre></div></pre>

### 总结与建议

1. **选择类型的原则**：根据你需要存储的数据范围来选择最合适的类型，以避免浪费内存或发生数据溢出。

   * 例如，存储年龄可以使用 `unsigned char`（0-255），存储国家人口数可能需要 `unsigned int`或 `long long`。
2. **默认选择**：

   * 整数用 `int`。
   * 小数用 `double`。
   * 判断条件用 `bool`。
3. **注意兼容性**：由于类型大小可能因编译器而异，在需要精确控制大小（如文件读写、网络通信）时，应使用标准类型如 `std::int32_t`（来自 `<cstdint>`头文件）。

# 函数

#### 1. 函数的定义 (Definition)

* **目的**：**避免代码重复**，将用于完成**特定任务**的代码块封装起来，以便多次调用。
* **基本语法**：

  <pre class="ybc-pre-component ybc-pre-component_not-math"><div class="hyc-common-markdown__code"><div class="hyc-common-markdown__code__hd"></div><pre class="hyc-common-markdown__code-lan"><div class="hyc-code-scrollbar"><div class="hyc-code-scrollbar__view"><code class="language-cpp">return_type function_name(parameter_list) {
      // ... 函数体 (执行任务的代码)
      return value; // 如果返回类型不是void，则必须包含return语句
  }</code></div><div class="hyc-code-scrollbar__track"><div class="hyc-code-scrollbar__thumb"></div></div><div><div></div></div></div></pre></div></pre>
* **关键组成部分**：

  * **返回类型 (Return Type)**：函数执行后返回给调用者的数据类型（如 `int`, `double`, `void`等）。
  * **函数名 (Function Name)**：函数的标识符，用于调用函数。
  * **参数列表 (Parameter List)**：传递给函数的值（可选），用于接收外部输入。
  * **函数体 (Function Body)**：包含实际执行任务的语句。
  * **返回语句 (Return Statement)**：用于结束函数执行并将结果返回给调用者。

#### 2. 函数的调用原理 (调用机制)

幻灯片重点解释了函数调用的底层过程，这关系到程序的性能。

* **栈帧 (Stack Frame)**：每次调用函数时，系统都会在内存的**栈 (Stack)** 区域为其分配一块空间，称为栈帧。
* **调用过程**：

  1. **参数入栈 (Push Parameters)**：将调用函数时传递的实参（arguments）压入栈中。
  2. **保存返回地址 (Save Return Address)**：将当前指令的下一条地址（即调用函数后应该返回的位置）压入栈中。
  3. **跳转 (Jump)**：CPU跳转到被调用函数的代码地址开始执行。
  4. **执行函数体**：执行函数内部的代码。
  5. **返回值与返回 (Return)**：将返回值存入指定寄存器或栈位置，然后根据之前保存的返回地址，跳回调用处继续执行。
  6. **清理栈帧 (Cleanup Stack Frame)**：函数调用结束后，其对应的栈帧被销毁。
* **性能开销 (Performance Overhead)**：

  * 创建和销毁栈帧、跳转指令等操作都需要消耗CPU时间。
  * **结论**：虽然函数提高了代码的清晰度和可维护性，但**频繁调用小型函数可能会带来性能损失**。因此，“不需要每一行都设个函数”，需要在代码结构和性能之间做出权衡。
* **内联函数 (Inline Function)**：

  * 为了解决小型函数调用的开销问题，C++提供了 `inline`关键字。
  * 建议编译器将函数体直接“嵌入”到每一个调用处，从而**避免函数调用的开销**。
  * 注意：`inline`只是一个建议，最终是否内联由编译器决定。

#### 3. 返回值 (Return Value)

这是函数与调用者通信的关键方式之一。

* **必须返回 (Must Return)**：如果一个函数声明了非 `void`的返回类型（如 `int`, `double`），那么**它在所有执行路径上都必须有一条return语句**，返回一个匹配类型的值。
* **main函数的特殊性**：`main`函数是程序的入口点。如果程序员没有写 `return`语句，C++标准规定编译器会自动在 `main`函数末尾插入 `return 0;`（表示程序成功执行）。**这是唯一一个有默认返回值的函数**。
* **调试模式 vs 发布模式 (Debug vs Release)**：

  * **Debug模式**：编译器通常会启用各种检查 flags（编译标记）。如果发现定义了返回值的函数存在某些执行路径没有返回值，**编译器会报错**，这极大地帮助了开发者调试代码。
  * **Release模式**：编译器以优化程序性能为首要目标，会关闭很多检查。如果函数未能返回一个值，**行为是未定义的 (Undefined Behavior)**。这意味着程序可能崩溃、返回一个垃圾值、或者看似“正常”运行。**这是非常危险的情况**。

### 总结与最佳实践

1. **用途**：使用函数来分解复杂问题，提高代码的**可读性、可复用性和可维护性**。
2. **设计原则**：函数应专注于完成**单一、明确的任务**。一个好的函数名应能清晰地反映其功能。
3. **性能意识**：了解函数调用的开销。对于简单的、频繁调用的短小函数，考虑使用 `inline`关键字。
4. **返回值**：
   * 确保所有非 `void`函数在所有可能路径上都有返回值。
   * 始终在 `main`函数中显式地使用 `return`语句是一个好习惯。
   * 牢记 **Release模式下的未定义行为**，务必在Debug模式下解决所有编译器警告。

# 头文件.h

头文件（Header Files）是C++模块化编程的基石，主要用于声明接口，从而实现代码的共享和分离编译。

---

#### 1. 头文件的核心用途 (Purpose)

* **主要作用**：头文件的核心用途是提供**声明**（declarations），如函数原型、类定义、外部变量声明、模板等。
* **实现共享**：通过在不同的源文件（.cpp）中包含（`#include`）同一个头文件，可以确保所有文件使用同一份声明，从而在整个程序中共享代码。
* **链接基础**：这与编译和链接过程紧密相关（可复习图片中提到的 *06 How the C++ Compiler Works*和 *07 How the C++ Linker Works*）。编译器编译每个`.cpp`文件（翻译单元）时，需要看到函数或变量的声明；链接器则根据声明将所有翻译单元中的实现链接在一起。

#### 2. 头文件保护符 (Header Guard) - `#pragma once`

为了防止头文件被多次包含到同一个翻译单元中而引起**重复定义**的错误，必须使用头文件保护符。

* **`#pragma once`**：

  * 这是一种**非标准但被几乎所有现代编译器支持**的预处理指令。
  * **作用**：指令所在的文件在**一个单独的翻译单元中只会被包含一次**。编译器会自动处理，避免了重复包含。
  * **用法**：通常放在头文件的最开头。
  * **优点**：简洁、高效，不易出错。

  <pre class="ybc-pre-component ybc-pre-component_not-math"><div class="hyc-common-markdown__code"><div class="hyc-common-markdown__code__hd"></div><pre class="hyc-common-markdown__code-lan"><div class="hyc-code-scrollbar"><div class="hyc-code-scrollbar__view"><code class="language-cpp">// MyClass.h
  #pragma once // 头文件保护符

  class MyClass {
      // ... 类定义
  };</code></div><div class="hyc-code-scrollbar__track"><div class="hyc-code-scrollbar__thumb"></div></div><div><div></div></div></div></pre></div></pre>

#### 3. 传统的头文件保护符 (Traditional Include Guards) - `#ifndef`/ `#define`/ `#endif`

在 `#pragma once`被广泛支持之前，这是标准的、可移植的方法。

* **`#ifndef`/ `#define`/ `#endif`**：

  * **原理**：利用预处理宏来判断一个唯一的标识符是否已被定义。如果未定义，则定义该宏并包含头文件内容；如果已定义，则跳过整个头文件内容。
  * **用法**：

    <pre class="ybc-pre-component ybc-pre-component_not-math"><div class="hyc-common-markdown__code"><div class="hyc-common-markdown__code__hd"></div><pre class="hyc-common-markdown__code-lan"><div class="hyc-code-scrollbar"><div class="hyc-code-scrollbar__view"><code class="language-cpp">// MyClass.h
    #ifndef MY_CLASS_H // 如果宏MY_CLASS_H未被定义
    #define MY_CLASS_H // 则定义它

    class MyClass {
        // ... 类定义
    };

    #endif // MY_CLASS_H // 结束条件编译</code></div><div class="hyc-code-scrollbar__track"><div class="hyc-code-scrollbar__thumb"></div></div><div><div></div></div></div></pre></div></pre>
  * **特点**：这是**C/C++标准的一部分**，具有最好的可移植性。但需要程序员确保宏名称的唯一性（通常用头文件名全大写加下划线）。

**总结**：现在**`#pragma once`**因其简单性已成为主流选择，但在需要最大限度保证可移植性的项目中，仍会使用传统的 `#ifndef`方式。

#### 4. `#include`指令的补充说明

`#include`用于将指定文件的内容在预处理阶段插入到当前文件中。

* **引号形式 `#include " "`**：

  * **搜索路径**：编译器通常**首先从当前文件所在目录**开始查找头文件。
  * **相对路径**：支持相对路径。例如，`#include "../utils/Helper.h"`会跳转到上一级目录的 `utils`文件夹中查找。
  * **现代编译器**：如图中所述，现在使用引号也可以包含标准库头文件（如 `#include "iostream"`），但**不推荐**这样做，以免造成混淆。
* **尖括号形式 `#include < >`**：

  * **搜索路径**：编译器直接在**预配置的包含目录**中查找，这些目录通常包含标准库和系统头文件。
  * **用途**：用于包含**标准库头文件**或**第三方库的头文件**。
  * **示例**：`#include <iostream>`, `#include <vector>`

#### 5. 为什么C++标准库头文件没有扩展名（如 `.h`）？

* **历史原因与区分**：这是由C++标准委员会决定的，主要目的是为了在源代码层面清晰地区分**C语言标准库头文件**和**C++标准库头文件**。

  * **C标准库头文件**：在C++中兼容，但通常加上`c`前缀并去掉`.h`（如 `#include <cstdio>`对应C的 `#include <stdio.h>`）。
  * **C++标准库头文件**：如 `<iostream>`, `<vector>`, `<string>`等，没有`.h`后缀。
* **例外**：一些旧的、非标准的或编译器特定的头文件可能仍有 `.h`后缀。

### 总结与最佳实践

1. **职责分离**：头文件放**声明**（declarations），源文件（.cpp）放**定义**（definitions）。
2. **必须包含保护**：每个头文件都必须使用 **`#pragma once`** 或传统的 **`#ifndef`保护符**，防止重复包含。
3. **正确使用`#include`**：

   * 包含标准库或第三方库，使用尖括号 `#include <filename>`。
   * 包含自己项目中的头文件，使用引号 `#include "filename.h"`。
4. **命名清晰**：使用描述性的头文件名，并确保传统保护符中的宏名称是全局唯一的。

# visual studio的debug

![](https://pic4.zhimg.com/v2-3553acb7aac6e3aec98fbd38f3202e3b_r.jpg)

# if 条件语句


#### 1. 基本语法与语义

* **基本形式**：

  <pre class="ybc-pre-component ybc-pre-component_not-math"><div class="hyc-common-markdown__code"><div class="hyc-common-markdown__code__hd"></div><pre class="hyc-common-markdown__code-lan"><div class="hyc-code-scrollbar"><div class="hyc-code-scrollbar__view"><code class="language-cpp">if (condition) {
      // 如果 condition 为 true，则执行这里的代码
  }</code></div><div class="hyc-code-scrollbar__track"><div class="hyc-code-scrollbar__thumb"></div></div><div><div></div></div></div></pre></div></pre>
* **`if-else`形式**：

  <pre class="ybc-pre-component ybc-pre-component_not-math"><div class="hyc-common-markdown__code"><div class="hyc-common-markdown__code__hd"></div><pre class="hyc-common-markdown__code-lan"><div class="hyc-code-scrollbar"><div class="hyc-code-scrollbar__view"><code class="language-cpp">if (condition) {
      // 如果 condition 为 true，则执行这里的代码
  } else {
      // 如果 condition 为 false，则执行这里的代码
  }</code></div><div class="hyc-code-scrollbar__track"><div class="hyc-code-scrollbar__thumb"></div></div><div><div></div></div></div></pre></div></pre>
* **`else if`形式**：

  <pre class="ybc-pre-component ybc-pre-component_not-math"><div class="hyc-common-markdown__code"><div class="hyc-common-markdown__code__hd"></div><pre class="hyc-common-markdown__code-lan"><div class="hyc-code-scrollbar"><div class="hyc-code-scrollbar__view"><code class="language-cpp">if (condition1) {
      // ...
  } else if (condition2) { // 这等价于 else { if (condition2) { ... } }
      // 只有当 condition1 为 false，且 condition2 为 true 时执行
  } else {
      // ...
  }</code></div><div class="hyc-code-scrollbar__track"><div class="hyc-code-scrollbar__thumb"></div></div><div><div></div></div></div></pre></div></pre>

  * **关键点**：`else if`并非一个单独的关键字，它只是 `else`和 `if`的连用。它的语义是：**只有在前面的所有 `if`或 `else if`条件都失败时，才会检查下一个条件**。


#### 2. 底层机制：汇编视角（Disassembly）

图片通过反汇编揭示了 `if`语句在CPU层面的执行方式，这是理解其性能的关键。

* **比较操作**：条件中的比较操作（如 `==`, `!=`, `<`, `>`）在汇编中通常对应 `cmp`(compare) 指令。例如，比较两个整数是否相等。
* **条件跳转**：`cmp`指令会设置CPU的标志寄存器（Flags）。紧随其后的是一条**条件跳转指令**（Conditional Jump），它根据标志寄存器的状态决定是否跳转到指定代码地址。

  * **`jne`** (Jump if Not Equal)：不相等时跳转。
  * **`je`** (Jump if Equal)：相等时跳转。
  * 还有其他如 `jg`(大于), `jl`(小于) 等。
* **性能开销**：`if`语句带来的主要开销就是**分支预测失败**。现代CPU会预测条件跳转的方向以提前执行代码。如果预测错误，就需要清空流水线，导致性能下降。因此，编写可预测的条件逻辑对性能有益。


#### 3. 编译器优化：常数折叠 (Constant Folding)

编译器会在编译阶段进行优化，直接影响 `if`语句的生成。

* **什么是常数折叠**？编译器会在编译时预先计算表达式中常量部分的值，并用结果替换该表达式。
* **对 `if`的影响**：如果 `if`的条件在编译时就能被确定（例如 `if (5 == 5)`或 `if (false)`），编译器会直接进行优化。

  * 对于永远为 `true`的条件，编译器会**删除整个 `if`判断**，直接保留其内部的代码。
  * 对于永远为 `false`的条件，编译器会**删除整个 `if`语句块**（包括条件和内部的代码）。
* **调试注意**：如图片所述，这种优化在 **Debug 模式** 下通常被禁用，以便于程序员调试。在 **Release 模式** 下则会积极进行，这也是 Release 版本运行更快的原因之一。

#### 4. 最佳实践与总结

1. **逻辑清晰**：`if-else if-else`链提供了一种清晰的多分支逻辑处理方式。确保条件的顺序符合你的业务逻辑。
2. **性能意识**：

   * 将**最可能为真**的条件放在前面，有助于CPU分支预测，提高效率。
   * 在极度注重性能的热点代码中，有时可以用**位运算**等技巧来避免分支判断（正如图片末尾所述：“用某些运算来代替比较和分支”）。
3. **拥抱优化**：信任编译器的优化能力。写出语义清晰、正确的代码，编译器会为你处理很多底层优化（如常数折叠）。
4. **调试技巧**：在 Debug 模式下，可以通过 IDE 的 **反汇编窗口** 观察 `if`语句对应的底层汇编指令，加深对程序运行机制的理解。
