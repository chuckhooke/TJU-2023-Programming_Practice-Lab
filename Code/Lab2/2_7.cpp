#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    //为了去重，多建一个数组
    long long *arr = new long long [n];
    long long *brr = new long long [n];
    int cnt = 0;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) brr[i] = arr[i];
    //先排序，则只需要检查两个数后面的数
    sort (arr, arr+n);
    sort (brr, brr+n);
    for (int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            long long m = arr[i] + arr[j];
            for(int k = j+1; k < n; k++){
                if (m == brr[k]) {
                    brr[k] = 0;  //防止重复统计该数
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}