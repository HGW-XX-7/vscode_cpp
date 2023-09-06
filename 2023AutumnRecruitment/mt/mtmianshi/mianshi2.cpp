#include <iostream>
#include <stack>

int minInsertionsToMatchParentheses(const std::string &s)
{
    int insertions, flag = 0; // 记录需要插入的括号数

    for (char c : s)
    {
        if (c == '(' || c == '['){
            flag++;
        }
        else if (c == ')' || c == ']'){
            if (flag == 0){
                insertions++;
            }
            else{
                flag--;
            }
        }
    }
    insertions += flag;
    return insertions;
}

int main()
{
    std::string input = "((]";

    int result = abs(minInsertionsToMatchParentheses(input));
    std::cout << result << std::endl;

    return 0;
}
