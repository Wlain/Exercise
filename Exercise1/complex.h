//
// Created by william on 2018/11/11.
//

#ifndef EXERCISE1_COMPLEX2_H
#define EXERCISE1_COMPLEX2_H

//前置声明
class complex;
complex&
    __doapl (complex* ths, const complex& r);
complex&
    __doami (complex* ths, const complex& r);
complex&
    __doaml (complex* ths, const complex& r);
complex&
    __doamd (complex* ths, const complex& r);


class complex
{
public:
    complex(double r = 0,double i = 0): re(r),im(i){}
    complex& operator += (const complex&);
    complex& operator -= (const complex&);
    complex& operator *= (const complex&);
    complex& operator /= (const complex&);
    double real() const { return re; }
    double imag() const { return im; }
private:
    double re,im;

    friend complex& __doapl (complex *, const complex&);
    friend complex& __doami (complex *, const complex&);
    friend complex& __doaml (complex *, const complex&);
    friend complex& __doamd (complex *, const complex&);
};
//友元函数
inline complex&
__doapl (complex* ths, const complex & r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex&
complex::operator += (const complex& r)
{
    return __doapl (this,r);
}

inline complex&
__doami (complex* ths, const complex& r)
{
    ths->re -= r.re;
    ths->im -= r.im;
    return *ths;
}

inline complex&
complex::operator -= (const complex& r)
{
    return __doami(this,r);
}

inline complex&
__doaml (complex* ths, const complex& r)
{
    double f = ths->re * r.re - ths->im * r.im;
    ths->im = ths->re * r.im + ths->im * r.re;
    ths->re = f;
    return *ths;
}

inline complex&
complex::operator *= (const complex& r)
{
    return __doaml(this,r);
}

inline complex&
__doamd (complex* ths, const complex& r)
{
    double f = r.re * r.re + r.im * r.im;
    ths->re = ( ths->re * r.re + ths->im * r.im ) / f;
    ths->im = ( ths->im * r.re - ths->re * r.im ) / f;
    return *ths;
}

inline complex&
complex::operator /= (const complex& r)
{
    return __doamd(this,r);
}

inline double
imag (const complex& r)
{
    return r.imag();
}

inline double
real (const complex& r)
{
    return r.real();
}
//加减乘数，需要考虑三种情况
inline complex
operator + (const complex& x, const complex& y)
{
    return complex(real(x) + real(y), imag(x) + imag(y));
}

inline complex
operator + (const complex& x, double y)
{
    return complex(real(x) + y, imag(x));
}

inline complex
operator + (double x, const complex& y)
{
    return complex(x + real(y), imag(y));
}

inline complex
operator - (const complex& x, const complex& y)
{
    return complex(real(x) + real(y), imag(x) + imag(y));
}

inline complex
operator - (const complex& x, double y)
{
    return complex(real(x) + y, imag(x));
}

inline complex
operator - (double x, const complex& y)
{
    return complex(x + real(y), imag(y));
}

inline complex
operator * (const complex& x, const complex& y)
{
    return complex(real(x) * real(y), imag(x) * imag(y));
}

inline complex
operator * (const complex& x, double y)
{
    return complex(real(x) * y, imag(x));
}

inline complex
operator * (double x, const complex& y)
{
    return complex(x * real(y), imag(y));
}

inline complex
operator / (const complex& x, const complex& y)
{
    return complex(real(x) / real(y), imag(x) / imag(y));
}

inline complex
operator / (const complex& x, double y)
{
    return complex(real(x) / y, imag(x) / y);
}

inline complex
operator / (double x, const complex& y)
{
    return complex(x / real(y),0);
}

//正负
inline complex
operator + (const complex& x){
    return x;
}

inline complex
operator - (const complex& x)
{
    return complex(-real(x), -imag(x));
}

//判断是否相等
inline bool
operator == (const complex& x, const complex& y)
{
    return real(x) == real(y) && imag(x) == imag(y);
}

inline bool
operator == (const complex& x, double y)
{
    return real(x) == y && imag(y) == 0;
}

inline bool
operator == (double x, const complex& y)
{
    return x == real(y) && imag(y) == 0;
}

inline bool
operator != (const complex& x, const complex& y)
{
    return real(x) != real(y) || imag(x) != imag(y);
}

inline bool
operator != (const complex& x, double y)
{
    return real(x) != y || real(x) != 0;
}

inline bool
operator != (double x, const complex& y)
{
    return x != real(y) || imag(y) != 0;
}

#include <cmath>

inline complex
polar (double r, double t)
{
    return complex(r * cos(t), r * sin(t));
}

//共轭复数
inline complex
conj(const complex& x)
{
    return complex(real(x), -imag(x));
}

inline complex
norm(const complex& x)
{
    return real(x) * real(x) + imag(x) * imag(x);
}



#endif //EXERCISE1_COMPLEX2_H
