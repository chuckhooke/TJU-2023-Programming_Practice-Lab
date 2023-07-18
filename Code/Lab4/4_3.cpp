#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10;
int n, k, tot;  // n: 棋盘大小, k: 棋子数量, tot: 棋盘中的 # 数量
int row[MAXN], a[MAXN][MAXN];
long long ans;  // 方案数
char c;

void dfs(int x, int now) {
    if (x == k + 1) {
        ans++;
        return;
    }
    // 从上一个棋子所在的列号之后开始枚举可能的列号
    for (int i = now + 1; i <= tot; i++) {
        int flag = 1;
        for (int j = 1; j <= n; ++j) {
            if (a[row[j]][i]) {
                flag = 0;
                break;
            }
        }
        // 如果在第 i 列可以放置棋子
        if (flag) {
            row[x] = i;
            dfs(x + 1, i);
            row[x] = 0;
        }
    }
}

int main() {
    while (cin >> n >> k, n != -1 || k != -1) {
        tot = 0;
        ans = 0;
        for (int i = 0; i < n; i++){
            row[i] = 0;
            for(int j = 0; j < n; j++){
                a[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; j++) {
                cin >> c;
                if (c == '#') {
                    a[i][++tot] = 1;  // 表示可以放棋子
                }
            }
        }
        dfs(1, 0);
        cout << ans << endl;
    }
    return 0;
}
