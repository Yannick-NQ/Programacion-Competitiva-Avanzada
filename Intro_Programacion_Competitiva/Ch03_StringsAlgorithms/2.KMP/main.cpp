#include <iostream>
#include "KMP.h"

int main() {
    std::string text = "ababcabcabababd";
    std::string pattern = "ababd";
    
    KMP kmp(pattern);

    // Buscar el patrón en el texto
    std::vector<int> results = kmp.search(text);

    // Mostrar los resultados
    for (int index : results) {
        std::cout << "Pattern found at position " << index << std::endl;
    }

    return 0;
}
