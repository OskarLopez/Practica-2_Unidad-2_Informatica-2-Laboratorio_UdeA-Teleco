#include <iostream>

// Función para calcular el número combinatorio C(2n, n) usando una fórmula directa
unsigned long long calcularCaminos(int n) {
    unsigned long long resultado = 1;

    // Cálculo de C(2n, n) usando una fórmula eficiente:
    // C(2n, n) = (2n * (2n-1) * ... * (n+1)) / (n * (n-1) * ... * 1)
    for (int i = 1; i <= n; ++i) {
        resultado *= (n + i);
        resultado /= i;
    }
    
    return resultado;
}

int main() {
    int n;
    
    // Solicitar al usuario el tamaño de la cuadrícula
    std::cout << "Introduce el tamaño de la cuadrícula (n): ";
    std::cin >> n;
    
    // Calcular el número de caminos posibles
    unsigned long long caminos = calcularCaminos(n);
    
    // Mostrar el resultado con el formato requerido
    std::cout << "Para una malla de " << n << "x" << n << " puntos hay " << caminos << " caminos." << std::endl;
    
    return 0;
}
