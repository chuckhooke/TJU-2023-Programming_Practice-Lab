#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

const int N = 510, P = 131;

// 计算字符串哈希值
unsigned long long hash_str(string s) {
    int n = s.size();
    unsigned long long h = 0;
    for (int i = 0; i < n; i++) {
        h = h * P + s[i];
    }
    return h;
}

// 计算本质不同的子串数目
int count_substrings(string s) {
    int n = s.size();
    unordered_set<unsigned long long> hash_set;
    for (int i = 0; i < n; i++) {
        // 构造字符串环
        string t = s.substr(i) + s.substr(0, i); 
        for (int j = 0; j < n; j++) {
            hash_set.insert(hash_str(t.substr(j)));
        }
    }
    return hash_set.size();
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        cout << count_substrings(s) << endl;
    }
    return 0;
}