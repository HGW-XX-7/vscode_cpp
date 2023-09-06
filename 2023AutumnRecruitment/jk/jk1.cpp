#include <iostream>
#include <vector>
using namespace std;

int f(int x, int n) 
{
    if(x<=1) return x;
    return ((n-3) * f(x-1,n)+(n-2)*f(x - 2,n))%n;
}

int main(){
    cout << f(2021, 1023) << endl;
    cout << f(1334, 2047) << endl;
    cout << f(2019, 511) << endl;
    cout << f(1729, 4995) << endl;

    return 0;
}

class Base {
    char data[3];
public:
virtual void f() {cout <<"Base::f" << endl;
}
virtual void g() {cout <<"Base::g"<< endl;
}
virtual void h() {cout <<"Base::h"<< endl;
}
};
int main(){
cout << sizeof(Base) << endl;
return 0;
}

void function(int *x, int n, int i = 0) {
if(i*2+1<n) function(x,n,i*2 +1);
if(i *2+2 <n) function(x,n,i*2+2);
cout << x[i] << endl;}