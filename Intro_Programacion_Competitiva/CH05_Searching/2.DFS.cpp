#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Función DFS para recorrer un grafo
void DFS(int startNode, const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> s;

    // Comenzar desde el nodo inicial
    s.push(startNode);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << "Visitando nodo: " << node << endl;

            // Recorrer todos los vecinos del nodo actual
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}

int main() {
    // Ejemplo de grafo como lista de adyacencia
    vector<vector<int>> graph = {
        {1, 2},    // Nodo 0 conectado con nodos 1 y 2
        {0, 3, 4}, // Nodo 1 conectado con nodos 0, 3 y 4
        {0},       // Nodo 2 conectado con nodo 0
        {1},       // Nodo 3 conectado con nodo 1
        {1}        // Nodo 4 conectado con nodo 1
    };

    DFS(0, graph); // Llamada a DFS desde el nodo 0

    return 0;
}
