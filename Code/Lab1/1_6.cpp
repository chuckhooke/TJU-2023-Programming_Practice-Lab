#include <bits/stdc++.h>
using namespace std;

long long han(int n);

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int j;
        cin >> j;
        cout << han(j) << endl;
    }

}

long long han(int n){
    if (n == 1) return 1;  //直到只有一层时，搬运一次
    else return 2*han(n - 1)+1; //搬运两次n-1层的塔 + 1次
}
