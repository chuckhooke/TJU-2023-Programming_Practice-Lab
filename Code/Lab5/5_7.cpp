#include<bits/stdc++.h>
using namespace std;
#define inf 10000
#define N 1000

int adj[N][N];
int d[N];
bool visited[N];

// dijkstra算法 求单源最短路
void dijkstra(int v){
    for(int i = 0; i < N; i++) {
        d[i] = inf;
        visited[i] = 0;
        }
    d[v] = 0;         
    // 寻找d[i]最小的i 出队
    for(int i = 0; i < N; i++){
        int md = inf;
        int mi;
        int j = 0;
        for(j = 0; j < N; j++){
            if (d[j] < md && visited[j] == 0){
                md = d[j];
                mi = j;
            }
        }
        visited[mi] = 1;
        // 重新计算其邻接节点的d
        for(int u = 0; u < N; u++){
            if(adj[mi][u] > 0 && visited[u] == 0){
                d[u] = min(d[u], d[mi] + adj[mi][u]);
            }
        }
    }
}

int main(){
    int n,e,s,t;
    cin >> n >> e >> s >> t;
    for(int i = 0; i < e; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        int vv1 = v1 - 1;
        int vv2 = v2 - 1;
        adj[vv1][vv2] = w;
        adj[vv2][vv1] = w;
    }


    dijkstra(s-1);

    if(d[t-1] == inf) cout << -1;
    else cout << d[t-1];




}
