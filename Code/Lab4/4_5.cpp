#include <bits/stdc++.h>
using namespace std;

const int INF = 100000;

int n, m;
char mp[205][205];  // 存储地图信息
int dis[2][205][205];  // 存储起点到各个点的最短路径
int sx[2], sy[2];  // 起点的坐标
bool vis[205][205];  // 标记是否访问过

struct Node {
    int x, y;
};

// 方向数组，用于在地图上移动
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

// 判断当前点是否可以走
bool is_valid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] != '#';
}

// bfs遍历求出起点到各个点的最短路径
void bfs(int id) {
    memset(vis, false, sizeof(vis));
    queue<Node> q;
    q.push({sx[id], sy[id]});
    dis[id][sx[id]][sy[id]] = 0;
    vis[sx[id]][sy[id]] = true;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        int x = node.x, y = node.y;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (is_valid(nx, ny) && !vis[nx][ny]) {
                vis[nx][ny] = true;
                dis[id][nx][ny] = dis[id][x][y] + 11;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    while (cin >> n >> m) {
        memset(mp, 0, sizeof(mp));
        memset(dis, INF, sizeof(dis));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> mp[i][j];
                if (mp[i][j] == 'Y') {
                    sx[0] = i;
                    sy[0] = j;
                } else if (mp[i][j] == 'M') {
                    sx[1] = i;
                    sy[1] = j;
                }
            }
        }

        bfs(0);  // 以Y点为起点进行bfs
        bfs(1);  // 以M点为起点进行bfs

        int ans = INF;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (mp[i][j] == '@') {
                    ans = min(ans, dis[0][i][j] + dis[1][i][j]);  // 计算最小总时间
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
