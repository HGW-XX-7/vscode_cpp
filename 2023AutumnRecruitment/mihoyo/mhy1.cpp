#include <iostream>
using std::cout;
using std::endl;
using std::move;

struct Test {
    Test() = default;
    Test(const Test& that) {
        cout <<"copy constructor,";
        }
    Test(Test&& that) {
        cout <<"rlvaue copy constructor,";
        }
};

Test func1(){
    Test t;
    return t;
}

Test func2(){
    Test t;
    return move(t);
}

int main() {
    Test t1 = func1();
    Test t2 = func2();
    return 0;
}
