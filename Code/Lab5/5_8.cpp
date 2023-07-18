#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100;
const int inf = 60000;
int d[MAXN][MAXN]; //表示任意两个点之间的距离

// 三重循环实现Floyd算法
void Floyd(int n)
{
    // 插入k节点
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
                if(i == j) d[i][j] = 0;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++ ){
        for(int j = 1; j <= n; j++){
            int w;
            cin >> w;
            if(i == j) d[i][j] = 0;
            else if(w == 0) d[i][j] = inf;
            else d[i][j] = w;
        }
    }
    Floyd(n);
    for(int i = 1; i <= n; i++ ){
        for(int j = 1; j <= n; j++){
            if(d[i][j] == inf) cout << -1 << " ";
            else cout << d[i][j] << " ";
        }
        cout << endl;
    }
}
