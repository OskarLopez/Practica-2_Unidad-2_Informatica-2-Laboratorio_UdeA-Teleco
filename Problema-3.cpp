#include <iostream>

// Función que compara dos cadenas de caracteres
bool compararCadenas(const char* cadena1, const char* cadena2) {
    // Contar la longitud de ambas cadenas
    int i = 0;
    while (cadena1[i] != '\0') { // Recorre la primera cadena
        i++;
    }
    int longitud1 = i; // Longitud de la primera cadena

    i = 0;
    while (cadena2[i] != '\0') { // Recorre la segunda cadena
        i++;
    }
    int longitud2 = i; // Longitud de la segunda cadena

    // Si las longitudes son diferentes, las cadenas no son iguales
    if (longitud1 != longitud2) {
        return false;
    }

    // Compara cada carácter de ambas cadenas
    for (i = 0; i < longitud1; i++) {
        if (cadena1[i] != cadena2[i]) {
            return false; // Si hay una diferencia, las cadenas no son iguales
        }
    }

    return true; // Si no hay diferencias, las cadenas son iguales
}

int main() {
    const int tamaño = 100; // Tamaño máximo de las cadenas
    char cadena1[tamaño], cadena2[tamaño];

    // Solicitar las cadenas al usuario
    std::cout << "Ingresa la primera cadena: ";
    std::cin.getline(cadena1, tamaño); // Lee la primera cadena

    std::cout << "Ingresa la segunda cadena: ";
    std::cin.getline(cadena2, tamaño); // Lee la segunda cadena

    // Comparar las cadenas y mostrar el resultado
    if (compararCadenas(cadena1, cadena2)) {
        std::cout << "Las cadenas son iguales." << std::endl;
    } else {
        std::cout << "Las cadenas son diferentes." << std::endl;
    }

    return 0;
}
