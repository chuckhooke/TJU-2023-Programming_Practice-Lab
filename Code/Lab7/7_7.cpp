#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t; 
    while (t--) { 
        int a, b, n;
        cin >> a >> b >> n; 
        if (n == 0) { 
            cout << a << endl;
        } else if (n == 1) { 
            cout << b << endl;
        } else {
            int f0 = a, f1 = b, fn;
            for (int i = 2; i <= n; i++) {
                fn = f0 ^ f1; // 计算 异或值
                f0 = f1; 
                f1 = fn;
            }
            cout << fn << endl; 
        }
    }
    return 0;
}