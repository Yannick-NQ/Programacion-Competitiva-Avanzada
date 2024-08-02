#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& potencia_de_conjunto) {
    // Agrega el subconjunto actual a la lista de todos los subconjuntos
    potencia_de_conjunto.push_back(path);

    // Itera sobre los elementos restantes para generar nuevos subconjuntos
    for (int i = start; i < nums.size(); ++i) {
        // Añadir el siguiente número al camino actual y continuar generando
        path.push_back(nums[i]);
        backtrack(nums, i + 1, path, potencia_de_conjunto);
        path.pop_back();
    }
}

vector<vector<int>> generar_subconjuntos(vector<int>& nums) {
    vector<vector<int>> potencia_de_conjunto;
    vector<int> path;
    // Inicia el backtracking desde el primer elemento
    backtrack(nums, 0, path, potencia_de_conjunto);
    return potencia_de_conjunto;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> subconjuntos = generar_subconjuntos(nums);

    for (const auto& subconjunto : subconjuntos) {
        cout << "{ ";
        for (int num : subconjunto) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
