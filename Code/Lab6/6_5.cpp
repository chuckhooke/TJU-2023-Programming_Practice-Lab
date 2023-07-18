#include<bits/stdc++.h>
using namespace std;

int main(){
    int fee[10];
    for(int i = 0; i < 10; i++){
        cin >> fee[i];
    }
    int des;
    cin >> des;
    int *dp = new int [des];
    dp[0] = fee[0];
    for(int i = 1; i < des; i++){
        int minfee = 10000;
        // 前十个车站是可以不换乘直达的
        if(i < 10) minfee = fee[i];
        // dp[i]则可由本站的前十个车站的dp加上从前面车站到本车站的费用的最小值表示
        for(int j = i - 1; j >= i - 10 && j >= 0; j--){
            minfee = min(minfee, dp[j] + fee[i - j -1]);
        }
        dp[i] = minfee;

    }
    cout << dp[des - 1];
}