#include <iostream>
#include <cmath>

class PIDController {
public:
    PIDController(double kp, double ki, double kd)
        : kp_(kp), ki_(ki), kd_(kd), integral_(0), previousError_(0) {}

    double calculateControl(double setpoint, double processVariable) {
        double error = setpoint - processVariable;
        integral_ += error;
        double derivative = error - previousError_;

        double controlOutput = kp_ * error + ki_ * integral_ + kd_ * derivative;

        previousError_ = error;

        return controlOutput;
    }

private:
    double kp_; // 比例系数
    double ki_; // 积分系数
    double kd_; // 微分系数

    double integral_; // 积分项
    double previousError_; // 上一次的误差
};

int main() {
    double kp = 1.0; // 设置比例系数
    double ki = 0.1; // 设置积分系数
    double kd = 0.01; // 设置微分系数

    PIDController pidController(kp, ki, kd);

    double setpoint = 50.0; // 设置目标值
    double processVariable = 0.0; // 初始过程变量值

    for (int i = 0; i < 100; ++i) {
        double controlOutput = pidController.calculateControl(setpoint, cos(processVariable));

            // 模拟过程变量的变化
        processVariable += 0.1;

        std::cout << "Iteration " << i << ": Process Variable (cos(x)) = " << cos(processVariable) << ", Control Output = " << controlOutput << std::endl;
    }

    return 0;
}
