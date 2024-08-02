#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Función BFS para recorrer un grafo
void BFS(int startNode, const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    // Comenzar desde el nodo inicial
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << "Visitando nodo: " << node << endl;

        // Recorrer todos los vecinos del nodo actual
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
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

    BFS(0, graph); // Llamada a BFS desde el nodo 0

    return 0;
}
