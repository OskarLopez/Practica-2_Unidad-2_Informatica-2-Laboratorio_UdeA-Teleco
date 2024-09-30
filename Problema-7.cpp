#include <iostream>

void eliminarCaracteresRepetidos(char* cadena) {
    int i = 0, j, k;

    // Recorremos cada carácter de la cadena
    while (cadena[i] != '\0') {
        j = i + 1;  // j es el índice del siguiente carácter a comparar

        // Comparamos el carácter actual con los siguientes
        while (cadena[j] != '\0') {
            if (cadena[i] == cadena[j]) {
                // Si encontramos un carácter repetido, desplazamos los caracteres hacia la izquierda
                k = j;
                while (cadena[k] != '\0') {
                    cadena[k] = cadena[k + 1];
                    k++;
                }
            } else {
                j++;  // Si no son iguales, avanzamos al siguiente carácter
            }
        }

        i++;  // Avanzamos al siguiente carácter en la cadena
    }
}

int main() {
    char cadena[100];  // Arreglo para almacenar la cadena de caracteres

    std::cout << "Ingresa una cadena de caracteres: ";
    std::cin.getline(cadena, 100);  // Leer la cadena de caracteres ingresada por el usuario

    eliminarCaracteresRepetidos(cadena);

    std::cout << "Cadena sin caracteres repetidos: " << cadena << std::endl;

    return 0;
}
