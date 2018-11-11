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

* 头文件（声明）
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
* 
	








