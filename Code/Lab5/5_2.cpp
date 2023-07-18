#include<bits/stdc++.h>
using namespace std;

int n, e;

// 广度优先遍历
void bfs(bool** adj, bool* visited){
    queue <int>q;
    q.push(0);     // 从节点1开始访问
    while(!q.empty()){
        int v;
        v = q.front();
        q.pop();
        visited[v] = 1;
        cout << v+1 << " ";
        
        // 将所有该节点连接且未被访问的节点入队
        for(int i = 0; i < n; i++){
            if(adj[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                q.push(i);
            }
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


    bfs(adj, visited);

}
