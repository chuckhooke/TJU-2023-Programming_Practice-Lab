#include <bits/stdc++.h>
using namespace std;
//void bubblesort(int *a, int n);
bool compare(int a,int b)
{
    return a>b;
}

int main(){
    int n;
    while(cin >> n){
        int m;
        cin >> m;
        int *a = new int [n];
        int u = n*(n-1)/2;
        int *arr = new int [u];
        for (int i = 0; i < n; i++) cin >> a[i];
        int num = 0;
        // 计算两两的和，存入数组
        for (int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                arr[num] = a[i] + a[j];
                num++;
            }
        }
        sort(arr, arr + u, compare); //从大到小的快排
        for (int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

//冒泡排序复杂度高
/*void bubblesort(int *a, int n){
    for(int i = 0; i < n-1; i++){
        for (int j = 0; j < n - 1 -i; j++){
            if (a[j] < a[j+1]){
            int t = a[j];
            a[j] = a[j+1];
            a[j+1] = t;

        }
        }
        
    }
}*/