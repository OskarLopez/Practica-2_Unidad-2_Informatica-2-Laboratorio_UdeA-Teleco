#include <iostream>

int main() {
    const int billetesMonedas[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50}; // Denominaciones
    const int numDenominaciones = sizeof(billetesMonedas) / sizeof(billetesMonedas[0]); // Número de denominaciones
    int cantidad; // Cantidad de dinero a convertir
    int contador[numDenominaciones] = {0}; // Contador de billetes y monedas

    std::cout << "Ingresa la cantidad de dinero a convertir: ";
    std::cin >> cantidad;

    // Almacenamos la cantidad original para la salida
    int cantidadOriginal = cantidad;

    // Calcular la cantidad de billetes y monedas
    for (int i = 0; i < numDenominaciones; i++) {
        if (cantidad >= billetesMonedas[i]) { // Si la cantidad es mayor o igual a la denominación
            contador[i] = cantidad / billetesMonedas[i]; // Calculamos cuántos billetes/monedas de esta denominación
            cantidad %= billetesMonedas[i]; // Actualizamos la cantidad restante
        }
    }

    // Imprimir el resultado
    std::cout << "Para la cantidad: " << cantidadOriginal << ", se requieren:" << std::endl;
    bool sePuedeLograr = false; // Variable para verificar si se logró la cantidad exacta

    for (int i = 0; i < numDenominaciones; i++) {
        if (contador[i] > 0) { // Solo imprimimos las denominaciones que se utilizan
            std::cout << "Denominación de $" << billetesMonedas[i] << ": " << contador[i] << std::endl;
            sePuedeLograr = true; // Se logró representar la cantidad
        }
    }

    // Si no se puede lograr la cantidad exacta
    if (cantidad > 0) {
        std::cout << "No se puede lograr la cantidad exacta. Resta: $" << cantidad << std::endl;
    } else if (!sePuedeLograr) {
        std::cout << "La cantidad ingresada es cero o no válida." << std::endl;
    }

    return 0;
}
