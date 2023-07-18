#include<bits/stdc++.h>
using namespace std;
const int maxn = 105; 
int A[maxn][maxn], B[maxn], dp[maxn], N; // 二维数组A，一维数组B、dp，变量N

int main(){
    while(cin >> N){ 
        memset(A, 0, sizeof A); // 将二维数组A清零
        for(int i = 0; i < N; i++) 
            for(int j = 0; j < N; j++)
                cin >> A[i][j];
        int ans = -32767; // ans为答案，初值为一个极小的数
        int i = 0; 
        while(i < N){ 
            for(int i = 0; i < sizeof(B) / sizeof(B[0]); i++) { 
                B[i] = 0;
            }
        memset(dp, 0, sizeof dp); 
        for(int j = i; j < N; j++){ 
            for(int k = 0; k < N; k++){ // 循环将二维数组A的每一列加到一维数组B中
                B[k] += A[j][k];
            }
            dp[0] = B[0]; 
            int i = 1; 
            while(i < N){ 
                dp[i] = max(B[i], dp[i-1] + B[i]); // 状态转移方程
                i++; // i加1
            }
            int k = 0; 
            for(int i = 1; i < N; i++){ // 循环找到dp数组中最大值的下标
                if(dp[i] > dp[k]) k = i;
            }
            if(ans < dp[k]) ans = dp[k]; // 如果当前答案小于dp数组中最大值，就将答案更新为最大值
        }
        i++; 
        }
        cout << ans << endl; 
    }
return 0; 
}