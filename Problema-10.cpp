#include <iostream>

// Función para obtener el valor arábigo de un carácter romano
int valorRomano(char c) {
    switch(c) {
        case 'M': return 1000;
        case 'D': return 500;
        case 'C': return 100;
        case 'L': return 50;
        case 'X': return 10;
        case 'V': return 5;
        case 'I': return 1;
        default: return 0; // Por si se introduce un carácter no válido
    }
}

// Función para convertir de números romanos a arábigos
int convertirRomanoArabigo(const char* romano) {
    int total = 0;
    int longitud = 0;

    // Calculamos la longitud de la cadena
    while (romano[longitud] != '\0') {
        longitud++;
    }

    // Recorremos la cadena de derecha a izquierda para aplicar las reglas de suma/resta
    for (int i = 0; i < longitud; i++) {
        int valorActual = valorRomano(romano[i]);
        int valorSiguiente = valorRomano(romano[i+1]);

        // Si el valor del carácter actual es mayor o igual que el siguiente, se suma
        if (valorActual >= valorSiguiente) {
            total += valorActual;
        } else {
            // Si el valor del carácter actual es menor que el siguiente, se resta
            total -= valorActual;
        }
    }

    return total;
}

int main() {
    char romano[100];  // Cadena para almacenar el número romano

    // Pedimos al usuario que introduzca un número en romano
    std::cout << "Ingresa un número en sistema romano: ";
    std::cin >> romano;

    // Convertimos el número romano a arábigo
    int resultado = convertirRomanoArabigo(romano);

    // Mostramos el resultado
    std::cout << "El número ingresado fue: " << romano << std::endl;
    std::cout << "Que corresponde a: " << resultado << std::endl;

    return 0;
}
