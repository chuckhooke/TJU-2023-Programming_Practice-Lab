#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int t;
        cin >> t;
        int c[7];
        int cnt = 0;
        for (int j = 0; j < 7; j++) cin >> c[j];  //输入个面额纸币的数量

        //面额从大到小找出
        //先判断是否存在该面额的纸币
        while(t >= 100){
            if (c[6] > 0) {
                c[6]--;
                t = t -100;
                cnt++;
            }
            else break;
        }
        while(t >= 50){
            if (c[5] > 0) {
                c[5]--;
                t = t -50;
                cnt++;
            }
            else break;
        }
        while(t >= 20){
            if (c[4] > 0) {
                c[4]--;
                t = t -20;
                cnt++;
            }
            else break;
        }
        while(t >= 10){
            if (c[3] > 0) {
                c[3]--;
                t = t -10;
                cnt++;
            }
            else break;
        }
        while(t >= 5){
            if (c[2] > 0) {
                c[2]--;
                t = t -5;
                cnt++;
            }
            else break;
        }
        while(t >= 2){
            if (c[1] > 0) {
                c[1]--;
                t = t -2;
                cnt++;
            }
            else break;
        }
        while(t >= 1){
            if (c[0] > 0) {
                c[0]--;
                t = t -1;
                cnt++;
            }
            else break;
        }
        if (t == 0) cout << cnt << endl;
        else cout << -1 << endl;
    }
    }