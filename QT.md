# QT

## QT基础

- 输入中文文本编译前需要在.pro文件中加入msvc{ QMAKE_CFLAGS += /uft-8 }

## 创建第一个Button

```c++
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"qpushbutton.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建一个按钮
    QPushButton * btn = new QPushButton;
    btn->resize(100,30);//按钮重新设置大小
    btn->setParent(this);//设置到父窗口中
    btn->setText("pushbuton");
    QPushButton * bt = new QPushButton("se英语d", this);
    bt->move(400, 200);
    resize(600,400);//重置窗口大小
    setWindowTitle("firstWindow");//设置标题
    setFixedSize(600, 400); //设置固定窗口大小

}

MainWindow::~MainWindow()
{
    delete ui;
}


```

## 对象树

- 当创建的对象在堆区的时候，如果指定的父亲是QObject派生下来的类或者QObject子类派生下来的类，可以不用管理释放的操作，将对象放入到对象树中
- 一定程度上简化了内存回收机制
- 局部对象的析构顺序和构造顺序相反

## QT窗口的坐标系

- 原点为左上角，x向右增加，y向下增加

## 信号槽

- connect(信号发送者，发送的具体信号，信号的接收者，信号的处理)

- 信号槽的优点：松散耦合：信号的发送端和接收端本身是没有关联的，通过connect连接实现两者的耦合

- ```c++
  #include "widget.h"
  #include "ui_widget.h"
  #include"QPushButton"
  
  Widget::Widget(QWidget *parent)
      : QWidget(parent)
      , ui(new Ui::Widget)
  {
      ui->setupUi(this);
      resize(400,400);
      QPushButton * pbt1 = new QPushButton;
      pbt1->setParent(this);
      pbt1->move(200, 0);
      pbt1->setText("hh");
      QPushButton * pbt2 = new QPushButton;
      pbt2->setParent(this);
      pbt2->move(200,200);
      connect(pbt1, &QPushButton::clicked, this, &Widget::close); //信号槽
  }
  
  Widget::~Widget()
  {
      delete ui;
  }
  
  ```

- 自定义信号

  - 写到signal下
  - 返回void
  - 需要声明，不需要实现
  - 可以有参数，可以重载

- 自定义槽函数
  - 返回void
  - 需要声明，也需要实现
  - 可以有参数，可以重载
  - 写到public或者public slot里面
- 触发自定义信号
  - emit

- 当自定义信号和槽出现重载

  - 需要利用函数指针明确指向函数的地址
  - void（Teacher：：signal）（QString）= &Teacher::hungry
  - QString转成char\*:利用toutf8()转为QByteArray,用.data()转为char\*

- ```c++
  //widgt.cpp
  #include "widget.h"
  #include "ui_widget.h"
  #include"QPushButton"
  
  Widget::Widget(QWidget *parent)
      : QWidget(parent)
      , ui(new Ui::Widget)
  {
      ui->setupUi(this);
      resize(400,400);
      //创建一个老师的对象和学生对象
      this->student1 = new Student(this);
      this->teacher1 = new Teacher(this);
      //老师和学生的连接
      //指针指向函数地址
      void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
      void(Student:: *studentslot)(QString) = &Student::treat;
      connect(teacher1, teacherSignal, student1,studentslot);
     //点击触发按钮就下课
      QPushButton *btn = new QPushButton("下课", this);
      btn->resize(100, 40);
      btn->move(150,0);
      //connect(btn, &QPushButton::clicked, this, &Widget::classIsOver);
      //无参信号和槽连接
      void(Teacher::*teachersignal2)(void) = &Teacher::hungry;
      void(Student::*studentslot2)(void) = &Student::treat;
      connect(teacher1, teachersignal2, student1, studentslot2);
      //信号连接信号
      connect(btn, &QPushButton::clicked, teacher1, teachersignal2);
      //断开信号
      disconnect(teacher1, teachersignal2, student1, studentslot2);
  
  }
  void Widget::classIsOver()
  {
      emit teacher1->hungry("宫保鸡丁");//触发信号
  }
  Widget::~Widget()
  {
      delete ui;
  }
  ```

- 信号可以连接信号；一个信号可以连接多个槽函数；多个信号可以连接同一个槽函数；信号和槽函数的参数必须类型一一对应

- 信号和槽参数个数。信号个数可以多于槽函数

## Lambda表达式

```c++
 [&](){
        btn->setText("First");
    }();//地址传递//值传递用[=]
```

- mutable关键字用于修饰值传递的变量，修改的是拷贝，而不是本体

## 作业

```c++
#include "widget.h"
#include "ui_widget.h"
#include"QPushButton"
#include"QWidget"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QWidget *first = new QWidget;
    first->resize(600,400);
    setWindowTitle("hhhh");
    QPushButton * btn = new QPushButton;
    btn->setParent(this);
    btn->resize(200,100);
    btn->move(250,150);
    btn->setText("open");
    btn->setFlat(1);
    connect(btn,&QPushButton::clicked, first,[=](){first->show();} );
   
     connect(btn,&QPushButton::clicked, first,[=](){
         if(btn->text()=="close")
         {
             first->close();
             btn->setText("open");
         }
         else {
             first->show();
             btn->setText("close");
         };} );
}

Widget::~Widget()
{
    delete ui;
}

```

## QMainWindow

- QMainWindow是一个为用户提供主窗口程序的类，包含一个菜单栏（menubar），多个工具栏（tool bar），多个链接部件（dock wights），一个状态栏（status bar）以及一个中心部件（central widget），是许多应用的基础，如文本编辑器，图片编辑器等

- 菜单栏
  - 最多只有一个
  - QMenuBar * bar  = new MenuBar();
  - setMenuBar(bar);
  - …..
  - 添加分割线
- 工具栏
  - 可以有多个
  - QToolBar * toolbar = new QToolBar(this);
  - 设置默认停靠区域
  - 添加菜单项，控件
- 状态栏
  - 只能有一个
  - QStatusBar  \* Sbar = statusBar()
  - 设置到窗口中 setStatusBar(Sbar)
  - ….
- 铆接部件
  - 浮动窗口，可以有多个
  - QDockWidget
  - …
- 核心部件
  - 只能有一个
  - setCentralWidget(edit)

- ```c++
  #include "mainwindow.h"
  #include "ui_mainwindow.h"
  #include"QMenuBar"
  #include"QToolBar"
  #include"QStatusBar"
  #include"QMenu"
  #include"QPushButton"
  #include"QLabel"
  #include"QDockWidget"
  #include"QTextEdit"
  MainWindow::MainWindow(QWidget *parent)
      : QMainWindow(parent)
      , ui(new Ui::MainWindow)
  {
      ui->setupUi(this);
      resize(600, 400);
      setWindowTitle("test01");
      //创建菜单
      QMenuBar * mBar = menuBar();
      setMenuBar(mBar);
      QMenu * fileMenu = mBar->addMenu("文件");
      QMenu * editMenu = mBar->addMenu("编辑");
      //创建菜单项
      QAction * openAction = fileMenu->addAction("新建");
      QAction * newAction = fileMenu->addAction("打开");
      //添加分割线
      fileMenu->addSeparator();
      fileMenu->addAction("保存");
      //创建工具栏 可以有多个
      QToolBar *tBar = new QToolBar;
      addToolBar(Qt::LeftToolBarArea,tBar);
      //设置停靠范围
      tBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
      tBar->setMovable(true);
      tBar->setFloatable(false);
      //QAction * newAction = tBar->addAction("新建");
      tBar->addAction(newAction);
      //QAction * openAction = tBar->addAction("打开");
      //添加分割线
      tBar->addAction(openAction);
      tBar->addSeparator();
      //在工具栏中添加控件
      QPushButton * btn = new QPushButton("btn", this);
      tBar->addWidget(btn);
      //状态栏 最多只有一个
      QStatusBar * stBar = statusBar();
      //设置到窗口中
      setStatusBar(stBar);
      //放标签控件
      QLabel * label = new QLabel("提示信息", this);
      stBar->addWidget(label);
      QLabel * label2 = new QLabel("右侧提示信息", this);
      stBar->addPermanentWidget(label2);
      //铆接部件（浮动窗口） 可以有多个
      QDockWidget * dockWidget = new QDockWidget("浮动", this);
      addDockWidget(Qt::BottomDockWidgetArea, dockWidget);
      dockWidget->setAllowedAreas(Qt::TopDockWidgetArea);
      //设置中心部件
      QTextEdit * edit = new QTextEdit(this);
      setCentralWidget(edit);
  
  }
  
  MainWindow::~MainWindow()
  {
      delete ui;
  }
  
  ```


## 资源文件

- 将资源文件拷贝到项目中、
- 右键项目---添加文件--Qt resouce file – 给资源文件起名
- res生成res.qrc
- open in editor 编辑资源
- 添加前缀 添加文件
- 使用  路径  “:+前缀+文件名”

## 模态对话框和非模态对话框

- 模态对话框：不可以对其他窗口进行操作

- 非模态对话框：可以对其他窗口进行操作

- ```c++
  #include "mainwindow.h"
  #include "ui_mainwindow.h"
  #include "QDialog"
  #include"QDebug"
  MainWindow::MainWindow(QWidget *parent)
      : QMainWindow(parent)
      , ui(new Ui::MainWindow)
  {
      ui->setupUi(this);
      //点击新建按钮 弹出一个对话框
      connect(ui->actionnew, &QAction::triggered, [=](){
          //对话矿分类
          //模态对话框（不可以对其他窗口进行操作）非模态对话框（可以对其他窗口操作）
          //模态创建
  //        QDialog dlg(this);
  //        dlg.exec();
  //        qDebug()<< "ddd";
          //非模态对话框
          QDialog *dlg2 = new QDialog(this);
          dlg2->resize(300, 300);
          dlg2->setAttribute(Qt::WA_DeleteOnClose);
          dlg2->show();
  
      });
  }
  
  MainWindow::~MainWindow()
  {
      delete ui;
  }
  
  ```

## 消息对话框

- ```c++
  #include "mainwindow.h"
  #include "ui_mainwindow.h"
  #include "QDialog"
  #include"QDebug"
  #include"QMessageBox"
  MainWindow::MainWindow(QWidget *parent)
      : QMainWindow(parent)
      , ui(new Ui::MainWindow)
  {
      ui->setupUi(this);
      //点击新建按钮 弹出一个对话框
      connect(ui->actionnew, &QAction::triggered,[=](){
          //消息对话框
          //错误对话框
         // QMessageBox::critical(this,"critical","错误");
          //信息对话框
          QMessageBox::information(this,"hello", "informat6ion");
          //提问对话框
          //参数1：父亲；参数2：标题；参数3：提示内容 参数4：按键类型 参数5：默认关联回车按键
  //        QMessageBox::question(this,"question","是否保存",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel );
          //警告对话框
          
      });
  }
  
  MainWindow::~MainWindow()
  {
      delete ui;
  }
  
  ```

- 其他对话框

  - 颜色对话框 QColorDialog::getColor(QColor(255, 0, 0))
  - 文件对话框：参数1：父亲；参数二：标题；参数3：默认打开路径；参数4：过滤文件格式；返回值是选取的路径
  - 字体对话框 QFileDialog::getOpenFileNames(this,"open the file", "D:\\qtproject","(*.png)")

## 界面布局

- 实现登录窗口
- 利用布局方式对窗口进行美化
- 选取widget进行布局，水平布局，垂直布局以及栅格布局
- 给用户名，密码，登录，退出按钮进行布局
- 默认窗口和控件之间有9个像素的间隙，通过调整layoutLeftMargin来调整间隙
- 利用弹簧进行布局

## 控件

- 按钮组
  - QPushButton 常用按钮
  - QToolButton 工具按钮 用于显示图片，
  - radioButton 单选按钮，设置默认ui->rBtnMan->setChecked(true)
  - checkBox  返回值2是选中（全选），1是半选中，0是未选中

- QListWidget 列表容器

  - ```c++
    #include "mainwindow.h"
    #include "ui_mainwindow.h"
    #include"QListWidgetItem"
    #include"QListWidget"
    #include"QString"
    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        //利用listWidget写诗
        QListWidgetItem * item = new QListWidgetItem("好家伙");
        ui->listWidget->addItem(item);
        item->setTextAlignment(Qt::AlignHCenter);// 水平居中
        QStringList list;
        list << "锄禾日当午" << "汗滴禾下土";
        ui->listWidget->addItems(list);//一次性添加整个容器
    }
    
    MainWindow::~MainWindow()
    {
        delete ui;
    }
    
    ```

- QTreeWidget

  - 设置头		ui->treeWidget->setHeaderLabels(QStringList() << "英雄" << "英雄介绍");

  - 设置根结点

  - 添加根节点到控件

  - 追加子节点

  - 将子节点添加到根节点 addchild()

  - ```c++
    #include "widget.h"
    #include "ui_widget.h"
    
    Widget::Widget(QWidget *parent)
        : QWidget(parent)
        , ui(new Ui::Widget)
    {
        ui->setupUi(this);
        //设置水平头
        ui->treeWidget->setHeaderLabels(QStringList() << "英雄" << "英雄介绍");
    
        QTreeWidgetItem * liItem = new QTreeWidgetItem(QStringList()<< "力量");
        QTreeWidgetItem * miniItem = new QTreeWidgetItem(QStringList()<< "敏捷");
        QTreeWidgetItem * zhiItem = new QTreeWidgetItem(QStringList()<< "智力");
        //加载顶层节点
        ui->treeWidget->addTopLevelItem(liItem);
        ui->treeWidget->addTopLevelItem(miniItem);
        ui->treeWidget->addTopLevelItem(zhiItem);
        //追加子节点
        QStringList hero1;
        hero1 << "simayi" << "laozei";
        QTreeWidgetItem * first = new QTreeWidgetItem(hero1);
        liItem->addChild(first);
    }
    
    Widget::~Widget()
    {
        delete ui;
    }
    
    ```

- QTableWidget

  - 设置列数

  - 设置水平表头

  - 设置行数

  - 设置正文

  - ```c++
    #include "widget.h"
    #include "ui_widget.h"
    
    Widget::Widget(QWidget *parent)
        : QWidget(parent)
        , ui(new Ui::Widget)
    {
        ui->setupUi(this);
        //TableWiget控件
        //设置列数
        ui->tableWidget->setColumnCount(3);
        //设置水平表头
        ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "name" << "age" << "sex");
        //设置行数
        ui->tableWidget->setRowCount(4);
        //设置正文
        //ui->tableWidget->setItem(0,0, new QTableWidgetItem("yasuo"));
        QStringList nameList;
        nameList << "yase" << "auto" << "english" << "six";
        for(int i = 0; i < 4; i++)
        {
            int col = 0;
            ui->tableWidget->setItem(i,col++,new QTableWidgetItem(nameList[i]));
            //int转QString
            ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(i+20)));
        }
    }
    
    Widget::~Widget()
    {
        delete ui;
    }
    ```

- 自定义控件封装

  - 添加新文件-设计师界面类，在.ui中设计SpinBox和QSlider两个控件

  - Widget中使用自定义控件，拖拽一个Widget点击提升为，点击添加，点击提升

  - 实现功能，改变数字，滑动条跟着移动

  - 提供getNum()和setNum()对外接口

  - ```c++
    #############widegt.cpp
    #include "widget.h"
    #include "ui_widget.h"
    #include"QPushButton"
    #include"QDebug"
    Widget::Widget(QWidget *parent)
        : QWidget(parent)
        , ui(new Ui::Widget)
    {
        ui->setupUi(this);
        //点击获取 获取控件当前的值
        connect(ui->btn_getNum, &QPushButton::clicked, [=](){
            QDebug() << ui->widget->getNum();
        } );
        //设置到一半
        connect(ui->btn_setNum, &QPushButton::clicked, [=](){
          ui->widget->setNum(50);  
        })
    }
    
    Widget::~Widget()
    {
        delete ui;
    }
    ############smallWidget.cpp
    #include "smallwidget.h"
    #include "ui_smallwidget.h"
    
    smallWidget::smallWidget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::smallWidget)
    {
        ui->setupUi(this);
        //QSpinBox移动， QSlider移动
        void(QSpinBox:: *spSingal)(int) = &QSpinBox::valueChanged;
        connect(ui->spinBox, spSingal, ui->horizontalSlider, &QSlider::setValue);
        //QSlider移动  QSpinBox也移动
        connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
    }
    //设置数字
    void smallWidget::setNum(int num)
    {
        ui->spinBox->setValue(num);
    }
    //获取数字
    int smallWidget::getNum()
    {
        return ui->spinBox->value();
    }
    smallWidget::~smallWidget()
    {
        delete ui;
    }
    
    
    ```


## 事件

### 鼠标事件

```c++
#include "mylabel.h"
#include"QDebug"
myLabel::myLabel()
{

}
void myLabel::enterEvent(QEvent *event)
{
    qDebug() << "鼠标进入";
}
void myLabel::leaveEvent(QEvent *event)
{
    qDebug() << "鼠标离开";
}
## 实现监控鼠标的进入和离开
```

- QMouseEvent:捕获鼠标按下，释放，离开以及坐标等事件

- 鼠标的进入事件 enterEvent
- 鼠标的离开事件 leaveEvent
- 鼠标按下 mousePressEvent(Qmouse* ev)
- 鼠标释放 mouseReleaseEvent
- 鼠标移动 mouseMoveEvent
- ev->x()   x坐标   ev->y()  y坐标
- ev->button() 可以判断所有按键 Qt::LeftButton  Qt::RightButton
- ev->buttons() 判断组合按键 判断move时候的左右键 结合&操作符
- 格式化字符串

### 定时器

- 第一种

  - 利用事件 void timerEvent(QTimerEvent \* ev)

  - 启动定时器 startTimer(1000) 单位ms

  - timerEvent的返回值是定时器的唯一标示 可以和ev->timerId做比较

  - ```c++
    #include "widget.h"
    #include "ui_widget.h"
    #include"QString"
    Widget::Widget(QWidget *parent)
        : QWidget(parent)
        , ui(new Ui::Widget)
    {
        ui->setupUi(this);
        //启动定时器
         id1 = startTimer(1000); //参数1 间隔 单位：ms
         id2 = startTimer(2000);
    }
    
    void Widget::timerEvent(QTimerEvent *ev)
    {
        if(ev->timerId() == id1)
        {
            static int num = 1;
           ui->label->setText(QString::number(num++));
         }
        //label_2 每隔两秒+1
        if(ev->timerId() == id2)
        {
            static int num2 = 1;
            ui->label2 ->setText(QString::number(num2++));
        }
    }
    Widget::~Widget()
    {
        delete ui;
    }
    
    ```

- 第二种：使用定时器的类

  - ```c++
     //第二种定时器
    //c
         QTimer *timer = new QTimer(this);
         //启动定时器
         timer->start(500);
         connect(timer, &QTimer::timeout,[=](){
             static int num = 1;
            ui->label_2->setText(QString::number(num++));
         });
    ```

- 定时器暂停：

  - ```c++
         connect(ui->btn, &QPushButton::clicked, timer, [=](){
             timer->stop();
         });
    ```


### 事件分发器

- bool event(QEvent \*ev)：布尔类型的事件分发器；返回值是bool类型，如果返回的是true,代表用户要处理这个事件，不向下分发事件了

- 用于事件的分发和拦截，不建议做拦截用

- ```c++
  bool myLabel::event(QEvent *e)
  {
      //如果鼠标按下，做拦截操作
      if(e->type() == QEvent::MouseButtonPress)
      {
          QMouseEvent *ev = static_cast<QMouseEvent *>(e);//静态类型转换
          QString str == QString("Event函数中；鼠标按下 x= %1 y=%2 globalX = %3 globalY = %4".arg(ev->x()).arg(ev->y()));
          qDebug()<<str;
          return true;//true代表用户自己处理这个事件，不向下分发
      }
      //其他事件交给父类处理
      return QLabel::event(e);
  }
  ```

### 事件过滤器

- 在程序分发到event事件之前再做一次高级拦截

- 使用有两个步骤

  - 给控件安装事件过滤器
  - 重写eventfilter事件

- ```c++
  //安装事件的过滤器
  ui->label->installEventFilter(this);
  //重写事件过滤器的事件
  bool Widget::eventFilter(QObject*, QEvent*)
  {
      if(obj == ui->label)
      {
          //如果鼠标按下，做拦截操作
      if(e->type() == QEvent::MouseButtonPress)
      {
          QMouseEvent *ev = static_cast<QMouseEvent *>(e);//静态类型转换
          QString str == QString("Event函数中；鼠标按下 x= %1 y=%2 globalX = %3 globalY = %4".arg(ev->x()).arg(ev->y()));
          qDebug()<<str;
          return true;//true代表用户自己处理这个事件，不向下分发
      }
      }
      //其他默认处理
      return QWidget::eventFilter(obj,e)
  }
  ```

## QPainter 绘图

```c++
#include "widget.h"
#include "ui_widget.h"
#include"QPainter"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);//this指定的是绘图设备
     //设置笔的颜色
    QPen pen(QColor(255, 100, 100));
    pen.setStyle(Qt::DotLine);
    painter.setPen(pen);
    //设置画刷
    QBrush brush(QColor(0, 200, 150));
    //设置画刷风格
    brush.setStyle(Qt::Dense4Pattern);
    //让画家使用画刷
    painter.setBrush(brush);
    painter.drawLine(QPoint(0,0),QPoint(100, 100));
    painter.drawEllipse(QPoint(100, 100), 80, 50);//椭圆
    //画矩形
    painter.drawRect(QRect(200,20,50,60));
    //画文字
    painter.drawText(QRect(100, 100, 100, 100), "好难");
}
Widget::~Widget()
{
    delete ui;
}

```

```c++
#include "widget.h"
#include "ui_widget.h"
#include"QPainter"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);//抗锯齿
    painter.drawEllipse(QPoint(100, 100), 50, 50);
    painter.translate(100, 0);//将画家移动
    painter.save();//保存画家状态
    painter.drawEllipse(QPoint(100, 100), 50, 50);
    painter.translate(100, 0);//将画家移动
    painter.restore();//还原画家状态
    painter.drawEllipse(QPoint(100, 100), 50, 50);




}
Widget::~Widget()
{
    delete ui;
}


```

- 画家画资源中的图

  - ```c++
    #include "widget.h"
    #include "ui_widget.h"
    #include"QPainter"
    Widget::Widget(QWidget *parent)
        : QWidget(parent)
        , ui(new Ui::Widget)
    {
        ui->setupUi(this);
        //点击移动按钮 图片移动
        connect(ui->pushButton, &QPushButton::clicked,[=](){
            update();
        });
    }
    void Widget::paintEvent(QPaintEvent *)
    {
        QPainter painter(this);
        int posX = 0;
        painter.drawPixmap(20, 20, QPixmap(":/01.png"));
    
    
    
    
    }
    Widget::~Widget()
    {
        delete ui;
    }
    
    
    ```

  - QImage对像素点进行修改

  - QPicture用来记录和重现绘图指令

  - QPixmap对不同平台进行了优化


## QFile 文件操作

```c++
#include "widget.h"
#include "ui_widget.h"
#include"QFileDialog"
#include"QPushButton"
#include"QTextCodec"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //点击文件选取按钮，弹出对话框
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString path = QFileDialog::getOpenFileName(this, "打开文件", "C:\\Users\\Dats\\Desktop");
        //将路径放到lineEdit中
        ui->lineEdit->setText(path);
        //读取内容 放入到textedit中 Qt默认格式为utf-8
        //编码格式类
       // QTextCodec * codec = QTextCodec::codecForName("gbk");
        QFile file(path);
        //设置打开方式
        file.open(QIODevice::ReadOnly);
       // QByteArray array = file.readAll();
        QByteArray array;
        if(! file.atEnd())
        {
            array += file.readLine();//按行读取
        }

        //将读取到的数据放入textedit中
        ui->textEdit->setText(array);
        //写文件
        file.open(QIODevice::Append);//用追加的方式写文件
        file.write("aaaa");
        file.close();

    });
}

Widget::~Widget()
{
    delete ui;
}

```

- QFileInfo–获取文件信息

