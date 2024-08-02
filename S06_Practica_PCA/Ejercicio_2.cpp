#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotateMatrix90Degrees(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Transponer la matriz
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Invertir cada fila
    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    return matrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Matriz original:" << endl;
    printMatrix(matrix);

    vector<vector<int>> rotatedMatrix = rotateMatrix90Degrees(matrix);

    cout << "Matriz rotada 90 grados en sentido horario:" << endl;
    printMatrix(rotatedMatrix);

    return 0;
}
