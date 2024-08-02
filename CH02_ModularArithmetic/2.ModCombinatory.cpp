#include <iostream>
#define MOD 1000000007

// Función para calcular el factorial de n modulo MOD
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result = (result * i) % MOD;
    }
    return result;
}

int main() {
    int n = 100000;
    std::cout << "Factorial de " << n << " modulo " << MOD << " es " << factorial(n) << std::endl;
    return 0;
}
