#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 5005;

int parent[MAXN];

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
        parent[x] = y;
}

int main()
{
    int n, m, p;
    cin >> n >> m >> p;

    for (int i = 1; i <= n; ++i)
        parent[i] = i;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        unite(x, y);
    }

    for (int i = 0; i < p; ++i) {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b))
            cout << "Consanguine" << endl;
        else
            cout << "Unrelated" << endl;
    }

    return 0;
}
