#include <iostream>
#include <vector>
#include <cctype>  // Para usar la función toupper()

using namespace std;

const int FILAS = 15;
const int ASIENTOS_POR_FILA = 20;

// Función que muestra el estado actual de la sala
void mostrarSala(const vector<vector<char>>& sala) {
    cout << "  ";
    for (int i = 1; i <= ASIENTOS_POR_FILA; ++i) {
        if (i < 10) cout << " ";
        cout << i << " ";
    }
    cout << endl;
    
    for (int i = 0; i < FILAS; ++i) {
        cout << char('A' + i) << " ";
        for (int j = 0; j < ASIENTOS_POR_FILA; ++j) {
            cout << sala[i][j] << "  ";
        }
        cout << endl;
    }
}

// Función que cuenta cuántos asientos están reservados en total
bool salaLlena(const vector<vector<char>>& sala) {
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < ASIENTOS_POR_FILA; ++j) {
            if (sala[i][j] == '-') {
                return false; // Si encuentra un asiento disponible, la sala no está llena
            }
        }
    }
    return true; // Si no encontró ninguno disponible, la sala está llena
}

// Función para reservar asiento
void reservarAsiento(vector<vector<char>>& sala, char fila, int asiento) {
    int filaIndex = toupper(fila) - 'A'; // Convertir fila a mayúscula y luego a índice
    if (sala[filaIndex][asiento - 1] == '-') {
        sala[filaIndex][asiento - 1] = '+';
        cout << "Asiento reservado exitosamente.\n";
    } else {
        cout << "El asiento ya está reservado: " << fila << asiento << ".\n";
    }
}

// Función para cancelar una reserva
void cancelarReserva(vector<vector<char>>& sala, char fila, int asiento) {
    int filaIndex = toupper(fila) - 'A'; // Convertir fila a mayúscula y luego a índice
    if (sala[filaIndex][asiento - 1] == '+') {
        sala[filaIndex][asiento - 1] = '-';
        cout << "Reserva cancelada exitosamente.\n";
    } else {
        cout << "El asiento ya está disponible.\n";
    }
}

int main() {
    vector<vector<char>> sala(FILAS, vector<char>(ASIENTOS_POR_FILA, '-'));
    char opcion;
    char fila;
    int asiento;

    do {
        cout << "\n--- Gestion de Reservas ---\n";
        mostrarSala(sala);

        // Verificar si la sala está completamente llena
        if (salaLlena(sala)) {
            cout << "La sala está completamente llena.\n";
            break;  // Salir del ciclo porque ya no se pueden hacer más reservas
        }

        cout << "Seleccione una opcion:\n";
        cout << "1. Reservar asiento\n";
        cout << "2. Cancelar reserva\n";
        cout << "3. Salir\n";
        cin >> opcion;

        switch (opcion) {
            case '1':
                do {
                    cout << "Ingrese la fila (A-O o a-o): ";
                    cin >> fila;
                    fila = toupper(fila);
                } while (fila < 'A' || fila > 'O');  // Verificar que la fila esté dentro del rango

                do {
                    cout << "Ingrese el numero del asiento (1-20): ";
                    cin >> asiento;
                } while (asiento < 1 || asiento > 20);  // Verificar que el asiento esté dentro del rango

                reservarAsiento(sala, fila, asiento);
                break;
            case '2':
                do {
                    cout << "Ingrese la fila (A-O o a-o): ";
                    cin >> fila;
                    fila = toupper(fila);
                } while (fila < 'A' || fila > 'O');  // Verificar que la fila esté dentro del rango

                do {
                    cout << "Ingrese el numero del asiento (1-20): ";
                    cin >> asiento;
                } while (asiento < 1 || asiento > 20);  // Verificar que el asiento esté dentro del rango

                cancelarReserva(sala, fila, asiento);
                break;
            case '3':
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
                break;
        }
    } while (opcion != '3');

    return 0;
}
