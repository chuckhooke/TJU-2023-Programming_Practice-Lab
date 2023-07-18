#include<bits/stdc++.h>
using namespace std;

int n, e;

// 深度优先遍历
void dfs(int v, bool** adj, bool* visited){
    if (visited[v-1] == 1) return;  // 若已经被访问，则不再访问
    visited[v-1] = 1;  // 标记被访问
    cout << v << " ";
    for(int i = 0; i < n; i++){
        if(adj[v-1][i] == 1){
            dfs(i+1, adj, visited);  // 访问下一个节点
        }
    }
}

int main(){
    cin >> n >> e;
    bool **adj = new bool* [n];  // 邻接矩阵
    bool *visited = new bool [n]; // 标记是否被访问
    for(int i = 0; i < n; i++) adj[i] = new bool [n];

    // 初始化
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            adj[i][j] = false;
        }
    }

    for(int i = 0; i < n; i++){
        visited[i] = false;
    }

    for(int j = 0; j < e; j++){
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1-1][v2-1] = true;
        adj[v2-1][v1-1] = true;
    }

    // 从节点1开始访问
    dfs(1, adj, visited);

}
