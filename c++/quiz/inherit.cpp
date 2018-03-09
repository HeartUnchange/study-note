#include <iostream>
using namespace std;

class A
{
  public:
    A() { cout << "A"; }
    A(const A &) { cout << "a"; }
};

class B : virtual A
{
  public:
    B() { cout << "B"; }
    B(const B &) { cout << "b"; }
};

class C : virtual A
{
  public:
    C() { cout << "C"; }
    C(const C &) { cout << "c"; }
};

class D : B, C
{
  public:
    D() { cout << "D"; }
    D(const D &) { cout << "d"; }
};

int main()
{
    D d1;
    D d2(d1);
}
/*
 * 运行结果
 */

// result
// ABCDABCd