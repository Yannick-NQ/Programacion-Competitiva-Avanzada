#include <iostream>
#include <string>
#define MOD 1000000007

// Función de hash simple utilizando aritmética modular
unsigned long long hashString(const std::string& s) {
    unsigned long long hash = 0;
    unsigned long long p = 31; // Número primo usado para el cálculo del hash
    unsigned long long p_pow = 1;
    for (char c : s) {
        hash = (hash + (c - 'a' + 1) * p_pow) % MOD;
        p_pow = (p_pow * p) % MOD;
    }
    return hash;
}

int main() {
    std::string s = "programming";
    std::cout << "Hash de \"" << s << "\" es " << hashString(s) << std::endl;
    return 0;
}
