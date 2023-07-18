#include<bits/stdc++.h>
using namespace std; 

int n, m, sx, sy; //n, m为棋盘的长和宽，sx, sy为马的坐标
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1}; 
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2}; 
int d[405][405]; //d[i][j]表示从马的坐标到(i, j)的最少步数
void bfs()
{
    memset(d, -1, sizeof(d)); //先将所有的距离初始化为-1，表示无法到达
    queue<pair<int, int> >q; 
    q.push(make_pair(sx, sy)); 
    d[sx][sy] = 0; //马到达自己的坐标，距离为0
    while(!q.empty())//队列非空，进行BFS搜索
    {
        pair<int, int> p = q.front(); 
        q.pop(); 
        for(int i = 0; i<8; i++)//尝试八个方向的移动
        {
            int nx = p.first+dx[i]; //横坐标移动的距离
            int ny = p.second+dy[i]; //纵坐标移动的距离
            if(nx >= 1 && nx<= n && ny>= 1 && ny<= m && d[nx][ny] == -1)//如果能移动到该坐标且该坐标还没有被访问过
            {
                d[nx][ny] = d[p.first][p.second]+1; //更新到该坐标的最短距离
                q.push(make_pair(nx, ny)); 
            }
        }
    }
}
int main()
{
    cin >> n >> m >> sx >> sy; 
    bfs(); //进行BFS搜索
    for(int i = 1; i <= n; i++)//输出结果
    {
        for(int j = 1; j <= m; j++)
        {
            cout << d[i][j] << " "; //输出(i, j)的最少步数
        }
        cout << endl; 
    }
    return 0; 
}
