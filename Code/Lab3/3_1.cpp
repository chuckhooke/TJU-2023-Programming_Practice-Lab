#include <bits/stdc++.h>

using namespace std;

string binary_to_decimal(string binary) {
    // 将一个长度为32的二进制数转换成由点分隔的四个十进制数，并返回字符串表示的结果
    // 将二进制字符串分隔成四个字节（每个字节8位）
    string byte1 = binary.substr(0, 8);
    string byte2 = binary.substr(8, 8);
    string byte3 = binary.substr(16, 8);
    string byte4 = binary.substr(24, 8);

    // 将每个字节转换为十进制数字
    int dec1 = stoi(byte1, nullptr, 2);
    int dec2 = stoi(byte2, nullptr, 2);
    int dec3 = stoi(byte3, nullptr, 2);
    int dec4 = stoi(byte4, nullptr, 2);

    // 将四个数字组合成点分十进制表示的ip地址
    string ip = to_string(dec1) + "." + to_string(dec2) + "." + to_string(dec3) + "." + to_string(dec4);

    return ip;
}

int main() {
    int T;
    cin >> T;  // 输入样例个数

    for (int i = 0; i < T; i++) {
        string binary_ip;
        cin >> binary_ip;

        string decimal_ip = binary_to_decimal(binary_ip);
        cout << decimal_ip << endl; 
    }

    return 0;
}
