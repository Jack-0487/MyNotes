# c++核心编程

## 内存分区模型

- 代码区：存放函数体的二进制代码，由操作系统进行管理
- 全局区：存放全局变量和静态变量以及常量
- 栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
- 堆区：由程序员分配和释放，若程序员不释放，则由程序结束后由系统释放

### 程序运行前

- 在程序编译后，生成了exe可执行程序，**未执行该程序前**分为两个区域
  - 代码区：
    - 存放CPU执行的机器指令
    - 代码区是**共享**的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可
    - 代码区是**只读**的，使其只读的原因是防止程序意外的修改指令
  - 全局区
    - 全局变量和静态变量存放区域
    - 全局区还包含了常量区，字符串常量和其他常量（const修饰的全局变量；const修饰的局部变量不在全局区）也存放于该区域
    - **该区域的数据在程序结束后由操作系统释放**

### 程序运行后

- 栈区：由编译器自动分配和释放，存放函数的参数值，局部变量等
  - 注意：**不要返回局部变量的地址**

- 堆区：由程序员分配释放，程序结束时由操作系统回收；在c++中主要利用**new在堆区开辟内存**

- **指针本质上也是局部变量，放在栈上，指针保存的数据是放在堆区**

- new返回的是一个地址

- ```c++
  #include<iostream>
  using namespace std;
  int* func()
  {
  	//在堆区创建整型数据
  	//new返回的是该数据类型的指针
  	int* p = new int(10);
  	return p;
  }
  void test()
  {
  	int* p = func();
  	cout << *p << endl;
  	cout << *p << endl;
  	delete p;
  }
  //在堆区开辟数组
  void func2()
  {
  	int* p = new int[10];//返回连续线性空间的首地址
  	for (int i = 0; i < 10; i++)
  	{
  		p[i] = i + 10;
  		cout << p[i] << " ";
  	}
  	delete[] p;
  }
  int main()
  {
  	test();
  	func2();
  	
  }
  ```

## 引用

### 引用的基本使用

- 引用的作用就是给变量起别名

- 引用的本质就是**指针常量**

- 引用必须初始化；引用在初始化后不可以发生改变

- 引用做函数参数：

  - 作用：函数传参时，可以利用引用的技术让形参修饰实参；可以简化指针的使用

  - 值传递形参不影响实参；地址传递形参影响实参

    - ```c++
      #include<iostream>
      using namespace std;
      void mySwap01(int a, int b)//值传递
      {
      	int temp = a;
      	a = b;
      	b = temp;
      }
      void mySwap02(int& a, int& b)//引用传递
      {
      	int temp = a;
      	a = b;
      	b = temp;
      }
      void mySwap03(int* a, int* b)
      {
      	int temp = *a;
      	*a = *b;
      	*b = temp;
      }
      int main()
      {
      	int a = 10;
      	int b = 20;
      	mySwap01(a, b);
      	mySwap02(a, b);
      	mySwap03(&a, &b);
      }
      ```

  - 引用做函数返回值

    - 不要返回局部变量的引用（因为局部变量存放在栈区）
    - 函数的调用可以作为左值