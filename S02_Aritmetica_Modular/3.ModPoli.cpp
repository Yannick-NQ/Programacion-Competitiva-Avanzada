#include <iostream>
#include <vector>
#define MOD 1000000007

// Función para añadir dos polinomios
std::vector<int> addPolynomials(const std::vector<int>& A, const std::vector<int>& B) {
    int n = std::max(A.size(), B.size());
    std::vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = ((i < A.size() ? A[i] : 0) + (i < B.size() ? B[i] : 0)) % MOD;
    }
    return result;
}

int main() {
    std::vector<int> poly1 = {1, 2, 3}; // 1 + 2x + 3x^2
    std::vector<int> poly2 = {3, 4, 5}; // 3 + 4x + 5x^2
    std::vector<int> result = addPolynomials(poly1, poly2);
    std::cout << "Polinomio resultante: ";
    for (int coeff : result) {
        std::cout << coeff << " ";
    }
    std::cout << std::endl;
    return 0;
}
