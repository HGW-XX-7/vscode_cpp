#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

vector<string> GenerateContracts(int m, int n, string currentMonth, int futureMonths) {
    vector<string> contracts;
    int currentYear = stoi(currentMonth.substr(0, 2));
    int currentMonthNum = stoi(currentMonth.substr(2, 2));

    while (futureMonths > 0) {
        stringstream contract;
        contract << "IZ" << currentYear % 100 << setw(2) << setfill('0') << currentMonthNum;
        contracts.push_back(contract.str());

        // 计算下一个月
        if (currentMonthNum == 12) {
            currentYear++;
            currentMonthNum = 1;
        } else {
            currentMonthNum++;
        }

        // 判断是否是近月或季月
        if (currentMonthNum == 3 || currentMonthNum == 6 || currentMonthNum == 9 || currentMonthNum == 12) {
            n--;
            if (n == 0) {
                currentMonthNum = (currentMonthNum == 12) ? 3 : (currentMonthNum + 3);
                n = 3;
            }
        } else {
            m--;
        }

        futureMonths--;
    }

    return contracts;
}

// 辅助函数：将字符串转换为整数
int strToInt(const string& str) {
    stringstream ss(str);
    int num;
    ss >> num;
    return num;
}

// 辅助函数：将整数转换为字符串
string intToStr(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

int main() {
    string input;
    getline(cin, input);

    stringstream ss(input);
    string mStr, nStr, currentMonth, xStr;
    getline(ss, mStr, ',');
    getline(ss, nStr, ',');
    getline(ss, currentMonth, ',');
    getline(ss, xStr, ',');

    int m = strToInt(mStr);
    int n = strToInt(nStr);
    int x = strToInt(xStr);

    vector<string> contracts = GenerateContracts(m, n, currentMonth, x);

    for (const string& contract : contracts) {
        cout << contract;
        if (&contract != &contracts.back()) {
            cout << ",";
        }
        cout << endl;
    }

    return 0;
}
