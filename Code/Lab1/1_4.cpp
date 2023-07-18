#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    int* p = new int[n]; 
    for (int i = 0; i < n; i++) cin >> p[i];
    int cnt = 0;

    //做三层for循环，即固定两个数，对第三个数循环
    //当满足两边之和大于第三边，两边之差小于第三边，就是三角形，计数+1
    for (int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for (int k = j+1; k < n; k++){
                if (p[i] + p[j] > p[k] && p[k] -p[i] < p[j]) cnt ++;
                }
            }
        }
    cout << cnt;
    delete p;
    }


