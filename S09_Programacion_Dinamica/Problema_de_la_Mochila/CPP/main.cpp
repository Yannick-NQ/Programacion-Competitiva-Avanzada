#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para resolver el problema de la mochila
int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
    // Crear una matriz para almacenar los valores óptimos
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    // Llenar la tabla usando programación dinámica
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    // Retornar el valor óptimo
    return dp[n][W];
}

int main() {
    // Datos de entrada
    vector<int> pesos = {2, 3, 6, 7};
    vector<int> beneficios = {30, 35, 40, 55};
    int capacidad = 10;
    int n = pesos.size();
    
    // Llamar a la función de la mochila
    int beneficio_maximo = knapSack(capacidad, pesos, beneficios, n);
    cout << "El beneficio máximo es S/." << beneficio_maximo  << endl;
    
    return 0;
}
