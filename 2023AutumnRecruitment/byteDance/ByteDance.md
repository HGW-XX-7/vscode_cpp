#### 题1：
小红拿到了一个数组，她准备进行最多一次以下操作：选挥两个相等的元素，将这两个元素之间的所有元素删除。小红想知道，她最多可以删除多少个元素?


#### 题2：
我拿到了许多牌，准备玩以下游戏:
每次操作在这堆牌中任取5张牌，计算这5张牌的分数，然后将其丢弃(丢弃的牌不可再次选取)
为了筒化，本题仅计算同花顺这一牌型:即取出的5张牌构成同花顺，则可以获得1分。其他牌型均不得分。所谓同花顺，即五张牌花色相同，且排序后满足$a_i+1=a_{i+1}$。
我想知道，经过若干次操作后，自己最多可以得到多少分?
请注意，同一个牌型可能出现多次!
	 
输入描述：第一行输入一个正整数n，代表牌堆中牌的种类(如果两张牌的花色或数值不同，则认为种类不同)。
接下来的n行，每行输入两个正整数: $a_i$和$cnt_i$和一个字符$c_i$，分别代表每种牌的大小、数量以及花色。
$c_i$只有’S’、’H’、’D’、’C’四种取值，代表扑克牌的四种花色: 黑(Spade) 、红桃(Heart)、方块 (Diamond) 、梅花(Club)保证每个种类的牌在输入中只出现了一次。
输出描述：一个整数，代表可以最多获得的分数
 
实例1：
输入：
```cpp
6
1 1 S
2 2 S
3 2 S
4 2 S
5 2 S
1 10 H
```

输出：
```
1
```
说明：可以取到一个同花顺: [1S,2S,3S,4S5S]。虽然有10个红桃1，但无法和其他牌凑成同花顺

实例2：
输入：
```
6
1 1 H
2 2 H
3 2 H
4 2 H
5 2 H
6 10 H
```
输出：
```
2
```
说明：可以取两次:[1H,2H,3H,4H,5H]和[2H,3H,4H,5H,6H]