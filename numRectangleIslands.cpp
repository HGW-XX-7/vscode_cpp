#include <iostream>
#include <vector>
using namespace std;

class island
{
private:
    int count = 0;                                      // 岛屿数量
    int cnt = 0;                                        // 每个岛屿的面积计数器
    vector<int> book;                                   // 记录每个岛屿的面积
    vector<vector<char>> vis, grid;                     // vis记录访问过的点 grid记录原始数据
    int x[4] = {1, 0, -1, 0}, y[4] = {0, 1, 0, -1};     // 方向数组 下 右 上 左
    int x1[4] = {1, 1, -1, -1}, y1[4] = {1, -1, 1, -1}; // 方向数组 右下 右上 左下 左上
    int row, col;                                       // 行列
    void dfs(vector<vector<char>> &temp_grid, int i, int j, int row, int col)
    {
        if (i < 0 || j < 0 || i >= row || j >= col || temp_grid[i][j] != '1') // 如果越界或者不是陆地
        {
            return;
        }
        cnt++;
        temp_grid[i][j] = '0';       // 标记为已经访问过
        vis[i][j] = '0' + count + 1; // 记录为已经访问过
        for (int k = 0; k < 4; k++)
        {
            dfs(temp_grid, i + x[k], j + y[k], row, col); // 向四个方向搜索
        }
    }

public:
    island(vector<vector<char>> &grid)
    {
        this->grid = grid;
        this->vis = vector<vector<char>>(grid.size(), vector<char>(grid[0].size(), '0'));
        row = grid.size(), col = grid[0].size();//行列
    };
    ~island(){};
    int numRectangleIslands()
    {

        if (grid.empty() || grid[0].empty())
            return 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++) // 遍历每个点
            {
                if (grid[i][j] == '1') // 如果是陆地
                {
                    cnt = 0;
                    dfs(grid, i, j, row, col); // 深度优先搜索
                    book.push_back(cnt);
                    count++;
                }
            }
        }

        for (int i = 0; i < row; i++)//输出vis
        {
            for (int j = 0; j < col; j++)
            {
                cout<<vis[i][j]<<" ";
            }
            cout<<endl;
        }
        
        for (int k = 0; k < book.size(); k++)//判断是否为矩形
        {
            int temp_side = 0;//记录边长

            for (int i = 0; i < row; i++)//遍历vis
            {
                for (int j = 0; j < col; j++)
                {
                    if (vis[i][j] == k + '0' + 1)
                    {
                        temp_side++;
                    }
                }
                if (temp_side != 0)
                    break;
            }
            
            if (book[k] % temp_side != 0)//如果不是矩形
            {
                count--;
            }
        }

        return count;
    }
};

int main()
{

    vector<vector<char>> grid1 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}},
    grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'1', '0', '0', '1', '1'}},
    grid3 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'1','1','1','0','0'},
        {'1','1','0','1','1'}};

    island i(grid1), j(grid2), k(grid3);
    cout << i.numRectangleIslands() << endl;
    cout << j.numRectangleIslands() << endl;
    cout << k.numRectangleIslands() << endl;
    return 0;
}