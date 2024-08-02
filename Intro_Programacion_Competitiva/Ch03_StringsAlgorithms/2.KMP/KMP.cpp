#include "KMP.h"

// Constructor que inicializa el patrón y construye el array de prefijos
KMP::KMP(const std::string& pattern) : pattern(pattern), lps(pattern.size(), 0) {
    buildLPS();
}

// Función para construir el array de prefijos más largos que son sufijos (LPS)
void KMP::buildLPS() {
    int length = 0;
    int i = 1;

    // El primer valor de LPS siempre es 0
    lps[0] = 0;

    // Construcción del array LPS
    while (i < pattern.size()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Función para buscar el patrón en el texto utilizando el algoritmo KMP
std::vector<int> KMP::search(const std::string& text) {
    std::vector<int> result;
    int m = pattern.size();
    int n = text.size();
    int i = 0; // Índice para text[]
    int j = 0; // Índice para pattern[]

    // Búsqueda del patrón en el texto
    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == m) {
            result.push_back(i - j); // Patrón encontrado en la posición i - j
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return result;
}
