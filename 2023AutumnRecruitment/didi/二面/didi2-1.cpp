#include <iostream>
#include <vector>

using namespace std;

class Vehicle {
public:
    Vehicle() {
        sum_speed = 0;
    }

    // This function takes the latest speed and returns the
    // average of the latest 10 speeds.
    // If you only have less than 10 speeds, return the avg of the speeds.
    double GetAverageSpeed(double latest_speed) {
        speeds.push_back(latest_speed);
        sum_speed += latest_speed;
        if (speeds.size() > 10) {
            sum_speed -= speeds.front();
            speeds.erase(speeds.begin());
        }
        return sum_speed / speeds.size();
    }

private:
    vector<double> speeds;
    double sum_speed;
};