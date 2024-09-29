#include <iostream>

void convertirMinusculasAMayusculas(char* cadena) {
    int i = 0;

    // Recorremos cada carácter de la cadena
    while (cadena[i] != '\0') {
        // Verificamos si el carácter es una letra minúscula
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            cadena[i] = cadena[i] - ('a' - 'A');  // Convertimos a mayúscula restando la diferencia entre 'a' y 'A'
        }
        i++;
    }
}

int main() {
    char cadena[100];  // Arreglo para almacenar la cadena ingresada por el usuario

    std::cout << "Ingresa una cadena de caracteres: ";
    std::cin.getline(cadena, 100);  // Usamos getline para permitir la entrada de cadenas con espacios

    convertirMinusculasAMayusculas(cadena);

    std::cout << "Cadena convertida a mayúsculas: " << cadena << std::endl;

    return 0;
}
