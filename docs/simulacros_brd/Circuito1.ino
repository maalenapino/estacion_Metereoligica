// Definición de pines
const int pinSensor = A0;
const int pinLedAlerta = 13;

void setup() {
  pinMode(pinLedAlerta, OUTPUT);
  Serial.begin(9600); // Iniciamos comunicación serie para ver los datos
}
void loop() {
  // Leemos el valor analógico (0 a 1023)
  int lectura = analogRead(pinSensor);  
  // Convertimos a Voltaje y luego a Grados Celsius
  float voltaje = lectura * 5.0 / 1023.0;
  float temperatura = (voltaje - 0.5) * 100;
  // Mostramos en el Monitor Serie
  Serial.print("Temperatura actual: ");
  Serial.print(temperatura);
  Serial.println(" C");
  // Lógica de alerta: Si hace calor, se prende el LED
  if (temperatura > 30) {
    digitalWrite(pinLedAlerta, HIGH);
  } else {
    digitalWrite(pinLedAlerta, LOW);
  }
  delay(1000); // Esperamos 1 segundo entre lecturas
}
