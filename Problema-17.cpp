#include <iostream>
using namespace std;

// Función que calcula la suma de divisores propios de un número
int sumaDivisoresPropios(int num) {
    int suma = 0;
    for (int i = 1; i <= num / 2; i++) { // Divisores propios menores que num
        if (num % i == 0) {
            suma += i;
        }
    }
    return suma;
}

// Función que encuentra y suma todos los números amigables menores que n
int sumaNumerosAmigables(int n) {
    int sumaTotal = 0;

    for (int a = 1; a < n; a++) {
        int b = sumaDivisoresPropios(a); // Encontrar suma de divisores de a
        // Verificamos que:
        // 1. b es diferente de a (no es un número perfecto)
        // 2. b es menor que n
        // 3. b es mayor que a (para evitar contar el mismo par dos veces)
        // 4. La suma de los divisores de b es igual a a (es decir, son un par amigable)
        if (b != a && b < n && b > a && sumaDivisoresPropios(b) == a) {
            cout << "Par amigable encontrado: " << a << " y " << b << endl;
            sumaTotal += a + b; // Sumamos ambos una sola vez
        }
    }
    return sumaTotal;
}

int main() {
    int n;

    // Solicitar al usuario el número límite
    cout << "Ingrese un numero: ";
    cin >> n;

    // Calcular y mostrar la suma de números amigables
    int resultado = sumaNumerosAmigables(n);
    cout << "El resultado de la suma es: " << resultado << endl;

    return 0;
}
