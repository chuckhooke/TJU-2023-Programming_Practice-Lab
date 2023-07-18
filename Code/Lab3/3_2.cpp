#include <bits/stdc++.h>
using namespace std;
string decimalToRadix(int decimal, int radix);

int main() {
    int n, R;
    while (cin >> n) {
        cin >> R;
        string result = decimalToRadix(abs(n), R);
        if (n < 0) cout << "-";
        cout << result << endl;
    }
}

// 将十进制数decimal转换成radix进制数的字符串表示
string decimalToRadix(int decimal, int radix) {
    string result = "";    //先将结果置空
    while (decimal > 0) {
        int remainder = decimal % radix;    //取进制R的余数
        if (remainder < 10) {
            result = (char)('0' + remainder) + result;
        } else {
            result = (char)('A' + remainder - 10) + result;
        }
        decimal /= radix;
    }
    return result;
}
