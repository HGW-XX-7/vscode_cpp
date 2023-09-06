#include <iostream>
using namespace std;

int fenTang(int *stu,int len)//糖果分糖问题
{
    int sugar[len];
    for (auto &&i:sugar) i = 1;
    for (int i = 1; i < len; i++)//正序遍历
        if (stu[i]>stu[i-1]&&sugar[i] <= sugar[i-1])//如果后面的学生比前面的学生分数高 且后面的学生的糖果数小于等于前面的学生的糖果数
            sugar[i] = sugar[i-1] + 1;
        
    for (int i = len-2; i >= 0; i--)//逆序遍历
        if (stu[i]>stu[i+1]&&sugar[i] <= sugar[i+1])//如果前面的学生比后面的学生分数高 且前面的学生的糖果数小于等于后面的学生的糖果数
            sugar[i] = sugar[i+1] + 1;
    int sum = 0;
    for (auto &&i : sugar) sum += i;
    return sum;
}

int main()
{
    int stu[] = {1,2,3,3};
    int len = sizeof(stu)/sizeof(*stu);
    cout<<fenTang(stu,len);
    return 0;
}