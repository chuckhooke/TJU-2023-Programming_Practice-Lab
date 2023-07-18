#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n;  
bool used[N];  // 标记数字是否已经使用过
int path[N];  // 存储搜索结果

// 判断一个数是否是素数
bool is_prime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0) return false;
    return true;
}

void dfs(int u)
{
    // 如果已经搜索到最后一个位置，则判断是否满足条件，输出结果并返回
    if (u == n)
    {
        if (is_prime(path[0] + path[n - 1]))
        {
            for (int i = 0; i < n; i++) cout << path[i] << " ";
            cout << endl;
        }
        return;
    }
    // 枚举下一个位置可以使用的数字
    for (int i = 2; i <= n; i++)
        if (!used[i] && is_prime(i + path[u - 1]))
        {
            used[i] = true;  // 标记该数字已经使用过
            path[u] = i;  // 将该数字存入搜索结果中
            dfs(u + 1);  // 继续搜索下一个位置
            used[i] = false;  // 恢复现场
        }
}

int main()
{

    int T = 0;
    while (cin >> n)
    {
        if (T++) cout << endl;  
        for (int i = 0; i < n; i++){
            used[i] = false;
        }
        path[0] = 1;  // 第一个位置必须是 1
        cout << "Case " << T << ":" << endl;  
        dfs(1);  
    }

    return 0;
}
