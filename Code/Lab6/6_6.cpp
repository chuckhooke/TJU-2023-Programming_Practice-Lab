#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int **a = new int *[n];
    int **dp = new int *[n];
    for(int i = 0; i < n; i++){
        a[i] = new int [n];
        dp[i] = new int [n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            dp[i][j] = 0;
        }
    }
    dp[0][0] = a[0][0];
    // 初始化第零行 和 第零列
    for(int i = 1; i < n; i++) dp[0][i] = dp[0][i - 1] + a[0][i];
    for(int i = 1; i < n; i++) dp[i][0] = dp[i - 1][0] + a[i][0];
    // 当经过这个数， 最大的值取决于其上面的最大值和左边的最大值
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
        }
    }
    cout << dp[n-1][n-1];
}