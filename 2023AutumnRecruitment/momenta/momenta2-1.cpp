#include <iostream>
#include <vector>

struct Point {
    double x;
    double y;
};

// 计算两个点的叉积
double crossProduct(const Point& A, const Point& B, const Point& C) {
    double x1 = B.x - A.x;
    double y1 = B.y - A.y;
    double x2 = C.x - B.x;
    double y2 = C.y - B.y;
    return (x1 * y2 - x2 * y1);
}

// 检查点集是否形成凸多边形
bool isConvexPolygon(const std::vector<Point>& points) {
    int n = points.size();
    if (n < 3) {
        // 至少需要3个点才能构成多边形
        return false;
    }

    bool isClockwise = false;
    bool isCounterClockwise = false;

    for (int i = 0; i < n; i++) {
        double cp = crossProduct(points[i], points[(i + 1) % n], points[(i + 2) % n]);
        if (cp < 0) {
            isCounterClockwise = true;
        } else if (cp > 0) {
            isClockwise = true;
        }

        if (isClockwise && isCounterClockwise) {
            return false; // 既有顺时针又有逆时针，不是凸多边形
        }
    }

    return true;
}

int main() {
    std::vector<Point> points = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
    
    bool isConvex = isConvexPolygon(points);
    
    if (isConvex) {
        std::cout << "y" << std::endl;
    } else {
        std::cout << "n" << std::endl;
    }
    
    return 0;
}
