// Pin 2 del arduino
const int ledPin2 = 2;

// Pin 3 del arduino
const int ledPin3 = 3;

// Intervalo de parpadeo (1000ms = 1 segundo)

const int periodo1Hz = 1000; // 1 Hz = 1000 ms por ciclo
const int periodo2Hz = 500; //  2 Hz = 500 ms por ciclo


// Variable para guardar el tiempo del último parpadeo
// Debe ser unsigned long
unsigned long tiempoAnterior2 = 0;
unsigned long tiempoAnterior3 = 0;

// Estado actual del LED (0=LOW, 1=HIGH)
int estadoLed2 = LOW;
int estadoLed3 = LOW;

void setup() {
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {

  // -------------------------    [ Señal 1 de  1Hz ]   ---------------------------
  
  // Obtiene el tiempo "actual" en cada ciclo del loop
  unsigned long tiempoActual2 = millis();

  // Compara el tiempo actual con el tiempo guardado
  // (tiempoActual - tiempoAnterior2) es el tiempo que ha pasado
  if (tiempoActual2 - tiempoAnterior2 >= periodo1Hz / 2) {
    
    // Si ya pasó (periodo1Hz / 2), guarda este momento como el "tiempoAnterior2"
    tiempoAnterior2 = tiempoActual2;

    // E invierte el estado del LED
    if (estadoLed2 == LOW) {
      estadoLed2 = HIGH;
    } else {
      estadoLed2 = LOW;
    }
    
    // Actualiza el LED
    digitalWrite(ledPin2, estadoLed2);
  }



  // -------------------------    [ Señal 2 de  2Hz ]   ---------------------------
  
  // Obtiene el tiempo "actual" en cada ciclo del loop
  unsigned long tiempoActual3 = millis();

  // Compara el tiempo actual con el tiempo guardado
  // (tiempoActual3 - tiempoAnterior3) es el tiempo que ha pasado
  if (tiempoActual3 - tiempoAnterior3 >= periodo2Hz / 2) {
    
    // Si ya pasó (periodo2Hz / 2), guarda este momento como el "tiempoAnterior3"
    tiempoAnterior3 = tiempoActual3;

    // E invierte el estado del LED
    if (estadoLed3 == LOW) {
      estadoLed3 = HIGH;
    } else {
      estadoLed3 = LOW;
    }
    
    // Actualiza el LED
    digitalWrite(ledPin3, estadoLed3);
  }

  /**
   * Aqui puedes agregar otra señal a otro
   * pin del arduino por ejemplo el pin 4
  */  
}
