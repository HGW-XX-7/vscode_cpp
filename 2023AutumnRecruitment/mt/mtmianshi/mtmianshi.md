#### 题1：

用cpp回答这个问题：给定一个由‘[’、‘]’、‘(’、‘)’组成的字符申，请问最少插入多少个括号就能使这个字符串的所有括号左有配对。例如当前串是“([[])”，那么插入一个‘]’即可满足，然后程序输出1。

两个cpp文件是对不同方法的尝试

正确思路：
用栈 左括号 不管小还是中 都进stack
遇到右小括号，就把栈顶所有的右中括号都弹出来(并补全)
比如说([[[[)，从左到右依次把字符弹进栈，遇到)的时候，我们的目标是弹出一个(，但是这时候栈顶只有[，就先把[都弹出来，弹多少个就在答案里加多少个
如果是三种括号 左括号进栈 if右小括号 先弹中大括号补全 if右中括号 先弹大括号小括号 if右大括号 巴拉巴拉
