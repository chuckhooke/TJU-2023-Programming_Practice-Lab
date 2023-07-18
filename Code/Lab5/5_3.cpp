#include<bits/stdc++.h>
using namespace std;

int n, e, totalw;


void dijkstra(int** adj, bool* visited){
    int u = n - 1; // 最小生成树的边数
    int t = 0;  // 已经检查的边数
    while(u > 0){
        t++;
        int min = 10000;
        int mi, mj;
        // 寻找最小权值的边
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(adj[i][j] < min) {
                    min = adj[i][j];
                    mi = i;
                    mj = j;
                } 
            }
        }

        // 若不能构成环，则加入最小生成树 
        if(visited[mi] == 0 || visited[mj] == 0){
            totalw += min;
            visited[mi] = 1;
            visited[mj] = 1;
            u--;
        }

        // 不在检查这条边
        adj[mi][mj] = 10000;

        // 如果已经检查了所有边，还没有退出，则没有生成树
        if(t == e+1){
            totalw = 0;
            return;
        }
    }
}

int main(){
    int num;
    cin >> num;
    for(int p = 0; p < num; p++){
        cin >> n >> e;
        int **adj = new int* [n];  // 邻接矩阵
        bool *visited = new bool [n]; // 标记是否被访问
        for(int i = 0; i < n; i++) adj[i] = new int [n];

        // 初始化
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                adj[i][j] = 10000;
            }
        }

        for(int i = 0; i < n; i++){
            visited[i] = false;
        }

        // 记录权值
        for(int j = 0; j < e; j++){
            int v1, v2, w;
            cin >> v1 >> v2 >> w;
            adj[v1-1][v2-1] = w;
            adj[v2-1][v1-1] = w;
        }


        dijkstra(adj, visited);

        cout << totalw;
    }
    

}
