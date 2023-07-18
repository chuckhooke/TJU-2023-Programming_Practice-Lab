#include <bits/stdc++.h>
using namespace std;

int main(){
    int m;
    cin >> m;
    for (int u = 0; u  < m; u++){
        int n, sum;
        int count = 0;
        cin >> n >> sum;
        int *a = new int[n];
        for (int i = 0; i < n; i++) cin >> a[i];  // 输入数组
        // 以每一个数组位置为起点，计算所有以其为起点的子集
        for (int i = 0; i < n; i++){
            int tsum = 0;
            int  j = i;
            while (j < n){
                tsum += a[j];
                j++;
                if (tsum == sum) count++;  // 满足条件 数目+1
            }
            
        }
        delete a;

        cout << count << endl;
    }
    return 0;
}