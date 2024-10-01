#include <LiquidCrystal.h>

// Configuración de pines: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Denominaciones de billetes y monedas disponibles
int denominaciones[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
int cantidadDenominaciones = 10;  // Total de denominaciones

void setup() {
  // Inicializa la comunicación serial
  Serial.begin(9600);
  
  // Inicializa la pantalla LCD con 16 columnas y 2 filas
  lcd.begin(16, 2);
  
  // Limpia cualquier cosa en la pantalla LCD
  lcd.clear();
  
  // Mensaje inicial en el monitor serial y en la pantalla LCD
  lcd.setCursor(0, 0);
  lcd.print("Ingrese Cantidad:");
  Serial.println("Por favor, ingrese la cantidad de dinero deseada:");
}

void loop() {
  // Verifica si el usuario ha ingresado un valor por el Monitor Serial
  if (Serial.available() > 0) {
    // Lee la cantidad ingresada por el usuario
    int cantidad = Serial.parseInt();
    lcd.clear();  // Limpia el LCD antes de mostrar resultados
    lcd.setCursor(0, 0);
    lcd.print("Calculando...");

    // Variable para almacenar la cantidad que falta por completar
    int faltante = cantidad;
    
    // Arreglo para almacenar cuántos billetes/monedas se necesitan de cada denominación
    int resultado[cantidadDenominaciones];

    // Inicializa el resultado con ceros
    for (int i = 0; i < cantidadDenominaciones; i++) {
      resultado[i] = 0;
    }

    // Calcula la cantidad de billetes y monedas
    for (int i = 0; i < cantidadDenominaciones; i++) {
      if (faltante >= denominaciones[i]) {
        resultado[i] = faltante / denominaciones[i];  // Número de billetes/monedas
        faltante = faltante % denominaciones[i];      // Actualiza el faltante
      }
    }

    // Muestra los resultados en el Monitor Serial
    Serial.println("Cantidad desglosada en billetes y monedas:");
    for (int i = 0; i < cantidadDenominaciones; i++) {
      Serial.print(denominaciones[i]);
      Serial.print(": ");
      Serial.println(resultado[i]);
    }

    // Si hay algún faltante que no se puede cubrir con las denominaciones disponibles
    if (faltante > 0) {
      Serial.print("Faltante: ");
      Serial.println(faltante);
    } else {
      Serial.println("Faltante: 0");
    }

    // Muestra los resultados en el LCD (máximo 2 líneas)
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Total: ");
    lcd.print(cantidad);  // Muestra el total en la primera línea

    lcd.setCursor(0, 1);  // Segunda línea del LCD
    lcd.print("Faltante: ");
    lcd.print(faltante);  // Muestra el faltante (si lo hay)

    delay(5000);  // Mantiene el resultado en la pantalla LCD por 5 segundos antes de reiniciar

    // Mensaje para ingresar otra cantidad
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Ingrese Cantidad:");
    Serial.println("Por favor, ingrese otra cantidad de dinero:");
  }
}