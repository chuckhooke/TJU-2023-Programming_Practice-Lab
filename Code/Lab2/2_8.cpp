#include <bits/stdc++.h>
using namespace std;
bool find(int top, int *a);

int n, m;
int main(){
    cin >> n >> m;
    int *arr = new int [n];
    int high = 0;
    int low = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        high += arr[i];  //上界为所有数之和
        if (arr[i] > low) low = arr[i];  //下界为最大的数
    }

    while(high > low){
        int mid = (high + low)/2;
        if(find(mid, arr)) low = mid +1;  //组数小于目标组数，则提高下限 
        else high = mid;  //组数大于目标组数，则降低上限
    }
    delete arr;
    cout << high;

    return 0;
}

// 二分查找
bool find(int top, int *a){
    int cnt = 1;
    int c = 0;
    for (int i = 0; i < n; i++){
        if(c < top) c += a[i];  //当目前的和小于最大，则继续加下一个
        if(c > top) {  //当目前的和大于最大，就新开一组
            cnt++;
            c = a[i];
        }
    }
    if(cnt <= m) return false;
    else return true;
}