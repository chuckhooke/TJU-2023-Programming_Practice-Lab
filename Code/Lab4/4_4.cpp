#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5;

int maze[MAX_N][MAX_N];  // 地图
bool visited[MAX_N][MAX_N];  // 记录节点是否已访问

struct Node {
  int x, y, pre;  // 当前节点坐标、前驱节点编号
} nodes[50];  // 存储BFS遍历时的节点信息

const int kDirections[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // 上下左右四个方向

int front = 0, rear = 0;  // BFS遍历队列的头尾指针

void bfs(int sx, int sy, int ex, int ey) {
    nodes[0].x = sx;
    nodes[0].y = sy;
    nodes[0].pre = -1;
    rear++;
    visited[sx][sy] = true;
    while (front < rear) {
    for (int i = 0; i < 4; i++) {
        int nx = nodes[front].x + kDirections[i][0];
        int ny = nodes[front].y + kDirections[i][1];
        if (nx < 0 || nx >= MAX_N || ny < 0 || ny >= MAX_N) {
            continue;  // 越界，继续检查下一个方向
        }
        if (maze[nx][ny] == 1) {
            continue;  // 障碍物，无法通过，继续检查下一个方向
        }
        if (visited[nx][ny]) {
        continue;  // 已经访问过，不需要再次访问，继续检查下一个方向
        }
        nodes[rear].x = nx;
        nodes[rear].y = ny;
        nodes[rear].pre = front;
        rear++;
        visited[nx][ny] = true;
        if (nx == ex && ny == ey) {
            return;  // 已经找到终点，结束搜索
        }
    }
    front++;
    }
}

void print_path(Node now) {
    if (now.pre == -1) {
        printf("(%d, %d)\n", now.x, now.y);
        return;
    }
    print_path(nodes[now.pre]);
    printf("(%d, %d)\n", now.x, now.y);
}

int main() {
    // 读入地图
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            cin >> maze[i][j];
            visited[i][j] = false;
        }
    }

  // BFS搜索
    bfs(0, 0, 4, 4);

  // 输出路径
    print_path(nodes[rear - 1]);

    return 0;
}
