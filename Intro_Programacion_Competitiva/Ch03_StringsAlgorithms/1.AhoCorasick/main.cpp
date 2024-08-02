#include <iostream>
#include "AhoCorasick.h"

int main() {
    AhoCorasick ac;
    std::vector<std::string> patterns = {"abc","ab","abcd","aaaab"};
    std::string text = "abadbacaaaabcd";

    // Insertar los patrones en el Trie
    for (int i = 0; i < patterns.size(); ++i) {
        ac.insert(patterns[i], i);
    }

    // Construir los enlaces de fallo
    ac.buildFailLinks();

    // Buscar los patrones en el texto
    std::vector<std::pair<int, int>> results = ac.search(text);

    // Mostrar los resultados
    for (const auto& result : results) {
        std::cout << "Pattern \"" << patterns[result.second] << "\" found at position " 
                  << result.first - patterns[result.second].size() + 1 << std::endl;
    }

    return 0;
}
