#include <iostream>

void separarNumerosDeTexto(const char* cadena, char* texto, char* numeros) {
    int indiceTexto = 0;
    int indiceNumeros = 0;

    // Recorremos la cadena de entrada
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] >= '0' && cadena[i] <= '9') {
            // Si es un número, lo añadimos a la cadena de números
            numeros[indiceNumeros++] = cadena[i];
        } else {
            // Si no es un número, lo añadimos a la cadena de texto
            texto[indiceTexto++] = cadena[i];
        }
    }

    // Agregamos el carácter nulo ('\0') al final de ambas cadenas
    texto[indiceTexto] = '\0';
    numeros[indiceNumeros] = '\0';
}

int main() {
    char cadena[100];   // Cadena de caracteres original
    char texto[100];    // Cadena que almacenará solo los caracteres no numéricos
    char numeros[100];  // Cadena que almacenará solo los números

    std::cout << "Ingresa una cadena de caracteres: ";
    std::cin.getline(cadena, 100);  // Leer la cadena ingresada por el usuario

    // Llamamos a la función para separar texto y números
    separarNumerosDeTexto(cadena, texto, numeros);

    // Imprimimos los resultados
    std::cout << "Original: " << cadena << std::endl;
    std::cout << "Texto: " << texto << ". Numero: " << numeros << "." << std::endl;

    return 0;
}
