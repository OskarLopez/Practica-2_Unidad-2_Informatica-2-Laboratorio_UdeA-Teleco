#include <iostream>
#include <array>
#include <sstream> // Para usar std::istringstream

// Función para encontrar la intersección entre dos rectángulos
std::array<int, 4> interseccionRectangulos(const std::array<int, 4>& A, const std::array<int, 4>& B) {
    // Coordenadas de la esquina superior izquierda del rectángulo C
    int xC = std::max(A[0], B[0]);
    int yC = std::max(A[1], B[1]);
    
    // Coordenadas de la esquina inferior derecha del rectángulo C
    int xC2 = std::min(A[0] + A[2], B[0] + B[2]);
    int yC2 = std::min(A[1] + A[3], B[1] + B[3]);
    
    // Verificamos si hay intersección
    if (xC2 > xC && yC2 > yC) {
        int anchoC = xC2 - xC;
        int altoC = yC2 - yC;
        return {xC, yC, anchoC, altoC}; // Retorna el rectángulo intersección C
    } else {
        // No hay intersección, retornamos un rectángulo vacío
        return {0, 0, 0, 0};
    }
}

// Función para leer un arreglo de 4 elementos desde una sola línea
std::array<int, 4> leerRectangulo(const std::string& mensaje) {
    std::array<int, 4> rectangulo;
    std::string entrada;
    
    std::cout << mensaje;
    std::getline(std::cin, entrada); // Leer toda la línea de entrada

    // Usamos std::istringstream para dividir la entrada por espacios
    std::istringstream stream(entrada);
    for (int i = 0; i < 4; ++i) {
        stream >> rectangulo[i]; // Leer cada valor en el arreglo
    }
    
    return rectangulo;
}

int main() {
    // Leemos los valores de los rectángulos A y B en una sola línea
    std::array<int, 4> A = leerRectangulo("Introduce los valores del rectángulo A (x, y, ancho, alto): ");
    std::array<int, 4> B = leerRectangulo("Introduce los valores del rectángulo B (x, y, ancho, alto): ");
    
    // Encontramos la intersección
    std::array<int, 4> C = interseccionRectangulos(A, B);
    
    // Mostramos el resultado
    if (C[2] == 0 || C[3] == 0) {
        std::cout << "No hay intersección entre los rectángulos A y B." << std::endl;
    } else {
        std::cout << "Rectángulo intersección C: {"
                  << C[0] << ", " << C[1] << ", " << C[2] << ", " << C[3] << "}" << std::endl;
    }
    
    return 0;
}
