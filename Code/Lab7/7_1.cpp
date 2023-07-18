#include<bits/stdc++.h>
using namespace std;


// 实现字符串匹配算法
int match(string a, string b) {
    int n = a.size(), m = b.size();
    for (int i = 0; i <= n - m; i++) {
        // 查询是否为子串
        if (a.substr(i, m) == b) {
            return i;
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << match(a, b) << endl;
    }
    return 0;
}