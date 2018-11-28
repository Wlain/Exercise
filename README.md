##C++进阶
侯捷

C++：

* C++语言
* C++标准库

推荐书籍：
《Effective C++》
《C++ primer》
《STL源码剖析》


C：

Type（built-in，struct）
data
Function

###C++ 面向对象
数据和函数包在一起，数据有很多分，函数只有一份。以此创建对象。

class，struct

###例子1，复数

complex c1(2，1)；

complex c2;

complex *pc = new complex（0，1）

###例子2：

string s1("hello ");

string s2("World ");

string *ps = new string;

###C++程序代码的基本形式

* 头文件（声明）（防卫式）
* 主程序
* 标准库

##大方向：
* 把构造函数放在 private区，是存在的
* 参数传递最好传引用（to const）
* 返回值传递最好传引用（to const）
* 相同class的各个object互为friend友元
* 什么时候不可以return by reference？
	* 返回的是新创建的东西，返回的是local的东西。
* 传递者需要知道是以reference形式接收
* 全局函数没有this指针
* temp object 临时对象 typename()
* 创建新的local对象，直接返回类的名称+括号来new一个对象。
* 在设计类的时候，要考虑一下方法要放在成员function还是local Function
* 
	
	
##C++三大函数（three Big）：

* 拷贝构造函数
* 拷贝复制
* 析构函数



如果一个类有指针成员，就必须有拷贝构造和拷贝复制函数

##栈，堆与内存管理：
scope:作用域
{}

Stack：是存在于某个作用域（scope）的一块内存空间（memory space）。例如当你调用函数，函数本身即会形成一个satck，用来放置它接收的参数，以及返回地址。在函数本身内声明的任何变量，起所使用的内存块都取自与stack。
stack object只要离开作用域，它的生命周期就终止了


Heap：或者说是system Heap，是由操作系统提供的一块全局（global）内存空间，程序可动态分配（dynamic allocated，就是用new），从中取得若干块（block）

##生命周期：
* local object 又叫做auto object ，因为它会被自动清理，它的析构函数会被自动调用。
* static local object 的生命周期。static object，其生命在作用域（scope）结束后仍然存在。知道整个程序结束。
* glabal object 的生命周期任何{}之外。其生命周期在整个程序结束后才结束。
* heap object的生命周期

## 内存泄露，内存溢出
* 内存泄露：拥有者本来有一块内存，经过某些事件或者某些作用域之后，拥有者对这块内存失去了控制，以至于拥有者没有办法还给操作系统。（内存是一个很重要的资源）
* new：先分配一块memory，再调用构造函数ctor，new被分解为三个动作(Complex * pc = new Complex(1,2))：
	* 分配内存memory （ void* mem = operator new（sizeof（object））），内部调用malloc。
	* 转型（pc = static_cast<Complex*>(men)）
	* 构造函数(pc->Complex:complex(1,2)),注意，构造函数的全名是 Complex::Complex(pc,1,2),其中pc也就是this指针
* array new 一定要搭配 array delete

* delete：先调用析构函数dtor，再释放内存。
	* 析构函数
	* 释放内存
* 例如：delete ps;
	* String::~String(ps);//析构函数
	* operator delete(ps);//释放内存（调用free（ps））
* 内存溢出：


##动态分配所得的内存块（memory block），in VC
* 调试模式（debug）下和发布模式（release）下的动态分配内存是不一样的

## 动态分配所得的array
Complex* p = new Complex[3]
String* s = new String[3]

##!!注意一种情况，连串赋值的时候，返回类型不能为void！要返回对象（或者的引用）
return &this;//传出去的人，不必知道接受端用什么形式来接受。this所指的是一个东西，不管是东西还是引用，反正都传东西出去，具体传出去是什么，主要看返回类型。


##namespace 经验谈
namespace起着包装作用

	namespace std
	{
	...
	}
使用namespace方法：

* using directive(指令)，例如，using namespace std;这种最方便。
* using declaration(声明)，例如，using std::cout;

##进一步了解static:

	complex c1,c2,c3;
	cout << c1.real();
	cout << c2.real();
	  
原来的形式为 
	
	complex c1,c2,c3;
	cout << complex::real(&c1);
	cout << complex::real(&c2);
	
此时，c1的地址成为指针。

* 一份函数，要处理很多个对象。成员函数有一个隐藏的this pointer指针，这个编译器会自动帮我们表现出来。
* 加了static之后，不属于任何一个对象。
* 静态函数没有this pointer
* 静态数据一定要在class外面定义该数据。（定义difination：变量获得内存）
* 调用static函数的方法有二：
	* 通过object来调用
	* 通过class name来调用

###类模板，模板函数
* 类模板：template <typename T>
* 模板函数：template <class T>


###OOP(Object Oriented Programming),OOD(Object Oriented Design)，类与类之间的关系。

* Inheritance(继承)
	* 表示is-a,表示“是一种！”
	* 构造是由内而外
	* 析构由外而内
	* 父类的析构dtor函数必须是virtual，否则会出现 undefined behavior，也就是说，如果一个类有可能成为父类，那么，它的析构函数一定要是virtual函数。
	* 函数继承的是调用权
	* 
* Composition（复合）
	* 表示 has-a，类里面含有类
	* 构造是由内而外
	* 析构由外而内
* Delegation（委托）：Composition by reference
	* pimpl（Handle / Body）
	* reference counting

Adapter（变压器，改造，适配）


##关于virtual函数
* non-virtual 函数：你不希望派生类derived class 重新定义（override，覆盖）它
* virtual函数：你希望derived class 重新定义（override，覆盖）它，且你对他已有默认定义
* pure virtual函数：你希望derived class一定要重新定义（override 覆盖）它，你对它没有默认定义。

例如：

	virtual void draw() const = 0; //pure virtual,子类一定要定义
	virtual void error(const std::string& msg);//impure virtual
	int objectID const; //non-virtual，不需要子类重新定义它




 


	




