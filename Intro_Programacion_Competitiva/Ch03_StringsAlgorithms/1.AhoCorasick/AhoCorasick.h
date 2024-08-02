#ifndef AHOCORASICK_H
#define AHOCORASICK_H

#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

class AhoCorasick {
public:
    // Estructura para los nodos del Trie
    struct TrieNode {
        std::unordered_map<char, TrieNode*> children; // Hijos del nodo
        TrieNode* fail; // Enlace de fallo
        std::vector<int> output; // Índices de los patrones que terminan en este nodo
        TrieNode() : fail(nullptr) {} // Constructor por defecto
    };

    AhoCorasick(); // Constructor de la clase
    void insert(const std::string& word, int index); // Función para insertar un patrón en el trie
    void buildFailLinks(); // Función para construir los enlaces de fallo
    std::vector<std::pair<int, int>> search(const std::string& text); // Función para buscar patrones en el texto

private:
    TrieNode* root; // Nodo raíz del Trie
};

#endif // AHOCORASICK_H
