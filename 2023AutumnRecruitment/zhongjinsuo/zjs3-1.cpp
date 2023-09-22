#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 函数用于生成指定个数的股指期货合约代号
vector<string> GenerateContracts(int m, int n, string current, int x) {
    vector<string> contracts;
    int currentYear = stoi(current.substr(0, 2)); // 获取当前年份的后两位并转换为整数
    int currentMonth = stoi(current.substr(2, 2)); // 获取当前月份的后两位并转换为整数

    for (int i = 0; i < x; i++) {
        // 生成近月和季月的合约代号
        vector<string> nearMonthContracts;
        vector<string> quarterMonthContracts;

        for (int j = 0; j < m; j++) {
            nearMonthContracts.push_back("IZ" + to_string(currentYear) + to_string(currentMonth));
            currentMonth++;
            if (currentMonth > 12) {
                currentMonth = 1;
                currentYear++;
            }
        }

        for (int j = 0; j < n; j++) {
            int quarterMonth = currentMonth + (j * 3);
            if (quarterMonth > 12) {
                quarterMonth -= 12;
                currentYear++;
            }
            quarterMonthContracts.push_back("IZ" + to_string(currentYear) + to_string(quarterMonth));
        }

        // 合并近月和季月的合约代号
        vector<string> allContracts;
        int nearMonthIndex = 0;
        int quarterMonthIndex = 0;
        while (nearMonthIndex < nearMonthContracts.size() && quarterMonthIndex < quarterMonthContracts.size()) {
            int nearMonth = stoi(nearMonthContracts[nearMonthIndex].substr(4, 2));
            int quarterMonth = stoi(quarterMonthContracts[quarterMonthIndex].substr(4, 2));
            if (nearMonth == quarterMonth) {
                allContracts.push_back(nearMonthContracts[nearMonthIndex]);
                nearMonthIndex++;
                quarterMonthIndex++;
            } else if (nearMonth < quarterMonth) {
                allContracts.push_back(nearMonthContracts[nearMonthIndex]);
                nearMonthIndex++;
            } else {
                allContracts.push_back(quarterMonthContracts[quarterMonthIndex]);
                quarterMonthIndex++;
            }
        }
        while (nearMonthIndex < nearMonthContracts.size()) {
            allContracts.push_back(nearMonthContracts[nearMonthIndex]);
            nearMonthIndex++;
        }
        while (quarterMonthIndex < quarterMonthContracts.size()) {
            allContracts.push_back(quarterMonthContracts[quarterMonthIndex]);
            quarterMonthIndex++;
        }

        // 输出当前月份的合约代号
        string currentContract = "IZ" + to_string(currentYear) + to_string(currentMonth);
        int currentContractIndex = -1;
        for (int j = 0; j < allContracts.size(); j++) {
            if (allContracts[j] == currentContract) {
                currentContractIndex = j;
                break;
            }
        }
        if (currentContractIndex == -1) {
            contracts.push_back("-");
        } else {
            string newContracts = "";
            for (int j = currentContractIndex + 1; j <= currentContractIndex + m + n; j++) {
                if (j < allContracts.size()) {
                    newContracts += allContracts[j];
                    if (j < currentContractIndex + m + n) {
                        newContracts += ",";
                    }
                }
            }
            contracts.push_back(newContracts);
        }

        // 更新当前年月
        currentMonth++;
        if (currentMonth > 12) {
            currentMonth = 1;
            currentYear++;
        }
    }

    return contracts;
}

int main() {
    string input;
    getline(cin, input);
    int m = stoi(input.substr(0, input.find(",")));
    input = input.substr(input.find(",") + 1);
    int n = stoi(input.substr(0, input.find(",")));
    input = input.substr(input.find(",") + 1);
    string current = input.substr(0, 4);
    input = input.substr(5);
    int x = stoi(input);

    vector<string> contracts = GenerateContracts(m, n, current, x);
    for (int i = 0; i < contracts.size(); i++) {
        cout << contracts[i] << endl;
    }

    return 0;
}