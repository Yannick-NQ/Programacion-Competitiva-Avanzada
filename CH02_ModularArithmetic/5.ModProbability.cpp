#include <iostream>
#include <vector>
#define MOD 1000000007

// Función para calcular combinaciones C(n, k) modulo MOD
long long modInverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

long long combination(int n, int k) {
    if (k == 0) return 1;
    std::vector<long long> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    return (fact[n] * modInverse(fact[k], MOD) % MOD * modInverse(fact[n - k], MOD) % MOD) % MOD;
}

int main() {
    int n = 10, k = 2;
    std::cout << "C(" << n << ", " << k << ") modulo " << MOD << " es " << combination(n, k) << std::endl;
    return 0;
}