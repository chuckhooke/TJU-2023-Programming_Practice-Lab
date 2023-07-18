#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        int *arr = new int [m];
        int *dp = new int [m];
        for(int j = 0; j < m; j++){
            cin >> arr[j];
        }
        int max_sum = 0;
        dp[0] = arr[0];
        for(int u = 1; u < m; u++){
            // 考虑两种可能 要么把当前的数加入之前的子序列中 要么从当前数开始一个子序列
            dp[u] = max(dp[u-1] + arr[u], arr[u]);
            // 更新最大子序列和
            max_sum = max(max_sum, dp[u]);
        }
        max_sum =  max_sum > 0 ? max_sum : 0;
        cout << max_sum << endl;
    }
}