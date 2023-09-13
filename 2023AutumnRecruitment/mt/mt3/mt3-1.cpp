#include <iostream>
#include <vector>

class BoolSequenceAnalyzer {
public:
    BoolSequenceAnalyzer(const std::vector<int>& sequence) : sequence_(sequence) {}

    bool isTrueValue() {
        int disturbanceCount = 0;
        int consecutiveZeros = 0;
        int consecutiveOnes = 0;
        int localPeriod = 0;

        for (int value : sequence_) {
            if (value == 0) {
                consecutiveZeros++;
                consecutiveOnes = 0;
            } else if (value == 1) {
                consecutiveOnes++;
                consecutiveZeros = 0;
            } else {
                // Invalid value, reset counters
                consecutiveZeros = 0;
                consecutiveOnes = 0;
                disturbanceCount++;
            }

            if (consecutiveZeros >= 6 || consecutiveOnes >= 6) {
                localPeriod++;
            } else {
                localPeriod = 0;
            }

            if (localPeriod >= 3) {
                return true;
            }

            // If there are more than 2 disturbances, it's not considered a true value
            if (disturbanceCount > 2) {
                return false;
            }
        }

        return false; // If we reach this point, there are not enough consecutive true values
    }

private:
    std::vector<int> sequence_;
};

int main() {
    std::vector<int> inputSequence = {0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1};
    BoolSequenceAnalyzer analyzer(inputSequence);

    if (analyzer.isTrueValue()) {
        std::cout << "The sequence is considered a true value." << std::endl;
    } else {
        std::cout << "The sequence is not a true value." << std::endl;
    }

    return 0;
}
