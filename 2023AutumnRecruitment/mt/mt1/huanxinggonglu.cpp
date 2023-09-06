#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    int N;
    cin>>N;
    long D[N];
    for (int i = 1; i < N; i++)
        cin >> D[i];
    cin >> D[0];
    long x,y;
    cin>>x>>y;
    long A1ToX[N];
	A1ToX[1] = D[1];
	for (int i = 2; i < N; ++i) {
		A1ToX[i] = A1ToX[i - 1] + D[i];
	}
	A1ToX[0] = A1ToX[N - 1] + D[0];
	long disI = x == 0 ? 0 : A1ToX[x - 1];
	long disJ = y == 0 ? 0 : A1ToX[y - 1];
	long dis = abs(disI - disJ);
	cout << ((dis > A1ToX[0] / 2) ? A1ToX[0] - dis : dis);
    return 0;
}