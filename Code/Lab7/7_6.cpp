#include<bits/stdc++.h>
using namespace std;


int main() {
    int a, b;
    while (cin >> a >> b && (a || b)) {
        int ans = 1;
        // 快速幂的思想
        while (b) {
            // 当b该位是1，则乘上一个a
            if (b & 1) {
                ans = ans * a % 1000;
            }
            a = a * a % 1000;
            b >>= 1;
        }
        cout << ans << endl;
    }
    return 0;
}