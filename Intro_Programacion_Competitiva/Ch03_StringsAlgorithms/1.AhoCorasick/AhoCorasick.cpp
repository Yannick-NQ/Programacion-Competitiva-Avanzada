#include "AhoCorasick.h"

// Constructor de la clase AhoCorasick
AhoCorasick::AhoCorasick() {
    root = new TrieNode();
}

// Función para insertar un patrón en el trie
void AhoCorasick::insert(const std::string& word, int index) {
    TrieNode* node = root;
    for (char c : word) {
        // Crear un nuevo nodo si no existe para el carácter c
        if (!node->children[c]) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    // Añadir el índice del patrón al nodo final
    node->output.push_back(index);
}

// Función para construir los enlaces de fallo
void AhoCorasick::buildFailLinks() {
    std::queue<TrieNode*> q;
    root->fail = root; // El enlace de fallo de la raíz apunta a sí misma

    // Inicializar los enlaces de fallo de los hijos de la raíz
    for (auto& pair : root->children) {
        pair.second->fail = root;
        q.push(pair.second);
    }

    // Construcción de los enlaces de fallo para el resto de los nodos
    while (!q.empty()) {
        TrieNode* current = q.front();
        q.pop();

        // Procesar todos los hijos del nodo actual
        for (auto& pair : current->children) {
            char c = pair.first;
            TrieNode* child = pair.second;
            TrieNode* failNode = current->fail;

            // Encontrar el enlace de fallo adecuado para el hijo
            while (failNode != root && !failNode->children[c]) {
                failNode = failNode->fail;
            }
            if (failNode->children[c] && failNode->children[c] != child) {
                child->fail = failNode->children[c];
            } else {
                child->fail = root;
            }

            // Combinar las salidas del nodo hijo y su nodo de fallo
            child->output.insert(child->output.end(), child->fail->output.begin(), child->fail->output.end());

            // Añadir el hijo a la cola para procesarlo después
            q.push(child);
        }
    }
}

// Función para buscar patrones en el texto
std::vector<std::pair<int, int>> AhoCorasick::search(const std::string& text) {
    std::vector<std::pair<int, int>> result;
    TrieNode* node = root;

    // Recorrer el texto carácter por carácter
    for (int i = 0; i < text.size(); ++i) {
        char c = text[i];

        // Seguir los enlaces de fallo hasta encontrar un hijo con el carácter c o llegar a la raíz
        while (node != root && !node->children[c]) {
            node = node->fail;
        }

        // Si existe un hijo con el carácter c, avanzar a ese nodo
        if (node->children[c]) {
            node = node->children[c];
        } else {
            node = root;
        }

        // Si el nodo actual tiene alguna salida, añadirla a los resultados
        if (!node->output.empty()) {
            for (int index : node->output) {
                result.push_back({i, index});
            }
        }
    }
    return result;
}
