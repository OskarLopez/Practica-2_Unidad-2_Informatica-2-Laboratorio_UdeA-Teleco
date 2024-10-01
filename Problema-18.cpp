#include <iostream>

using namespace std;

// Función para calcular el factorial de un número
int factorial(int número) {
    int resultado = 1;
    for (int i = 2; i <= número; i++) {
        resultado *= i;
    }
    return resultado;
}

// Función para calcular la enésima permutación lexicográfica
void permutación(int número) {
    int dígitos[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int valoresFactoriales[] = {factorial(9), factorial(8), factorial(7), factorial(6), factorial(5), factorial(4), factorial(3), factorial(2), factorial(1), factorial(0)};
    int índice = número - 1;

    for (int i = 0; i < 10; i++) {
        int valorFactorial = valoresFactoriales[i];
        int índiceDígito = índice / valorFactorial;
        índice %= valorFactorial;

        cout << dígitos[índiceDígito];
        for (int j = índiceDígito + 1; j < 10; j++) {
            dígitos[j - 1] = dígitos[j];
        }
    }
}

int main() {
    int número;
    cout << "Ingrese un número: ";
    cin >> número;

    permutación(número);

    return 0;
}
