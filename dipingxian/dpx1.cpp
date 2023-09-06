#include <iostream>
#include <cmath>

using namespace std;

double func(double x) {
    return log(x) + pow(x, 3);
}

double derivative(double x) {
    return 1.0 / x + 3 * pow(x, 2);
}

double newtonRaphson(double x0, double precision, int maxIterations) {
    double x = x0;
    int iterations = 0;

    while (fabs(func(x)) > precision && iterations < maxIterations) {
        x = x - func(x) / derivative(x);
        iterations++;
    }

    return x;
}

int main() {
    double x0 = 0.5; // 初始猜测值
    double precision = 0.0001; // 精度要求
    int maxIterations = 1000; // 最大迭代次数

    double root = newtonRaphson(x0, precision, maxIterations);

    cout << root << endl;

    return 0;
}
