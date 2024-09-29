#include <iostream>

int numeroAleatorio(int limite) {
    static int semilla = 1; // Semilla inicial
    semilla = (semilla + 1) % 100; // Incrementa la semilla y la mantiene dentro de un rango
    return semilla % limite; // Retorna un número dentro del rango deseado
}

int main() {
    const int tamaño = 200; // Tamaño del arreglo
    char letras[tamaño]; // Arreglo para almacenar letras mayúsculas
    int contador[26] = {0}; // Contador para cada letra (A-Z)

    // Generamos letras mayúsculas aleatorias
    for (int i = 0; i < tamaño; i++) {
        letras[i] = 'A' + numeroAleatorio(26); // Generamos una letra aleatoria entre A y Z
    }

    // Imprimimos el arreglo generado
    std::cout << "Arreglo generado: ";
    for (int i = 0; i < tamaño; i++) {
        std::cout << letras[i]; // Imprimimos cada letra
    }
    std::cout << std::endl;

    // Contamos la frecuencia de cada letra
    for (int i = 0; i < tamaño; i++) {
        contador[letras[i] - 'A']++; // Incrementamos el contador correspondiente
    }

    // Imprimimos el conteo de cada letra
    std::cout << "Frecuencia de letras:" << std::endl;
    for (int i = 0; i < 26; i++) {
        if (contador[i] > 0) { // Solo imprimimos letras que aparecen al menos una vez
            std::cout << static_cast<char>('A' + i) << ": " << contador[i] << std::endl;
        }
    }

    return 0;
}
