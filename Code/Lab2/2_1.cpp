#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n; //容器数量
    int *a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];  //输入柱子长度
    int mh, s, max = 0;  //mh 较短柱子长度    s 两柱子间面积    max 目前最大面积
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (a[i] < a[j]) mh = a[i];
            else mh = a[j];
            s = mh * (j - i);
            if (s > max) max = s;
        }
    }
    cout << max;
    return 0;
}