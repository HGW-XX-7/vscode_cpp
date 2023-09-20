#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

map<string, int> variables; // 用于存储变量和值的映射

int calculate(string expression);

bool isValidVariableName(const string &name)
{
    // 变量命名规范检查
    if (name.empty() || !isalpha(name[0]) && name[0] != '_')
    {
        return false;
    }
    for (char c : name)
    {
        if (!isalnum(c) && c != '_')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        if (line.empty())
        {
            continue;
        }
        size_t letPos = line.find("let ");
        if (letPos != string::npos)
        {
            size_t equalsPos = line.find('=');
            if (equalsPos != string::npos)
            {
                string assignment = line.substr(letPos + 4, equalsPos - letPos - 4);
                stringstream ss(assignment);
                string varName, expr;
                ss >> varName >> expr;
                if (isValidVariableName(varName))
                {
                    variables[varName] = calculate(expr);
                }
                else
                {
                    cout << "Invalid variable name." << endl;
                }
            }
            else
            {
                cout << "Invalid assignment format." << endl;
            }
        }
        else if (line.find("out(") != string::npos)
        {
            size_t startPos = line.find("out(");
            size_t endPos = line.find(")");
            if (startPos != string::npos && endPos != string::npos)
            {
                string varName = line.substr(startPos + 4, endPos - startPos - 4);
                if (variables.find(varName) != variables.end())
                {
                    cout << variables[varName] << endl;
                }
                else
                {
                    cout << "Variable is undefined." << endl;
                }
            }
            else
            {
                cout << "Invalid out function format." << endl;
            }
        }
        else
        {
            cout << "Invalid input." << endl;
        }
    }

    return 0;
}

int calculate(string expression)
{
    // 简单的四则运算表达式求值
    int result = 0;
    int num = 0;
    char op = '+';

    for (char c : expression)
    {
        if (isdigit(c))
        {
            num = num * 10 + (c - '0');
        }
        else
        {
            if (op == '+')
            {
                result += num;
            }
            else if (op == '-')
            {
                result -= num;
            }
            else if (op == '*')
            {
                result *= num;
            }
            else if (op == '/')
            {
                if (num != 0)
                {
                    result /= num;
                }
                else
                {
                    cout << "Division by zero." << endl;
                    return 0;
                }
            }

            num = 0;
            op = c;
        }
    }

    if (op == '+')
    {
        result += num;
    }
    else if (op == '-')
    {
        result -= num;
    }
    else if (op == '*')
    {
        result *= num;
    }
    else if (op == '/')
    {
        if (num != 0)
        {
            result /= num;
        }
        else
        {
            cout << "Division by zero." << endl;
            return 0;
        }
    }

    return result;
}
