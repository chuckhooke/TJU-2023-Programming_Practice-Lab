#include<bits/stdc++.h>
using namespace std;


// 高精度加法函数
vector<int> add(const vector<int>& a, const vector<int>& b) {  
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size() || i < b.size(); i++) {
        if (i < a.size()) {
            t += a[i];
        }
        if (i < b.size()) {
            t += b[i];
        }
        c.push_back(t % 10);
        t /= 10;
    }
    if (t) {
        c.push_back(1);
    }
    return c;
}

vector<int> dp[3005];  

int main() {
    // 边界条件
    dp[0] = {1};  
    dp[1] = {1};  
    dp[2] = {2};  
    for (int i = 3; i <= 3000; i++) {  
        // 由递推式 使用动态规划算法
        dp[i] = add(dp[i-1], add(dp[i-2], dp[i-3]));
    }
    int n;
    while (cin >> n) { 
        for (int i = dp[n].size()-1; i >= 0; i--) {  
            cout << dp[n][i];
        }
        cout << endl;
    }
    return 0;
}
