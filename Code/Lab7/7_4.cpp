#include <iostream>
using namespace std;

// 求两个数的最大公约数
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 求两个数的最小公倍数
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        cout << lcm(a, b) << endl;
    }
    return 0;
}