#include<bits/stdc++.h>
using namespace std;

// 实现字符串匹配算法
int match(string w, string t) {
    int n = w.size(), m = t.size();
    int cnt = 0;
    for (int i = 0; i <= m - n; i++) {
        // 查询是否为子串
        if (t.substr(i, n) == w) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string w, t;
        cin >> w >> t;
        int cnt = match(w, t);
        cout << cnt << endl;
    }
    return 0;
}