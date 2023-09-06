#include <iostream>
#include <vector>
using namespace std;

void test1(int a[10])
{
    cout << sizeof(a) << endl;
}

void test2(int a[])
{
    cout << sizeof(a) << endl;
}

void test3(int *a)
{
    cout << sizeof(a) << endl;
}

int main()
{
    int a[10];
    cout << a + 1 << endl;
    cout << a[1] << endl;
    cout << &a[0] << " " << a << " " << &a << endl;
    cout << &a[0] + 1 << endl;
    return 0;
}