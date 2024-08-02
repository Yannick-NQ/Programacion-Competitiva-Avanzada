#include <iostream>
#include <tuple>
#define MOD 1000000007

// Función para encontrar el MCD de a y b
long long gcdExtended(long long a, long long b, long long* x, long long* y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

// Función para resolver la congruencia ax ≡ b (mod m)
void solveCongruence(long long a, long long b, long long m) {
    long long x, y;
    long long g = gcdExtended(a, m, &x, &y);
    if (g != 1) {
        std::cout << "No hay solución" << std::endl;
    } else {
        long long res = (x % m + m) % m;
        std::cout << "Solucion de " << a << "x = " << b << " (mod " << m << ") es x = " << (res * (b / g) % m) << " (mod " << m << ")" << std::endl;
    }
}

int main() {
    long long a = 14, b = 30, m = 19;
    solveCongruence(a, b, m);
    return 0;
}
