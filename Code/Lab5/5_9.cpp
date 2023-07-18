#include<bits/stdc++.h>
using namespace std;

const int maxn = 10000;
struct node{
    int num; // 入度
    int mon; // 最小时间
    node ():num(0),mon(100){};  
}G[maxn];
struct Edge{
    int to,next;
}g[20000];
int head[maxn],tot=0;
void add(int u,int v){
    g[++tot].to = v;
    g[tot].next = head[u];
    head[u] = tot; 
}
int cnt=0;
int q[maxn],l=0,r=0;
int main(){
    int n,m;
    cin >> n >> m;
    bool flag = true;int a,b;
    for (int i = 1; i <= m; i++){
        cin >> a >> b;
        add(b, a); // 建反向边
        G[a].num++; // 纪录每一个点的入度
    }
    int h = 1;
    // 找入度为 0 的点
    while (h <= n){
        if (G[h].num == 0){
            q[r] = h;
            ++r;
        }
        ++h;
    }
    int tmp;
    // 拓扑排序
    while (l<r){
        tmp = q[l];++l;
        for(int i = head[tmp]; i ; i = g[i].next){
            G[g[i].to].num--;
            if(G[g[i].to].mon <= G[tmp].mon)
               G[g[i].to].mon = G[tmp].mon + 1;
            if(G[g[i].to].num == 0){
                //入度为零则不可能再一次被更新了 
                q[r] = g[i].to ; ++r;
            }
        }
    }
    int hh = 1;
    // 判断是否有环
    while (hh <= n){
        if (G[hh].num != 0){
            flag = false;
            break;
        }
        cnt += G[hh].mon;
        hh++;
    }
    if (!flag) cout << "impossible";
    else cout << cnt;
    return 0;
}
