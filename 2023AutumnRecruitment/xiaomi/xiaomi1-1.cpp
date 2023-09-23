#include <iostream>
#include <vector>
#include <sstream>
//输入模块见.\readArr.cpp
int main() {
    std::vector<std::vector<int>> twoDArray;

    std::string input;
    std::cout << "请输入二维数组，每行以逗号分隔，每个元素之间以空格分隔：" << std::endl;

    // 逐行读取输入
    while (std::getline(std::cin, input)) {
        std::vector<int> row;
        std::stringstream row_ss(input);

        char ch;
        // 跳过开头的 '['
        row_ss >> ch;

        // 逐列读取数据
        while (row_ss >> ch && ch != ']') {
            int num;
            row_ss >> num;
            row.push_back(num);
        }

        if (!row.empty()) {
            twoDArray.push_back(row);
        }
    }

    // 打印二维数组
    for (const auto& row : twoDArray) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}