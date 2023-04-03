# Matlab

- clc 清屏
- clear all 清除工作区
- \%%+空格 注释全行
- % 也能注释

## matlab命名规则

- 变量名区分大小写
- 变量名不超过64位
- 变量名以字母开头，可以由字母，数字和下划线组成，但是不能使用标点
- 变量名应简洁明了，通过变量名可以直观看出变量所表示的物理意义

## 数据类型

- 数字
- 字符和字符串
  - abs(str)  ASCII码
  - char(97) 
  - num2str(65)
  - length(str) 字符串长度
- 矩阵
  - a = [1 2 3; 4 5 6; 7 8 9]
  - b = a’ 转置
  - c = a(:) 按列拉长
  - d = inv(a) 求逆
  - e = zeros(10, 5, 3) 创建一个10行5列的三维矩阵
- 随机数
  - f = rand(m, n) 随机生成m行n列的随机数矩阵,在0~1之间
  - f = rand(m, n, ‘double’) 精度为double的均匀分布的伪随机数
  - rand(RandStream, m, n) 利用指定的随机数种子生成伪随机数
  - randn 生成标准正态分布的伪随机数，均值为0，方差为1
  - randi 生成均匀分布的伪随机整数
    - randi(iMax) 在开区间(0, iMax)生成均匀分布的伪随机整数‘
    - randi(iMax, m, n)在开区间生成m*n的随机矩阵
    - randi([iMin,iMax], m, n) 在开区间（imin, iMax）生成m*n的随机矩阵
- 元胞数组
  - 元胞数组是matlab中特有的数据类型，是数组的一种，内部元素可以是属于不同的数据类型；与C中的结构体类似
  - a = cell(1, 6)
  - a{2} = eye(3) %索引从1开始
  - magic(n)生成一个n阶幻方，幻方是每行，每列以及主副对角线上的n个数之和相等

- 结构体

  - books = struct(‘name’, {{‘ machine leaning’}}, ‘price’, [30 40])

  - books = struct('name', {{'machine learning', 'hello'}}, 'price', [30 40]);
    books.name
    books.name(1) % 取元胞数组？？？
    books.name{1} %取出字符串

    books.price(1) %取出30

## matlab的矩阵操作

- 矩阵定义与构造

- A = 1:2:9 %1到9步长为2
  B = repmat(A, 3, 2) %将A的行重复3次， 列重复2次
  C = ones(2, 4)%元素全为1的矩阵

- 矩阵的运算

  A = [1 2 3; 4 5 6; 7 8 9];
  B = [9 8 7; 1 2 3; 4 5 6];
  C = A .* B %对应项相乘
  D = A / B % A*（B的逆）
  E = A ./ B % 对应项相除

- 矩阵的下标
  - a = magic(5)
    b = a(2, 3)%取2行3列元素
    c = a(3,:) %取a的第3行
    d = a(:,4) %取第四列
    [m, n] = find(a > 20) %找大于20的矩阵元素序号值

## matlab的逻辑和流程控制

- for

  - ```matlab
    for 循环变量 = 初值：步长：终值
    	执行语句
    end
    ```

  - ```matlab
    sum = 0;
    for i = 0:2:5
        sum = sum + i^2;
    end
    ```

- while循环

  - ```matlab
    while 循环表达式
        执行语句；
        end
    ```

  - ```matlab
    sum = 0;
    i = 0;
    while i < 10
        sum = sum + i;
        i = i + 1;
    end
    sum
    ```

- if…end 结构

  - ```matlab
    if 条件表达式
    	执行语句
    end
    ```

- if…else…end

  - ```matlab
    if 表达式
    	语句体
    else
    	语句体
    end
    ```

- switch…case…end

## 绘图

- 二维绘图
  - clear all
    clc
    x = 0:0.1:10;
    y = sin(x);
    y1 = cos(x);
    title('y = sin(x)');
    xlabel('x');
    ylabel('sin(x)');
    xlim([0 2*pi]); %限定x坐标轴的范围
    figure %建立一个幕布，不用也可
    plot(x, y) %绘制二维图
    [AX, H1, H2] = plotyy(x,y,x,y1,'plot'); %共用x轴坐标系
    set(get(AX(1),'Ylabel'), 'String','first');
    set(get(AX(2),'Ylabel'), 'String','second');
    xlabel('Time(\musec)');
    title('test');
    set(H1, 'LineStyle', ':');
- 三维绘图
  - plot3