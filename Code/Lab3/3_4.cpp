#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int n;
queue<int> q;
stack<int> stk;

void clear() {
    while (!q.empty()) q.pop();
    while (!stk.empty()) stk.pop();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        clear();
        cin >> n;
        string op;
        int k;
        bool qflag = true, stkflag = true;
        while (n--) {
            cin >> op;
            if (op == "push") {
                cin >> k;
                q.push(k);
                stk.push(k);
            } else {
                if (q.empty() || stk.empty()) {
                    qflag = false;
                    stkflag = false;
                    continue;
                }
                if (op == "pop") {
                    q.pop();
                    stk.pop();
                }
            }
        }
        if (qflag) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                cout << q.front() << (i == size - 1 ? "\n" : " ");
                q.push(q.front());
                q.pop();
            }
        } else {
            cout << "error\n";
        }
        if (stkflag) {
            int size = stk.size();
            int *m = new int[size];
            for (int i = 0; i < size; i++) {
                m[i] = stk.top();
                stk.pop();
            }
            for (int i = size-1; i >=0; i--) {
                cout << m[i] << " ";
            }
            cout << endl;
        } else {
            cout << "error\n";
        }
    }
    return 0;
}
