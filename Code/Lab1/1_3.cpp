#include <bits/stdc++.h>
using namespace std;
int swap(char *p);

int main(){
    char a[200], b[200], c[201]; //存放输入输出的数组
    cin >> a >> b;
    //将数组a,b逆序
    int a1 = swap(a);
    int b1 = swap(b);
    int flag = 0;
    //为防止出现字符与空相加，先把较短数字的空项赋值为’0’
    if (a1 > b1) {
        for (int i = b1; i < a1; i++) b[i] = '0';
    }
    if (a1 < b1) {
        for (int i = a1; i < b1; i++) a[i] = '0';
    }
    //每位相加并设置进位
    for(int i = 0; i < 201; i++){
        if (a[i] == 0) a[i] = '0';
        if (b[i] == 0) b[i] = '0';
        if(a[i] == '0' && b[i] == '0' && flag == 0) a[i] = b[i] = 0;
        c[i] = a[i] + b[i] - '0';
        if(flag == 1) c[i] += 1;
        flag = 0;
        if(c[i] > '9'+10 || c[i] < '0' ) c[i] = 0;
        if(c[i] > '9' && c[i] <= '9' + 10) {
            c[i] = c[i] - 10;
            flag = 1;
        }
    }
    swap(c);
    cout << c;
    
}

//将数组逆序
int swap(char *p){
    int n = 0;
    for (int i = 0; i < 200; i++) if (p[i] == '\0'){
        n = i ; 
        break;
    } 
    for (int i = 0; i < n/2; i++){
        char tem = p[n - 1 - i];
        p[n - 1 - i] = p[i];
        p[i] = tem;
    }
    return n;
}

