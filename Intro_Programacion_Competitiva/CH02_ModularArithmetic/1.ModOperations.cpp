#include <bits/stdc++.h>

using namespace std;
 
// Función para realizar la adición modular
int modAdd(int a, int b, int m) {
    return ((a % m) + (b % m)) % m;
}
 
// Función para realizar la sustracción modular
int modSub(int a, int b, int m) {
    return ((a % m) - (b % m) + m) % m; // Añadiendo m para manejar números negativos
}
 
// Función para realizar la multiplicación modular
int modMul(int a, int b, int m) {
    return ((a % m) * (b % m)) % m;
}
 
// Función para calcular la potencia de un número
int power(int x, unsigned int y, int p) {
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 
// Función para encontrar el inverso modular de a bajo el módulo m
// Asunción: m es primo
int modInverse(int a, int m) {
    return power(a, m - 2, m);
}
 
// Función para realizar la división modular
int modDiv(int a, int b, int m) {
    a = a % m;
    int inv = modInverse(b, m);
    return (inv * a) % m;
}

int main() {
    int a = 10, b = 20, m = 7;
    cout << "Adición Modular: " << modAdd(a, b, m) << endl;
    cout << "Sustracción Modular: " << modSub(a, b, m) << endl;
    cout << "Multiplicación Modular: " << modMul(a, b, m) << endl;
    cout << "División Modular: " << modDiv(a, b, m) << endl;
    return 0;
}
