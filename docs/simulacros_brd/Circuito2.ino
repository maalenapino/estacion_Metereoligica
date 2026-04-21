// Definición de pines
const int pinSensor = A0;
const int pinLedCalor = 13; // Rojo
const int pinLedFrio = 12;  // Azul
void setup() {
  pinMode(pinLedCalor, OUTPUT);
  pinMode(pinLedFrio, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int lectura = analogRead(pinSensor);
  float voltaje = lectura * 5.0 / 1023.0;
  float temperatura = (voltaje - 0.5) * 100;
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");
  // --- ESTRUCTURA DE CONTROL DE TEMPERATURA ---  
  if (temperatura > 30) {
    // CASO 1: Hace mucho calor
    digitalWrite(pinLedCalor, HIGH);
    digitalWrite(pinLedFrio, LOW);
  } 
  else if (temperatura < 15) {
    // CASO 2: Hace mucho frío
    digitalWrite(pinLedCalor, LOW);
    digitalWrite(pinLedFrio, HIGH);
  } 
  else {
    // CASO 3: Temperatura normal (entre 15 y 30)
    digitalWrite(pinLedCalor, LOW);
    digitalWrite(pinLedFrio, LOW);
  }

  delay(1000); 
}
