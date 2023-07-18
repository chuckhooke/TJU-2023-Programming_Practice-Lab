#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
	while (cin >> n){
        int *p = new int[n];
        for (int i = 0; i < n; i++){
            cin >> p[i];
        }
        
        for (int i = 1; i < n; i++){
            int j = i;
            int tmp = p[i];
            // 绝对值之间的判断
            while((abs(tmp) > abs(p[j-1])) && j > 0){
                p[j] = p[j-1];
                j--;
            }
            p[j] = tmp;
        }

        for (int i = 0; i < n; i++){
            cout << p[i] << " ";
        }

        delete []p;
    }
}

