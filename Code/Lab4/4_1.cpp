#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
double nums[MAXN];
double sum, side;
int cnt;
bool used[MAXN];

// 判断能否构成正方形
bool dfs(int cur, double len) {
    if (len == side) {
        if (++cnt == 4) return true;
        return dfs(0, 0); // 继续搜索下一边
    }
    for (int i = cur; i < MAXN; i++) {
        if (!used[i] && len + nums[i] <= side) { // 能用于构成边
            used[i] = true;
            if (dfs(i + 1, len + nums[i])) return true; //加入后 构造成功
            used[i] = false;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            sum += nums[i];
            used[i] = false;
        }
        if (sum < 4) {
            cout << "no" << endl;
            continue;
        }
        side = sum / 4.0; // 计算正方形边长
        if (side != int(side)) {
            cout << "no" << endl;
            continue;
        }
        cnt = 0;
        if (dfs(0, 0)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
