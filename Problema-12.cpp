#include <iostream>
#include <vector>

using namespace std;

// Función para imprimir la matriz
void imprimirMatriz(const vector<vector<int>>& matriz) {
    int n = matriz.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para verificar si la matriz es un cuadrado mágico
bool esCuadradoMagico(const vector<vector<int>>& matriz) {
    int n = matriz.size();
    int sumaDiagonalPrincipal = 0;
    int sumaDiagonalSecundaria = 0;

    // Calcular la suma de la diagonal principal y secundaria
    for (int i = 0; i < n; ++i) {
        sumaDiagonalPrincipal += matriz[i][i];
        sumaDiagonalSecundaria += matriz[i][n - i - 1];
    }

    // Verificar si las diagonales son iguales
    if (sumaDiagonalPrincipal != sumaDiagonalSecundaria) {
        return false;
    }

    // Calcular la suma de la primera fila para usar como referencia
    int sumaReferencia = 0;
    for (int j = 0; j < n; ++j) {
        sumaReferencia += matriz[0][j];
    }

    // Verificar las sumas de todas las filas
    for (int i = 1; i < n; ++i) {
        int sumaFila = 0;
        for (int j = 0; j < n; ++j) {
            sumaFila += matriz[i][j];
        }
        if (sumaFila != sumaReferencia) {
            return false;
        }
    }

    // Verificar las sumas de todas las columnas
    for (int j = 0; j < n; ++j) {
        int sumaColumna = 0;
        for (int i = 0; i < n; ++i) {
            sumaColumna += matriz[i][j];
        }
        if (sumaColumna != sumaReferencia) {
            return false;
        }
    }

    // Si todas las sumas son iguales, es un cuadrado mágico
    return true;
}

int main() {
    int n;

    // Pedir el tamaño de la matriz (debe ser cuadrada)
    cout << "Ingrese el tamaño de la matriz (n x n): ";
    cin >> n;

    // Crear la matriz usando un vector de vectores
    vector<vector<int>> matriz(n, vector<int>(n));

    // Ingresar los valores de la matriz
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matriz[i][j];
        }
    }

    // Imprimir la matriz
    cout << "La matriz ingresada es:" << endl;
    imprimirMatriz(matriz);

    // Verificar si es un cuadrado mágico
    if (esCuadradoMagico(matriz)) {
        cout << "La matriz es un cuadrado mágico." << endl;
    } else {
        cout << "La matriz no es un cuadrado mágico." << endl;
    }

    return 0;
}
