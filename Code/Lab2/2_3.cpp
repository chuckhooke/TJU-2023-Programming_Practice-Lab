#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n, q;
    cin >> m >> n >> q;

    //建立动态二维数组
    long long **arr = new long long*[m];
    for (int i = 0; i < m; ++i) arr[i] = new long long[n];

    //给数组中的元素赋值
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < q; i++){
        int x1,y1,x2,y2;
        int sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        // 保证x1<x2,y1<y2
        if (x1 > x2) {
            int m = x1;
            x1 = x2;
            x2 = m;
        }
        if (y1 > y2) {
            int m = y1;
            y1 = y2;
            y2 = m;
        }
        //对子矩阵求和
        for (int u = x1; u <= x2; u++){
            for (int w = y1; w <= y2; w++){
                sum += arr[u][w];
            }
        }
        cout << sum << endl;
    }

    delete arr;
    return 0;
}