#include <iostream>

void convertirEnteroACadena(int numero, char* cadena) {
    int i = 0; // Índice para recorrer la cadena
    bool esNegativo = false;

    // Verificar si el número es negativo
    if (numero < 0) {
        esNegativo = true;
        numero = -numero;  // Hacemos el número positivo para facilitar la conversión
    }

    // Convertimos el número a cadena de caracteres
    do {
        cadena[i++] = (numero % 10) + '0';  // Extraemos el último dígito y lo convertimos a carácter
        numero /= 10;  // Eliminamos el último dígito del número
    } while (numero > 0);

    // Si el número era negativo, agregamos el signo menos
    if (esNegativo) {
        cadena[i++] = '-';
    }

    cadena[i] = '\0';  // Agregamos el carácter nulo al final de la cadena

    // Invertimos la cadena para obtener el número en el orden correcto
    for (int j = 0, k = i - 1; j < k; j++, k--) {
        std::swap(cadena[j], cadena[k]);
    }
}

int main() {
    int numero;
    char cadena[100];  // Arreglo para almacenar la cadena de caracteres

    std::cout << "Ingresa un número entero: ";
    std::cin >> numero;

    convertirEnteroACadena(numero, cadena);

    std::cout << "El número convertido a cadena es: " << cadena << std::endl;

    return 0;
}
