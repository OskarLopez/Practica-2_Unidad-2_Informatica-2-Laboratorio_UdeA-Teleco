#include <iostream>

int convertirCadenaAEntero(const char* cadena) {
    int numero = 0;
    int i = 0;
    
    // Verificar si la cadena tiene un signo negativo
    bool esNegativo = (cadena[0] == '-');
    if (esNegativo) {
        i = 1; // Si es negativo, empezamos desde el siguiente carácter
    }
    
    // Recorremos la cadena de caracteres
    for (; cadena[i] != '\0'; i++) {
        // Verificar si el carácter actual es un número
        if (cadena[i] < '0' || cadena[i] > '9') {
            std::cout << "Error: La cadena contiene caracteres no numéricos." << std::endl;
            return 0; // O podrías usar otro valor o lógica para manejar este caso
        }
        
        // Convertir el carácter a número
        numero = numero * 10 + (cadena[i] - '0');
    }
    
    // Si la cadena era negativa, ajustar el signo
    if (esNegativo) {
        numero = -numero;
    }
    
    return numero;
}

int main() {
    char cadena[100];
    
    std::cout << "Ingresa una cadena de caracteres numéricos: ";
    std::cin >> cadena;

    int resultado = convertirCadenaAEntero(cadena);
    if (resultado != 0 || cadena[0] == '0') {
        std::cout << "El número convertido es: " << resultado << std::endl;
    }

    return 0;
}
