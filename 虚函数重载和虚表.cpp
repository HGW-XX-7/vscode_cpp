#include <iostream>

using namespace std;

struct A
{
    virtual void f() { cout << "A::f" << endl; }
};

struct B
{
    virtual void f() { cout << "B::f" << endl; }
};

struct C : public A, public B
{
    virtual void f() override { cout << "C::f" << endl; }
};

int main()
{
    C c;
    A *pa = &c;
    B *pb = &c;
    C *pc = &c;

    pa->f();
    pb->f();
    pc->f();
    c.f();
    c.A::f();

    return 0;
}
