#include<bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    int *w = new int [n+1];
    int *p = new int [n+1];
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> p[i];
    }

    // 动态分配二维数组，f[i][j] 表示前 i 件物品放入一个容量为 j 的背包可以获得的最大价值
    int **f = new int* [n+1];
    for(int i = 1; i <= n; i++){
        f[i] = new int [m+1];
    }

    // 初始化 f[n][j]，即只剩下最后一件物品，这时的最大价值只有两种情况，不选或选一次
    int ymax = w[n] > m ? m : w[n]; // 防止数组越界
    for(int y = 0; y < ymax; y++){ // 不选最后一件物品，背包容量为 y 时最大价值为 0
        f[n][y] = 0;
    }
    for(int y = w[n]; y <= m; y++){ // 选最后一件物品，背包容量为 y 时最大价值为 p[n]
        f[n][y] = p[n];
    }

    // 从倒数第二个物品开始考虑，一直到第一个物品
    for(int i = n - 1; i > 1; i--){
        if(w[i] > m){ // 当前物品重量大于背包容量时，无法放入背包
            for(int y = 0; y <= m; y++){ // 背包容量为 y 时，最大价值等于放入下一个物品时背包容量为 y 时的最大价值
                f[i][y] = f[i+1][y];
            }
            continue;
        }
        // 当前物品重量小于背包容量时，无法放入，最大价值等于放入下一个物品时背包容量为 y 时的最大价值
        for(int y = 0; y < w[i]; y++){ 
            f[i][y] = f[i+1][y];
        }
        // 当前物品重量小于等于背包容量时，最大价值等于放入下一个物品时背包容量为 y 时的最大价值和放入当前物品的最大价值的最大值
        for(int y = w[i]; y <= m; y++){ 
            f[i][y] = max(f[i+1][y], f[i+1][y-w[i]] + p[i]);
        }
    }

    // 最后考虑第一个物品
    f[1][m] = f[2][m];
    if(m >= w[1]){
        f[1][m] = max(f[2][m], f[2][m-w[1]] + p[1]);
    }

    cout << f[1][m];
}
