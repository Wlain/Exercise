//
// Created by william on 2018/11/10.
//

#ifndef EXERCISE1_COMPLEX_H
#define EXERCISE1_COMPLEX_H
//防卫式声明
#include <cmath>
#include <complex>
#include <iostream>

//前置声明
class ostream;
class complex;
complex & __doapl(complex *ths,const complex& r);


//类-声明,类要有这几个部分,使用到了模板
//利用C++ 重载

class complex
{
public:
    //默认实参，以后要这样写，这样效率上比较高
    //初值列，初始列
    complex(double r = 0,double i = 0):re(r),im(i) {}
    complex &operator +=(const complex&);
    //加const 只读，千万别忽略，这边要正归写
    double real() const { return re;}//可以换成inline类型
    double imag() const { return im;}

    //这样写是对的
    //相同class的各个object互为friend友元
    int func(const complex& param)
    {
        return param.re+ param.im;
    }

private:
    //数据部分，要封装起来
    double re,im;
    //友元
    friend complex& __doapl (complex* ths, const complex & r);
};

//global function
inline double real(const complex& x)
{
    return x.real();
}

inline double imag(const complex& x)
{
    return x.imag();
}

inline complex& __doapl (complex* ths, const complex & r)
{
    ths ->re += r.re;
    ths ->im += r.im;
    return *ths;//指针所指的东西，是一个object；
}

inline complex& complex::operator += (const complex& r)
{
    return __doapl(this,r);
}

//加法重载可能有三种情况，这三种情况不可以返回reference，因为他们返回的必定是local object
inline complex operator + (const complex& x,const complex& y)
{
    return complex(real(x) + real(y),imag(x) + imag(y));
}

inline complex operator + (const complex& x,double y)
{
    return complex(real(x) + y,imag(x));
}

inline complex operator + (double x,const complex& y)
{
    return complex(x + real(y),imag(y));
}

//正负复数
inline complex operator + (const complex& x)
{
    return x;
}

inline complex operator - (const complex& x)
{
    return complex(-real(x),-imag(x));
}

//判断两个复数是否相等,考虑三种情况
inline bool operator == (const complex& x, const complex& y)
{
    return real(x) == real(y) && imag(x) == imag(y);
}

inline bool operator == (const complex& x,double y )
{
    return real(x) == y && real(x) == 0;
}

inline bool operator == (double x, const complex& y)
{
    return x == real(y) && imag(y) == 0;
}

//判断两个复数是否不相等,考虑三种情况
inline bool operator != (const complex& x, const complex& y)
{
    return real(x) != real(y) || imag(x) != imag(y);
}

inline bool operator != (const complex& x, double y)
{
    return real(x) != y || real(x) != 0;
}

inline bool operator != (double x,const complex& y)
{
    return x != real(y) || real(y) != 0;
}

//求共轭复数

inline complex conj(const complex& x)
{
    return complex(real(x),-imag(x));
}

inline ostream& operator <<(ostream& os, const complex& x)
{
    return os << '('<< real(x) <<',' << imag(x) <<')';
}

//类定义

#endif //EXERCISE1_COMPLEX_H
