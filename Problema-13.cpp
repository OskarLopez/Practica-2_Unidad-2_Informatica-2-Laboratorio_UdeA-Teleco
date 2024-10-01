#include <iostream>

using namespace std;

// Función que verifica si el elemento es una estrella
bool esEstrella(int** matriz, int filas, int columnas, int i, int j) {
    float promedio = (matriz[i][j] + matriz[i][j - 1] + matriz[i][j + 1] + 
                      matriz[i - 1][j] + matriz[i + 1][j]) / 5.0;
    return promedio > 6;
}

// Función que cuenta las estrellas y recibe un puntero a la matriz
int contarEstrellas(int** matriz, int filas, int columnas) {
    int estrellas = 0;

    // Ignorar bordes y procesar los elementos internos
    for (int i = 1; i < filas - 1; ++i) {
        for (int j = 1; j < columnas - 1; ++j) {
            if (esEstrella(matriz, filas, columnas, i, j)) {
                estrellas++;
            }
        }
    }
    
    return estrellas;
}

int main() {
    // Definir dimensiones de la matriz
    const int filas = 6;
    const int columnas = 8;

    // Crear matriz dinámica
    int** matriz = new int*[filas];
    for (int i = 0; i < filas; ++i) {
        matriz[i] = new int[columnas];
    }

    // Inicializar la matriz con los valores dados en el problema
    int valores[filas][columnas] = {
        {0, 3, 4, 0, 0, 0, 6, 8},
        {5, 13, 6, 0, 0, 2, 3, 0},
        {2, 6, 2, 7, 3, 0, 10, 0},
        {0, 0, 4, 15, 4, 1, 6, 0},
        {0, 0, 7, 12, 9, 6, 10, 4},
        {5, 0, 6, 10, 6, 4, 8, 0}
    };

    // Copiar valores a la matriz dinámica
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = valores[i][j];
        }
    }

    // Contar estrellas llamando a la función con el puntero a la matriz
    int totalEstrellas = contarEstrellas(matriz, filas, columnas);

    // Imprimir el resultado
    cout << "El número de estrellas encontradas en la imagen es: " << totalEstrellas << endl;

    // Liberar memoria
    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}
