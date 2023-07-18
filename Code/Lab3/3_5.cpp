#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> students(n, 0);
        int count = 0; // 报数
        int index = 0; // 当前同学的下标
        int remaining = n; // 剩余的同学数
        while (remaining >= 7) {
            if (students[index] == 0) {
                count++;
                if (count % 7 == 0) {
                    students[index] = 1;
                    remaining--;
                }
            }
            index = (index + 1) % n;
        }
        for (int i = 0; i < n; i++) {
            if (students[i] == 0) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
