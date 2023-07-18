#include<bits/stdc++.h>
using namespace std;

const int MAXN = 400;
int n, m;
char a[MAXN][MAXN];
int vis[MAXN][MAXN]; // 记录该位置是否被访问过
int ans; // 细胞个数

int dx[4] = {1, -1, 0, 0}; // 上下左右四个方向
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y) // 搜索函数
{
    vis[x][y] = 1; // 标记该位置已经被访问过
    for (int i = 0; i < 4; i++) // 枚举四个方向
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] != '0' && !vis[nx][ny]) // 判断是否可以往该位置走
            dfs(nx, ny);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] != '0' && !vis[i][j]) // 如果该位置有细胞且还没被访问过
            {
                ans++;
                dfs(i, j); // 搜索该位置的连通块
            }
    cout << ans << endl; // 输出答案
    return 0;
}
