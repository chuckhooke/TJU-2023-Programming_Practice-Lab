#include<bits/stdc++.h>
using namespace std;


// 埃氏筛法求素数
long* getPrimes(long n) {
    long *prime = new long [n+5];
    bool *isPrime = new bool [n+5];
    for (long i = 2; i <= n; i++) {
        prime[i] = i;
        isPrime[i] = true;
    }
    
    // 所有其倍数都是非素数
    for (long i = 2; i <= n; i++) {
        if (isPrime[i]) {
            for (long j = i * i; j <= n; j += i) {
                isPrime[j] = false;
                prime[j] = 0;
            }
        }
    }
    return prime;
}

int main() {
    long n;
    cin >> n;
    long* primes = getPrimes(n);
    unsigned long long sum = 0;
    for (long i = 2; i <= n; i++) {
        sum += primes[i];
    }
    cout << sum << endl;
    return 0;
}