#include <iostream>
#include <cmath>
#include <vector>

const double pi = 3.14159265358979323846;

// 车辆信息
struct Vehicle {
    double v0;      // 速度 (m/s)
    double delta0;  // 方向盘角度 (弧度)
    double L;       // 轴距 (m)
};

// 计算车辆轨迹
std::vector<std::vector<double>> calculateTrajectory(const Vehicle& vehicle, double duration, double interval) {
    double t = 0.0;
    double x = 0.0;
    double y = 0.0;
    double yaw = 0.0;

    std::vector<std::vector<double>> trajectory;

    while (t <= duration) {
        x = vehicle.v0 * cos(yaw) * t;
        y = vehicle.v0 * sin(yaw) * t;
        yaw = vehicle.v0 * tan(vehicle.delta0) / vehicle.L * t;

        std::vector<double> point = { x, y, yaw };
        trajectory.push_back(point);

        t += interval;
    }

    return trajectory;
}

int main() {
    Vehicle vehicle;
    vehicle.v0 = 10.0;          // 速度设为10 m/s
    vehicle.delta0 = pi / 6.0;  // 方向盘角度设为30度（弧度）
    vehicle.L = 2.0;            // 轴距设为2m

    double duration = 5.0;      // 持续时间为5秒
    double interval = 0.02;     // 时间间隔为0.02秒

    std::vector<std::vector<double>> trajectory = calculateTrajectory(vehicle, duration, interval);

    // 打印轨迹上的点
    std::cout << "轨迹点坐标和航向角：" << std::endl;
    for (const auto& point : trajectory) {
        std::cout << "x = " << point[0] << ", y = " << point[1] << ", yaw = " << point[2] << std::endl;
    }

    return 0;
}
