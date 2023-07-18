#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long *a = new long long [n];
    long long *b = new long long [n];
    long long *c = new long long [n];


    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) c[i] = b[i] - a[i];  //每个can的剩余容量

    // 找出两个剩余容量最大的can
    int max = c[0];
    int num = 0;
    for (int i = 0; i < n; i++){
        if (c[i] > max) {
            max = c[i];
            num = i; 
        }
    }
    int c1 = c[num];
    int a1 = a[num];
    c[num] = 0;

    max = c[0];
    num = 0;
    for (int i = 0; i < n; i++){
        if (c[i] > max) {
            max = c[i];
            num = i; 
        }
    }

    int c2 = c[num];
    int a2 = a[num];
    c[num] = 0;

    int totalc = c1 + c2;  //剩余容量之和
    int totala = -a1 - a2;; //这两个can中的cola，不需要再占用totalc
    for (int i = 0; i < n; i++) totala += a[i];

    if (totalc >= totala ) cout << "YES";
    else cout << "NO";
    return 0;
}
