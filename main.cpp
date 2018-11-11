#include <iostream>
#include "complex.h"
//#include "complex1.h"
//侯捷笔记
//大部分我们用的C++都是C++98（1.0）的
using namespace std;

ostream&
operator << (ostream& os, const complex& x)
{
    return os << '(' << real(x) << ',' << imag(x) <<')';
}

int main() {
    complex c1(2,1);
    complex c2(4,2);

    cout << c1 << endl;
    cout << c2 << endl;

    cout << c1 + c2 << endl;
    cout << c1 - c2 << endl;
    cout << c1 * c2 << endl;
    cout << c1 / c2 << endl;

    cout << conj(c1) << endl;
    cout << norm(c1) << endl;
    cout << polar(10,4) << endl;

    cout << (c1 += c2) << endl;

    cout << (c1 == c2) << endl;
    cout << (c1 != c2) << endl;
    cout << +c2 << endl;
    cout << -c2 << endl;

    cout << (c2 - 2) << endl;
    cout << (5 + c2) << endl;


    return 0;
}