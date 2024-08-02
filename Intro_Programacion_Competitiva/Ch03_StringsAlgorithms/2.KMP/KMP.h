#ifndef KMP_H
#define KMP_H

#include <vector>
#include <string>

class KMP {
public:
    KMP(const std::string& pattern); // Constructor que inicializa el patrón y construye el array de prefijos
    std::vector<int> search(const std::string& text); // Función para buscar el patrón en el texto

private:
    std::string pattern; // Patrón a buscar
    std::vector<int> lps; // Array de prefijos más largos que son sufijos

    void buildLPS(); // Función para construir el array de prefijos
};

#endif // KMP_H
