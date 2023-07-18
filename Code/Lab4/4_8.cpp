#include<bits/stdc++.h>
using namespace std;

const int N = 410;

int n, m;
char g[N][N];
bool vis[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

// 深度优先搜索，求解连通块大小
int dfs(int x, int y)
{
    // 标记当前位置已经遍历过
    vis[x][y] = true;
    // 连通块大小初始化为1（包括自身）
    int size = 1;
    // 枚举相邻四个位置
    for (int i = 0; i < 4; i ++)
    {
        int a = x + dx[i], b = y + dy[i];
        // 判断相邻位置是否越界，是否为连通块的一部分，是否已经遍历过
        if (a < 0 || a >= n || b < 0 || b >= n || g[x][y] == g[a][b] || vis[a][b])
            continue;
        // 如果符合条件，则以相邻位置为起点继续遍历
        size += dfs(a, b);
    }
    // 返回连通块大小
    return size;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
        cin >> g[i];

    while (m -- )
    {
        int x, y;
        cin >> x >> y;
        x --, y --;
        // 搜索从当前位置开始的连通块大小
        int size = dfs(x, y);
        // 输出连通块大小
        cout << size << endl;
        // 将已经遍历过的位置重新标记为未遍历过
        memset(vis, false, sizeof vis);
    }

    return 0;
}
