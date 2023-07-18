#include <bits/stdc++.h>
using namespace std;
void selectsort (int a[], int n);

int main(){
    int u;
    cin >> u;
    for (int k = 0; k < u; k++){
        int n; 
        cin >> n;
        int *arr = new int [n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        selectsort(arr, n);
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// 选择排序
void selectsort (int a[], int n){
    for(int i = 0; i < n-1; i++){
        int min = a[i]; 
        int num = 0;
        int j = i+1;
        // 找出当前无序区的最小值
        for (; j < n; j++){
            if (a[j] < min){
                min = a[j];
                num = j;
            } 
        }
        // 如果找到，则做交换
        if (num != 0){
            int tem = a[i];
            a[i] = a[num];
            a[num] = tem;
        }
        
    }
}

