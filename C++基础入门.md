# C++基础入门

## 1 C++初识

### 1.1  第一个C++程序

编写一个C++程序总共分为4个步骤

* 创建项目
* 创建文件
* 编写代码
* 运行程序

#### 1.1.1 创建项目

​	Visual Studio是我们用来编写C++程序的主要工具，我们先将它打开

![1541383178746](assets/1541383178746.png)



![1541384366413](assets/1541384366413.png)

#### 1.1.2 创建文件

右键源文件，选择添加->新建项

![1541383817248](assets/1541383817248.png)

给C++文件起个名称，然后点击添加即可。

![1541384140042](assets/1541384140042.png)



#### 1.1.3 编写代码

```c++
#include<iostream>
using namespace std;

int main() {

	cout << "Hello world" << endl;

	system("pause");

	return 0;
}
```

#### 1.1.4 运行程序

![1541384818688](assets/1541384818688.png)













### 1.2 注释

**作用**：在代码中加一些说明和解释，方便自己或其他程序员程序员阅读代码

**两种格式**

1. **单行注释**：`// 描述信息` 
   - 通常放在一行代码的上方，或者一条语句的末尾，==对该行代码说明==
2. **多行注释**： `/* 描述信息 */`
   - 通常放在一段代码的上方，==对该段代码做整体说明==

> 提示：编译器在编译代码时，会忽略注释的内容

**ctrl + K + C可以直接注释多行代码**









### 1.3 变量

**作用**：给一段指定的内存空间起名，方便操作这段内存

**语法**：`数据类型 变量名 = 初始值;`

**示例：**

```C++
#include<iostream>
using namespace std;

int main() {

	//变量的定义
	//语法：数据类型  变量名 = 初始值

	int a = 10;

	cout << "a = " << a << endl;
	
	system("pause");

	return 0;
}
```



> 注意：C++在创建变量时，必须给变量一个初始值，否则会报错















### 1.4  常量

**作用**：用于记录程序中不可更改的数据

C++定义常量两种方式

1. **\#define** 宏常量： `#define 常量名 常量值`
   * ==通常在文件上方定义==，表示一个常量


2. **const**修饰的变量 `const 数据类型 常量名 = 常量值`
   * ==通常在变量定义前加关键字const==，修饰该变量为常量，不可修改



**示例：**

```C++
//1、宏常量
#define day 7

int main() {

	cout << "一周里总共有 " << day << " 天" << endl;
	//day = 8;  //报错，宏常量不可以修改

	//2、const修饰变量
	const int month = 12;
	cout << "一年里总共有 " << month << " 个月份" << endl;
	//month = 24; //报错，常量是不可以修改的
	
	
	system("pause");

	return 0;
}
```










### 1.5 关键字

**作用：**关键字是C++中预先保留的单词（标识符）

* **在定义变量或者常量时候，不要用关键字**



C++关键字如下：

| asm        | do           | if               | return      | typedef  |
| ---------- | ------------ | ---------------- | ----------- | -------- |
| auto       | double       | inline           | short       | typeid   |
| bool       | dynamic_cast | int              | signed      | typename |
| break      | else         | long             | sizeof      | union    |
| case       | enum         | mutable          | static      | unsigned |
| catch      | explicit     | namespace        | static_cast | using    |
| char       | export       | new              | struct      | virtual  |
| class      | extern       | operator         | switch      | void     |
| const      | false        | private          | template    | volatile |
| const_cast | float        | protected        | this        | wchar_t  |
| continue   | for          | public           | throw       | while    |
| default    | friend       | register         | true        |          |
| delete     | goto         | reinterpret_cast | try         |          |

`提示：在给变量或者常量起名称时候，不要用C++得关键字，否则会产生歧义。`











### 1.6 标识符命名规则

**作用**：C++规定给标识符（变量、常量）命名时，有一套自己的规则

* 标识符不能是关键字
* 标识符只能由字母、数字、下划线组成
* 第一个字符必须为字母或下划线
* 标识符中字母区分大小写

> 建议：给标识符命名时，争取做到见名知意的效果，方便自己和他人的阅读















## 2 数据类型

C++规定在创建一个变量或者常量时，必须要指定出相应的数据类型，否则无法给变量分配内存

### 2.1 整型

**作用**：整型变量表示的是==整数类型==的数据

C++中能够表示整型的类型有以下几种方式，**区别在于所占内存空间不同**：

| **数据类型**        | **占用空间**                                    | 取值范围         |
| ------------------- | ----------------------------------------------- | ---------------- |
| short(短整型)       | 2字节                                           | (-2^15 ~ 2^15-1) |
| int(整型)           | 4字节                                           | (-2^31 ~ 2^31-1) |
| long(长整形)        | Windows为4字节，Linux为4字节(32位)，8字节(64位) | (-2^31 ~ 2^31-1) |
| long long(长长整形) | 8字节                                           | (-2^63 ~ 2^63-1) |













### 2.2 sizeof关键字

**作用：**利用sizeof关键字可以==统计数据类型所占内存大小==

**语法：** `sizeof( 数据类型 / 变量)`

**示例：**

```C++
int main() {

	cout << "short 类型所占内存空间为： " << sizeof(short) << endl;

	cout << "int 类型所占内存空间为： " << sizeof(int) << endl;

	cout << "long 类型所占内存空间为： " << sizeof(long) << endl;

	cout << "long long 类型所占内存空间为： " << sizeof(long long) << endl;

	system("pause");

	return 0;
}
```

> **整型结论**：==short < int <= long <= long long==















### 2.3 实型（浮点型）

**作用**：用于==表示小数==

浮点型变量分为两种：

1. 单精度float 
2. 双精度double

两者的**区别**在于表示的有效数字范围不同。

| **数据类型** | **占用空间** | **有效数字范围** |
| ------------ | ------------ | ---------------- |
| float        | 4字节        | 7位有效数字      |
| double       | 8字节        | 15～16位有效数字 |

**示例：**

```C++
int main() {

	float f1 = 3.14f;
	double d1 = 3.14;

	cout << f1 << endl;
	cout << d1<< endl;

	cout << "float  sizeof = " << sizeof(f1) << endl;
	cout << "double sizeof = " << sizeof(d1) << endl;

	//科学计数法
	float f2 = 3e2; // 3 * 10 ^ 2 
	cout << "f2 = " << f2 << endl;

	float f3 = 3e-2;  // 3 * 0.1 ^ 2
	cout << "f3 = " << f3 << endl;

	system("pause");

	return 0;
}
```











### 2.4 字符型

**作用：**字符型变量用于显示单个字符

**语法：**`char ch = 'a';`



> 注意1：在显示字符型变量时，用单引号将字符括起来，不要用双引号

> 注意2：单引号内只能有一个字符，不可以是字符串



- C和C++中字符型变量只占用==1个字节==。
- 字符型变量并不是把字符本身放到内存中存储，而是将对应的ASCII编码放入到存储单元



示例：

```C++
int main() {
	
	char ch = 'a';
	cout << ch << endl;
	cout << sizeof(char) << endl;

	//ch = "abcde"; //错误，不可以用双引号
	//ch = 'abcde'; //错误，单引号内只能引用一个字符

	cout << (int)ch << endl;  //查看字符a对应的ASCII码
	ch = 97; //可以直接用ASCII给字符型变量赋值
	cout << ch << endl;

	system("pause");

	return 0;
}
```

ASCII码表格：

| **ASCII**值 | **控制字符** | **ASCII**值 | **字符** | **ASCII**值 | **字符** | **ASCII**值 | **字符** |
| ----------- | ------------ | ----------- | -------- | ----------- | -------- | ----------- | -------- |
| 0           | NUT          | 32          | (space)  | 64          | @        | 96          | 、       |
| 1           | SOH          | 33          | !        | 65          | A        | 97          | a        |
| 2           | STX          | 34          | "        | 66          | B        | 98          | b        |
| 3           | ETX          | 35          | #        | 67          | C        | 99          | c        |
| 4           | EOT          | 36          | $        | 68          | D        | 100         | d        |
| 5           | ENQ          | 37          | %        | 69          | E        | 101         | e        |
| 6           | ACK          | 38          | &        | 70          | F        | 102         | f        |
| 7           | BEL          | 39          | ,        | 71          | G        | 103         | g        |
| 8           | BS           | 40          | (        | 72          | H        | 104         | h        |
| 9           | HT           | 41          | )        | 73          | I        | 105         | i        |
| 10          | LF           | 42          | *        | 74          | J        | 106         | j        |
| 11          | VT           | 43          | +        | 75          | K        | 107         | k        |
| 12          | FF           | 44          | ,        | 76          | L        | 108         | l        |
| 13          | CR           | 45          | -        | 77          | M        | 109         | m        |
| 14          | SO           | 46          | .        | 78          | N        | 110         | n        |
| 15          | SI           | 47          | /        | 79          | O        | 111         | o        |
| 16          | DLE          | 48          | 0        | 80          | P        | 112         | p        |
| 17          | DCI          | 49          | 1        | 81          | Q        | 113         | q        |
| 18          | DC2          | 50          | 2        | 82          | R        | 114         | r        |
| 19          | DC3          | 51          | 3        | 83          | S        | 115         | s        |
| 20          | DC4          | 52          | 4        | 84          | T        | 116         | t        |
| 21          | NAK          | 53          | 5        | 85          | U        | 117         | u        |
| 22          | SYN          | 54          | 6        | 86          | V        | 118         | v        |
| 23          | TB           | 55          | 7        | 87          | W        | 119         | w        |
| 24          | CAN          | 56          | 8        | 88          | X        | 120         | x        |
| 25          | EM           | 57          | 9        | 89          | Y        | 121         | y        |
| 26          | SUB          | 58          | :        | 90          | Z        | 122         | z        |
| 27          | ESC          | 59          | ;        | 91          | [        | 123         | {        |
| 28          | FS           | 60          | <        | 92          | /        | 124         | \|       |
| 29          | GS           | 61          | =        | 93          | ]        | 125         | }        |
| 30          | RS           | 62          | >        | 94          | ^        | 126         | `        |
| 31          | US           | 63          | ?        | 95          | _        | 127         | DEL      |

ASCII 码大致由以下**两部分组**成：

* ASCII 非打印控制字符： ASCII 表上的数字 **0-31** 分配给了控制字符，用于控制像打印机等一些外围设备。
* ASCII 打印字符：数字 **32-126** 分配给了能在键盘上找到的字符，当查看或打印文档时就会出现。













### 2.5 转义字符

**作用：**用于表示一些==不能显示出来的ASCII字符==

现阶段我们常用的转义字符有：` \n  \\  \t`

| **转义字符** | **含义**                                | **ASCII**码值（十进制） |
| ------------ | --------------------------------------- | ----------------------- |
| \a           | 警报                                    | 007                     |
| \b           | 退格(BS) ，将当前位置移到前一列         | 008                     |
| \f           | 换页(FF)，将当前位置移到下页开头        | 012                     |
| **\n**       | **换行(LF) ，将当前位置移到下一行开头** | **010**                 |
| \r           | 回车(CR) ，将当前位置移到本行开头       | 013                     |
| **\t**       | **水平制表(HT)  （跳到下一个TAB位置）** | **009**                 |
| \v           | 垂直制表(VT)                            | 011                     |
| **\\\\**     | **代表一个反斜线字符"\"**               | **092**                 |
| \'           | 代表一个单引号（撇号）字符              | 039                     |
| \"           | 代表一个双引号字符                      | 034                     |
| \?           | 代表一个问号                            | 063                     |
| \0           | 数字0                                   | 000                     |
| \ddd         | 8进制转义字符，d范围0~7                 | 3位8进制                |
| \xhh         | 16进制转义字符，h范围0~9，a~f，A~F      | 3位16进制               |

示例：

```C++
int main() {
	
	
	cout << "\\" << endl;
	cout << "\tHello" << endl;
	cout << "\n" << endl;

	system("pause");

	return 0;
}
```













### 2.6 字符串型

**作用**：用于表示一串字符

**两种风格**

1. **C风格字符串**： `char 变量名[] = "字符串值"`

   示例：

   ```C++
   int main() {
   
   	char str1[] = "hello world";
   	cout << str1 << endl;
       
   	system("pause");
   
   	return 0;
   }
   ```

> 注意：C风格的字符串要用双引号括起来

1. **C++风格字符串**：  `string  变量名 = "字符串值"`

   示例：

   ```C++
   int main() {
   
   	string str = "hello world";
   	cout << str << endl;
   	
   	system("pause");
   
   	return 0;
   }
   ```

   

> 注意：C++风格字符串，需要加入头文件==#include\<string>==

### 2.7 布尔类型 bool

**作用：**布尔数据类型代表真或假的值 

bool类型只有两个值：

* true  --- 真（本质是1）
* false --- 假（本质是0）

**bool类型占==1个字节==大小**

示例：

```C++
int main() {

	bool flag = true;
	cout << flag << endl; // 1

	flag = false;
	cout << flag << endl; // 0

	cout << "size of bool = " << sizeof(bool) << endl; //1
	
	system("pause");

	return 0;
}
```

- 布尔数据类型只要不为0都为真

### 2.8 数据的输入

**作用：用于从键盘获取数据**

**关键字：**cin

**语法：** `cin >> 变量 `

示例：

```C++
int main(){

	//整型输入
	int a = 0;
	cout << "请输入整型变量：" << endl;
	cin >> a;
	cout << a << endl;

	//浮点型输入
	double d = 0;
	cout << "请输入浮点型变量：" << endl;
	cin >> d;
	cout << d << endl;

	//字符型输入
	char ch = 0;
	cout << "请输入字符型变量：" << endl;
	cin >> ch;
	cout << ch << endl;

	//字符串型输入
	string str;
	cout << "请输入字符串型变量：" << endl;
	cin >> str;
	cout << str << endl;

	//布尔类型输入
	bool flag = true;
	cout << "请输入布尔型变量：" << endl;
	cin >> flag;
	cout << flag << endl;
	system("pause");
	return EXIT_SUCCESS;
}
```













## 3 运算符

**作用：**用于执行代码的运算

本章我们主要讲解以下几类运算符：

| **运算符类型** | **作用**                               |
| -------------- | -------------------------------------- |
| 算术运算符     | 用于处理四则运算                       |
| 赋值运算符     | 用于将表达式的值赋给变量               |
| 比较运算符     | 用于表达式的比较，并返回一个真值或假值 |
| 逻辑运算符     | 用于根据表达式的值返回真值或假值       |

### 3.1 算术运算符

**作用**：用于处理四则运算 

算术运算符包括以下符号：

| **运算符** | **术语**   | **示例**    | **结果**  |
| ---------- | ---------- | ----------- | --------- |
| +          | 正号       | +3          | 3         |
| -          | 负号       | -3          | -3        |
| +          | 加         | 10 + 5      | 15        |
| -          | 减         | 10 - 5      | 5         |
| *          | 乘         | 10 * 5      | 50        |
| /          | 除         | 10 / 5      | 2         |
| %          | 取模(取余) | 10 % 3      | 1         |
| ++         | 前置递增   | a=2; b=++a; | a=3; b=3; |
| ++         | 后置递增   | a=2; b=a++; | a=3; b=2; |
| --         | 前置递减   | a=2; b=--a; | a=1; b=1; |
| --         | 后置递减   | a=2; b=a--; | a=1; b=2; |

**示例1：**

```C++
//加减乘除
int main() {

	int a1 = 10;
	int b1 = 3;

	cout << a1 + b1 << endl;
	cout << a1 - b1 << endl;
	cout << a1 * b1 << endl;
	cout << a1 / b1 << endl;  //两个整数相除结果依然是整数，会将小数部分去除掉

	int a2 = 10;
	int b2 = 20;
	cout << a2 / b2 << endl; 

	int a3 = 10;
	int b3 = 0;
	//cout << a3 / b3 << endl; //报错，除数不可以为0


	//两个小数可以相除
	double d1 = 0.5;
	double d2 = 0.25;
	cout << d1 / d2 << endl;

	system("pause");

	return 0;
}
```

> 总结：在除法运算中，除数不能为0





**示例2：**

```C++
//取模
int main() {

	int a1 = 10;
	int b1 = 3;

	cout << 10 % 3 << endl;

	int a2 = 10;
	int b2 = 20;

	cout << a2 % b2 << endl;

	int a3 = 10;
	int b3 = 0;

	//cout << a3 % b3 << endl; //取模运算时，除数也不能为0

	//两个小数不可以取模
	double d1 = 3.14;
	double d2 = 1.1;

	//cout << d1 % d2 << endl;

	system("pause");

	return 0;
}

```

> 总结：只有整型变量可以进行取模运算，取模运算是基于除法运算的，所以除数为0



**示例3：**

```C++
//递增
int main() {

	//后置递增
	int a = 10;
	a++; //等价于a = a + 1
	cout << a << endl; // 11

	//前置递增
	int b = 10;
	++b;
	cout << b << endl; // 11

	//区别
	//前置递增先对变量进行++，再计算表达式
	int a2 = 10;
	int b2 = ++a2 * 10;
	cout << b2 << endl;

	//后置递增先计算表达式，后对变量进行++
	int a3 = 10;
	int b3 = a3++ * 10;
	cout << b3 << endl;

	system("pause");

	return 0;
}

```



> 总结：前置递增先对变量进行++，再计算表达式，后置递增相反









### 3.2 赋值运算符

**作用：**用于将表达式的值赋给变量

赋值运算符包括以下几个符号：

| **运算符** | **术语** | **示例**   | **结果**  |
| ---------- | -------- | ---------- | --------- |
| =          | 赋值     | a=2; b=3;  | a=2; b=3; |
| +=         | 加等于   | a=0; a+=2; | a=2;      |
| -=         | 减等于   | a=5; a-=3; | a=2;      |
| *=         | 乘等于   | a=2; a*=2; | a=4;      |
| /=         | 除等于   | a=4; a/=2; | a=2;      |
| %=         | 模等于   | a=3; a%2;  | a=1;      |



**示例：**

```C++
int main() {

	//赋值运算符

	// =
	int a = 10;
	a = 100;
	cout << "a = " << a << endl;

	// +=
	a = 10;
	a += 2; // a = a + 2;
	cout << "a = " << a << endl;

	// -=
	a = 10;
	a -= 2; // a = a - 2
	cout << "a = " << a << endl;

	// *=
	a = 10;
	a *= 2; // a = a * 2
	cout << "a = " << a << endl;

	// /=
	a = 10;
	a /= 2;  // a = a / 2;
	cout << "a = " << a << endl;

	// %=
	a = 10;
	a %= 2;  // a = a % 2;
	cout << "a = " << a << endl;

	system("pause");

	return 0;
}
```









### 3.3 比较运算符

**作用：**用于表达式的比较，并返回一个真值或假值

比较运算符有以下符号：

| **运算符** | **术语** | **示例** | **结果** |
| ---------- | -------- | -------- | -------- |
| ==         | 相等于   | 4 == 3   | 0        |
| !=         | 不等于   | 4 != 3   | 1        |
| <          | 小于     | 4 < 3    | 0        |
| \>         | 大于     | 4 > 3    | 1        |
| <=         | 小于等于 | 4 <= 3   | 0        |
| \>=        | 大于等于 | 4 >= 1   | 1        |

示例：

```C++
int main() {

	int a = 10;
	int b = 20;

	cout << (a == b) << endl; // 0 //括号的使用保证了运算的优先级

	cout << (a != b) << endl; // 1

	cout << (a > b) << endl; // 0

	cout << (a < b) << endl; // 1

	cout << (a >= b) << endl; // 0

	cout << (a <= b) << endl; // 1
	
	system("pause");

	return 0;
}
```



> 注意：C和C++ 语言的比较运算中， ==“真”用数字“1”来表示， “假”用数字“0”来表示。== 













### 3.4 逻辑运算符

**作用：**用于根据表达式的值返回真值或假值

逻辑运算符有以下符号：

| **运算符** | **术语** | **示例** | **结果**                                                 |
| ---------- | -------- | -------- | -------------------------------------------------------- |
| !          | 非       | !a       | 如果a为假，则!a为真；  如果a为真，则!a为假。             |
| &&         | 与       | a && b   | 如果a和b都为真，则结果为真，否则为假。                   |
| \|\|       | 或       | a \|\| b | 如果a和b有一个为真，则结果为真，二者都为假时，结果为假。 |

**示例1：**逻辑非

```C++
//逻辑运算符  --- 非
int main() {

	int a = 10;

	cout << !a << endl; // 0

	cout << !!a << endl; // 1

	system("pause");

	return 0;
}
```

> 总结： 真变假，假变真





**示例2：**逻辑与

```C++
//逻辑运算符  --- 与
int main() {

	int a = 10;
	int b = 10;

	cout << (a && b) << endl;// 1

	a = 10;
	b = 0;

	cout << (a && b) << endl;// 0 

	a = 0;
	b = 0;

	cout << (a && b) << endl;// 0

	system("pause");

	return 0;
}

```

> 总结：逻辑==与==运算符总结： ==同真为真，其余为假==







**示例3：**逻辑或

```c++
//逻辑运算符  --- 或
int main() {

	int a = 10;
	int b = 10;

	cout << (a || b) << endl;// 1

	a = 10;
	b = 0;

	cout << (a || b) << endl;// 1 

	a = 0;
	b = 0;

	cout << (a || b) << endl;// 0

	system("pause");

	return 0;
}
```

> 逻辑==或==运算符总结： ==同假为假，其余为真==

















## 4 程序流程结构

C/C++支持最基本的三种程序运行结构：==顺序结构、选择结构、循环结构==

* 顺序结构：程序按顺序执行，不发生跳转
* 选择结构：依据条件是否满足，有选择的执行相应功能
* 循环结构：依据条件是否满足，循环多次执行某段代码



### 4.1 选择结构

#### 4.1.1 if语句

**作用：**执行满足条件的语句

if语句的三种形式

* 单行格式if语句

* 多行格式if语句

* 多条件的if语句

  

1. 单行格式if语句：`if(条件){ 条件满足执行的语句 }`

    ![img](assets/clip_image002.png)

   示例：

   ```C++
   int main() {
   
   	//选择结构-单行if语句
   	//输入一个分数，如果分数大于600分，视为考上一本大学，并在屏幕上打印
   
   	int score = 0;
   	cout << "请输入一个分数：" << endl;
   	cin >> score;
   
   	cout << "您输入的分数为： " << score << endl;
   
   	//if语句
   	//注意事项，在if判断语句后面，不要加分号
   	if (score > 600)
   	{
   		cout << "我考上了一本大学！！！" << endl;
   	}
   
   	system("pause");
   
   	return 0;
   }
   ```

   


> 注意：if条件表达式后不要加分号







2. 多行格式if语句：`if(条件){ 条件满足执行的语句 }else{ 条件不满足执行的语句 };`

![img](assets/clip_image002-1541662519170.png)



示例：

```C++
int main() {

	int score = 0;

	cout << "请输入考试分数：" << endl;

	cin >> score;

	if (score > 600)
	{
		cout << "我考上了一本大学" << endl;
	}
	else
	{
		cout << "我未考上一本大学" << endl;
	}

	system("pause");

	return 0;
}
```











3. 多条件的if语句：`if(条件1){ 条件1满足执行的语句 }else if(条件2){条件2满足执行的语句}... else{ 都不满足执行的语句}`

![img](assets/clip_image002-1541662566808.png)







示例：

```C++
	int main() {

	int score = 0;

	cout << "请输入考试分数：" << endl;

	cin >> score;

	if (score > 600)
	{
		cout << "我考上了一本大学" << endl;
	}
	else if (score > 500)
	{
		cout << "我考上了二本大学" << endl;
	}
	else if (score > 400)
	{
		cout << "我考上了三本大学" << endl;
	}
	else
	{
		cout << "我未考上本科" << endl;
	}

	system("pause");

	return 0;
}
```









**嵌套if语句**：在if语句中，可以嵌套使用if语句，达到更精确的条件判断



案例需求：

* 提示用户输入一个高考考试分数，根据分数做如下判断
* 分数如果大于600分视为考上一本，大于500分考上二本，大于400考上三本，其余视为未考上本科；
* 在一本分数中，如果大于700分，考入北大，大于650分，考入清华，大于600考入人大。



**示例：**

```c++
int main() {

	int score = 0;

	cout << "请输入考试分数：" << endl;

	cin >> score;

	if (score > 600)
	{
		cout << "我考上了一本大学" << endl;
		if (score > 700)
		{
			cout << "我考上了北大" << endl;
		}
		else if (score > 650)
		{
			cout << "我考上了清华" << endl;
		}
		else
		{
			cout << "我考上了人大" << endl;
		}
		
	}
	else if (score > 500)
	{
		cout << "我考上了二本大学" << endl;
	}
	else if (score > 400)
	{
		cout << "我考上了三本大学" << endl;
	}
	else
	{
		cout << "我未考上本科" << endl;
	}

	system("pause");

	return 0;
}
```







**练习案例：** 三只小猪称体重

有三只小猪ABC，请分别输入三只小猪的体重，并且判断哪只小猪最重？![三只小猪](assets/三只小猪.jpg)









#### 4.1.2 三目运算符

**作用：** 通过三目运算符实现简单的判断

**语法：**`表达式1 ? 表达式2 ：表达式3`

**解释：**

如果表达式1的值为真，执行表达式2，并返回表达式2的结果；

如果表达式1的值为假，执行表达式3，并返回表达式3的结果。

**示例：**

```C++
int main() {

	int a = 10;
	int b = 20;
	int c = 0;

	c = a > b ? a : b;
	cout << "c = " << c << endl;

	//C++中三目运算符返回的是变量,可以继续赋值

	(a > b ? a : b) = 100;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	system("pause");

	return 0;
}
```

> 总结：和if语句比较，三目运算符优点是短小整洁，缺点是如果用嵌套，结构不清晰









#### 4.1.3 switch语句

**作用：**执行多条件分支语句

**语法：**

```C++
switch(表达式)

{

	case 结果1：执行语句;break;

	case 结果2：执行语句;break;

	...

	default:执行语句;break;

}

```







**示例：**

```C++
int main() {

	//请给电影评分 
	//10 ~ 9   经典   
	// 8 ~ 7   非常好
	// 6 ~ 5   一般
	// 5分以下 烂片

	int score = 0;
	cout << "请给电影打分" << endl;
	cin >> score;

	switch (score)
	{
	case 10:
	case 9:
		cout << "经典" << endl;
		break;
	case 8:
		cout << "非常好" << endl;
		break;
	case 7:
	case 6:
		cout << "一般" << endl;
		break;
	default:
		cout << "烂片" << endl;
		break;
	}

	system("pause");

	return 0;
}
```



> 注意1：switch语句中表达式类型只能是整型或者字符型

> 注意2：case里如果没有break，那么程序会一直向下执行

> 总结：与if语句比，对于多条件判断时，switch的结构清晰，执行效率高，缺点是switch不可以判断区间















### 4.2 循环结构

#### 4.2.1 while循环语句

**作用：**满足循环条件，执行循环语句

**语法：**` while(循环条件){ 循环语句 }`

**解释：**==只要循环条件的结果为真，就执行循环语句==

![img](assets/clip_image002-1541668640382.png)







**示例：**

```C++
int main() {

	int num = 0;
	while (num < 10)
	{
		cout << "num = " << num << endl;
		num++;
	}
	
	system("pause");

	return 0;
}
```



> 注意：在执行循环语句时候，程序必须提供跳出循环的出口，否则出现死循环









**while循环练习案例：**==猜数字==

**案例描述：**系统随机生成一个1到100之间的数字，玩家进行猜测，如果猜错，提示玩家数字过大或过小，如果猜对恭喜玩家胜利，并且退出游戏。



![猜数字](assets/猜数字.jpg)

















#### 4.2.2 do...while循环语句

**作用：** 满足循环条件，执行循环语句

**语法：** `do{ 循环语句 } while(循环条件);`

**注意：**与while的区别在于==do...while会先执行一次循环语句==，再判断循环条件

![img](assets/clip_image002-1541671163478.png)



**示例：**

```C++
int main() {

	int num = 0;

	do
	{
		cout << num << endl;
		num++;

	} while (num < 10);
	
	
	system("pause");

	return 0;
}
```



> 总结：与while循环区别在于，do...while先执行一次循环语句，再判断循环条件













**练习案例：水仙花数**

**案例描述：**水仙花数是指一个 3 位数，它的每个位上的数字的 3次幂之和等于它本身

例如：1^3 + 5^3+ 3^3 = 153

请利用do...while语句，求出所有3位数中的水仙花数





















#### 4.2.3 for循环语句

**作用：** 满足循环条件，执行循环语句

**语法：**` for(起始表达式;条件表达式;末尾循环体) { 循环语句; }`



**示例：**

```C++
int main() {

	for (int i = 0; i < 10; i++)
	{
		cout << i << endl;
	}
	
	system("pause");

	return 0;
}
```







**详解：**

![1541673704101](assets/1541673704101.png)



> 注意：for循环中的表达式，要用分号进行分隔

> 总结：while , do...while, for都是开发中常用的循环语句，for循环结构比较清晰，比较常用











**练习案例：敲桌子**

案例描述：从1开始数到数字100， 如果数字个位含有7，或者数字十位含有7，或者该数字是7的倍数，我们打印敲桌子，其余数字直接打印输出。

![timg](assets/timg.gif)













#### 4.2.4 嵌套循环

**作用：** 在循环体中再嵌套一层循环，解决一些实际问题

例如我们想在屏幕中打印如下图片，就需要利用嵌套循环

![1541676003486](assets/1541676003486.png)











**示例：**

```C++
int main() {

	//外层循环执行1次，内层循环执行1轮
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << "*" << " ";
		}
		cout << endl;
	}

	system("pause");

	return 0;
}
```













**练习案例：**乘法口诀表

案例描述：利用嵌套循环，实现九九乘法表

![0006018857256120_b](assets/0006018857256120_b.jpg)





### 4.3 跳转语句

#### 4.3.1 break语句

**作用:** 用于跳出==选择结构==或者==循环结构==

break使用的时机：

* 出现在switch条件语句中，作用是终止case并跳出switch
* 出现在循环语句中，作用是跳出当前的循环语句
* 出现在嵌套循环中，跳出最近的内层循环语句



**示例1：**

```C++
int main() {
	//1、在switch 语句中使用break
	cout << "请选择您挑战副本的难度：" << endl;
	cout << "1、普通" << endl;
	cout << "2、中等" << endl;
	cout << "3、困难" << endl;

	int num = 0;

	cin >> num;

	switch (num)
	{
	case 1:
		cout << "您选择的是普通难度" << endl;
		break;
	case 2:
		cout << "您选择的是中等难度" << endl;
		break;
	case 3:
		cout << "您选择的是困难难度" << endl;
		break;
	}

	system("pause");

	return 0;
}
```



**示例2：**

```C++
int main() {
	//2、在循环语句中用break
	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			break; //跳出循环语句
		}
		cout << i << endl;
	}

	system("pause");

	return 0;
}
```



**示例3：**

```C++
int main() {
	//在嵌套循环语句中使用break，退出内层循环
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 5)
			{
				break;
			}
			cout << "*" << " ";
		}
		cout << endl;
	}
	
	system("pause");

	return 0;
}
```















#### 4.3.2 continue语句

**作用：**在==循环语句==中，跳过本次循环中余下尚未执行的语句，继续执行下一次循环

**示例：**

```C++
int main() {

	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
		{
			continue;
		}
		cout << i << endl;
	}
	
	system("pause");

	return 0;
}
```



> 注意：continue并没有使整个循环终止，而break会跳出循环











#### 4.3.3 goto语句

**作用：**可以无条件跳转语句



**语法：** `goto 标记;`

**解释：**如果标记的名称存在，执行到goto语句时，会跳转到标记的位置



**示例：**

```C++
int main() {

	cout << "1" << endl;

	goto FLAG;

	cout << "2" << endl;
	cout << "3" << endl;
	cout << "4" << endl;

	FLAG:

	cout << "5" << endl;
	
	system("pause");

	return 0;
}
```



> 注意：在程序中不建议使用goto语句，以免造成程序流程混乱













## 5 数组

### 5.1 概述

所谓数组，就是一个集合，里面存放了相同类型的数据元素



**特点1：**数组中的每个==数据元素都是相同的数据类型==

**特点2：**数组是由==连续的内存==位置组成的













![1541748375356](assets/1541748375356.png)













### 5.2 一维数组

#### 5.2.1 一维数组定义方式

一维数组定义的三种方式：

1. ` 数据类型  数组名[ 数组长度 ]; `
2. `数据类型  数组名[ 数组长度 ] = { 值1，值2 ...};`
3. `数据类型  数组名[ ] = { 值1，值2 ...};`



示例

```C++
int main() {

	//定义方式1
	//数据类型 数组名[元素个数];
	int score[10];

	//利用下标赋值
	score[0] = 100;
	score[1] = 99;
	score[2] = 85;

	//利用下标输出
	cout << score[0] << endl;
	cout << score[1] << endl;
	cout << score[2] << endl;


	//第二种定义方式
	//数据类型 数组名[元素个数] =  {值1，值2 ，值3 ...};
	//如果{}内不足10个数据，剩余数据用0补全
	int score2[10] = { 100, 90,80,70,60,50,40,30,20,10 };
	
	//逐个输出
	//cout << score2[0] << endl;
	//cout << score2[1] << endl;

	//一个一个输出太麻烦，因此可以利用循环进行输出
	for (int i = 0; i < 10; i++)
	{
		cout << score2[i] << endl;
	}

	//定义方式3
	//数据类型 数组名[] =  {值1，值2 ，值3 ...};
	int score3[] = { 100,90,80,70,60,50,40,30,20,10 };

	for (int i = 0; i < 10; i++)
	{
		cout << score3[i] << endl;
	}

	system("pause");

	return 0;
}
```



> 总结1：数组名的命名规范与变量名命名规范一致，不要和变量重名

> 总结2：数组中下标是从0开始索引









#### 5.2.2 一维数组数组名

一维数组名称的**用途**：

1. 可以统计整个数组在内存中的长度
2. 可以获取数组在内存中的首地址





**示例：**

```C++
int main() {

	//数组名用途
	//1、可以获取整个数组占用内存空间大小
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	cout << "整个数组所占内存空间为： " << sizeof(arr) << endl;
	cout << "每个元素所占内存空间为： " << sizeof(arr[0]) << endl;
	cout << "数组的元素个数为： " << sizeof(arr) / sizeof(arr[0]) << endl;

	//2、可以通过数组名获取到数组首地址
	cout << "数组首地址为： " << (int)arr << endl;
	cout << "数组中第一个元素地址为： " << (int)&arr[0] << endl;
	cout << "数组中第二个元素地址为： " << (int)&arr[1] << endl;

	//arr = 100; 错误，数组名是常量，因此不可以赋值


	system("pause");

	return 0;
}
```



> 注意：数组名是常量，不可以赋值

> 总结1：直接打印数组名，可以查看数组所占内存的首地址

>总结2：对数组名进行sizeof，可以获取整个数组占内存空间的大小











**练习案例1**：五只小猪称体重

**案例描述：**

在一个数组中记录了五只小猪的体重，如：int arr[5] = {300,350,200,400,250};

找出并打印最重的小猪体重。









**练习案例2：**数组元素逆置

**案例描述：**请声明一个5个元素的数组，并且将元素逆置.

(如原数组元素为：1,3,2,5,4;逆置后输出结果为:4,5,2,3,1);

















#### 5.2.3 冒泡排序

**作用：** 最常用的排序算法，对数组内元素进行排序

1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
2. 对每一对相邻元素做同样的工作，执行完毕后，找到第一个最大值。
3. 重复以上的步骤，每次比较次数-1，直到不需要比较

![1541905327273](assets/1541905327273.png)

**示例：** 将数组 { 4,2,8,0,5,7,1,3,9 } 进行升序排序

```C++
int main() {

	int arr[9] = { 4,2,8,0,5,7,1,3,9 };

	for (int i = 0; i < 9 - 1; i++)
	{
		for (int j = 0; j < 9 - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << endl;
	}
    
	system("pause");

	return 0;
}
```









### 5.3 二维数组

二维数组就是在一维数组上，多加一个维度。

![1541905559138](assets/1541905559138.png)

#### 5.3.1 二维数组定义方式

二维数组定义的四种方式：

1. ` 数据类型  数组名[ 行数 ][ 列数 ]; `
2. `数据类型  数组名[ 行数 ][ 列数 ] = { {数据1，数据2 } ，{数据3，数据4 } };`
3. `数据类型  数组名[ 行数 ][ 列数 ] = { 数据1，数据2，数据3，数据4};`
4. ` 数据类型  数组名[  ][ 列数 ] = { 数据1，数据2，数据3，数据4};`



> 建议：以上4种定义方式，利用==第二种更加直观，提高代码的可读性==

示例：

```C++
int main() {

	//方式1  
	//数组类型 数组名 [行数][列数]
	int arr[2][3];
	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 3;
	arr[1][0] = 4;
	arr[1][1] = 5;
	arr[1][2] = 6;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	//方式2 
	//数据类型 数组名[行数][列数] = { {数据1，数据2 } ，{数据3，数据4 } };
	int arr2[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};

	//方式3
	//数据类型 数组名[行数][列数] = { 数据1，数据2 ,数据3，数据4  };
	int arr3[2][3] = { 1,2,3,4,5,6 }; 

	//方式4 
	//数据类型 数组名[][列数] = { 数据1，数据2 ,数据3，数据4  };
	int arr4[][3] = { 1,2,3,4,5,6 };
	
	system("pause");

	return 0;
}
```



> 总结：在定义二维数组时，如果初始化了数据，可以省略行数













#### 5.3.2 二维数组数组名



* 查看二维数组所占内存空间
* 获取二维数组首地址





**示例：**

```C++
int main() {

	//二维数组数组名
	int arr[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};

	cout << "二维数组大小： " << sizeof(arr) << endl;
	cout << "二维数组一行大小： " << sizeof(arr[0]) << endl;
	cout << "二维数组元素大小： " << sizeof(arr[0][0]) << endl;

	cout << "二维数组行数： " << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "二维数组列数： " << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

	//地址
	cout << "二维数组首地址：" << arr << endl;
	cout << "二维数组第一行地址：" << arr[0] << endl;
	cout << "二维数组第二行地址：" << arr[1] << endl;

	cout << "二维数组第一个元素地址：" << &arr[0][0] << endl;
	cout << "二维数组第二个元素地址：" << &arr[0][1] << endl;

	system("pause");

	return 0;
}
```



> 总结1：二维数组名就是这个数组的首地址

> 总结2：对二维数组名进行sizeof时，可以获取整个二维数组占用的内存空间大小













#### **5.3.3 二维数组应用案例**

**考试成绩统计：**

案例描述：有三名同学（张三，李四，王五），在一次考试中的成绩分别如下表，**请分别输出三名同学的总成绩**

|      | 语文 | 数学 | 英语 |
| ---- | ---- | ---- | ---- |
| 张三 | 100  | 100  | 100  |
| 李四 | 90   | 50   | 100  |
| 王五 | 60   | 70   | 80   |





**参考答案：**

```C++
int main() {

	int scores[3][3] =
	{
		{100,100,100},
		{90,50,100},
		{60,70,80},
	};

	string names[3] = { "张三","李四","王五" };

	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum += scores[i][j];
		}
		cout << names[i] << "同学总成绩为： " << sum << endl;
	}

	system("pause");

	return 0;
}
```













## 6 函数

### 6.1 概述

**作用：**将一段经常使用的代码封装起来，减少重复代码

一个较大的程序，一般分为若干个程序块，每个模块实现特定的功能。

### 6.2 函数的定义

函数的定义一般主要有5个步骤：

1、返回值类型 

2、函数名

3、参数表列

4、函数体语句 

5、return 表达式

**语法：** 

```C++
返回值类型 函数名 （参数列表）
{

       函数体语句

       return表达式

}
```



* 返回值类型 ：一个函数可以返回一个值。在函数定义中
* 函数名：给函数起个名称
* 参数列表：使用该函数时，传入的数据
* 函数体语句：花括号内的代码，函数内需要执行的语句
* return表达式： 和返回值类型挂钩，函数执行完后，返回相应的数据





**示例：**定义一个加法函数，实现两个数相加

```C++
//函数定义
int add(int num1, int num2)
{
	int sum = num1 + num2;
	return sum;
}
```











### 6.3 函数的调用

**功能：**使用定义好的函数

**语法：**` 函数名（参数）`

**示例：**

```C++
//函数定义
int add(int num1, int num2) //定义中的num1,num2称为形式参数，简称形参
{
	int sum = num1 + num2;
	return sum;
}

int main() {

	int a = 10;
	int b = 10;
	//调用add函数
	int sum = add(a, b);//调用时的a，b称为实际参数，简称实参
	cout << "sum = " << sum << endl;

	a = 100;
	b = 100;

	sum = add(a, b);
	cout << "sum = " << sum << endl;

	system("pause");

	return 0;
}
```

> 总结：函数定义里小括号内称为形参，函数调用时传入的参数称为实参









### 6.4 值传递

* 所谓值传递，就是函数调用时实参将数值传入给形参
* 值传递时，==如果形参发生，并不会影响实参==



**示例：**

```C++
void swap(int num1, int num2)
{
	cout << "交换前：" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	int temp = num1;
	num1 = num2;
	num2 = temp;

	cout << "交换后：" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	//return ; 当函数声明时候，不需要返回值，可以不写return
}

int main() {

	int a = 10;
	int b = 20;

	swap(a, b);

	cout << "mian中的 a = " << a << endl;
	cout << "mian中的 b = " << b << endl;

	system("pause");

	return 0;
}
```



> 总结： 值传递时，形参是修饰不了实参的









### **6.5 函数的常见样式**

常见的函数样式有4种

1. 无参无返
2. 有参无返
3. 无参有返
4. 有参有返

**示例：**

```C++
//函数常见样式
//1、 无参无返
void test01()
{
	//void a = 10; //无类型不可以创建变量,原因无法分配内存
	cout << "this is test01" << endl;
	//test01(); 函数调用
}

//2、 有参无返
void test02(int a)
{
	cout << "this is test02" << endl;
	cout << "a = " << a << endl;
}

//3、无参有返
int test03()
{
	cout << "this is test03 " << endl;
	return 10;
}

//4、有参有返
int test04(int a, int b)
{
	cout << "this is test04 " << endl;
	int sum = a + b;
	return sum;
}
```











### 6.6 函数的声明

**作用：** 告诉编译器函数名称及如何调用函数。函数的实际主体可以单独定义。



*  函数的**声明可以多次**，但是函数的**定义只能有一次**



**示例：**

```C++
//声明可以多次，定义只能一次
//声明
int max(int a, int b);
int max(int a, int b);
//定义
int max(int a, int b)
{
	return a > b ? a : b;
}

int main() {

	int a = 100;
	int b = 200;

	cout << max(a, b) << endl;

	system("pause");

	return 0;
}
```











### 6.7 函数的分文件编写

**作用：**让代码结构更加清晰

函数分文件编写一般有4个步骤

1. 创建后缀名为.h的头文件  
2. 创建后缀名为.cpp的源文件
3. 在头文件中写函数的声明
4. 在源文件中写函数的定义

**示例：**

```C++
//swap.h文件
#include<iostream>
using namespace std;

//实现两个数字交换的函数声明
void swap(int a, int b);

```

```C++
//swap.cpp文件
#include "swap.h"

void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}
```

```C++
//main函数文件
#include "swap.h"
int main() {

	int a = 100;
	int b = 200;
	swap(a, b);

	system("pause");

	return 0;
}

```













## 7 指针

### 7.1 指针的基本概念

**指针的作用：** 可以通过指针间接访问内存



* 内存编号是从0开始记录的，一般用十六进制数字表示
* 可以利用指针变量保存地址

  

### 7.2 指针变量的定义和使用

指针变量定义语法： `数据类型 * 变量名；`

**示例：**

```C++
int main() {

	//1、指针的定义
	int a = 10; //定义整型变量a
	
	//指针定义语法： 数据类型 * 变量名 ;
	int * p;

	//指针变量赋值
	p = &a; //指针指向变量a的地址
	cout << &a << endl; //打印数据a的地址
	cout << p << endl;  //打印指针变量p

	//2、指针的使用
	//通过*操作指针变量指向的内存
	cout << "*p = " << *p << endl;

	system("pause");

	return 0;
}
```



指针变量和普通变量的区别

* 普通变量存放的是数据,指针变量存放的是地址
* 指针变量可以通过" * "操作符，操作指针变量指向的内存空间，这个过程称为解引用



> 总结1： 我们可以通过 & 符号 获取变量的地址

> 总结2：利用指针可以记录地址

> 总结3：对指针变量解引用，可以操作指针指向的内存











### 7.3 指针所占内存空间



提问：指针也是种数据类型，那么这种数据类型占用多少内存空间？



**示例：**

```C++
int main() {

	int a = 10;

	int * p;
	p = &a; //指针指向数据a的地址

	cout << *p << endl; //* 解引用
	cout << sizeof(p) << endl;
	cout << sizeof(char *) << endl;
	cout << sizeof(float *) << endl;
	cout << sizeof(double *) << endl;

	system("pause");

	return 0;
}
```



> 总结：所有指针类型在32位操作系统下是4个字节，不管是什么类型的指针都一样
>
> 在64位操作系统下指针占8个字节











### 7.4 空指针和野指针

**空指针**：指针变量指向内存中编号为0的空间

**用途：**初始化指针变量

**注意：**空指针指向的内存是不可以访问的；内存编号0 ~255为系统占用内存，不允许用户访问



**示例1：空指针**

```C++
int main() {

	//指针变量p指向内存地址编号为0的空间
	int * p = NULL;

	//访问空指针报错 
	//内存编号0 ~255为系统占用内存，不允许用户访问
	cout << *p << endl;

	system("pause");

	return 0;
}
```















**野指针**：指针变量指向非法的内存空间

**示例2：野指针**

```C++
int main() {

	//指针变量p指向内存地址编号为0x1100的空间
	int * p = (int *)0x1100;

	//访问野指针报错 
	cout << *p << endl;

	system("pause");

	return 0;
}
```





> 总结：空指针和野指针都不是我们申请的空间，因此不要访问。









### 7.5 const修饰指针

const修饰指针有三种情况

1. const修饰指针   --- 常量指针
2. const修饰常量   --- 指针常量
3. const即修饰指针，又修饰常量




**示例：**


```c++
int main() {

	int a = 10;
	int b = 10;

	//const修饰的是指针，指针指向可以改，指针指向的值不可以更改
	const int * p1 = &a; 
	p1 = &b; //正确
	//*p1 = 100;  报错
	

	//const修饰的是常量，指针指向不可以改，指针指向的值可以更改
	int * const p2 = &a;
	//p2 = &b; //错误
	*p2 = 100; //正确

    //const既修饰指针又修饰常量
	const int * const p3 = &a;
	//p3 = &b; //错误
	//*p3 = 100; //错误

	system("pause");

	return 0;
}
```



> 技巧：看const右侧紧跟着的是指针还是常量, 是指针就是常量指针，是常量就是指针常量









### 7.6 指针和数组

**作用：**利用指针访问数组中元素

**示例：**

```C++
int main() {

	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

	int * p = arr;  //指向数组的指针

	cout << "第一个元素： " << arr[0] << endl;
	cout << "指针访问第一个元素： " << *p << endl;

	for (int i = 0; i < 10; i++)
	{
		//利用指针遍历数组
		cout << *p << endl;
		p++;
	}

	system("pause");

	return 0;
}
```











### 7.7 指针和函数

**作用：**利用指针作函数参数，可以修改实参的值



**示例：**

```C++
//值传递
void swap1(int a ,int b)
{
	int temp = a;
	a = b; 
	b = temp;
}
//地址传递
void swap2(int * p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main() {

	int a = 10;
	int b = 20;
	swap1(a, b); // 值传递不会改变实参

	swap2(&a, &b); //地址传递会改变实参

	cout << "a = " << a << endl;

	cout << "b = " << b << endl;

	system("pause");

	return 0;
}
```



> 总结：如果不想修改实参，就用值传递，如果想修改实参，就用地址传递













### 7.8 指针、数组、函数

**案例描述：**封装一个函数，利用冒泡排序，实现对整型数组的升序排序

例如数组：int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };



**示例：**

```c++
//冒泡排序函数
void bubbleSort(int * arr, int len)  //int * arr 也可以写为int arr[]
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//打印数组函数
void printArray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}
}

int main() {

	int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
	int len = sizeof(arr) / sizeof(int);

	bubbleSort(arr, len);

	printArray(arr, len);

	system("pause");

	return 0;
}
```



> 总结：当数组名传入到函数作为参数时，被退化为指向首元素的指针









## 8 结构体

### 8.1 结构体基本概念

结构体属于用户自定义的数据类型，允许用户存储不同的数据类型



### 8.2 结构体定义和使用

**语法：**`struct 结构体名 { 结构体成员列表 }；`

通过结构体创建变量的方式有三种：

* struct 结构体名 变量名
* struct 结构体名 变量名 = { 成员1值 ， 成员2值...}
* 定义结构体时顺便创建变量

**示例：**

```C++
//结构体定义
struct student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
}stu3; //结构体变量创建方式3 


int main() {

	//结构体变量创建方式1
	struct student stu1; //struct 关键字可以省略

	stu1.name = "张三";
	stu1.age = 18;
	stu1.score = 100;
	
	cout << "姓名：" << stu1.name << " 年龄：" << stu1.age  << " 分数：" << stu1.score << endl;

	//结构体变量创建方式2
	struct student stu2 = { "李四",19,60 };

	cout << "姓名：" << stu2.name << " 年龄：" << stu2.age  << " 分数：" << stu2.score << endl;


	stu3.name = "王五";
	stu3.age = 18;
	stu3.score = 80;
	

	cout << "姓名：" << stu3.name << " 年龄：" << stu3.age  << " 分数：" << stu3.score << endl;

	system("pause");

	return 0;
}
```



> 总结1：定义结构体时的关键字是struct，不可省略

> 总结2：创建结构体变量时，关键字struct可以省略

> 总结3：结构体变量利用操作符 ''.''  访问成员









### 8.3 结构体数组

**作用：**将自定义的结构体放入到数组中方便维护

**语法：**` struct  结构体名 数组名[元素个数] = {  {} , {} , ... {} }`

**示例：**

```C++
//结构体定义
struct student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
}

int main() {
	
	//结构体数组
	struct student arr[3]=
	{
		{"张三",18,80 },
		{"李四",19,60 },
		{"王五",20,70 }
	};

	for (int i = 0; i < 3; i++)
	{
		cout << "姓名：" << arr[i].name << " 年龄：" << arr[i].age << " 分数：" << arr[i].score << endl;
	}

	system("pause");

	return 0;
}
```











### 8.4 结构体指针

**作用：**通过指针访问结构体中的成员



* 利用操作符 `-> `可以通过结构体指针访问结构体属性



**示例：**

```C++
//结构体定义
struct student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};


int main() {
	
	struct student stu = { "张三",18,100, };
	
	struct student * p = &stu;
	
	p->score = 80; //指针通过 -> 操作符可以访问成员

	cout << "姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score << endl;
	
	system("pause");

	return 0;
}
```



> 总结：结构体指针可以通过 -> 操作符 来访问结构体中的成员













### 8.5 结构体嵌套结构体

**作用：** 结构体中的成员可以是另一个结构体

**例如：**每个老师辅导一个学员，一个老师的结构体中，记录一个学生的结构体

**示例：**

```C++
//学生结构体定义
struct student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};

//教师结构体定义
struct teacher
{
    //成员列表
	int id; //职工编号
	string name;  //教师姓名
	int age;   //教师年龄
	struct student stu; //子结构体 学生
};


int main() {

	struct teacher t1;
	t1.id = 10000;
	t1.name = "老王";
	t1.age = 40;

	t1.stu.name = "张三";
	t1.stu.age = 18;
	t1.stu.score = 100;

	cout << "教师 职工编号： " << t1.id << " 姓名： " << t1.name << " 年龄： " << t1.age << endl;
	
	cout << "辅导学员 姓名： " << t1.stu.name << " 年龄：" << t1.stu.age << " 考试分数： " << t1.stu.score << endl;

	system("pause");

	return 0;
}
```



**总结：**在结构体中可以定义另一个结构体作为成员，用来解决实际问题









### 8.6 结构体做函数参数 

**作用：**将结构体作为参数向函数中传递

传递方式有两种：

* 值传递
* 地址传递

**示例：**

```C++
//学生结构体定义
struct student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};

//值传递
void printStudent(student stu )
{
	stu.age = 28;
	cout << "子函数中 姓名：" << stu.name << " 年龄： " << stu.age  << " 分数：" << stu.score << endl;
}

//地址传递
void printStudent2(student *stu)
{
	stu->age = 28;
	cout << "子函数中 姓名：" << stu->name << " 年龄： " << stu->age  << " 分数：" << stu->score << endl;
}

int main() {

	student stu = { "张三",18,100};
	//值传递
	printStudent(stu);
	cout << "主函数中 姓名：" << stu.name << " 年龄： " << stu.age << " 分数：" << stu.score << endl;

	cout << endl;

	//地址传递
	printStudent2(&stu);
	cout << "主函数中 姓名：" << stu.name << " 年龄： " << stu.age  << " 分数：" << stu.score << endl;

	system("pause");

	return 0;
}
```

> 总结：如果不想修改主函数中的数据，用值传递，反之用地址传递







### 8.7 结构体中 const使用场景

**作用：**用const来防止误操作

**示例：**

```C++
//学生结构体定义
struct student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};

//const使用场景
void printStudent(const student *stu) //加const防止函数体中的误操作
{
	//stu->age = 100; //操作失败，因为加了const修饰
	cout << "姓名：" << stu->name << " 年龄：" << stu->age << " 分数：" << stu->score << endl;

}

int main() {

	student stu = { "张三",18,100 };

	printStudent(&stu);

	system("pause");

	return 0;
}
```









### 8.8 结构体案例

#### 8.8.1 案例1

**案例描述：**

学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下

设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员

学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值

最终打印出老师数据以及老师所带的学生数据。



**示例：**

```C++
struct Student
{
	string name;
	int score;
};
struct Teacher
{
	string name;
	Student sArray[5];
};

void allocateSpace(Teacher tArray[] , int len)
{
	string tName = "教师";
	string sName = "学生";
	string nameSeed = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		tArray[i].name = tName + nameSeed[i];
		
		for (int j = 0; j < 5; j++)
		{
			tArray[i].sArray[j].name = sName + nameSeed[j];
			tArray[i].sArray[j].score = rand() % 61 + 40;
		}
	}
}

void printTeachers(Teacher tArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << tArray[i].name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t姓名：" << tArray[i].sArray[j].name << " 分数：" << tArray[i].sArray[j].score << endl;
		}
	}
}

int main() {

	srand((unsigned int)time(NULL)); //随机数种子 头文件 #include <ctime>

	Teacher tArray[3]; //老师数组

	int len = sizeof(tArray) / sizeof(Teacher);

	allocateSpace(tArray, len); //创建数据

	printTeachers(tArray, len); //打印数据
	
	system("pause");

	return 0;
}
```









#### 8.8.2 案例2

**案例描述：**

设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。

通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。



五名英雄信息如下：

```C++
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},
```









**示例：**

```C++
//英雄结构体
struct hero
{
	string name;
	int age;
	string sex;
};
//冒泡排序
void bubbleSort(hero arr[] , int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j].age > arr[j + 1].age)
			{
				hero temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
//打印数组
void printHeros(hero arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "姓名： " << arr[i].name << " 性别： " << arr[i].sex << " 年龄： " << arr[i].age << endl;
	}
}

int main() {

	struct hero arr[5] =
	{
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},
	};

	int len = sizeof(arr) / sizeof(hero); //获取数组元素个数

	bubbleSort(arr, len); //排序

	printHeros(arr, len); //打印

	system("pause");

	return 0;
}
```



-----------------------

- 构造函数：函数名一定要和类名相同，构造函数有初始列，可以进行赋值

  ```c++
  public:
  	complex (double r = 0, double i = 0)//构造函数，默认实参r=0,i=0
  		: re (r), im (i)//利用构造函数的特性进行赋值（初值列）
  	{ }
  ```

  *在大括号中初始化会导致效率降低*

  - 不带指针的类大部分不会使用构造函数
  - 构造函数可以有很多个--**重载**
  - 函数重载经常发生在构造函数中

  - 构造函数可以放在private中（singleton）

- 一个类中可以有多个public和private

- 常量函数const(不改变函数中数据的内容)

  ```c++
  double real() const { return re; }
  ```

  - 常量函数调用时参数也需要是常量

    ```c++
    class complex
    {
        public:
        double real() const { return re; }
        double imag() const { return im; }
    }
    ...
        const complex c1(2,1)
    ```

- 参数传递（在实际编程中最好不要直接传递值，传递reference即可）

- 返回值传递（会影响程序的运行效率）

- **友元函数**：friend：定义在私有类但是外部函数也可以调用

- 同一个类中的各个对象互为友元函数

- 返回值最好用reference来传递

-------------

- 内存分区：
  - 代码区：特点：共享，只读
  - 全局区：存放全局变量，
    - 静态变量（static），
    - 常量
      - 字符串常量
      - const修饰常量（const修饰的全局变量和局部变量）
  - 堆区：由程序员自己管理释放，利用new关键字在堆区开辟数据区域
  - 栈区：由编译器自动分配，存放函数的参数值，局部变量**由于是编译器自动释放，不要返回局部变量的地址**

- new操作符：利用new操作符在堆区开辟数据区域，由程序员手动开辟，手动释放（利用delete释放）
  - new返回的是该数据类型的指针

## 引用

- 引用：给变量取别名

  - ```c++
    int &b = a;//b为别名
    ```

  - 引用必须要初始化；引用初始化之后不可以再发生改变

  - 如果函数的返回值是引用，则该函数调用可以作为左值

  - ```c++
    int& swap()
    {
        static int a = 10;//静态变量在全局区，程序结束后系统自动释放
        return a;
    }
    swap() = 1000;
    ```

  - 引用的本质就是**指针常量**（地址不变值可以变）

  - 常量引用：主要用来修饰形参，防止误操作

  - ```c++
    const int& ref = 10;
    void show(const int& val)//修饰形参，在函数体内不可再次修改
    {
    	cout << val;
    }
    ```

- 函数默认参数：可以给形参设置默认值

  ```c++
  int func(int a, int b = 100)
  {
      return a+b;
  }
  func(a)//有默认形参的函数可以少传参数值
  ```

  - 如果某个位置有了默认参数，则从这个位置开始从左到右都必须有默认参数
  - 如果函数的声明有默认参数，函数的实现就不能有默认参数了（声明和实现只能有一个有默认参数，否则会出现二义性）

- 占位参数

  ```c++
  void func(int a, int);
  void func(int a, int 10)//占位参数可以有默认参数
  func(10, 10);//必须要有，但是不能用
  ```

- 函数重载：函数名相同，提高复用性

  - 满足条件：同一作用域下；函数名相同；函数参数类型不同，或者个数不同，顺序不同
  - 引用作为函数重载
  - 重载遇到参数默认值

- 类中的属性和行为同一称为成员，属性也称为成员属性和成员变量；行为称为成员函数和成员方法

- 封装的含义：

  - public公共权限：在类内和类外都可以访问
  - protected保护：在类内可以访问，类外不可以访问
  - private私有权限：在类内可以访问，类外不可以访问（在继承时保护和私有权限有区别）

- struct和class唯一的区别在于默认的访问权限不同（struct默认为公有，class默认权限为私有）

- 成员属性设为私有后可以自己控制读写权限

## 构造函数和析构函数

-------------

- 利用**构造函数**和**析构函数**对对象进行初始化和清理，这两个函数可以由编译器自动调用，编译器提供的构造函数和析构函数是空的

- 构造函数：用来初始化，可以有参数，可以发生重载，函数名称与类名相同，没有返回值也不用写void

  - ```c++
    类名（）{}
    ```

  - 构造函数的分类：

    - 有参构造和无参构造（默认构造函数）
    - 普通构造函数和拷贝构造函数

  - 构造函数的调用：

    - 括号法
    - 显示法
    - 隐式转换法

  - 匿名对象：当前行执行结束后，系统会立即回收掉匿名对象；**不要利用拷贝构造函数来初始化匿名对象**，编译器会认为是个对象的声明

  - 拷贝构造函数的使用时机：

    - 使用一个已经创建完毕的对象来初始化一个新对象
    - 值传递的方式给函数参数传值
    - 以值方式返回局部对象

  - 如果用户定义有参构造函数，c++不再提供默认无参构造，但是会提供默认拷贝构造；如果用户定义拷贝构造函数，c++不会再提供其它的构造函数

- 析构函数：用来清理，函数名和类名相同，不能有参数，不能发生重载，对象在**销毁**前会调用析构函数，而且只会调用一次

  - ```c++
    ~类名（）{}
    ```

  - 

- 构造函数和析构函数都是必须有的，若自己不定义系统会自动提供

  - ```c++
    class Person
    {
    public:
    	Person(const Person &p)//拷贝构造函数
    	{
    		cout << "person构造函数调用";
    	}
    	~Person()
    	{
    		cout << "hhhhh" << endl;
    	}
    };
    ```


  ## 深拷贝和浅拷贝

- **深拷贝和浅拷贝**

  - 浅拷贝：简单的赋值拷贝操作，浅拷贝带来的问题就是会使得堆区的内存重复释放；若利用系统提供的拷贝构造函数会使用浅拷贝
  - 深拷贝：在堆区重新申请空间进行拷贝操作

- 初始化列表：c++提供初始化列表，对属性进行初始化

  - ```c++
    class Person
    {
    public:
    	Person(int a, int b, int c):m_a(a),m_b(b),m_c(c)
    	{
    		
    	}
    	int m_a, m_b, m_c;
    };
    ```

- 类对象作为类成员

- 静态成员（static）

  - 静态成员变量

    - 所有对象共同分享一份数据

    - 在**编译阶段分配内存**（程序没有运行前分配内存，在全局区里面）

    - 类内声明，类外初始化，必须有初始值

    - ```c++
      class Person
      {
      public:
      	static int m_A;
      };
      int Person::m_A = 4;
      ```

    - 可以通过对象进行访问，或者通过类名进行访问

    - ```c++
      cout << p.m_A <<endl;
      cout << Person::m_A << endl;//由于所有d
      ```

    - 

  - 静态成员函数：**静态成员函数可以访问静态成员变量，不可以访问非静态成员变量**（由于所有对象共享一份数据）

- 成员变量和成员函数是分开存储的，非静态成员变量属于类的对象上，静态成员变量/函数和非静态成员函数不属于类的对象上

## this指针

- this指针：不需要定义，直接使用即可，是隐含在每一个非静态成员函数内的一种指针

  - this指针指向的是**被调用的成员函数所属的对象**

  - 作用1是解决名称冲突

  - ```c++
    class Person
    {
    public:
    	Person(int age)
    	{
    		this->age = age;
    	}
    	int age;
    };
    ```

  - 作用2是返回对象本身用*this:

  - ```c++
    #include<iostream>
    using namespace std;
    class Person
    {
    public:
    	Person(int age)
    	{
    		this->age = age;
    	}
    	Person& PersonAddPerson(Person& p)//注意返回的是引用值
    	{
    		this->age += p.age;
    		return *this;
    	}
    	int age;
    };
    int main()
    {
    	Person p1(10);
    	Person p2(10);
    	p2.PersonAddPerson(p1).PersonAddPerson(p1);//
    	cout << "年龄为" << p2.age << endl;
    }
    ```

  - this指针本质上是指针常量，指针的指向是不可以修改的

- 关键字mutable：特殊变量，即使在常函数中，值加上关键字mutable也可以进行修改

- 常函数：常函数内不可以修改成员属性，成员属性声明时加关键字mutable后在常函数中依然可以进行修改

  ```c++
  class Person
  {
  public:
  	void showPerson() const//this修饰的this的指向，指向的值是不可以修改的
  	{
  
  	}
  	int age;
      int
  };
  ```

  

- 常对象：在对象前加上const变为常对象，对象中的变量不可以进行修改，常对象只能调用**常函数**，不能调用普通成员函数，因为普通成员函数的属性可以进行修改

## 友元函数

- 友元函数：friend，可以访问类的私有成员

  - 全局函数做友元函数

    ```c++
    #include<iostream>
    using namespace std;
    class Building
    {
    	friend void goodgay(Building* building);//友元函数，写到类里面就可以
    public:
    	Building()
    	{
    		m_sittingroom = "客厅";
    		m_restroom = "卧室";
    	}
    	string m_sittingroom;
    private:
    	string m_restroom;
    };
    
    void goodgay(Building *building)
    {
    	cout <<"来了" << building->m_sittingroom << endl;
    	cout << "来了"<< building->m_restroom << endl;
    	
    }
    int main()
    {
    	Building b;
    	goodgay(&b);
    }
    ```

  - 类做友元函数：(类外写成员函数)

  - ```c++
    #include<iostream>
    using namespace std;
    class Building;
    class GoodGay
    {
    public:
    	
    	GoodGay();
    	void visit();
    	Building* building;
    };
    class Building
    {
    public:
    	friend GoodGay;//类做友元函数
    	Building();
    	string m_sittingroom;
    private:
    	string m_restroom;
    };
    Building::Building()//类外写成员函数
    {
    	m_sittingroom = "客厅";
    	m_restroom = "卧室";
    }
    GoodGay::GoodGay()//类外写成员函数
    {
    	building = new Building;//堆区新建
    }
    void GoodGay::visit()//类外写成员函数
    {
    	cout << "好基友正在访问" << building->m_sittingroom << endl;
    	cout << "好基友正在访问" << building->m_restroom << endl;
    }
    void test01()
    {
    	GoodGay g;
    	g.visit();
    }
    int main()
    {
    	test01();
    }
    ```

  - 成员函数做友元

  - ```c++
    #include<iostream>
    using namespace std;
    class Building;
    class GoodGay
    {
    public:
    	GoodGay();
    	void visit();//让visit函数访问Building中的私有成员
    	void visit2();//不可以访问Building中的私有成员
    	Building* building;
    };
    class Building
    {
    	friend void GoodGay::visit();//成员函数作为类的友元函数
    public:
    	Building();
    	string m_sittingroom;
    private:
    	string m_restroom;
    };
    //类外实现成员函数
    Building::Building()
    {
    	m_sittingroom = "客厅";
    	m_restroom = "卧室";
    }
    GoodGay::GoodGay()
    {
    	building = new Building;
    }
    void GoodGay::visit()
    {
    	cout << "visit函数正在访问" << building->m_sittingroom << endl;
    	cout << "visit函数正在访问" << building->m_restroom << endl;
    	
    }
    void GoodGay::visit2()
    {
    	cout << "visit2函数正在访问" << building->m_sittingroom << endl;
    }
    void test01()
    {
    	GoodGay GG;
    	GG.visit();
    
    }
    int main()
    {
    	test01();
    }
    ```

## 运算符重载

- 运算符重载：给运算符重新进行定义，赋予其另外的功能，以适应不同的数据类型

  - 加号运算符重载：作用是实现两个自定义数据类型相加的运算;

  - ```c++
    #include<iostream>
    using namespace std;
    class Person
    {
    public:
    	Person operator+(Person& p1)
    	{
    		Person temp;
    		temp.m_A = this->m_A + p1.m_A;
    		temp.m_B = this->m_A + p1.m_B;
    		return temp;
    	}
    	int m_A;
    	int m_B;
    };
    
    void test()
    {
    	Person p1;
    	p1.m_A = 10;
    	p1.m_B = 10;
    	Person p2;
    	p2.m_A = 33;
    	p2.m_B = 44;
    	Person p3 = p1 + p2;
    	cout << "m_a" << p3.m_A << "m_b" << p3.m_B;
    }
    int main()
    {
    	test();
    	system("pause");
    }
    ```

  - 全局函数重载+号

  - 左移运算符重载：通常**不会使用成员函数**对左移运算符进行重载;左移运算符重载实现自定义数据类型的输出（一般配合private使用）

  - ```c++
    #include<iostream>
    using namespace std;
    class Person
    {
    public:
    
    	int m_A;
    	int m_B;
    };
    
    ostream & operator<<(ostream &cout,Person& p)//本质上是operator<<(cout,p),简化为cout<<p
    {
    	cout << "m_A=" << p.m_A << "	m_B=" << p.m_B << endl;
    	return cout;//ostream为输出流，返回该数据类型后调用后可以使用endl进行换行
    }
    void test01()
    {
    	Person p;
    	p.m_A = 10;
    	p.m_B = 20;
    	cout << p << endl;
    }
    int main()
    {
    	test01();
    	system("pause");
    }
    ```

  - 递增数据运算符的重载:区分前置和后置递增运算符：加入一个int占位则系统认为是后置递增，没有这是前置递增运算符进行重载；后置递增一定**返回的是值**，前置递增返回的是引用&

  - ```c++
    #include<iostream>
    using namespace std;
    class Person
    {
    	friend ostream& operator<<(ostream& cout, Person p);
    public:
    	Person()
    	{
    		m_num = 0;
    	}
    	//重载前置++运算符
    	Person& operator++()//返回引用是为了对一个数据进行操作
    	{
    		m_num++;//先进行++运算
    		return *this;//再将自身进行返回
    	}
    	//重载后置++运算符
    	Person operator++(int)//加入一个int占位，系统认为是后置递增，后置递增一定返回的是值
    	{
    		Person temp = *this;
    		m_num++;
    		return temp;
    	}
    private:
    	int m_num = 0;
    };
    //重载左移运算符
    ostream& operator<<(ostream& cout, Person p1)
    {
    	cout << p1.m_num;
    	return cout;
    }
    void test01()
    {
    	Person p1;
    	cout << "前置递增运算符" << ++(++p1) << endl;
    	cout << p1 << endl;
    }
    void test02()
    {
    	Person pp1;
    	cout << "后置递增运算符" << pp1++ << endl;
    	cout << "后置递增运算符" << pp1 << endl;
    }
    int main()
    {
    	test01();
    	test02();
    	system("pause");
    }
    ```

  - 赋值运算符的重载

    - c++编译器至少对一个类添加4个函数

      - 默认构造函数
      - 默认析构函数
      - 默认拷贝构造函数
      - 赋值运算符operator=，对属性进行值拷贝（如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题）

    - ```c++
      #include<iostream>
      using namespace std;
      class Person
      {
      public:
      	Person(int age)
      	{
      		m_age = new int(age);//在堆区开辟内存
      	}
      	//赋值运算符的重载
      	Person& operator=(Person &p)
      	{
      		//编译器默认的赋值运算符是浅拷贝
      		//判断是否有属性在堆区，清理干净，然后再深拷贝
      		if (m_age != NULL)
      		{
      			delete m_age;
      			m_age = NULL;
      		}
      		m_age = new int(*p.m_age);//深拷贝
      		return *this;//返回对象本身为了实现连等操作
      	}
      	int* m_age;
      	
      private:
      	
      };
      void test01()
      {
      	Person P1(70);
      	Person P2(30);
      	P1 = P2;
      	cout << *P1.m_age << endl;
      }
      int main()
      {
      	test01();
      	system("pause");
      }
      ```

  - 关系运算符的重载（大于号小于号等于号）

    - ```c++
      #include<iostream>
      using namespace std;
      class Person
      {
      public:
      	Person(string name, int age)
      	{
      		m_age = age;
      		m_name = name;
      	}
      	//重载关系运算符==
      	bool operator==(Person& p)
      	{
      		if (this->m_name == p.m_name && this->m_age == p.m_age)
      			return true;
      		else
      		{
      			return false;
      		}
      	}
      
      private:
      	string m_name;
      	int m_age;
      };
      
      int main()
      {
      	Person p1("zhangsan", 34);
      	Person p2("zhangsan", 34);
      	if (p1 == p2)
      	{
      		cout << "p1和p2相等" << endl;
      	}
      	else
      	{
      		cout << "p1和p2不相等" << endl;
      	}
      }
      ```

  - 函数调用运算符进行重载（函数调用运算符（）也可以进行重载）；由于重载后的使用方式非常像函数的调用，因此称为仿函数；仿函数没有固定的写法，非常灵活

    - ```c++
      #include<iostream>
      using namespace std;
      class MyPrint
      {
      public:
      	//重载函数调用运算符
      	void operator()(string test)
      	{
      		cout << test << endl;
      	}
      
      private:
      
      };
      class MyAdd
      {
      public:
      	int operator()(int num1, int num2)
      	{
      		return num1 + num2;
      	}
      };
      int main()
      {
      	MyPrint p1;
      	p1("好家伙");//由于使用起来非常像函数调用，因此称为仿函数
      	MyAdd add;
      	cout << add(3, 5) << endl;
          cout << MyAdd()(34, 67) << endl;//匿名函数对象的使用
      }
      ```

  - 匿名函数对象：当前对象使用完之后立即被释放

------------------

## 继承(面向对象的三大特性之一)

- 下级别的成员除了拥有上一级的共性，还有自己的特性

- 语法  class 子类（也称为派生类）：继承方式 父类（也称为基类）

- 派生类中包含基类中的成员（共性）以及自己新增的成员（个性）

- 作用是减少重复的代码

- 公共继承

  - ```c++
    #include<iostream>
    using namespace std;
    class BasePage
    {
    public:
    	void up()
    	{
    		cout << "gggg" << endl;
    	}
    	void down()
    	{
    		cout << "好家伙" << endl;
    	}
    		
    };
    class JAVA: public BasePage
    {
    public:
    	void content()
    	{
    		cout << "lalal" << endl;
    	}
    };
    int main()
    {
    	JAVA ja;
    	ja.down();
    	ja.content();
    	ja.up();
    }
    ```

- 继承方式有三种：

  - 公共继承：在父类中的成员权限继承到子类中没有变化，父类的私有成员子类不可以访问
  - 私有继承：父类中的公共成员以及保护成员变成了子类中的私有成员，父类的私有成员不可以访问
  - 保护继承：父类中的公共成员以及保护成员在子类中变成了保护成员，私有成员子类不可以访问

- 父类中所有的非静态成员属性都会被子类继承下去，但是父类中私有成员属性是被编译器隐藏了，是访问不到，但是是被继承下去了

- 子类继承父类后，当创建子类对象，也会调用父类的构造函数

  - ```c++
    #include<iostream>
    using namespace std;
    class Base
    {
    public:
    	Base()
    	{
    		cout << "Base的构造函数" << endl;
    	}
    	~Base()
    	{
    		cout << "Base的析构函数" << endl;
    	}
    
    
    };
    class Son : public Base
    {
    public:
    	Son()
    	{
    		cout << "son的构造函数" << endl;
    	}
    	~Son()
    	{
    		cout << "son的析构函数" << endl;
    	}
    
    private:
    
    };
    void test01()
    {
    	Base b1;
    	Son s1;
    }
    int main()
    {
    	test01();
    	system("pause");
    }
    
    ```

  - **先调用父类的构造函数，再调用子类的构造函数，然后调用子类的析构函数，再调用父类的析构函数**

- 继承中同名成员处理方式

  - 访问子类同名成员，直接访问即可

  - 访问父类同名成员，需要加上作用域

  - ```c++
    #include<iostream>
    using namespace std;
    class Base
    {
    public:
    	Base()
    	{
    		cout << "Base的构造函数" << endl;
    	}
    	int m_a = 100;
    	~Base()
    	{
    		cout << "Base的析构函数" << endl;
    	}
    
    
    };
    class Son : public Base
    {
    public:
    	Son()
    	{
    		cout << "son的构造函数" << endl;
    	}
    	int m_a = 34;
    	~Son()
    	{
    		cout << "son的析构函数" << endl;
    	}
    
    private:
    
    };
    void test01()
    {
    	Son s1;
    	cout << "son下的m_a" << s1.m_a << endl;
    	cout << "Base下的m_a" << s1.Base::m_a << endl;//加上作用域即可访问
    }
    int main()
    {
    	test01();
    	system("pause");
    }
    
    ```

- 继承中同名成员函数的处理（同样是加作用域）

  - ```c++
    #include<iostream>
    using namespace std;
    class Base
    {
    public:
    	void func()
    	{
    		cout << "base func" << endl;
    	}
    	
    
    };
    class Son : public Base
    {
    public:
    	void func()
    	{
    		cout << "son func" << endl;
    	}
    	int m_a = 34;
    	
    
    private:
    
    };
    void test01()
    {
    	Son s1;
    	s1.func();
    	s1.Base::func();//加作用域
    }
    int main()
    {
    	test01();
    	system("pause");
    }
    
    ```

  - ```c++
    #include<iostream>
    using namespace std;
    
    class base
    {
    public:
        base(int a, int b) { x = a; y = b; cout << "base constructor" << endl; }
    private:
        int x;
        int y;
    };
    
    class derived : public base
    {
    public:
        derived(int a, int b, int c) :base(a, b) { z = c; cout << "derived constructor" << endl; }
    private:
        int z;
    };
    
    int main()
    {
        derived B(1, 2, 3);
        return 0;
    }
    ```

  - 如果子类中出现和父类的同名成员函数，子类同名成员会隐藏掉父类中所有的同名成员函数，包括重载的情况，如果想访问一定要加作用域

- 总结：

  - 子类对象可以直接访问到子类中的同名成员
  - 子类对象加作用域可以访问到父类的同名成员
  - 当子类中含有与父类相同名称的成员函数，子类会隐藏父类中的同名成员函数，加上作用域可以访问到父类中的同名成员函数。

- 继承中的同名静态成员处理方式

  - ```c++
    #include<iostream>
    #include<time.h>
    #include <stdlib.h>
    using namespace std;
    class Base
    {
    public:
    	static int m_a;
    	static void func()
    	{
    		cout << "Base中的func" << endl;
    	}
    };
    int Base::m_a = 10;
    
    class Son:public Base
    {
    public:
    	static int m_a;
    	static void func()
    	{
    		cout << "Son中的func" << endl;
    	}
    };
    int Son::m_a = 1000;
    void test01()
    {
    	//1.通过对象访问
    	Son s;
    	cout << "通过对象访问" << endl;
    	cout << "son下m_a" << s.m_a << endl;
    	cout << "Base下m_a" << s.Base::m_a << endl;
    	//2.通过类名进行访问
    	cout << "通过类名进行访问" << endl;
    	cout << "son下m_a" << Son::m_a << endl;//通过类名进行访问
    	cout << "Base下m_a" << Son::Base::m_a << endl;//第一个::代表通过类名进行访问，第二个::代表访问父类作用域下
    }
    void test02()
    {
    	//1.通过对象对静态成员函数进行访问
    	Son s1;
    	
    	s1.func();
    	cout << "通过对象访问" << endl;
    	s1.Base::func();
    	//2.通过类名对静态成员函数进行访问
    	cout << "通过类名进行访问" << endl;
    	Son::func();
    	Son::Base::func();
    }
    int main()
    {
    	test01();
    	test02();
    	system("pause");
    }
    ```

  - 总结：同名静态成员处理方式和非静态处理方式一样，只不过有两种访问的方式（通过对象和通过类名）

- 多继承语法：c++允许一个类继承多个类

  - 语法：class 子类：继承方式 父类，继承方式 父类
  - 当父类中出现同名成员，需要加作用域区分
  - 通常在开发中不使用多继承语法

- 菱形继承：有两个派生类继承同一个基类，又有某个类同时继承两个派生类

  - 菱形继承导致最后那个类含有两份基类数据，导致数据空间浪费

  - 解决方式：继承之前加上关键字virtual变为虚继承

  - vbptr——虚基类指针，指向虚基类表，虚继承继承了指针

  - ```c++
    #include<iostream>
    #include<time.h>
    #include <stdlib.h>
    using namespace std;
    class animal
    {
    public:
    	int m_Age = 100;
    
    };
    class sheep : virtual public animal//animal为虚基类
    {
    public:
    	int m_name;
    };
    class Tuo :virtual public animal
    {
    public:
    	int tuo_name;
    };
    
    class Sheeptuo : public sheep, public Tuo
    {
    public:
    	int name21;
    };
    int main()
    {
    	Sheeptuo p1;
    	cout << p1.m_Age<<endl;//直接访问不会出错
    	cout << p1.sheep::m_Age << endl;
    	system("pause");
    }
    ```

  - 

-------

## 多态（c++面向对象三大特性之一）

- 多态分为两类：

  - 静态多态：函数重载和运算符重载属于静态多态，复用函数名
  - 动态多态：派生类和虚函数实现运行时的多态

- 静态多态和动态多态的区别：

  - 静态多态函数地址早绑定—编译器阶段就确定了函数地址
  - 动态多态的函数地址晚绑定—运行阶段确定函数地址

- 动态多态满足条件：

  - 有继承关系
  - 子类需要**重写**父类中的虚函数（**重写需要返回值类型，函数名称以及参数列表完全相同**）

- 动态多态的使用：父类的指针或者引用指向子类对象

- ```c++
  #include<iostream>
  #include<time.h>
  #include <stdlib.h>
  using namespace std;
  class animal
  {
  public:
  	virtual void speak()//虚函数实现地址晚绑定
  	{
  		cout << "animal is speaking" << endl;
  	}
  };
  class Cat : public animal
  {
  public:
  	void speak()//！！
  	{
  		cout << "Cat is speaking" << endl;
  	}
  };
  void dospeak(animal& Animal)//由于地址早绑定，在编译阶段就确定了函数地址，所以是执行animal speak
  {
  	Animal.speak();
  }
  void test01()
  {
  	Cat cat;
  	dospeak(cat);//由于speak多态，传入什么对象就访问什么地址
  }
  //如果想执行cat speak,那么这个函数地址就不能提前绑定，需要使用多态进行晚绑定
  int main()
  {
  	test01();
  }
  ```

- 多态的优点

  - 代码组织清晰
  - 可读性强
  - 利于前期和后期的扩展以及维护

- 在实际开发中提倡开闭原则：对扩展进行开放，对修改进行关闭

  - ```c++
    #include<iostream>
    #include<time.h>
    #include <stdlib.h>
    #define MAXSIZE 100
    using namespace std;
    //实现计算器抽象类//任何功能都没有
    class AbstractCalculator
    {
    public:
    	virtual int getResult()
    	{
    		return 0;
    	}
    	int m_num1;
    	int m_num2;
    };
    class AddCalculator : public AbstractCalculator
    {
    public:
    	int getResult()
    	{
    		return m_num1 + m_num2;
    	}
    private:
    };
    class MulCalculator :public AbstractCalculator
    {
    public:
    	int getResult()
    	{
    		return m_num1 * m_num2;
    	}
    private:
    
    };
    void test()
    {
    	//多态使用条件
    	//父类指针或者引用指向子类对象
    	//加法运算
    	AbstractCalculator* p1 = new AddCalculator;
    	p1->m_num1 = 12;
    	p1->m_num2 = 23;
    	cout << p1->m_num1 << "+" << p1->m_num2 << "=" << p1->getResult() << endl;
    	delete p1;//堆区数据记得释放
    	AbstractCalculator* p2 = new MulCalculator;
    	p2->m_num1 = 12;
    	p2->m_num2 = 23;
    	cout << p2->m_num1 << "*" << p2->m_num2 << "=" << p2->getResult() << endl;
    }
    int main()
    {
    	test();
    	system("pause");
    }
    ```

- 纯虚函数和抽象类

  - 在多态中，通常父类中的虚函数的实现是无意义的，主要是调用子类重写内容，因此可以将虚函数改为纯虚函数

  - **纯虚类没有构造函数**

  - 纯虚函数语法：virtual 返回值类型 函数名 （参数列表） = 0；当类中有了纯虚函数，这个类也称为抽象类

  - 抽象类的特点：

    - 无法实例化对象
    - 子类必须重写抽象类中的纯虚函数，否则也属于抽象类

  - ```c++
    #include<iostream>
    using namespace std;
    class Base
    {
    public:
    	virtual void func() = 0;//只要有一个纯虚函数，这个类就是抽象类,无法实例化
    };
    class Person : public Base
    {
    public:
    	void func()
    	{
    		cout << "好家伙" << endl;
    	}
    };
    
    void test()
    {
    	Base* p1 = new Person;
    	p1->func();
    }
    int main()
    {
    	test();
    	system("pause");
    }
    ```

- 多态案例

  - ```c++
    #include<iostream>
    #include<time.h>
    #include <stdlib.h>
    #define MAXSIZE 100
    using namespace std;
    //案例：制作饮品
    class AbstractDrinking
    {
    public:
    	//煮水
    	virtual void Boil()= 0;
    	//冲泡
    	virtual void Brew() = 0;
    	//倒入杯中
    	virtual void PourInCup() = 0;
    	//加入辅料
    	virtual void PutSth() = 0;
    	//制作饮品
    	void makeDrink()
    	{
    		Boil();
    		Brew();
    		PourInCup();
    		PutSth();
    	}
    private:
    
    };
    class Coffee : public AbstractDrinking
    {
    public:
    	virtual void Boil()
    	{
    		cout << "煮农夫山泉" << endl;
    	}
    	virtual void Brew()
    	{
    		cout << "冲泡咖啡" << endl;
    	}
    	virtual void PourInCup()
    	{
    		cout << "倒入杯中" << endl;
    	}
    	virtual void PutSth()
    	{
    		cout << "加糖" << endl;
    	}
    private:
    
    };
    //制作茶叶
    class Tea : public AbstractDrinking
    {
    public:
    	virtual void Boil()
    	{
    		cout << "煮矿泉水" << endl;
    	}
    	virtual void Brew()
    	{
    		cout << "冲茶叶" << endl;
    	}
    	virtual void PourInCup()
    	{
    		cout << "倒入杯中" << endl;
    	}
    	virtual void PutSth()
    	{
    		cout << "加入枸杞" << endl;
    	}
    private:
    
    };
    void doWork(AbstractDrinking* abs)
    {
    	abs->makeDrink();
    	delete abs;
    }
    void test01()
    {
    	//制作咖啡
    	doWork(new Coffee);
    	//制作茶叶
    	doWork(new Tea);
    	//多态：一种接口有多种形态
    }
    int main()
    {
    	test01();
    	system("pause");
    }
    ```

## 虚析构和纯虚析构

- 多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码，解决方式是将父类中的析构函数改为虚析构或者纯虚析构

- 虚析构和纯虚析构的共性

  - 可以解决父类指针释放子类对象
  - 都需要有具体的函数实现

- 虚析构和纯虚析构区别

  - 如果是**纯虚析构，该类属于抽象类，无法实例化对象**

- 虚析构语法：virtual ~类名(){}

- 纯虚析构语法：virtual ~类名()=0; 类名:: ~类名()

- 纯虚析构函数**既要有函数的声明，也要有代码的实现**（得单独写出来）

- 如果子类中没有堆区数据，可以不写为虚析构或者纯虚析构

- ```c++
  #include<iostream>
  using namespace std;
  //虚析构和纯虚析构
  class Animal
  {
  public:
  	Animal()
  	{
  		cout << "Animal构造函数调用" << endl;
  	}
  	/*virtual ~Animal()
  	{
  		cout << "Animal析构函数调用" << endl;
  	}*/
  	
  	virtual void speak() = 0;
  
  private:
  
  };
  Animal:: ~Animal()
  {
  	cout << "Animal纯虚析构函数调用"<<endl;
  }
  class Cat : public Animal
  {
  public:
  	Cat(string name)
  	{
  		m_name = new string(name);//堆区数据应该在析构函数释放掉
  	}
  	virtual void speak()
  	{
  		cout << *m_name << "小猫在说话" << endl;
  	}
  	string* m_name;
  	~Cat()
  	{
  		if (m_name != NULL)
  		{
  			cout << "Cat析构函数调用" << endl;
  			delete m_name;
  			m_name = NULL;
  		}
  	}
  };
  void test01()
  {
  	Animal* animal = new Cat("Tom");
  	animal->speak();
  	delete animal;
  }
  int main()
  {
  	test01();
  	system("pause");
  }
  ```

- 多态案例：电脑组装

  ```c++
  #include<iostream>
  using namespace std;
  class CPU
  {
  public:
  	virtual void calculate() = 0;
  private:
  
  };
  class GPU
  {
  public:
  	virtual void display() = 0;
  private:
  
  };
  class  RAM
  {
  public:
  	virtual void storage()= 0;
  
  private:
  
  };
  class  computer
  {
  public:
  	computer(CPU* cpu, GPU* gpu, RAM* ram)
  	{
  		m_cpu = cpu;
  		m_gpu = gpu;
  		m_ram = ram;
  	 }
  	void work()
  	{
  		m_cpu->calculate();
  		m_gpu->display();
  		m_ram->storage();
  	}
  	//提供析构函数释放
  	~computer()
  	{
  		//释放cpu零件
  		if (m_cpu != NULL)
  		{
  			delete m_cpu;
  			m_cpu = NULL;
  		}
  		//释放gpu零件
  		if (m_gpu != NULL)
  		{
  			delete m_gpu;
  			m_gpu = NULL;
  		}
  		//释放ram零件
  		if (m_ram != NULL)
  		{
  			delete m_ram;
  			m_ram = NULL;
  		}
  	}
  private:
  	CPU* m_cpu;
  	GPU* m_gpu;
  	RAM* m_ram;
  };
  //具体厂商
  class IntelCPU : public CPU
  {
  public:
  	virtual void calculate()
  	{
  		cout << "IntelCpu is working" << endl;
  	}
  
  private:
  
  };
  class IntelGPU :public GPU
  {
  public:
  	virtual void display()
  	{
  		cout << "IntelGpu is working" << endl;
  	}
  
  private:
  
  };
  class IntelRAM :public RAM
  {
  public:
  	virtual void storage()
  	{
  		cout << "IntelRAM is working" << endl;
  	}
  
  private:
  
  };
  //lenovo
  class LenovoCPU :public CPU
  {
  public:
  	virtual void calculate()
  	{
  		cout << "LenovoCpu is working" << endl;
  	}
  
  private:
  
  };
  class LenovoGPU :public GPU
  {
  public:
  	virtual void display()
  	{
  		cout << "LenovoGpu is working" << endl;
  	}
  
  private:
  
  };
  class LenovoRAM :public RAM
  {
  public:
  	virtual void storage()
  	{
  		cout << "LenovoRAM is working" << endl;
  	}
  
  private:
  
  };
  void test01()
  {
  	//第一台电脑零件
  	CPU* intelcpu = new IntelCPU;
  	GPU* intelgpu = new IntelGPU;
  	RAM* intelram = new IntelRAM;
  	computer* computer1 = new computer(intelcpu, intelgpu, intelram);
  	computer1->work();
  	delete computer1;
  	cout << "-------------------------------" << endl;
  	computer* computer2 = new computer(new LenovoCPU, new LenovoGPU, new LenovoRAM);
  	computer2->work();
  	delete computer2;
  }
  int main()
  {
  	test01();
  	system("pause");
  }
  ```

## 文件操作

- 程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放，通过文件可以将数据持久化

- c++中对文件操作需要包含头文件<fstream>

- 文件类型分为两种

  - 文本文件：文件以文本的ascii码形式存储在计算机中
  - 二进制文件：文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂他们

- 操作文件分为三大类：

  - ofstream:写操作（output file）
  - ifstream:读操作(input file)
  - fstream:读写操作

- **写文本文件的步骤****

  1. 包含头文件  #include<fstream>
  2. 创建流对象  ofstream ofs
  3. 打开文件  ofs.open(“文件路径”, 打开方式);
  4. 写数据 ofs<<“写入数据”
  5. 关闭文件 ofs.close()

- 文件打开方式：

  - | 打开方式    | 解释                       |
    | ----------- | -------------------------- |
    | ios::in     | 为读文件而打开文件         |
    | ios::out    | 为写文件而打开文件         |
    | ios::ate    | 初始位置在文件尾           |
    | ios::app    | 追加方式写文件             |
    | ios::trunc  | 如果文件存在先删除，再创建 |
    | ios::binary | 二进制方式                 |

  - 文件打开方式可以配合使用，利用|操作符；如 利用二进制方式写文件：ios::binary | ios::out

- ```c++
  #include<iostream>
  #include<fstream>//包含头文件
  using namespace std;
  void test01()
  {
  	//创建流对象
  	ofstream ofs;
  	//指定打开方式
  	ofs.open("text.txt", ios::binary|ios::out);
  	//写内容
  	ofs << "姓名： 张三" << endl;
  	ofs.close();
  
  }
  int main()
  {
  	test01();
  }
  ```

- **读文件步骤**：

  1. 包含头文件 #include<fstream>
  2. 创建流对象 ifstream ifs
  3. 打开文件并判断文件是否打开成功 ifs.open(“文件路径”，打开方式);
  4. 读数据：四种方式读数据
  5. 关闭文件: ifs.close();

- ```c++
  #include<iostream>
  #include<fstream>//包含头文件
  #include<string>
  using namespace std;
  void test01()
  {
  	//创建流对象
  	ifstream ifs;
  	//打开文件并判断是否打开成功
  	ifs.open("text.txt",ios::in);
  	if (!ifs.is_open())
  	{
  		cout << "文件打开失败" << endl;
  	}
  	//读数据
  	////第一种
  	//char buf[1024] = { 0 };
  	//while (ifs >> buf)
  	//{
  	//	cout << buf << endl;
  	//}
  	//ifs.close();
  	////第二种
  	//char buf[1024] = {0};
  	//while (ifs.getline(buf,sizeof(buf)))
  	//{
  	//	cout << buf << endl;
  	//}
  	//第三种
  	/*string buf;
  	while (getline(ifs, buf))
  	{
  		cout << buf << endl;
  	}*/
  	//第四种(不建议使用)
  	char c;
  	while ((c = ifs.get()) != EOF)//EOF end of file
  	{
  		cout << c;
  	}
  }
  int main()
  {
  	test01();
  }
  ```

- 二进制文件：以二进制的方式对文件进行读写操作，打开方式指定为ios::binary

  - ```c++
    #include<iostream>
    #include<fstream>//包含头文件
    #include<string>
    using namespace std;
    class Person
    {
    public:
    	char m_name[64];//姓名、
    	int age;
    
    private:
    
    };
    void test01()
    {
    	//创建流对象
    	ofstream ofs("person.txt", ios::out | ios::binary);
    	Person p = { "张三", 18 };
        //写文件
    	ofs.write((const char*)&p, sizeof(Person));
    	//关闭文件
    	ofs.close();
    }
    int main()
    {
    	test01();
    }
    ```

  - ```c++
    #include<iostream>
    #include<fstream>//包含头文件
    #include<string>
    using namespace std;
    //二进制文件的读取
    class Person
    {
    public:
    	char m_name[64];//姓名、
    	int age;
    
    private:
    
    };
    void test01()
    {
    	//创建流对象
    	ifstream ifs;
    	Person p = { "张三", 18 };
    	//打开文件，判断文件是否打开成功
    	ifs.open("Person.txt", ios::in | ios::binary);
    	if (!ifs.is_open())
    	{
    		cout << "文件打开失败" << endl;
    		return;
    	}
    	//读文件
    	Person p1;
    	ifs.read((char*)&p1, sizeof(Person));
    	//关闭文件
    	cout << "姓名:" << p1.m_name << "年龄：" << p1.age << endl;
    	ifs.close();
    }
    int main()
    {
    	test01();
    }
    ```

  - 

- 二级指针

## 函数模板

- C++提供另外一种编程思想称为**泛型编程**，主要利用的技术就是模板

- C++有函数模板和类模板

- 函数模板作用：建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个**虚拟的类型**来代表

- 语法

  ```c++
  template<typename T>
  ```

  template–声明创建模板

  typename–表明其后面的符号是一种数据类型，可以用class代替

  T--通用数据类型，名称可以替换，通常为大写字母

- ```c++
  #include<iostream>
  using namespace std;
  //函数模板
  template<typename T>//声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T代表一个通用数据类型
  void swap1(T& a, T& b)
  {
  	T temp;
  	temp = a;
  	a = b;
  	b = temp;
  }
  template<typename T>
  void swap2(T& a, T& b)
  {
  	T temp;
  	temp = a;
  	a = b;
  	b = temp;
  }
  void test01()
  {
  	int a = 10;
  	int b = 20;
  	swap1(a, b);//自动类型推导
  	swap2<int>(a, b);//显示指定类型
  	cout << "a=" << a
  		<< "b=" << b << endl;
  }
  int main()
  {
  	test01();
  	system("pause");
  	return 0;
  }
  ```

- 总结：模板的作用是类型参数化，提高了代码的复用性；函数模板利用关键字template；函数模板有两种使用方式：自动类型推导以及显示指定类型

- 注意事项：

  - 自动类型推导必须推导出一致的数据类型T才可以使用

  - 模板必须要确定出T的数据类型才可以使用

  - ```c++
    template<class T>
    void func()
    {
    	cout << "hhhh" << endl;
    }
    int main()
    {
    	func<int>();
    	system("pause");
    	return 0;
    }
    ```

  - ```c++
    #include<iostream>
    using namespace std;
    //函数模板
    //实现通用 对数组进行排序的函数
    template<class T>
    void mySwap(T& a, T& b)
    {
    	T temp = a;
    	a = b;
    	b = temp;
    }
    template <class T>
    void printArray(T arr[], int len)
    {
    	for (int i = 0; i < len; i++)
    	{
    		cout << arr[i]<<" ";
    	}
    	cout << endl;
    }
    template <class T>
    void mySort(T arr[], int len)
    {
    	for (int i = 0; i < len; i++)
    	{
    		int max = i;
    		for (int j = i + 1; j < len; j++)
    		{
    			if (arr[max] < arr[j])
    			{
    				max = j;
    			}
    		}
    		if (max != i)
    		{
    			mySwap(arr[max], arr[i]);
    		}
    	}
    }
    void test01()
    {
    	char charr[] = "gfreewdg";
    	int num = sizeof(charr) / sizeof(char);
    	mySort(charr, num);
    	printArray(charr, num);
    }
    void test02()
    {
    	int arrint[] = {2,4,6,1,7,3};
    	int num = sizeof(arrint) / sizeof(int);
    	mySort(arrint, num);
    	printArray(arrint,num);
    }
    
    int main()
    {
    	test01();
    	test02();
    	system("pause");
    }
    ```

- 普通函数与函数模板区别

  - 普通函数可以发生自动类型转换（隐式类型转换）

  - 函数模板调用时，利用自动类型推导，不会发生隐式类型转换

  - 如果利用显示指定类型方式，可以发生隐式类型转换

  - ```c++
    #include<iostream>
    using namespace std;
    //函数模板
    template <class T>
    T myAdd01(T a, T b)
    {
    	return a + b;
    }
    void test01()
    {
    	int a = 10;
    	char b = 's';
    	cout << myAdd01<int>(a, b);
    }
    int main()
    {
    	test01();
    }
    ```

- 普通函数与函数模板的调用规则

  - 如果函数模板和普通函数都可以实现，**优先调用普通函数**

  - ```c++
    #include<iostream>
    using namespace std;
    //函数模板与普通函数的调用规则
    void myPrint(int a, int b);//此时也是调用普通函数，报错
    template<class T>
    void myPrint(T a, T b)
    {
    	cout << "调用模板函数" << endl;
    }
    void test01()
    {
    	int a = 19;
    	int b = 29;
    	myPrint(a, b);
    }
    int main()
    {
    	test01();
    }
    ```

  - 可以**通过空模板参数列表来强制调用函数模板**

  - ```c++
    #include<iostream>
    using namespace std;
    //函数模板与普通函数的调用规则
    void myPrint(int a, int b);
    
    template<class T>
    void myPrint(T a, T b)
    {
    	cout << "调用模板函数" << endl;
    }
    void test01()
    {
    	int a = 19;
    	int b = 29;
    	myPrint<>(a, b);//强制调用函数模板
    }
    int main()
    {
    	test01();
    }
    ```

  - 函数模板也可以发生重载

  - ```c++
    #include<iostream>
    using namespace std;
    //函数模板与普通函数的调用规则
    void myPrint(int a, int b);
    //{
    //	cout << "调用普通函数" << endl;
    //}
    template<class T>
    void myPrint(T a, T b)
    {
    	cout << "调用模板函数" << endl;
    }
    template<class T>
    void myPrint(T a, T b, T c)
    {
    	cout << "调用重载的模板函数" << endl;
    }
    void test01()
    {
    	int a = 19;
    	int b = 29;
    	int c = 32;
    	myPrint<>(a, b, c);
    }
    int main()
    {
    	test01();
    }
    ```

  - 如果函数模板可以产生更好的匹配，优先调用函数模板

  - ```c++
    #include<iostream>
    using namespace std;
    //函数模板与普通函数的调用规则
    void myPrint(int a, int b)
    {
    	cout << "调用普通函数" << endl;
    }
    template<class T>
    void myPrint(T a, T b)
    {
    	cout << "调用模板函数" << endl;
    }
    void test01()
    {
    	char a = 19;
    	char b = 29;
    	myPrint(a, b);//此时调用模板时不用转换数据类型，直接调用模板
    }
    int main()
    {
    	test01();
    }
    ```

  - 在实际开发中，使用普通函数就不会使用函数模板

- 模板的局限性：模板的通用性并不是万能的，某些特定的数据类型需要用具体化方式做特殊实现

- ```c++
  #include<iostream>
  using namespace std;
  //函数模板的局限性
  class  Person
  {
  public:
  	Person(string name, int age);
  	~ Person();
  	string m_name;
  	int m_age;
  
  private:
  
  };
  
   Person:: Person(string name, int age)
  {
  	 this->m_name = name;
  	 this->m_age = age;
  }
  
   Person::~ Person()
  {
  }
   template<class T>
   bool myCompare(T& a, T& b)
   {
  	 if (a == b)
  	 {
  		 return true;
  	 }
  	 else
  	 {
  		 return false;
  	 }
   }
   //利用具体化的Person的版本实现代码，具体化优先调用
   template<> bool myCompare(Person& a, Person& b)
   {
  	 if (a.m_name == b.m_name)
  	 {
  		 return true;
  	 }
  	 else
  	 {
  		 return false;
  	 }
   }
   void test01()
   {
  	 int a = 10;
  	 int b = 20;
  	 bool ret = myCompare(a, b);
  	 if (ret)
  	 {
  		 cout << "a == b" << endl;
  	 }
  	 else
  	 {
  		 cout << "a != b" << endl;
  	 }
  	 Person p1("liujun", 20);
  	 Person p2("liujun", 23);
  	 bool ret1 = myCompare(p1, p2);
  	 cout << "具体化：" << ret1 << endl;
   }
   int main()
   {
  	 test01();
  	 system("pause");
   }
  ```

- 学习模板并不是为了写模板，而是为了在STL能够运用系统提供的模板

## 类模板

- 类模板的作用：建立一个通用类，类中的成员数据类型可以不具体指定，用一个虚拟的类型来代表

- 语法

  - ```c++
    template<typename T>
    类
    ```

  - 解释：

    - template–声明创建模板
    - typename–表明其后面的符号是一种数据类型，可以用class代替
    - T--通用数据类型，名称可以替换，通常为大写字母

- ```c++
  #include<iostream>
  using namespace std;
  //类模板
  template <typename NameType, typename AgeType>
  class Person
  {
  public:
  	Person(NameType name, AgeType age)
  	{
  		this->m_name = name;
  		this->m_age = age;
  	}
  	NameType m_name;
  	AgeType m_age;
  };
  void test01()
  {
  	Person<string, int>p1("liujun", 34);//模板参数列表
  	cout << "姓名为" << p1.m_name << "\n"
  		<< "年龄为" << p1.m_age << endl;
  }
  int main()
  {
  	test01();
  }
  ```

- 类模板与函数模板十分类似，在声明模板template后面加类，此类称为类模板

- 类模板与函数模板的区别

  - **类模板没有自动类型推导的使用方式**

  - 类模板在模板参数列表中可以有**默认参数**

  - ```c++
    #include<iostream>
    using namespace std;
    //类模板
    template <typename NameType, typename AgeType = int>//AgeType默认为整型
    class Person
    {
    public:
    	Person(NameType name, AgeType age)
    	{
    		this->m_name = name;
    		this->m_age = age;
    	}
    	NameType m_name;
    	AgeType m_age;
    };
    void test01()
    {
    	Person<string, int>p1("liujun", 34);//模板参数列表
    	cout << "姓名为" << p1.m_name << "\n"
    		<< "年龄为" << p1.m_age << endl;
    }
    void test02()
    {
    	Person<string>p2("孙悟空", 100);//有默认数据类型，可以不用声明
    }
    int main()
    {
    	test01();
    	system("pause");
    }
    ```

- 类模板中成员函数和普通类中成员函数创建时机是有区别的

  - 普通类中成员函数一开始就可以创建

  - 类模板中的成员函数在调用时才创建

  - ```c++
    #include<iostream>
    using namespace std;
    //类模板中成员函数的创建时机
    class Person1
    {
    public:
    	void showPerson1()
    	{
    		cout << "Person1 show" << endl;
    	}
    };
    class Person2
    {
    public:
    	void showPerson2()
    	{
    		cout << "Person2 show" << endl;
    	}
    
    private:
    
    };
    template<typename T>
    class Show
    {
    public:
    	T obj;
    	//类模板中成员函数在调用时才创建
    	void func1()
    	{
    		obj.showPerson1();
    	}
    	void func2()
    	{
    		obj.showPerson2();
    	}
    
    private:
    
    };
    void test01()
    {
    	Show<Person1>m1;
    	m1.func1();
    }
    int main()
    {
    	test01();
    }
    ```

- 类模板对象做函数参数：类模板实例化出的对象；向函数传参的方式

  - 向函数传参一共有三种方式

    - 指定传入类型--直接显示对象的数据类型

    - 参数模板化--将对象中的参数变为模板进行传递

    - 整个类模板化--将这个对象类型模板化进行传递

    - ```c++
      #include<iostream>
      using namespace std;
      //类模板对象做函数参数
      template<class T1, class T2>
      class Person
      {
      public:
      	Person(T1 name, T2 age)
      	{
      		this->m_name = name;
      		this->m_age = age;
      	}
      	void showPerson()
      	{
      		cout << "姓名" << this->m_name
      			<< "\n年龄" << this->m_age << endl;
      	}
      	T1 m_name;
      	T2 m_age;
      private:
      
      };
      //指定传入类型,最常用的
      void printPerson1(Person<string, int> &p)
      {
      	p.showPerson();
      }
      
      
      void test01()
      {
      	Person<string, int>p1("孙悟空", 100);
      	printPerson1(p1);
      }
      //参数模板化
      template<class T1, class T2>
      void printPerson2(Person<T1, T2>& p)
      {
      	p.showPerson();
      	cout << "T1的数据类型为" << typeid(T1).name() << endl
      		<< "T2的数据类型为" << typeid(T2).name() << endl;
      }
      void test02()
      {
      	Person<string, int> p2("猪八戒", 43);
      	printPerson2(p2);
      }
      //将整个类模板化
      template<class T>
      void printPerson3(T& p)
      {
      	p.showPerson();
      	cout << "T的数据类型为" << typeid(T).name() << endl;
      }
      void test03()
      {
      	Person<string, int>P3("沙僧", 43);
      	printPerson3(P3);
      }
      int main()
      {
      	test01();
      	test02();
      	test03();
      }
      ```

- 类模板与继承

  - 当子类继承的父类是一个类模板时，子类在声明的时候要指定出父类中T的类型

  - 如果不指定，编译器无法给子类分配内存

  - 如果想灵活指定出父类中T的类型，子类也需要变为类模板

  - ```c++
    #include<iostream>
    using namespace std;
    //类模板与继承
    template<class T>
    class Base
    {
    public:
    	T m;
    };
    class Son :public Base<int>//必须要知道父类中T的数据类型才能够继承给子类
    {
    
    };
    void test01()
    {
    	Son s1;
    }
    //如果想灵活指定父类中T类型，子类也需要变类模板
    template<class T1, class T2>
    class Son1 :public Base<T2>
    {
    public:
    	Son1()
    	{
    		cout << "T1的数据类型为" << typeid(T1).name()
    			<< "\nT2的数据类型为" << typeid(T2).name() << endl;
    	}
    	T1 obj;
    };
    void test02()
    {
    	Son1<int, char>s1;
    }
    int main()
    {
    	test01();
    	test02();
    }
    	
    ```

- 类模板的成员函数的类外实现

```c++
#include<iostream>
using namespace std;
//类模板成员函数类外实现
template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	void showPerson();
	T1 m_name;
	T2 m_age;
};
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->m_name = name;
	this->m_age = age;
}
template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "姓名" << this->m_name
		<< "\t年龄" << this->m_age << endl;
}
void test01()
{
	Person<string, int> P1("liujun", 43);
	P1.showPerson();
}
int main()
{
	test01();
}
	
```

- 类模板分文件编写

  - 第一种解决方式：直接包含.cpp文件

  - 第二种解决方式：将.h文件以及.cpp文件中的内容写到一起，将后缀名改为.hpp文件(实际开发中用的多)

  - ```c++
    // person.hpp
    template<class T1, class T2>
    Person<T1, T2>::Person(T1 name, T2 age)
    {
    	this->m_name = name;
    	this->m_age = age;
    }
    template<class T1, class T2>
    void Person<T1, T2>::showPerson()
    {
    	cout << "姓名" << this->m_name
    		<< "\t年龄" << this->m_age << endl;
    }
    ```

  - ```c++
    //test1028.cpp
    #include<iostream>
    #include"person.hpp"
    using namespace std;
    void test01()
    {
    	Person<string, int> P1("liujun", 43);
    	P1.showPerson();
    }
    int main()
    {
    	test01();
    }
    ```

- 类模板与友元函数

  - 全局函数类内实现--直接在类内声明友元函数即可

  - 全局函数类外实现-需要提前让编译器知道全局函数的存在

  - ```c++
    #include<iostream>
    using namespace std;
    template<class T1, class T2>//提前告诉编译器有person模板类
    class Person;
    //全局函数类外实现
    template<class T1, class T2>//提前告诉编译器有全局函数实现
    void printPerson2(Person<T1, T2> p)
    {
    	cout << "姓名" << p.m_name
    		<< "\t年龄" << p.m_age << endl;
    }
    template<class T1, class T2>
    class Person
    {
    	//全局函数在类内实现
    	friend void printPerson(Person<T1, T2> p)
    	{
    		cout << "姓名" << p.m_name
    			<< "\t年龄" << p.m_age << endl;
    	}
    	friend void printPerson2<>(Person<T1, T2> p);//加空模板参数列表<>代表函数模板的声明
    public:
    	Person(T1 name, T2 age)
    	{
    		this->m_name = name;
    		this->m_age = age;
    	}
    private:
    	T1 m_name;
    	T2 m_age;
    };
    
    
    void test01()
    {
    	Person<string, int> P1("liuj",23);
    	printPerson(P1);
    
    }
    
    void test02()
    {
    	Person<string, int>P2("hao", 32);
    	printPerson2(P2);
    }
    int main()
    {
    	test01();
    	test02();
    	system("pause");
    }
    ```

  - 没有特殊情况都使用类内实现

- ```c++
  myarray.hpp
   #pragma once
  #include<iostream>
  using namespace std;
  //数组类封装；类模板案例
  template<class T>
  class MyArray
  {
  public:
  	MyArray(int capacity)//有参构造
  	{
  		cout << "有参构造调用" << endl;
  		this->m_capacity = capacity;
  		this->m_size = 0;
  		this->pAddress = new T[this->m_capacity];
  	}
  	//拷贝构造
  	MyArray(const MyArray& arr)
  	{
  		cout << "拷贝构造调用" << endl;
  		this->m_capacity = arr.m_capacity;
  		this->m_size = arr.m_size;
  		//深拷贝
  		this->pAddress = new T[arr.m_capacity];
  		for (int i = 0; i < this->m_size; i++)
  		{
  			this->pAddress[i] = arr.pAddress[i];
  		}
  		//return *this;
  	}
  	//operator= 防止浅拷贝问题
  	MyArray& operator=(const MyArray& arr)
  	{
  		//先判断原来堆区是否有数据，如果有先释放
  		if (this->pAddress != NULL)
  		{
  			delete[] this->pAddress;
  			this->pAddress = NULL;
  			this->m_capacity = 0;
  			this->m_size = 0;
  		}
  		this->m_capacity = arr.m_capacity;
  		this->m_size = arr.m_size;
  		this->pAddress = new T[arr.m_capacity];
  		for (int j = 0; j < this->m_size; j++)
  		{
  			this->pAddress[j] = arr.pAddress[j];
  		}
  		return *this;
  	}
  	//尾插法
  	void Push_Back(const T &val)
  	{
  		//判断容量是否等于大小
  		if (this->m_capacity == this->m_size)
  		{
  			return;
  		}
  		this->pAddress[this->m_size] = val;
  		this->m_size++;
  	}
  	//尾删法
  	void Pop_Back()
  	{
  		//让用户访问不到最后一个元素
  		if (this->m_size == 0)
  		{
  			return;
  		}
  		this->m_size--;
  	}
  	//通过下标方式访问数组中的元素
  	T& operator[](int index)
  	{
  		return this->pAddress[index];
  	}
  	//返回数组容量
  	int getCapacity()
  	{
  		return this->m_capacity;
  	}
  	int getSize()
  	{
  		return this->m_size;
  	}
  	~MyArray()
  	{
  		if (this->pAddress != NULL)
  		{
  			delete[] this->pAddress;/
  			this->pAddress = NULL;
  		}
  		cout << "析构函数调用" << endl;
  	}
  
  private:
  	T* pAddress;//指针指向堆区开辟真实数组
  	int m_capacity;//数组容量
  	int m_size;//数组大小
  
  };
  ///----------------------------------------------------------------------//
  //myarray.cpp
  #include<iostream>
  #include"myarray.hpp"
  using namespace std;
  void printIntArray(MyArray<int>& arr)
  {
  	for (int i = 0; i < arr.getSize(); i++)
  	{
  		cout << arr[i] << endl;
  	}
  }
  void test01()
  {
  	MyArray<int> arr1(3);//有参构造
  	for (int i = 0; i < 3; i++)
  	{
  		arr1.Push_Back(i);
  	}
  	printIntArray(arr1);
  	cout << "arr1的容量为" << arr1.getCapacity() << endl
  		<< "arr1的大小为" << arr1.getSize() << endl;
  	MyArray<int> arr2(arr1);
  	cout << "arr2的打印输出为";
  	printIntArray(arr2);
  	arr2.Pop_Back();
  	printIntArray(arr2);
  	cout << "arr2的容量为" << arr2.getCapacity() << endl
  		<< "arr2的大小为" << arr2.getSize() << endl;
  
  }
  //测试自定义数据类型
  class Person
  {
  public:
  	Person() {};
  	Person(string name, int age)
  	{
  		this->m_name = name;
  		this->m_age = age;
  	}
  	~Person() {};
  	string m_name;
  	int m_age;
  private:
  
  };
  void printPersonArray(MyArray<Person>& arr)
  {
  	for (int i = 0; i < arr.getSize(); i++)
  	{
  		cout << "姓名" << arr[i].m_name
  			<< "\t年龄" << arr[i].m_age << endl;
  	}
  }
  void test02()
  {
  	MyArray<Person>arr(10);
  	Person p1("赵云", 23);
  	Person p2("曹操", 32);
  	Person p3("诸葛亮", 54);
  	Person p4("司马懿", 30);
  	Person p5("吕布", 40);
  	//将数据插入到数组中
  	arr.Push_Back(p1);
  	arr.Push_Back(p2);
  	arr.Push_Back(p3);
  	arr.Push_Back(p4);
  	arr.Push_Back(p5);
  	printPersonArray(arr);
  	cout << "arr的容量" << arr.getCapacity() << endl;
  	cout << "arr的大小" << arr.getSize() << endl;
  }
  int main()
  {
  	test01();
  	test02();
  }
  
  ```

## STL

- 长久以来，软件界一直希望建立一种可以重复利用的东西，C++的**面向对象**和**泛型编程**思想，目的就是复用性提升；大多数情况下，数据结构和算法都未能有一套标准导致被迫从事大量重复性工作；为了建立数据结构和算法的一套标准，诞生了STL

- STL基本概念

  - STL（standard template library,标准模板库 ）
  - **STL从广义上分为容器，算法和迭代器**
  - STL几乎所有代码都采用了模板类或者模板函数

- STL**六大组件**

  - 容器：各种数据结构，如vector，list, deque, set, map等，用来存放数据
  - 算法：各种常用的算法，如sort, find, copy, for_each等
  - 迭代器：扮演了容器与算法之间的胶合剂
  - 仿函数：行为类似函数，可作为算法的某种策略；重载()
  - 适配器：一种用来修饰容器或者仿函数或迭代器接口的东西
  - 空间适配器：负责空间的配置与管理

- 容器分为**序列式容器**和**关联式容器**

  - 序列式容器强调值的排序，序列式容器中的每个元素均有固定的元素
  - 关联式容器：二叉树结构，各元素之间没有严格的物理上的顺序关系

- 算法：有限的步骤解决逻辑或数学上的问题

  - 质变算法：是指运算过程中会更改区间内的元素内容，如拷贝替换和删除
  - 非质变算法是指运算过程中不会更改区间内的元素内容，例如查找，计数，遍历等

- 迭代器：提供一种方法，使之能够依序访问某个容器所含的各个元素，而又无需暴露该容器的内部表示方式

  - 每个容器都有自己专属的迭代器

  - 迭代器使用非常类似于指针，初学阶段可以将迭代器理解为指针

  - 迭代器种类(常用的迭代器为**双向迭代器**和**随机访问迭代器**)

    | 种类           | 功能                                                     | 支持运算                           |
    | -------------- | -------------------------------------------------------- | ---------------------------------- |
    | 输入迭代器     | 对数据的只读访问                                         | 只读，支持++，==，！=              |
    | 输出迭代器     | 对数据的只写访问                                         | 只写，支持++                       |
    | 前向迭代器     | 读写操作，并能向前推进迭代器                             | 读写，支持++，==，！=              |
    | 双向迭代器     | 读写操作，并能向前和向后操作                             | 读写，支持++，--                   |
    | 随机访问迭代器 | 读写操作，可以以跳跃的方式访问任意数据，功能最强的迭代器 | 读写，支持++，==，[n],-n,<,<=,>,>= |

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>//标准算法的头文件
    using namespace std;
    //vector容器存放内置数据类型
    void myprint(int val)
    {
    	cout << val << endl;
    }
    void test01()
    {
    	//创建一个vector容器（数组）
    	vector<int> v;
    	//向容器中插入数据
    	v.push_back(2);
    	v.push_back(6);
    	v.push_back(5);
    	v.push_back(9);
    	v.push_back(3);
    	////通过迭代器访问容器中的数据
    	//vector<int>::iterator itBegin = v.begin();//起始迭代器，指向容器中第一个元素
    	//vector<int>::iterator itEnd = v.end();//结束迭代器，指向容器中最后一个元素的下一个位置
    	////第一种遍历方式
    	//while (itBegin != itEnd)
    	//{
    	//	cout << *itBegin << endl;
    	//	itBegin++;
    	//}
    	/*********************************/
    	//第二种遍历方式
    	/*for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    	{
    		cout << *it << endl;
    	}*/
    	/*第三种遍历方式，利用STL提供遍历算法*/
    	for_each(v.begin(), v.end(), myprint);
    }
    int main()
    {
    	test01();
    }
    ```

- vector容器嵌套容器

  ```c++
  #include<iostream>
  #include<vector>
  #include<algorithm>//标准算法的头文件
  using namespace std;
  void test01()
  {
  	vector<vector<int>> v;
  	vector<int> v1;
  	vector<int> v2;
  	vector<int> v3;
  	vector<int> v4;
  	for (int i = 0; i < 4; i++)
  	{
  		v1.push_back(i + 1);
  		v2.push_back(i + 2);
  		v3.push_back(i + 3);
  		v4.push_back(i + 4);
  
  	}
  	v.push_back(v1);
  	v.push_back(v2);
  	v.push_back(v3);
  	v.push_back(v4);
  	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
  	{
  		for (vector<int>::iterator it1 = (*it).begin(); it1 != (*it).end(); it1++)
  		{
  			cout << *it1 << "\t";//容器嵌套
  		}
  		cout << endl;
  	}
  }
  int main()
  {
  	test01();
  }
  ```

- string基本概念

  - 本质：string是c++的字符串，而<u>string本质上是一个类</u>
  - string和char*的区别
    - char*是一个指针
    - string是一个类，类的内部封装了char*,管理这个字符串，是一个char*型的容器

- 特点

  - string内部封装了很多成员方法，例如：查找find，拷贝copy， 删除delete，替换replace，插入insert
  - string管理char*所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责

- string构造函数

  ```c++
  #include<iostream>
  using namespace std;
  void test01()
  {
  	string s1;//默认构造，创建一个空字符串
  	const char* str = "hello world";
  	string s2(str); //使用字符串str初始化
  	cout << "s2=" << s2 << endl;
  	string s3(s2);
  	cout << "s3=" << s3 << endl;//使用一个string对象初始化另一个string对象
  	string s4(10, 'a');//使用N个字符c初始化
  	cout << "S4=" << s4 << endl;
  }
  int main()
  {
  	test01();
  }
  ```

- string赋值操作

  ```c++
  #include<iostream>
  using namespace std;
  //string的赋值操作
  void test01()
  {
  	string str1;
  	str1 = "Hello World";//char*字符串赋值给当前字符串
  	cout << "str1=" << str1 << endl;
  	string str2;
  	str2 = str1;//把字符串S赋值给当前的字符串
  	cout << "str2= " << str2 << endl;
  	string str3;
  	str3 = 'a';//字符赋值给当前的字符串
  	cout << "str3=" << str3 << endl;
  	string str4;
  	str4.assign("Hello c++");//把字符串S赋值给当前的字符串
  	cout << "str4=" << str4 << endl;
  	string str5;
  	str5.assign("Hello c++", 5);//把字符串前n个字符赋值给字符串
  	cout << "str5=" << str5 << endl;
  	string str6;
  	str6.assign(str5); //把字符串S赋值给当前的字符串
  	cout << "str6=" << str6 << endl;
  	string str7;
  	str7.assign(10, 'w');//用N个字符赋值给字符串
  	cout << "str7=" << str7 << endl;
  }
  int main()
  {
  	test01();
  }
  ```

- string字符串的拼接

  - 实现字符串末尾拼接字符串

  - ```c++
    #include<iostream>
    using namespace std;
    //string的拼接操作
    void test01()
    {
    	string str1 = "hi";
    	str1 += "world";//重载+=操作符
    	cout << "str1= "<<str1 << endl;
    	str1 += 'a';//重载+=操作符
    	cout << "str1= " << str1 << endl;
    	string str2 = "internet";
    	str1 += str2;
    	cout << "str1= " << str1 << endl;
    	string str3 = "work";
    	str3.append("boring");
    	cout << "str3= " << str3 << endl;
    	str3.append("gameabcde", 4);
    	cout << "str3= " << str3 << endl;
    	str3.append(str2);
    	cout << "str3= " << str3 << endl;
    	str3.append(str2, 4, 3);//从0开始截取，截取三位字符
    	cout << "str3= " << str3 << endl;
    }
    int main()
    {
    	test01();
    }
    ```

- string查找和替换

  - 查找：查找指定字符串是否存在

  - 替换：在指定位置替换字符串

  - ```c++
    #include<iostream>
    using namespace std;
    //string的查找和替换
    //1 查找
    void test01()
    {
    	
    	string str1 = "abcdefg";
    	int pos = str1.find("de");//从0开始查找字符串中是否有de;若没有返回-1，若有返回起始位置值
    	if (pos != -1)
    	{
    		cout << "字符串找到" << endl;
    	}
    	else
    	{
    		cout << "字符串不存在" << endl;
    	}
    	pos = str1.rfind("de");//rfind是从右往左查找，find是从左往右查找
    	cout << "pos" << pos << endl;
    }
    //2 替换
    void test02()
    {
    	string str2 = "abcdefg";
    	str2.replace(1, 3, "1111");//从第一个位置到第三个位置替换为字符串1111
    	cout << str2 << endl;
    }
    int main()
    {
    	test01();
    	test02();
    }
    ```

- string字符串比较

  - 字符串的比较是按照字符的ascii码进行对比

    - = 返回0 > 返回1 < 返回-1

    - 最大的用途是判断两个字符串之间是否相等

    - ```c++
      #include<iostream>
      using namespace std;
      //string的比较
      void test01()
      {
      	string str1 = "hello";
      	string str2 = "hello";
      	if (str1.compare(str2) == 0)
      	{
      		cout << "str1 = str2" << endl;
      	}
      	else if (str1.compare(str2) > 0)
      	{
      		cout << "str1>str2" << endl;
      	}
      	else if (str1.compare(str2) < 0)
      	{
      		cout << "str1 < str2" << endl;
      	}
      }
      int main()
      {
      	test01();
      }
      ```

- string字符存取（对单个字符进行读或者写）

  - ```c++
    #include<iostream>
    using namespace std;
    //string字符存取
    void test01()
    {
    	string str1 = "hello";
    	//1 通过[]访问单个字符
    	for (int i = 0; i < str1.size(); i++)
    	{
    		cout << str1[i] << " ";
    	}
    	cout << endl;
    	//2 通过at方式访问单个字符
    	for (int i = 0; i < str1.size(); i++)
    	{
    		cout << str1.at(i) << " ";
    	}
    	cout << endl;
    	//修改单个字符
    	str1[0] = 'x';
    	cout << str1 << endl;
    	str1.at(2) = 'c';
    	cout << str1 << endl;
    }
    int main()
    {
    	test01();
    }
    ```

- string字符串插入和删除

  - ```c++
    #include<iostream>
    using namespace std;
    //string字符de插入和删除
    void test01()
    {
    	string str = "hello";
    	//插入
    	str.insert(1, "4444");//在第一个位置中插入4444
    	cout << str << endl;
    	//删除
    	str.erase(1, 4);//从第一个位置起删除4位
    	cout << str << endl;
    }
    int main()
    {
    	test01();
    }
    ```

  - 

- string子串

  - ```c++
    #include<iostream>
    using namespace std;
    //string字符de子串
    void test01()
    {
    	string str = "hello";
    	string substr = str.substr(1, 3);//从1开始截取，截取三位
    	cout << substr << endl;
    }
    void test02()
    {
    	string email = "zhangsan@163.com";
    	//从邮件中获取用户信息
    	int pos = email.find("@");
    	string userName = email.substr(0, pos);
    	cout << userName << endl;
    }
    int main()
    {
    	test01();
    	test02();
    }
    ```


## vector容器

- vector数据结构和数组非常类似，也称为**单端数组**

- 和普通数组不同的是普通数组是静态空间，而**vector可以动态扩展**

- 动态扩展并不是在原有的空间中接上新空间，而是查找更大的空间，然后将原数据拷贝到新空间，释放原空间

- vector容器的迭代器是支持随机访问的迭代器

- vector的构造函数：创建vector容器

  - ```c++
    vector<T>;//采用模板类实现，默认构造函数
    vector<v.begin(),v.end()>;//将[begin(),end())区间中的元素拷贝给本身
    vector<n,elem>;//构造函数n个elem拷贝给本身
    vector<const vector &vec>;//拷贝构造函数
    ```

  - ```c++
    #include<iostream>
    #include<vector>
    using namespace std;
    //vector容器的构造
    void printVector(vector<int>& v)
    {
    	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    void test01()
    {
    	vector<int> v1;
    	for (int i = 0; i < 10; i++)
    	{
    		v1.push_back(i + 1);
    	}
    	printVector(v1);
    	//通过区间方式进行构造
    	vector<int>v2(v1.begin(), v1.end());
    	printVector(v2);
    	//n个elem方式构造
    	vector<int>v3(10, 20);
    	printVector(v3);
    	//拷贝构造
    	vector<int>v4(v3);
    	printVector(v4);
    }
    int main()
    {
    	test01();
    	
    }
    ```

- vector赋值操作

  - ```c++
    #include<iostream>
    #include<vector>
    using namespace std;
    //vector容器的赋值操作
    void printVector(vector<int>& v)
    {
    	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    void test01()
    {
    	vector<int> v1;
    	for (int i = 0; i < 10; i++)
    	{
    		v1.push_back(i + 1);
    	}
    	//operator
    	vector<int> v2;
    	v2 = v1;
    	//assign
    	vector<int> v3;
    	v3.assign(v1.begin(), v1.end());
    	printVector(v3);
    	//n个elem
    	vector<int> v4;
    	v4.assign(10, 200);
    	printVector(v4);
    
    
    }
    int main()
    {
    	test01();
    	
    }
    ```

- vector容量和大小

  - ```c++
    #include<iostream>
    #include<vector>
    using namespace std;
    //vector容器的容量和大小操作
    void printVector(vector<int>& v)
    {
    	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    void test01()
    {
    	vector<int> v1;
    	for (int i = 0; i < 10; i++)
    	{
    		v1.push_back(i + 1);
    	}
    	//判断是否为空
    	if (v1.empty())
    	{
    		cout << "v1为空" << endl;
    	}
    	else
    	{
    		cout << "v1不为空" << endl;
    		cout << "v1的容量为" << v1.capacity() << endl;
    		cout << "v1的大小为" << v1.size() << endl;
    	}
    	v1.resize(20, 32);//如果重新指定的大小比原来过长，默认使用0来填充，利用重载版本可以指定填充值
    	v1.resize(5);//如果重新指定的比原来小了，则会将多余的删除
    	printVector(v1);
    
    }
    int main()
    {
    	test01();
    	
    }
    ```

- vector的插入和删除

  - ```c++
    #include<iostream>
    #include<vector>
    using namespace std;
    //vector容器的插入和删除
    void printVector(vector<int>& v)
    {
    	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    void test01()
    {
    	vector<int> v1;
    	for (int i = 0; i < 10; i++)
    	{
    		v1.push_back(i + 1);//尾插法插入数据
    	}
    	//尾删法
    	v1.pop_back();
    	printVector(v1);
    	//插入
    	v1.insert(v1.begin()+5, 100);//第一个参数必须是迭代器
    	printVector(v1);
    	v1.insert(v1.begin(), 2, 34);//插入N个数据
    	printVector(v1);
    	//删除
    	v1.erase(v1.begin());//参数需要迭代器
    	printVector(v1);
    	v1.erase(v1.begin(), v1.end());//直接清空容器
    	printVector(v1);
    	v1.clear();
    	printVector(v1);//清空
    }
    int main()
    {
    	test01();
    	
    }
    ```

- vector数据存取

  - ```c++
    #include<iostream>
    #include<vector>
    using namespace std;
    //vector容器的数据存取
    void test01()
    {
    	vector<int> v1;
    	for (int i = 0; i < 10; i++)
    	{
    		v1.push_back(i + 1);//尾插法插入数据
    	}
    	for (int i = 0; i < v1.size(); i++)
    	{
    		cout << v1[i] << " ";
    	}
    	cout << endl;
    	//利用at方式访问元素
    	for (int i = 0; i < v1.size(); i++)
    	{
    		cout << v1.at(i) << " ";
    	}
    	cout << endl;
    	//获取第一个元素
    	cout << "第一个元素为" << v1.front() << endl;
    	//获取最后一个元素
    	cout << "最后一个元素为" << v1.back() << endl;
    }
    int main()
    {
    	test01();
    	
    }
    ```

- vector互换容器

  - ```c++
    #include<iostream>
    #include<vector>
    using namespace std;
    //vector容器互换
    void printVector(vector<int>& v)
    {
    	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    void test01()
    {
    	vector<int> v1;
    	for (int i = 0; i < 10; i++)
    	{
    		v1.push_back(i + 1);//尾插法插入数据
    	}
    	printVector(v1);
    	vector<int> v2;
    	for (int j = 10; j > 0; j--)
    	{
    		v2.push_back(j);
    	}
    	printVector(v2);
    	cout << "交换后" << endl;
    	v1.swap(v2);
    	printVector(v1);
    	printVector(v2);
    }
    //互换的实际用途是收缩储存空间
    void test02()
    {
    	vector<int> v3;
    	for (int i = 0; i < 10000; i++)
    	{
    		v3.push_back(i);
    	}
    	cout << "v3的容量为" << v3.capacity() << endl;
    	cout << "v3的大小为" << v3.size() << endl;
    	v3.resize(3);//此时会浪费内存空间
    	cout << "v3的容量为" << v3.capacity() << endl;
    	cout << "v3的大小为" << v3.size() << endl;
    	//巧用swap收缩内存（拷贝构造匿名对象，匿名对象由系统自动回收）
    	vector<int>(v3).swap(v3);
    	cout << "v3的容量为" << v3.capacity() << endl;
    	cout << "v3的大小为" << v3.size() << endl;
    
    }
    int main()
    {
    	test01();
    	test02();
    }
    ```

- vector预留空间

  - 功能：减少vector在动态扩展容量时的扩展次数

  - ```c++
    #include<iostream>
    #include<vector>
    using namespace std;
    //vector容器预留空间
    void printVector(vector<int>& v)
    {
    	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    void test01()
    {
    	vector<int> v1;
    	int num = 0;//统计开辟次数
    	int* p = NULL;
    	for (int i = 0; i < 10; i++)
    	{
    		v1.push_back(i + 1);//尾插法插入数据
    		if (p != &v1[0])
    		{
    			p = &v1[0];
    			num++;//相当于开辟了多次内存
    		}
    	}
    	cout << num << endl;
    	
    }
    void test02()
    {
    	vector<int> v1;
    	int num = 0;//统计开辟次数
    	v1.reserve(10);//预留数据空间
    	int* p = NULL;
    	for (int i = 0; i < 10; i++)
    	{
    		v1.push_back(i + 1);//尾插法插入数据
    		if (p != &v1[0])
    		{
    			p = &v1[0];
    			num++;//相当于开辟了多次内存
    		}
    	}
    	cout << num<< endl;
    
    }
    int main()
    {
    	test01();
    	test02();
    }
    ```

  - 

## deque容器

- deque容器是双端数组，可以对头端进行插入和删除操作

- deque和vector的区别

  - vector对于头部的插入删除效率低，数据量越大，效率越低
  - deque相对而言对头部的插入和删除速度比vector快
  - vector访问元素时的速度会比deque快，这与两者内部实现有关

- deque内部有中控器维护每一段缓冲区的内容，缓冲区中存放真实数据；中控器维护的是每个缓冲区的地址，使得deque像一片连续的内存空间

- deque容器的迭代器是支持随机访问的

- deque的构造函数

  - ```c++
    #include<iostream>
    #include<deque>
    using namespace std;
    //deque容器的构造函数
    void printDeque(const deque<int>& d1)
    {
    	for (deque<int>::const_iterator it = d1.begin(); it != d1.end(); it++)//const_iterator为只读迭代器
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    void test01()
    {
    	deque<int> d1;
    	for (int i = 0; i < 10; i++)
    	{
    		d1.push_back(i);
    	}
    	printDeque(d1);
    	deque<int>d2(d1.begin(), d1.end());//区间方式赋值
    	printDeque(d2);
    	deque<int>d3(10, 100);//n个elem
    	printDeque(d3);
    	deque<int>d4(d1);//拷贝构造
    	printDeque(d4);
    }
    int main()
    {
    	test01();
    }
    ```

- deque的赋值操作

  - ```c++
    #include<iostream>
    #include<deque>
    using namespace std;
    //deque容器的赋值操作
    void printDeque(const deque<int>& d1)
    {
    	for (deque<int>::const_iterator it = d1.begin(); it != d1.end(); it++)//const_iterator为只读迭代器
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    void test01()
    {
    	deque<int> d1;
    	for (int i = 0; i < 10; i++)
    	{
    		d1.push_back(i + 1);
    	}
    	printDeque(d1);
    	//operator赋值
    	deque<int> d2;
    	d2 = d1;
    	printDeque(d2);
    	//assign赋值
    	deque<int> d3;
    	d3.assign(d1.begin(), d1.end());
    	printDeque(d3);
    	deque<int> d4;
    	d4.assign(10, 100);
    	printDeque(d4);
    }
    int main()
    {
    	test01();
    }
    ```

- deque大小操作（deque容器没有容量这个概念，可以无限扩展）

  - ```c++
    #include<iostream>
    #include<deque>
    using namespace std;
    //deque容器的大小操作
    void printDeque(const deque<int>& d1)
    {
    	for (deque<int>::const_iterator it = d1.begin(); it != d1.end(); it++)//const_iterator为只读迭代器
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    void test01()
    {
    	deque<int> d1;
    	for (int i = 0; i < 10; i++)
    	{
    		d1.push_back(i + 1);
    	}
    	printDeque(d1);
    	if (d1.empty())
    	{
    		cout << "d1为空" << endl;
    	}
    	else
    	{
    		cout << "d1不为空" << endl;
    		cout << "d1的大小为" << d1.size() << endl;
    	}
    	d1.resize(15);
    	printDeque(d1);
    	d1.resize(15, 23);
    	printDeque(d1);
    	d1.resize(5);
    	printDeque(d1);
    	
    }
    int main()
    {
    	test01();
    }
    ```

- deque的插入和删除

  - ```c++
    #include<iostream>
    #include<deque>
    using namespace std;
    //deque容器的插入和删除操作
    void printDeque(const deque<int>& d1)
    {
    	for (deque<int>::const_iterator it = d1.begin(); it != d1.end(); it++)//const_iterator为只读迭代器
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    //两端操作
    void test01()
    {
    	deque<int> d1;
    	//尾插
    	d1.push_back(20);
    	d1.push_back(30);
    	//头插
    	d1.push_front(60);
    	d1.push_front(90);
    	printDeque(d1);
    	//尾删
    	d1.pop_back();
    	//头删
    	d1.pop_front();
    	printDeque(d1);
    }
    void test02()
    {
    	deque<int> d2;
    	//尾插
    	d2.push_back(20);
    	d2.push_back(30);
    	d2.push_front(60);
    	d2.push_front(90);
    	
    	//insert插入
    	d2.insert(d2.begin(), 34);
    	printDeque(d2);
    	d2.insert(d2.begin(), 3, 200);//插入3个200
    	printDeque(d2);
    	//按照区间插入数据
    	deque<int> d3;
    	d3.push_back(10);
    	d3.push_back(20);
    	d3.push_back(30);
    	d3.push_back(40);
    	d2.insert(d2.begin(), d3.begin(), d3.end());
    	printDeque(d2);
    }
    void test03()
    {
    	deque<int> d1;
    	d1.push_back(10);
    	d1.push_back(20);
    	d1.push_back(30);
    	d1.push_back(40);
    	//删除操作
    	deque<int>::iterator it = d1.begin();
    	it++;
    	d1.erase(it);//删除第it个数据
    	printDeque(d1);
    	d1.erase(d1.begin(), d1.end());//区间删除
    	d1.clear();
    }
    int main()
    {
    	test01();
    	test02();
    	test03();
    }
    ```

- deque的数据存取

  - ```c++
    #include<iostream>
    #include<deque>
    using namespace std;
    //deque容器的数据存取
    void test01()
    {
    	deque<int> d1;
    	d1.push_back(20);
    	d1.push_back(30);
    	d1.push_front(60);
    	d1.push_front(90);
    	d1.push_front(100);
    	//通过[]方式来访问元素
    	for (int i = 0; i < d1.size(); i++)
    	{
    		cout << d1[i] << " ";
    	}
    	cout << endl;
    	//通过at方式来访问
    	for (int i = 0; i < d1.size(); i++)
    	{
    		cout << d1.at(i) << " ";
    	}
    	cout << endl;
    	//访问头部和尾部元素
    	cout << "d1的头部元素为" << d1.front() << endl;
    	cout << "d1的尾部元素为" << d1.back() << endl;
    }
    
    int main()
    {
    	test01();
    }
    ```

- deque排序

  - ```c++
    #include<iostream>
    #include<deque>
    #include<algorithm>
    using namespace std;
    //deque容器的数据存取
    void printDeque(const deque<int>& d1)
    {
    	for (deque<int>::const_iterator it = d1.begin(); it != d1.end(); it++)//const_iterator为只读迭代器
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    //两端操作
    void test01()
    {
    	deque<int> d1;
    	d1.push_back(20);
    	d1.push_back(650);
    	d1.push_front(50);
    	d1.push_front(90);
    	d1.push_front(10);
    	printDeque(d1);
    	//排序
    	//对于支持随机访问的迭代器的容器都可以利用sort算法直接对其进行排序
    	sort(d1.begin(), d1.end());
    	cout << "排序后：" << endl;
    	printDeque(d1);
    
    }
    
    int main()
    {
    	test01();
    }
    ```

    

- 容器案例：评委打分

  ```c++
  #include<vector>
  #include<iostream>
  #include<algorithm>
  #include<deque>
  #include<ctime>
  using namespace std;
  
  //选手类
  class Person
  {
  public:
  	Person(string name, int score)
  	{
  		this->m_Name = name;
  		this->m_Score = score;
  	}
  	string m_Name;
  	int m_Score;
  };
  void creatPerson(vector<Person>& v)
  {
  	string nameSeed = "ABCDE";
  	for (int i = 0; i < 5; i++)
  	{
  		string name = "选手";
  		name += nameSeed[i];
  		int score = 0;
  		Person p(name, score);
  		v.push_back(p);
  	}
  }
  void setScore(vector<Person> v)
  {
  	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
  	{
  		deque<int> d;
  		for (int i = 0; i < 10; i++)
  		{
  			int score = rand() % 41 + 60;
  			d.push_back(score);
  		}
  		cout << "选手" << it->m_Name << "\t" << "打分：" << endl;
  		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
  		{
  			cout << *dit << "\t";
  		}
  		cout << endl;
  		sort(d.begin(), d.end());
  		d.pop_front();
  		d.pop_back();//去除最高分和最低分
  		//取平均分
  		int sum = 0;
  		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
  		{
  			sum += *dit;
  		}
  		int avg = sum / d.size();
  		//cout << avg << endl;
  		it->m_Score = avg;//将平均分赋值给选手
  		//cout << it->m_Score << endl;
  	}
  	cout << "*********************************" << endl;
  }
  void showScore(vector<Person>& v)
  {
  	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
  	{
  		cout << "姓名：" << it->m_Name << "\t分数：" << it->m_Score << endl;
  	}
  }
  int main()
  {
  	//随机数种子
  	srand((unsigned int)time(NULL));
  	//创建五个选手
  	vector<Person> v;
  	creatPerson(v);
  	//给五个选手打分
  	setScore(v);
  	//显示分数
  	showScore(v);
  }
  ```

## stack容器

- stack容器是一种**先进后出**的数据结构，只有一个出口（栈）

- 栈不允许有遍历行为

- ```c++
  #include<stack>
  #include<iostream>
  using namespace std;
  //栈（stack）容器
  void test01()
  {
  	stack<int> s;
  	//入栈
  	for (int i = 0; i < 5; i++)
  	{
  		s.push(i);
  	}
  	cout << "栈的大小为" << s.size() << endl;
  	//只要栈不为空，查看栈顶，并执行出栈操作
  	while (!s.empty())
  	{
  		cout << "栈顶元素为" << s.top() << endl;
  		s.pop();
  	}
  	cout << "栈的大小为" << s.size() << endl;
  	
  }
  int main()
  {
  	test01();
  }
  ```

## queue容器

- 队列是一种**先进先出**的数据结构，有两个出口

- 对头出队，对尾入队

- 只有队头和队尾元素能被外界访问，因此不允许有遍历行为

- ```c++
  #include<queue>
  #include<iostream>
  using namespace std;
  //队列容器
  class Person
  {
  public:
  	Person(string name, int age)
  	{
  		this->m_Name = name;
  		this->m_Age = age;
  	}
  	string m_Name;
  	int m_Age;
  };
  void test01()
  {
  	queue<Person> q;
  	Person p1("关羽", 43);
  	Person p2("张飞", 32);
  	Person p3("刘备", 54);
  	Person p4("董卓", 76);
  	//入队
  	q.push(p1);
  	q.push(p2);
  	q.push(p3);
  	q.push(p4);
  	while (!q.empty())
  	{
  		//查看队头
  		cout << "队头元素--姓名" << q.front().m_Name << "\t年龄" << q.front().m_Age << endl;
  		//查看队尾
  		cout << "队尾元素--姓名" << q.back().m_Name << "\t年龄" << q.back().m_Age << endl;
  		//出队
  		q.pop();
  	}
  
  	
  }
  int main()
  {
  	test01();
  }
  ```

## list容器

- 功能：将数据进行**链式存储**
- 链表是一种物理储存单元上非连续的储存结构，数据元素的逻辑顺序是通过链表中的指针链接来实现的
- 链表由一系列结点组成；结点由储存数据元素的**数据域**和储存下一个结点地址的**指针域**构成

- STL中的链表是一个**双向循环链表**

- 链表可以对任意的位置进行快速的添加，插入或者删除元素

- 链表的迭代器只支持前移和后移，不支持随机访问，属于**双向迭代器**

- 链表采用动态储存分配，不会造成内存的浪费

- 链表的插入和删除操作不会使原有的迭代器失效（vector容器不成立）

- list的构造函数

  - ```c++
    #include<list>
    #include<iostream>
    using namespace std;
    //list容器的构造函数
    void printList(list<int>& L)
    {
    	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    void test01()
    {
    	list<int> l1;
    	for (int i = 0; i < 5; i++)
    	{
    		//默认构造
    		l1.push_back(i);
    	}
    	printList(l1);
    	//区间方式构造
    	list<int> l2(l1.begin(), l1.end());
    	printList(l2);
    	//拷贝构造
    	list<int> l3(l2);
    	printList(l3);
    	//n个elem
    	list<int> l4(10, 233);
    	printList(l4);
    }
    int main()
    {
    	test01();
    }
    ```

- list容器的赋值和交换

  - ```c++
    #include<list>
    #include<iostream>
    using namespace std;
    //list容器赋值和交换
    void printList(list<int>& L)
    {
    	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    void test01()
    {
    	list<int> L1;
    	for (int i = 0; i < 5; i++)
    	{
    		//默认构造
    		L1.push_back(i);
    	}
    	//operator
    	list<int> L2;
    	L2 = L1;
    	printList(L2);
    	//assign赋值
    	list<int> L3;
    	L3.assign(L2.begin(), L2.end());
    	printList(L3);
    	list<int> L4;
    	L4.assign(5, 233);
    	printList(L4);
    }
    void test02()
    {
    	list<int> L1;
    	list<int> L2;
    	for (int i = 0; i < 5; i++)
    	{
    		//默认构造
    		L1.push_back(i);
    		L2.push_back(i + 10);
    	}
    	cout << "交换前:" << endl;
    	printList(L1);
    	printList(L2);
    	L1.swap(L2);
    	cout << "交换后：" << endl;
    	printList(L1);
    	printList(L2);
    }
    int main()
    {
    	test01();
    	test02();
    }
    ```

- list容器大小操作

  - ```c++
    #include<list>
    #include<iostream>
    using namespace std;
    //list容器的大小操作
    void printList(list<int>& L)
    {
    	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    void test01()
    {
    	list<int> L1;
    	for (int i = 0; i < 5; i++)
    	{
    		//默认构造
    		L1.push_back(i);
    	}
    	//判断容器是否为空
    	if (L1.empty())
    	{
    		cout << "L1为空" << endl;
    	}
    	else
    	{
    		cout << "L1的元素个数为" << L1.size() << endl;
    	}
    	//重新指定大小
    	L1.resize(10);
    	printList(L1);
    	L1.resize(2);
    	printList(L1);
    	
    }
    int main()
    {
    	test01();
    }
    ```

- list插入和删除

  ```c++
  #include<list>
  #include<iostream>
  using namespace std;
  //list容器的插入和删除操作
  void printList(list<int>& L)
  {
  	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
  	{
  		cout << *it << " ";
  	}
  	cout << endl;
  }
  void test01()
  {
  	list<int> L1;
  	for (int i = 0; i < 5; i++)
  	{
  		//默认构造
  		L1.push_back(i);
  		L1.push_front(i + 4);
  	}
  	printList(L1);
  	//尾删
  	L1.pop_back();
  	//头删
  	L1.pop_front();
  	//insert插入
  	L1.insert(L1.begin(), 20);
  	list<int>::iterator it = L1.begin();
  	L1.insert(++it, 32);
  	printList(L1);
  	//删除
  	it = L1.begin();
  	L1.erase(it++);//参数一定是迭代器
  	printList(L1);
  	//移除
  	L1.push_back(100);
  	L1.push_back(100);
  	L1.push_back(100);
  	printList(L1);
  	L1.remove(100);
  	printList(L1);
  	//清空
  	L1.clear();
  }
  int main()
  {
  	test01();
  }
  ```


- list的数据存取

  - ```c++
    #include<list>
    #include<iostream>
    using namespace std;
    //list容器的数据存取
    void printList(list<int>& L)
    {
    	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    void test01()
    {
    	list<int> L1;
    	for (int i = 0; i < 5; i++)
    	{
    		//默认构造
    		L1.push_back(i);
    		L1.push_front(i + 4);
    	}
    	cout << "list的尾部为：" << L1.back() << endl;
    	cout << "list的头部为" << L1.front() << endl;
    	//list的本质是一个链表，不是线性空间存储数据，迭代器不支持随机访问（只支持++或者--操作）
    }
    int main()
    {
    	test01();
    }
    ```

- list的反转和排序

  - ```c++
    #include<list>
    #include<iostream>
    using namespace std;
    //list容器的反转和排序
    void printList(list<int>& L)
    {
    	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    bool myCompare(int v1, int v2)//降序排序
    {
    	
    	return v1 > v2;
    }
    void test01()
    {
    	list<int> L1;
    	for (int i = 0; i < 5; i++)
    	{
    		//默认构造
    		L1.push_back(i);
    		L1.push_front(i + 4);
    	}
    	printList(L1);
    	L1.reverse();
    	cout << "反转后：" << endl;
    	printList(L1);
    	L1.sort();
    	cout << "排序后：" << endl;
    	printList(L1);
    	cout << "降序排序后" << endl;
    	L1.sort(myCompare);
    	printList(L1);
    	
    }
    int main()
    {
    	test01();
    }
    ```

  - **所有不支持随机访问迭代器的容器不可以使用标准算法；不支持随机访问迭代器的容器内部会提供对应的算法**

  - 自定义数据高级排序

    - ```c++
      #include<list>
      #include<iostream>
      using namespace std;
      //list容器的排序案例
      class Person
      {
      public:
      	Person(string name, int age, int height)
      	{
      		this->m_age = age;
      		this->m_name = name;
      		this->m_height = height;
      	}
      	string m_name;
      	int m_age;
      	int m_height;
      
      private:
      
      };
      //指定排序规则
      bool myCompareAge(Person& p1, Person &p2)
      {
      	if (p1.m_age == p2.m_age)
      	{
      		return p1.m_height > p2.m_height;
      	}
      	else
      	{
      		return p1.m_age > p2.m_age;
      	}
      	
      }
      void printList(list<Person>& L)
      {
      	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
      	{
      		cout << "姓名:" << (*it).m_name << "\t年龄:" << (*it).m_age
      			<< "\t身高:" << (*it).m_height << endl;
      	}
      }
      void test01()
      {
      	Person p1("关羽", 43, 187);
      	Person p2("张飞", 54, 176);
      	Person p3("刘备", 54, 175);
      	Person p4("董卓", 76, 165);
      	list<Person> L;
      	L.push_back(p1);
      	L.push_back(p2);
      	L.push_back(p3);
      	L.push_back(p4);
      	printList(L);
      	cout << "--------------------------------------------------" << endl;
      	cout << "按照年龄排序" << endl;
      	L.sort(myCompareAge);
      	printList(L);
      }
      int main()
      {
      	test01();
      }
      ```

## set/multiset容器

- 所有元素都会在插入时**自动排序**

- set/multiset属于关联式容器，底层结构是**二叉树**

- set/multiset容器的区别：set不允许有重复的数据；multiset允许有重复的数据

- set的构造和赋值

  - ```c++
    #include<set>
    #include<iostream>
    using namespace std;
    //set容器
    void printSet(set<int>& s)
    {
    	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    void test01()
    {
    	set<int> s1;
    	s1.insert(1);//插入数据只有insert函数
    	s1.insert(7);
    	s1.insert(2);//set不允许插入重复的值
    	s1.insert(2);
    	printSet(s1);
    	//拷贝构造
    	set<int> s2(s1);
    	printSet(s2);
    	//赋值操作
    	set<int> s3;
    	s3 = s2;
    	printSet(s3);
    }
    int main()
    {
    	test01();
    }
    ```

- set的大小和交换

  - ```c++
    #include<set>
    #include<iostream>
    using namespace std;
    //set容器的大小和交换
    void printSet(set<int>& s)
    {
    	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    void test01()
    {
    	set<int> s1;
    	s1.insert(1);//插入数据只有insert函数
    	s1.insert(7);
    	s1.insert(2);//set不允许插入重复的值
    	s1.insert(2);
    	printSet(s1);
    	//判断是否为空
    	if (s1.empty())
    	{
    		cout << "s1为空" << endl;
    	}
    	else
    	{
    		cout << "s1的大小为" << s1.size() << endl;
    	}
    	set<int> s2;
    	s2.insert(43);
    	s2.insert(21);
    	s2.insert(53);
    	s2.insert(57);
    	s2.swap(s1);//交换容器
    	printSet(s1);
    	printSet(s2);
    
    
    }
    int main()
    {
    	test01();
    }
    ```

- set的插入和删除

  - ```c++
    #include<set>
    #include<iostream>
    using namespace std;
    //set容器的插入和删除
    void printSet(set<int>& s)
    {
    	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    void test01()
    {
    	set<int> s2;
    	s2.insert(43);
    	s2.insert(21);
    	s2.insert(53);
    	s2.insert(57);
    	s2.erase(21);//相当于list的remove
    	printSet(s2);
    	s2.erase(s2.begin());
    	//清空
    	s2.erase(s2.begin(), s2.end());
    	s2.clear();
    }
    int main()
    {
    	test01();
    }
    ```

- set的查找和统计

  - ```c++
    #include<set>
    #include<iostream>
    using namespace std;
    //set容器的插入和删除
    void printSet(set<int>& s)
    {
    	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    void test01()
    {
    	set<int> s2;
    	s2.insert(43);
    	s2.insert(21);
    	s2.insert(53);
    	s2.insert(57);
    	//查找
    	set<int>::iterator pos = s2.find(21);//find函数返回end值
    	if (pos != s2.end())
    	{
    		cout << "找到元素" << *pos << endl;
    	}
    	else
    	{
    		cout << "未找到该元素" << endl;
    	}
    }
    void test02()//统计
    {
    	set<int> s2;
    	s2.insert(43);
    	s2.insert(21);
    	s2.insert(53);
    	s2.insert(57);
    	//统计元素的个数
    	int num = s2.count(21);//对于set而言，count返回值要么是0，要么是1
    	cout << num << endl;
    }
    int main()
    {
    	test01();
        test02();
    }
    ```

- set和multiset的区别

  - ```c++
    #include<set>
    #include<iostream>
    using namespace std;
    void printSet(set<int>& s)
    {
    	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    void test01()
    {
    	set<int> s2;
    	s2.insert(43);
    	s2.insert(21);
    	s2.insert(53);
    	s2.insert(57);
    	pair<set<int>::iterator, bool> ret = s2.insert(20);
    	if (ret.second)
    	{
    		cout << "第一次插入成功" << endl;
    	}
    	else
    	{
    		cout << "第一次插入失败" << endl;
    	}
    	ret = s2.insert(20);
    	if (ret.second)
    	{
    		cout << "第二次插入成功" << endl;
    	}
    	else
    	{
    		cout << "第二次插入失败" << endl;
    	}
    	multiset<int> s1;
    	//允许插入重复值
    	s1.insert(10);
    	s1.insert(10);
    	for (multiset<int>::iterator it = s1.begin(); it != s1.end(); it++)
    	{
    		cout << *it << "\t";
    	}
    	cout << endl;
    }
    void test02()//统计
    {
    	set<int> s2;
    	s2.insert(43);
    	s2.insert(21);
    	s2.insert(53);
    	s2.insert(57);
    	//统计元素的个数
    	int num = s2.count(21);//对于set而言，count返回值要么是0，要么是1
    	cout << num << endl;
    }
    int main()
    {
    	test01();
    }
    ```

- pair队组创建

  - ```c++
    #include<set>
    #include<iostream>
    using namespace std;
    //pair队组的创建
    void printSet(set<int>& s)
    {
    	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    void test01()
    {
    	pair<string, int> p1("tom", 32);
    	cout << p1.first << endl;
    	cout << p1.second << endl;
    }
    
    int main()
    {
    	test01();
    }
    ```

- set容器排序

  - ```c++
    #include<set>
    #include<iostream>
    using namespace std;
    //set容器的排序
    //仿函数:本质上是一个类型
    class MyCompare
    {
    public:
    	bool operator()(int v1, int v2) const
    	{
    		return v1 > v2;
    	}
    };
    void printSet(set<int>& s)
    {
    	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    }
    void test01()
    {
    	set<int> s1;
    	s1.insert(20);
    	s1.insert(30);
    	s1.insert(40);
    	s1.insert(50);
    	s1.insert(60);
    	printSet(s1);
    	//指定排序规则为从大到小，必须在数据未插入之前改变规则
    	set<int, MyCompare> s2;
    	s2.insert(20);
    	s2.insert(30);
    	s2.insert(40);
    	s2.insert(50);
    	s2.insert(60);
    	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++)
    	{
    		cout << *it << endl;
    	}
    
    }
    
    int main()
    {
    	test01();
    }
    ```

  - set容器自定义数据如何进行排序

    - ```c++
      #include<set>
      #include<iostream>
      using namespace std;
      //set容器的排序
      //仿函数:本质上是一个类型
      class Person
      {
      public:
      	Person(string name, int age)
      	{
      		this->m_name = name;
      		this->m_age = age;
      	}
      	string m_name;
      	int m_age;
      };
      class comparePerson
      {
      public:
      	bool operator()(const Person &p1,const Person &p2) const
      	{
      		return p1.m_age > p2.m_age;
      	}
      };
      
      void printSet(set<int>& s)
      {
      	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
      	{
      		cout << *it << " ";
      	}
      	cout << endl;
      }
      void test01()
      {
      	//自定义的数据类型需要指定排序规则
      	set<Person, comparePerson> s1;
      	Person p1("关羽", 43);
      	Person p2("张飞", 32);
      	Person p3("刘备", 54);
      	Person p4("董卓", 76);
      	
      	s1.insert(p1);
      	s1.insert(p2);
      	s1.insert(p3);
      	s1.insert(p4);
      	for (set<Person, comparePerson>::iterator it = s1.begin(); it != s1.end(); it++)
      	{
      		cout << "姓名" << (*it).m_name << "\t年龄" << (*it).m_age << endl;
      	}
      }
      int main()
      {
      	test01();
      }
      ```


## map/multimap容器

- map容器所有元素都是pair

- pair中第一个元素为key(键值)，起到索引作用，第二个元素为value（实值）

- 所有的元素都会根据元素的键值进行自动排序

- map/multimap属于关联式容器，底层结构是用**二叉树**实现

- map/multimap的区别：map不允许有重复的key值元素；multimap允许有重复的key值

- map构造和赋值

  - ```c++
    #include<map>
    #include<iostream>
    using namespace std;
    //map容器的构造和赋值
    void printMap(map<int, int>& m)
    {
    	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    	{
    		cout << "key = " << (*it).first << "\tvalue = " << (*it).second << endl;
    	}
    }
    void test01()
    {
    	//创建map容器
    	//默认构造
    	map<int, int> m;
       //map容器中元素都是成对出现，插入数值时需要使用pair
    	m.insert(pair<int, int>(1, 20));
    	m.insert(pair<int, int>(2, 30));
    	m.insert(pair<int, int>(3, 60));
    	m.insert(pair<int, int>(4, 40));
    	m.insert(pair<int, int>(5, 90));
    	printMap(m);
    	//拷贝构造
    	map<int, int> m2(m);
    	printMap(m2);
    	//赋值
    	map<int, int> m3;
    	m3 = m2;
    	printMap(m3);
    
    }
    int main()
    {
    	test01();
    }
    ```

- map的大小和交换

  - ```c++
    #include<map>
    #include<iostream>
    using namespace std;
    //map容器的构造和赋值
    void printMap(map<int, int>& m)
    {
    	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    	{
    		cout << "key = " << (*it).first << "\tvalue = " << (*it).second << endl;
    	}
    	cout << endl;
    }
    void test01()
    {
    	//创建map容器
    	//默认构造
    	map<int, int> m;
    	m.insert(pair<int, int>(1, 20));
    	m.insert(pair<int, int>(2, 30));
    	m.insert(pair<int, int>(3, 60));
    	m.insert(pair<int, int>(4, 40));
    	m.insert(pair<int, int>(5, 90));
    	printMap(m);
    	//判断是否为空
    	if (m.empty())
    	{
    		cout << "map为空" << endl;
    	}
    	else
    	{
    		cout << "********************************" << endl;
    		
    		cout << m.size() << endl;
    	}
    }
    void test02()
    {
    	//交换
    	map<int, int> m1;
    	m1.insert(pair<int, int>(1, 20));
    	m1.insert(pair<int, int>(2, 30));
    	m1.insert(pair<int, int>(3, 60));
    	m1.insert(pair<int, int>(4, 40));
    	m1.insert(pair<int, int>(5, 90));
    	map<int, int> m2;
    	m2.insert(pair<int, int>(1, 43));
    	m2.insert(pair<int, int>(2, 35));
    	m2.insert(pair<int, int>(3, 54));
    	m2.insert(pair<int, int>(4, 63));
    	m2.insert(pair<int, int>(5, 24));
    	cout << "交换前" << endl;
    	printMap(m1);
    	printMap(m2);
    	cout << "交换后" << endl;
    	m2.swap(m1);
    	printMap(m1);
    	printMap(m2);
    
    }
    int main()
    {
    	test01();
    	test02();
    }
    ```

- map元素的插入和删除

  - ```c++
    #include<map>
    #include<iostream>
    using namespace std;
    //map容器的插入和删除
    void printMap(map<int, int>& m)
    {
    	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    	{
    		cout << "key = " << (*it).first << "\tvalue = " << (*it).second << endl;
    	}
    	cout << endl;
    }
    void test01()
    {
    	//创建map容器
    	//默认构造
    	map<int, int> m;
    	m.insert(pair<int, int>(1, 20));
    	m.insert(pair<int, int>(2, 30));
    	m.insert(pair<int, int>(3, 60));
    	m.insert(pair<int, int>(4, 40));
    	m.insert(pair<int, int>(5, 90));
    	printMap(m);
    	//判断是否为空
    	if (m.empty())
    	{
    		cout << "map为空" << endl;
    	}
    	else
    	{
    		//插入
    		m.insert(pair<int, int>(6,32));
    		printMap(m);
    		m.insert(make_pair(8, 32));
    		printMap(m);
    		m.insert(map<int, int>::value_type(9, 23));
    		printMap(m);
    		m[8] = 43;//重载[],不建议使用该方式
    		cout << m[3] << endl;//通常使用key值来访问value，而不是用来插入
    		printMap(m);
    		//删除
    		m.erase(m.begin());
    		printMap(m);
    		m.erase(2);//按照key删除
    		printMap(m);
    		m.erase(m.begin(), m.end());//区间方式删除
    		printMap(m);
    		//清空
    		m.clear();
    
    	}
    }
    int main()
    {
    	test01();
    }
    ```

- map的查找和统计

  - ```c++
    #include<map>
    #include<iostream>
    using namespace std;
    //map容器的查找和统计
    void printMap(map<int, int>& m)
    {
    	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    	{
    		cout << "key = " << (*it).first << "\tvalue = " << (*it).second << endl;
    	}
    	cout << endl;
    }
    void test01()
    {
    	//创建map容器
    	//默认构造
    	map<int, int> m;
    	m.insert(pair<int, int>(1, 20));
    	m.insert(pair<int, int>(2, 30));
    	m.insert(pair<int, int>(3, 60));
    	m.insert(pair<int, int>(4, 40));
    	m.insert(pair<int, int>(5, 90));
    	printMap(m);
    	//判断是否为空
    	if (m.empty())
    	{
    		cout << "map为空" << endl;
    	}
    	else
    	{
    		//查找
    		map<int, int>::iterator pos = m.find(3);//返回值为迭代器
    		if (pos != m.end())
    		{
    			cout << "查找到了元素 key = " << (*pos).first << "\tvalue = " << (*pos).second << endl;
    		}
    		else
    		{
    			cout << "未找到元素" << endl;
    		}
    		//统计
    		int num = m.count(3);//输出要么是0，要么是1；multimap的值可以大于1
    		cout << num << endl;
    	}
    }
    
    int main()
    {
    	test01();
    }
    ```

- map容器排序

  - ```c++
    #include<map>
    #include<iostream>
    using namespace std;
    //map容器的排序
    class myCompare
    {
    public:
    	bool operator()(int v1, int v2) const
    	{
    		return v1 > v2;
    	}
    };
    void printMap(map<int, int, myCompare>& m)
    {
    	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    	{
    		cout << "key = " << (*it).first << "\tvalue = " << (*it).second << endl;
    	}
    	cout << endl;
    }
    void test01()
    {
    	//创建map容器
    	//默认构造
    	map<int, int, myCompare> m;
    	m.insert(pair<int, int>(1, 20));
    	m.insert(pair<int, int>(2, 30));
    	m.insert(pair<int, int>(3, 60));
    	m.insert(pair<int, int>(4, 40));
    	m.insert(pair<int, int>(5, 90));
    	printMap(m);
    	//判断是否为空
    	if (m.empty())
    	{
    		cout << "map为空" << endl;
    	}
    	else
    	{
    		printMap(m);
    	}
    }
    
    int main()
    {
    	test01();
    }
    ```

- map案例

  - ```c++
    #include<iostream>
    #include<map>
    #include<vector>
    #include<time.h>
    using namespace std;
    #define CEHUA 1
    #define MEISHU 2
    #define YANFA 3
    class Worker
    {
    public:
    	
    	string m_name;
    	int m_salary;
    };
    void creatWorker(vector<Worker> &w)
    {
    	string nameSeed = "ABCDEFGHIJ";
    	for (int i = 0; i < 10; i++)
    	{
    		Worker worker;
    		worker.m_name = "员工";
    		worker.m_name += nameSeed[i];
    		worker.m_salary = rand() % 10000 + 10000;
    		w.push_back(worker);
    	}
    
    }
    void setGroup(vector<Worker> &v, multimap<int, Worker>& g)
    {
    	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    	{
    		int deptId = rand() % 3 + 1;
    		g.insert(make_pair(deptId, *it));
    	}
    }
    void showWorkerByGroup(multimap<int, Worker>& g)
    {
    	cout << "策划部门" << endl;
    	multimap<int, Worker>::iterator pos = g.find(CEHUA);
    	int count = g.count(CEHUA);
    	int index = 0;
    	for (; pos != g.end() && index < count; pos++, index++)
    	{
    		cout << "姓名：" << pos->second.m_name << "\t工资：" << pos->second.m_salary << endl;
    	}
    	cout << "------------------------------------------" << endl;
    	cout << "美术部门" << endl;
    	pos = g.find(MEISHU);
    	count = g.count(MEISHU);
    	index = 0;
    	for (; pos != g.end() && index < count; pos++, index++)
    	{
    		cout << "姓名：" << pos->second.m_name << "\t工资：" << pos->second.m_salary << endl;
    	}
    	cout << "------------------------------------------" << endl;
    	cout << "研发部门" << endl;
    	pos = g.find(YANFA);
    	count = g.count(MEISHU);
    	index = 0;
    	for (; pos != g.end() && index < count; pos++, index++)
    	{
    		cout << "姓名：" << pos->second.m_name << "\t工资：" << pos->second.m_salary << endl;
    	}
    }
    int main()
    {
    	srand((unsigned int)time(NULL));
    	//创建员工
    	vector<Worker> v_worker;
    	creatWorker(v_worker);
    	//员工分组
    	multimap<int, Worker> g_worker;
    	setGroup(v_worker, g_worker);
    	//分组显示员工
    	showWorkerByGroup(g_worker);
    }
    ```


##  函数对象（仿函数）

- 重载函数调用操作符的类，其对象称为函数对象

- 函数对象使用重载的（）时，行为类似函数调用，也叫仿函数

- 本质：**函数对象是一个类而不是一个函数**

- 函数对象的使用

  - 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
  - 函数对象超出普通函数的概念，函数对象可以有自己的状态
  - 函数对象可以作为参数传递

- ```c++
  #include<iostream>
  using namespace std;
  //函数对象
  class MyAdd
  {
  public:
  	int operator()(int v1, int v2)
  	{
  		return v1 + v2;
  	}
  
  private:
  
  };
  //函数对象可以有自己的状态
  class MyPrint
  {
  public:
  	void operator()(string test)
  	{
  		cout << test << endl;
  		this->count++;
  	}
  	int count = 0;//内部自己的状态记录
  };
  
  void test01()
  {
  	MyAdd myadd;
  	cout << myadd(10, 10) << endl;
  }
  void test02()
  {
  	MyPrint myprint;
  	myprint("liujun");
  	cout << myprint.count << endl;
  }
  //函数对象可以作为参数传递
  void doPrint(MyPrint& mp, string test)
  {
  	mp(test);
  }
  void test03()
  {
  	MyPrint myprint;
  	doPrint(myprint, "hello world");
  }
  int main()
  {
  	test01();
  	test02();
  	test03();
  	system("pause");
  }
  ```

## 谓词

- 返回bool类型的仿函数称为**谓词**；如果operator（）接受一个参数，那么叫做**一元谓词**；如果operator（）接受两个参数，那么叫做**二元谓词**

- 一元谓词

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;
    //谓词
    class GreaterTwo
    {
    public:
    	bool operator()(int val)//一元谓词
    	{
    		return val > 2;
    	}
    };
    void test01()
    {
    	vector<int> v;
    	for (int i = 0; i < 5; i++)
    	{
    		v.push_back(i + 1);
    	}
    	//查找容器中是否有大于2的数字
    	//GreaterTwo为匿名的函数对象
    		vector<int>::iterator it =	find_if(v.begin(), v.end(), GreaterTwo());
    		if (it == v.end())
    		{
    			cout << "未找到" << endl;
    		}
    		else
    		{
    			cout << *it << endl;
    		}
    	
    }
    int main()
    {
    	test01();
    }
    ```

- 二元谓词

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;
    //二元谓词
    class MyCompare
    {
    public:
    	bool operator()(int val1, int val2)
    	{
    		return val1 > val2;
    	}
    };
    void test01()
    {
    	vector<int> v1;
    	for (int i = 0; i < 10; i++)
    	{
    		v1.push_back(i + 1);
    	}
    	sort(v1.begin(), v1.end(), MyCompare());
    	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    	{
    		cout << *it << endl;
    	}
    }
    int main()
    {
    	test01();
    }
    ```

## 内建函数对象

- STL中内建了部分函数对象；分为算术仿函数；关系仿函数； 逻辑仿函数

- 这些仿函数所产生的对象用法和一般函数完全相同

- 使用内建的仿函数，需要引入头文件functional

- 算术仿函数

  - 功能：实现四则运算；其中negate是一元运算，其他都是二元运算

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<functional>//内建函数对象头文件
    using namespace std;
    //算术仿函数
    //negate一元仿函数 取反仿函数
    void test01()
    {
    	negate<int> n;//取反运算
    	cout << n(50) << endl;
    }
    //plus 二元仿函数 加法
    void test02()
    {
    	plus<int> p;
    	cout << p(10, 20) << endl;
    }
    int main()
    {
    	test01();
    	test02();
    }
    ```

- 关系仿函数：最常用的是greater

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<functional>//内建函数对象头文件
    using namespace std;
    //关系仿函数
    //greater 大于
    void test01()
    {
    	vector<int> v;
    	v.push_back(4);
    	v.push_back(8);
    	v.push_back(2);
    	v.push_back(6);
    	v.push_back(9);
    	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    	sort(v.begin(), v.end(), greater<int>());
    	cout << "--------------------------" << endl;
    	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    	{
    		cout << *it << " ";
    	}
    }
    
    int main()
    {
    	test01();
    }
    ```

- 逻辑仿函数（基本用不上）

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<functional>//内建函数对象头文件
    using namespace std;
    //逻辑仿函数
    //逻辑非 logical_not
    void test01()
    {
    	vector<bool> v;
    	v.push_back(true);
    	v.push_back(false);
    	v.push_back(true);
    	v.push_back(false);
    	v.push_back(true);
    	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
    	{
    		cout << *it << " ";
    	}
    	cout << endl;
    	//利用逻辑非将容器搬运到容器v2中，并执行取反操作
    	vector<bool> v2;
    	v2.resize(v.size());
    	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
    	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
    	{
    		cout << *it << " ";
    	}
    }
    int main()
    {
    	test01();
    }
    ```

## STL常用算法

- 主要是由头文件<algorithm><functional><numeric>组成

- for_each

  - 用于遍历容器

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<functional>//内建函数对象头文件
    using namespace std;
    //for_each函数，遍历容器
    void print01(int val)
    {
    	cout << val << " ";
    }
    //仿函数
    class print02
    {
    public:
    	void operator()(int val)
    	{
    		cout << val << " ";
    	}
    };
    void test01()
    {
    	vector<int> v;
    	v.push_back(10);
    	v.push_back(20);
    	v.push_back(54);
    	v.push_back(23);
    	v.push_back(53);
    	for_each(v.begin(), v.end(),print01);
    	cout << endl;
    	for_each(v.begin(), v.end(), print02());
    
    }
    int main()
    {
    	test01();
    }
    ```

- transform:搬运到另一个容器中

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<functional>//内建函数对象头文件
    using namespace std;
    //transform
    class MyPrint
    {
    public:
    	void operator()(int val)
    	{
    		cout << val << " ";
    	}
    };
    //仿函数
    class Transform
    {
    public:
    	int operator()(int v)
    	{
    		return v;
    	}
    };
    void test01()
    {
    	vector<int> v;
    	v.push_back(10);
    	v.push_back(20);
    	v.push_back(54);
    	v.push_back(23);
    	v.push_back(53);
    	vector<int>vTarget;
    	vTarget.resize(v.size());//目标容器需要提前开辟空间
    	transform(v.begin(), v.end(), vTarget.begin(),Transform());
    	for_each(vTarget.begin(), vTarget.end(), MyPrint());
    
    }
    int main()
    {
    	test01();
    }
    ```

  - 搬运的目标容器必须提前开辟空间，否则无法搬运

- 常用的查找算法

  - find：查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<functional>//内建函数对象头文件
    using namespace std;
    //查找内置数据类型
    void test01()
    {
    	vector<int>v;
    	for (int i = 0; i < 10; i++)
    	{
    		v.push_back(i + 1);
    	}
    	vector<int>::iterator it = find(v.begin(), v.end(), 6);
    	if (it == v.end())
    	{
    		cout << "没有找到";
    	}
    	else
    	{
    		cout << "找到" << *it << endl;
    	}
    }
    //查找自定义数据类型
    class Person
    {
    public:
    	Person(string name, int age)
    	{
    		this->m_name = name;
    		this->m_age = age;
    	}
    	//重载==,使底层的find知道如何对比person数据类型
    	bool operator==(const Person& p)
    	{
    		if (this->m_name == p.m_name && this->m_age == p.m_age)
    		{
    			return true;
    		}
    		else
    		{
    			return false;
    		}
    	}
    	string m_name;
    	int m_age;
    };
    
    void test02()
    {
    	vector<Person> v;
    	Person p1("A", 10);
    	Person p2("B", 20);
    	Person p3("C", 40);
    	Person p4("D", 50);
    	
    	v.push_back(p1);
    	v.push_back(p2);
    	v.push_back(p3);
    	v.push_back(p4);
    	vector<Person>::iterator it = find(v.begin(), v.end(), p2);
    	if (it == v.end())
    	{
    		cout << "没有找到" << endl;
    	}
    	else
    	{
    		cout << "找到这个人了" << endl;
    		cout << "姓名" << (*it).m_name << "\t年龄" << (*it).m_age << endl;
    	}
    }
    int main()
    {
    	test01();
    	test02();
    }
    ```

- find_if–按条件查找数据

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<functional>//内建函数对象头文件
    using namespace std;
    //查找内置数据类型
    class GreaterFive
    {
    public:
    	bool operator()(int val)
    	{
    		return val > 5;
    	}
    };
    void test01()
    {
    	vector<int>v;
    	for (int i = 0; i < 10; i++)
    	{
    		v.push_back(i + 1);
    	}
    	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    	if (it == v.end())
    	{
    		cout << "不存在" << endl;
    	}
    	else
    	{
    		cout << *it << endl;
    	}
    	
    }
    //查找自定义数据类型
    class Person
    {
    public:
    	Person(string name, int age)
    	{
    		this->m_name = name;
    		this->m_age = age;
    	}
    	string m_name;
    	int m_age;
    };
    class Greater20
    {
    public:
    	bool operator()(Person& p)
    	{
    		return p.m_age > 20;
    	}
    };
    void test02()
    {
    	vector<Person> v;
    	Person p1("A", 10);
    	Person p2("B", 20);
    	Person p3("C", 40);
    	Person p4("D", 50);
    	
    	v.push_back(p1);
    	v.push_back(p2);
    	v.push_back(p3);
    	v.push_back(p4);
    	for (vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20()); it != v.end(); it++)
    	{
    		if (it == v.end())
    		{
    			cout << "没有找到" << endl;
    		}
    		else
    		{
    			cout << "找到这个人了" << endl;
    			cout << "姓名" << (*it).m_name << "\t年龄" << (*it).m_age << endl;
    		}
    	}
    	
    }
    int main()
    {
    	test01();
    	test02();
    }
    ```

- adjacent_find 查找相邻重复元素算法

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<functional>//内建函数对象头文件
    using namespace std;
    //查找 adjacent_find
    void test01()
    {
    	vector<int>v;
    	for (int i = 0; i < 10; i++)
    	{
    		v.push_back(i + 1);
    	}
    	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
    	if (pos == v.end())
    	{
    		cout << "未找到相邻重复元素" << endl;
    	}
    	else
    	{
    		cout << *pos << endl;
    	}
    }
    int main()
    {
    	test01();
    }
    ```

- binary_search:查找元素是否存在

  - 二分查找算法，该算法在**无序序列中不可使用**；该算法效率高

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<functional>//内建函数对象头文件
    using namespace std;
    //查找 adjacent_find
    void test01()
    {
    	vector<int>v;
    	for (int i = 0; i < 10; i++)
    	{
    		v.push_back(i + 1);
    	}
    	bool ret = binary_search(v.begin(), v.end(), 4);
    	if (ret)
    	{
    		cout << "找到元素" << endl;
    	}
    	else
    	{
    		cout << "未找到元素" << endl;
    	}
    }
    
    int main()
    {
    	test01();
    }
    ```

- count：统计元素个数

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<functional>//内建函数对象头文件
    using namespace std;
    //count
    //1.统计内置数据类型
    void test01()
    {
    	vector<int> v;
    	v.push_back(10);
    	v.push_back(10);
    	v.push_back(30);
    	v.push_back(40);
    	v.push_back(10);
    	int num = count(v.begin(), v.end(), 10);
    	cout << num << endl;
    }
    //2.统计自定义数据类型
    class Person
    {
    public:
    	Person(string name, int age)
    	{
    		this->m_name = name;
    		this->m_age = age;
    	}
    	bool operator==(const Person& p) 
    	{
    		if (this->m_age == p.m_age)
    		{
    			return true;
    		}
    		else
    		{
    			return false;
    		}
    	}
    	string m_name;
    	int m_age;
    };
    void test02()
    {
    	vector<Person> p;
    	Person p1("赵云", 20);
    	Person p2("左慈", 30);
    	Person p3("孙权", 40);
    	Person p4("周瑜", 20);
    	Person p5("张飞", 20);
    	p.push_back(p1);
    	p.push_back(p2);
    	p.push_back(p3);
    	p.push_back(p4);
    	p.push_back(p5);
    	Person p6("诸葛亮", 20);
    	int num = count(p.begin(), p.end(), p6);//找与诸葛亮同岁数的个数
    	cout << num << endl;
    
    
    }
    
    int main()
    {
    	test01();
    	test02();
    }
    ```

- count_if:按条件统计元素个数

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<functional>//内建函数对象头文件
    using namespace std;
    //count
    //1.统计内置数据类型
    class Greater20
    {
    public:
    	bool operator()(int val)
    	{
    		return val > 20;
    	}
    
    private:
    
    };
    
    void test01()
    {
    	vector<int> v;
    	v.push_back(10);
    	v.push_back(10);
    	v.push_back(30);
    	v.push_back(40);
    	v.push_back(10);
    	int num = count_if(v.begin(), v.end(), Greater20());
    	cout << "大于20的元素个数为" << num << endl;
    }
    //2.统计自定义数据类型
    class Person
    {
    public:
    	Person(string name, int age)
    	{
    		this->m_name = name;
    		this->m_age = age;
    	}
    	string m_name;
    	int m_age;
    };
    class AgeGreater20
    {
    public:
    	bool operator()(const Person& p)
    	{
    		return p.m_age > 20;
    	}
    };
    void test02()
    {
    	vector<Person> p;
    	Person p1("赵云", 20);
    	Person p2("左慈", 30);
    	Person p3("孙权", 40);
    	Person p4("周瑜", 20);
    	Person p5("张飞", 20);
    	p.push_back(p1);
    	p.push_back(p2);
    	p.push_back(p3);
    	p.push_back(p4);
    	p.push_back(p5);
    	int num = count_if(p.begin(), p.end(), AgeGreater20());//找年龄大于20的个数
    	cout << num << endl;
    }
    
    int main()
    {
    	test01();
    	test02();
    }
    ```

- sort:对容器内元素进行排序;**需要熟练掌握**

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<functional>//内建函数对象头文件
    using namespace std;
    //sort排序算法
    void myPrint(int val)
    {
    	cout << val << " ";
    }
    void test01()
    {
    	vector<int> v;
    	v.push_back(10);
    	v.push_back(10);
    	v.push_back(30);
    	v.push_back(40);
    	v.push_back(10);
    	sort(v.begin(), v.end());
    	for_each(v.begin(), v.end(), myPrint);
    	cout << endl;
    	//由升序改为降序
    	sort(v.begin(), v.end(), greater<int>());
    	for_each(v.begin(), v.end(), myPrint);
    	cout << endl;
    
    }
    int main()
    {
    	test01();
    }
    ```

    

- random_shuffle:洗牌算法，将元素顺序打乱

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<functional>//内建函数对象头文件
    using namespace std;
    //sort排序算法
    void myPrint(int val)
    {
    	cout << val << " ";
    }
    void test01()
    {
    	vector<int> v;
    	for (int i = 0; i < 10; i++)
    	{
    		v.push_back(i + 1);
    	}
    	//利用洗牌算法打乱顺序
    	random_shuffle(v.begin(), v.end());
    	for_each(v.begin(), v.end(), myPrint);
    }
    int main()
    {
    	srand((unsigned int)time(NULL));
    	test01();
    }
    ```

- merge:将两个容器合并，储存到另一个容器中

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<functional>//内建函数对象头文件
    using namespace std;
    //merge排序算法
    void myPrint(int val)
    {
    	cout << val << " ";
    }
    void test01()
    {
    	vector<int> v1;
    	vector<int> v2;
    	for (int i = 0; i < 10; i++)
    	{
    		v1.push_back(i);
    		v2.push_back(i + 5);
    	}
    	vector<int> vTarget;
    	vTarget.resize(v1.size() + v2.size());
    	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    	for_each(vTarget.begin(), vTarget.end(), myPrint);
    }
    int main()
    {
    	test01();
    }
    ```

- reverse：反转

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<functional>//内建函数对象头文件
    using namespace std;
    //merge排序算法
    void myPrint(int val)
    {
    	cout << val << " ";
    }
    void test01()
    {
    	vector<int> v1;
    	vector<int> v2;
    	for (int i = 0; i < 10; i++)
    	{
    		v1.push_back(i);
    	}
    	cout << "反转前" << endl;
    	for_each(v1.begin(), v1.end(), myPrint);
    	cout << endl;
    	cout << "反转后" << endl;
    	reverse(v1.begin(), v1.end());
    	for_each(v1.begin(), v1.end(), myPrint);
    
    }
    int main()
    {
    	test01();
    }
    ```

- copy:将容器内的指定范围的元素拷贝到另一容器中

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<functional>//内建函数对象头文件
    using namespace std;
    //merge排序算法
    void myPrint(int val)
    {
    	cout << val << " ";
    }
    void test01()
    {
    	vector<int> v1;
    	vector<int> v2;
    	for (int i = 0; i < 10; i++)
    	{
    		v1.push_back(i);
    	}
    	v2.resize(v1.size());
    	copy(v1.begin(), v1.end(), v2.begin());
    	for_each(v2.begin(), v2.end(), myPrint);
    }
    int main()
    {
    	test01();
    }
    ```

- replace:将容器里面的旧元素替换为新元素

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<functional>//内建函数对象头文件
    using namespace std;
    //merge排序算法
    void myPrint(int val)
    {
    	cout << val << " ";
    }
    void test01()
    {
    	vector<int> v1;
    	vector<int> v2;
    	for (int i = 0; i < 10; i++)
    	{
    		v1.push_back(i);
    	}
    	cout << "替换前" << endl;
    	for_each(v1.begin(), v1.end(), myPrint);
    	replace(v1.begin(), v1.end(), 4, 20);
    	cout << endl;
    	cout << "替换后" << endl;
    	for_each(v1.begin(), v1.end(), myPrint);
    }
    int main()
    {
    	test01();
    }
    ```

- replace_if:将满足条件的元素替换为新元素

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<functional>//内建函数对象头文件
    using namespace std;
    //merge排序算法
    void myPrint(int val)
    {
    	cout << val << " ";
    }
    class Greater
    {
    public:
    	bool operator()(int val)
    	{
    		return val > 5;
    	}
    };
    void test01()
    {
    	vector<int> v1;
    	vector<int> v2;
    	for (int i = 0; i < 10; i++)
    	{
    		v1.push_back(i);
    	}
    	cout << "替换前" << endl;
    	for_each(v1.begin(), v1.end(), myPrint);
    	replace_if(v1.begin(), v1.end(), Greater(), 100);
    	cout << "替换后" << endl;
    	for_each(v1.begin(), v1.end(), myPrint);
    }
    int main()
    {
    	test01();
    }
    ```

- swap:互换

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<functional>//内建函数对象头文件
    using namespace std;
    //merge排序算法
    void myPrint(int val)
    {
    	cout << val << " ";
    }
    class Greater
    {
    public:
    	bool operator()(int val)
    	{
    		return val > 5;
    	}
    };
    void test01()
    {
    	vector<int> v1;
    	vector<int> v2;
    	for (int i = 0; i < 10; i++)
    	{
    		v1.push_back(i);
    		v2.push_back(i + 32);
    	}
    	cout << "交换前" << endl;
    	for_each(v1.begin(), v1.end(), myPrint);
    	cout << endl;
    	for_each(v2.begin(), v2.end(), myPrint);
    	cout << endl;
    	cout << "交换后" << endl;
    	swap(v1, v2);
    	for_each(v1.begin(), v1.end(), myPrint);
    	cout << endl;
    	for_each(v2.begin(), v2.end(), myPrint);
    }
    int main()
    {
    	test01();
    }
    ```

- accumulate:将容器内元素累加；在头文件numeric中

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<numeric>
    using namespace std;
    //accumulate
    void test01()
    {
    	vector<int> v1;
    	for (int i = 0; i <= 100; i++)
    	{
    		v1.push_back(i);
    
    	}
    	int sum = accumulate(v1.begin(), v1.end(), 0);//最后一个参数是起始值
    	cout << sum << endl;
    }
    	
    int main()
    {
    	test01();
    }
    ```

- fill:向容器中填充元素

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<numeric>
    using namespace std;
    //fill算法
    void myPrint(int val)
    {
    	cout << val << " ";
    }
    class Greater
    {
    public:
    	bool operator()(int val)
    	{
    		return val > 5;
    	}
    };
    void test01()
    {
    	vector<int> v1;
    	v1.resize(10);
    	fill(v1.begin(), v1.end(), 100);
    	for_each(v1.begin(), v1.end(), myPrint);
    }
    	
    int main()
    {
    	test01();
    }
    ```

- set_intersection:求两个容器的交集

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<numeric>
    using namespace std;
    //常用集合算法
    void myPrint(int val)
    {
    	cout << val << " ";
    }
    class Greater
    {
    public:
    	bool operator()(int val)
    	{
    		return val > 5;
    	}
    };
    void test01()
    {
    	vector<int> v1;
    	vector<int> v2;
    	for (int i = 0; i < 5; i++)
    	{
    		v1.push_back(i);
    		v2.push_back(i + 2);
    	}
    	//目标容器
    	vector<int> vTarget;
    	//目标容器需要提前开辟空间
    	//最特殊的情况；开辟空间取小值
    	vTarget.resize(min(v1.size(), v2.size()));
    	//获取交集
    	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    	for_each(vTarget.begin(), itEnd, myPrint);// !!!!
    }
    	
    int main()
    {
    	test01();
    }
    ```

- set_union:求两个集合的并集

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<numeric>
    using namespace std;
    //常用集合算法
    void myPrint(int val)
    {
    	cout << val << " ";
    }
    class Greater
    {
    public:
    	bool operator()(int val)
    	{
    		return val > 5;
    	}
    };
    void test01()
    {
    	vector<int> v1;
    	vector<int> v2;
    	for (int i = 0; i < 5; i++)
    	{
    		v1.push_back(i);
    		v2.push_back(i + 2);
    	}
    	//目标容器
    	vector<int> vTarget;
    	//目标容器需要提前开辟空间
    	//最特殊的情况；开辟空间取小值
    	vTarget.resize(v1.size()+v2.size());
    	//获取并集
    	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    	for_each(vTarget.begin(), itEnd, myPrint);// !!!!
    }
    int main()
    {
    	test01();
    }
    ```

- set_different:求两个集合的差集

  - ```c++
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<numeric>
    using namespace std;
    //常用集合算法
    void myPrint(int val)
    {
    	cout << val << " ";
    }
    class Greater
    {
    public:
    	bool operator()(int val)
    	{
    		return val > 5;
    	}
    };
    void test01()
    {
    	vector<int> v1;
    	vector<int> v2;
    	for (int i = 0; i < 5; i++)
    	{
    		v1.push_back(i);
    		v2.push_back(i + 2);
    	}
    	//目标容器
    	vector<int> vTarget;
    	//目标容器需要提前开辟空间
    	//最特殊的情况；开辟空间取小值
    	vTarget.resize(max(v1.size(),v2.size()));
    	//获取差集
    	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    	for_each(vTarget.begin(), itEnd, myPrint);// !!!!
    }
    int main()
    {
    	test01();
    }
    ```

  - 

