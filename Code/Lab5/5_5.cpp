#include<bits/stdc++.h>
using namespace std;
#define inf 1000
#define N 100

int adj[N][N];
int d[N];
bool visited[N];
int t,s,dd;

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
    cin >> t >> s >> dd;
    int *start = new int [s];
    int *des = new int [dd];
    for(int i = 0; i < t; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        int vv1 = v1 - 1;
        int vv2 = v2 - 1;
        adj[vv1][vv2] = w;
        adj[vv2][vv1] = w;
    }
    for(int i = 0; i < s; i++) {
        int v;
        cin >> v;
        int vv = v - 1;
        start[i] = vv;
    }
    for(int i = 0; i < dd; i++) {
        int v;
        cin >> v;
        int vv = v - 1;
        des[i] = vv;
    }

    int min = inf;

    // 计算所有起点的d数组 找出所有终点中d值最小的代价
    for(int i = 0; i < s; i++){
        dijkstra(start[i]);
        for(int j = 0; j < dd; j++){
            if(d[des[j]] < min) min = d[des[j]];
        }
    }

    cout << min;


}
