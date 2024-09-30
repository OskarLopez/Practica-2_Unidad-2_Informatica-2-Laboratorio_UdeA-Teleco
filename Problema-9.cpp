#include <iostream>
#include <string>

int sumarNumerosPorNCifras(const char* cadena, int n, std::string& desglose) {
    int longitud = 0, suma = 0;
    int numeroActual = 0;
    bool esPrimerGrupo = true; // Para controlar si agregamos el signo '+'

    // Calculamos la longitud de la cadena
    while (cadena[longitud] != '\0') {
        longitud++;
    }

    // Calculamos cuántos ceros debemos agregar si la longitud no es múltiplo de n
    int cerosAAgregar = n - (longitud % n);
    if (cerosAAgregar == n) {
        cerosAAgregar = 0; // Si es múltiplo exacto, no agregamos ceros
    }

    // Agregamos los ceros iniciales si es necesario
    for (int i = 0; i < cerosAAgregar; i++) {
        if (esPrimerGrupo) {
            desglose += '0';
            esPrimerGrupo = false;
        } else {
            desglose += '0';
        }
        numeroActual = numeroActual * 10;  // Los ceros a la izquierda no afectan el valor del número
    }

    // Recorremos la cadena original
    for (int i = 0; i < longitud; i++) {
        numeroActual = numeroActual * 10 + (cadena[i] - '0');  // Convertimos el carácter a número
        desglose += cadena[i];  // Agregamos el dígito al desglose

        // Cada vez que completamos n dígitos, sumamos el número y reiniciamos el número actual
        if ((i + cerosAAgregar + 1) % n == 0) {
            suma += numeroActual;
            numeroActual = 0;

            // Agregamos el signo '+' para el siguiente grupo
            if (i + 1 != longitud) {
                desglose += '+';
            }
        }
    }

    return suma;
}

int main() {
    int n;
    char cadena[100];  // Cadena de caracteres numéricos
    std::string desglose = "";  // Para mostrar los números separados por '+'

    std::cout << "Ingresa el valor de n: ";
    std::cin >> n;

    std::cout << "Ingresa una cadena de caracteres numéricos: ";
    std::cin >> cadena;  // Leemos la cadena de caracteres

    int suma = sumarNumerosPorNCifras(cadena, n, desglose);

    // Imprimimos el resultado
    std::cout << "Original: " << cadena << "." << std::endl;
    std::cout << "Suma: " << desglose << "=" << suma << "." << std::endl;

    return 0;
}
