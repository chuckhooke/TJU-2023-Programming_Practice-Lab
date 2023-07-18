#include <bits/stdc++.h>
using namespace std;
long long f[60]; //设置全部数组遍历 long long类型
void fobi();
int main(){
    fobi();
	int n;
	cin >> n;  //输入n个样例
	for (int i = 0; i < n; i++) {
		int m;
        cin >> m; //获取第m-1项的值
        cout << f[m-1] << endl;
	}
}

//计算出每一项的值，使得该项的值为前两项的和
void fobi(){
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < 60; i++) f[i] = f[i-1] + f[i-2];  
}

