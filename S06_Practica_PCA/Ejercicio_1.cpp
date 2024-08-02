#include <iostream>
#include <unordered_set>
#include <vector>

bool existe_suma(const std::vector<int>& arreglo, int k) {
    std::unordered_set<int> numeros_vistos;

    for (int num : arreglo) {
        int diferencia = k - num;

        if (numeros_vistos.find(diferencia) != numeros_vistos.end()) {
            return true;
        }

        numeros_vistos.insert(num);
    }

    return false;
}

int main() {
    std::vector<int> arreglo = {4, 1, 2, 5, 3};
    int k = 5;

    if (existe_suma(arreglo, k)) {
        std::cout << "Existe una pareja de números cuya suma es " << k << std::endl;
    } else {
        std::cout << "No existe una pareja de números cuya suma es " << k << std::endl;
    }

    return 0;
}
