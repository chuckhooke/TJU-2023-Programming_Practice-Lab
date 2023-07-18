#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        //直接利用公式输出答案即可
        cout << 2 * long long(sqrt(n)) - (!(n / long long(sqrt(n)) - long long(sqrt(n)))) << endl;
    }
}
