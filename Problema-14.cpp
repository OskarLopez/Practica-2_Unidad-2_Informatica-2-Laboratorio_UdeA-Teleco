#include <iostream>
using namespace std;

// Función para imprimir una matriz 5x5
void imprimirMatriz(int matriz[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// Función para rotar la matriz 90 grados
void rotar90(int original[5][5], int rotada[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            rotada[j][5 - i - 1] = original[i][j];
        }
    }
}

// Función para rotar la matriz 180 grados
void rotar180(int original[5][5], int rotada[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            rotada[5 - i - 1][5 - j - 1] = original[i][j];
        }
    }
}

// Función para rotar la matriz 270 grados
void rotar270(int original[5][5], int rotada[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            rotada[5 - j - 1][i] = original[i][j];
        }
    }
}

int main() {
    // Declaramos la matriz 5x5 y la llenamos con los números del 1 al 25
    int matriz[5][5] = {
        { 1,  2,  3,  4,  5},
        { 6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    // Matrices para almacenar las rotaciones
    int rotada90[5][5], rotada180[5][5], rotada270[5][5];

    // Imprimir la matriz original
    cout << "Matriz original:" << endl;
    imprimirMatriz(matriz);

    // Rotar la matriz 90 grados
    rotar90(matriz, rotada90);
    cout << "Matriz rotada 90 grados:" << endl;
    imprimirMatriz(rotada90);

    // Rotar la matriz 180 grados
    rotar180(matriz, rotada180);
    cout << "Matriz rotada 180 grados:" << endl;
    imprimirMatriz(rotada180);

    // Rotar la matriz 270 grados
    rotar270(matriz, rotada270);
    cout << "Matriz rotada 270 grados:" << endl;
    imprimirMatriz(rotada270);

    return 0;
}
