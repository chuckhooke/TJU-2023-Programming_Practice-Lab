#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, a[MAXN], dp[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = 1;  //初始化为1 
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // 遍历由0到i-1 加入能满足的最长序列
            if (a[j] < a[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    // 输出dp中最大的数
    cout << *max_element(dp, dp+n) << endl;
    return 0;
}
