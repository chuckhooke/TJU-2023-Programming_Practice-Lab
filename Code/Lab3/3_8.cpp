#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq; // 小根堆，存储果堆的大小（个数）
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        pq.push(m); // 将每个果堆的大小存入小根堆中
    }

    long long ans = 0; 

    while (pq.size() > 1) { // 只要堆的大小大于1，就继续合并
        int a = pq.top(); pq.pop(); 
        int b = pq.top(); pq.pop(); 
        ans += a + b; // 合并这两个堆，记录体力耗费
        pq.push(a + b); // 将新的果堆大小推回小根堆，继续等待合并
    }

    cout << ans << endl; // 输出最小体力耗费值
    return 0;
}
