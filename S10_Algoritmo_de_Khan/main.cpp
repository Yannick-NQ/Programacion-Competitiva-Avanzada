#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> topological_sort(int n, vector<pair<int, int>>& dependencies) {
    unordered_map<int, vector<int>> graph;  // Grafo representado como una lista de adyacencia
    vector<int> in_degree(n, 0);  // Grado de entrada de cada nodo
    
    // Construcción del grafo y cálculo del grado de entrada
    for (auto& dep : dependencies) {
        int u = dep.first;
        int v = dep.second;
        graph[u].push_back(v);
        in_degree[v]++;
    }
    
    queue<int> q;  // Cola para procesar los nodos con grado de entrada 0
    for (int i = 0; i < n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> topological_order;  // Orden topológico de los nodos
    
    // Procesamiento de la cola
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topological_order.push_back(node);
        
        // Disminuir el grado de entrada de los nodos vecinos
        for (int neighbor : graph[node]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    // Verificación de la presencia de ciclos
    if (topological_order.size() == n) {
        return topological_order;  // Si se procesaron todos los nodos, no hay ciclos
    } else {
        return {};  // Si no se procesaron todos los nodos, hay un ciclo
    }
}

int main() {
    int n = 5;  // Número de nodos
    vector<pair<int, int>> dependencies = {{0, 1}, {1, 2}, {3, 1}, {3, 4}};  // Dependencias entre nodos
    
    vector<int> result = topological_sort(n, dependencies);
    
    if (!result.empty()) {
        cout << "Orden topologico: ";
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No es posible ordenar las tareas debido a un ciclo." << endl;
    }
    
    return 0;
}
