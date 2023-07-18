#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, e;
    while(cin >> n >> e){
        set<int> s;  // 创建一个集合，用于统计联通集个数
        int w = n;
        int x;
        
        int *arr = new int [n];
        for(int i = 0; i < n; i++) arr[i] = i;

        if(e == 0) cin >> x;

        // 判断是否在一个联通集中
        for(int i = 0; i < e; i++){
            int v1, v2;
            cin >> v1 >> v2;
            int vv1 = v1-1;
            int vv2 = v2-1;

            // 创建新联通集
            if(arr[vv1] == vv1 && arr[vv2] == vv2){
                arr[vv1] = w;
                arr[vv2] = w;
                w++;
            }

            // 把节点加入某一联通集
            else if(arr[vv1] != vv1 && arr[vv2] == vv2){
                arr[vv2] = arr[vv1];
            }

            else if(arr[vv1] == vv1 && arr[vv2] != vv2){
                arr[vv1] = arr[vv2];
            }

            // 合并联通集
            else{
                if(arr[vv1] < arr[vv2]) {
                    for(int u = 0; u < n; u++){
                        if(arr[u] == arr[2]) arr[u] = arr[1];
                    }
                }
                else {
                    for(int u = 0; u < n; u++){
                        if(arr[u] == arr[1]) arr[u] = arr[2];
                    }
                }
                
            }


        }

        // 统计联通集个数
        for(int i = 0; i < n; i++){
            s.insert(arr[i]);
        }

        cout << s.size() - 1 << endl;

    }
}
