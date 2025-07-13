#include <LiquidCrystal.h>

// LCD pin configuration: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Sensor pins
const int tempPin   = A0;  // TMP36
const int soilPin   = A1;  // Soil moisture
const int gasPin    = A2;  // Potentiometer simulating gas sensor
const int tiltPin   = 7;   // Tilt sensor
const int buzzerPin = 8;   // Buzzer

void setup() {
  lcd.begin(16, 2);
  pinMode(tiltPin, INPUT_PULLUP); // assuming 2-pin tilt sensor
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // --- Temperature Reading (TMP36) ---
  int tempRaw = analogRead(tempPin);
  float voltage = tempRaw * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100.0;

  // --- Soil Moisture ---
  int soilValue = analogRead(soilPin);

  // --- Gas Sensor (potentiometer) ---
  int gasValue = analogRead(gasPin);

  // --- Tilt Sensor ---
  bool tilted = digitalRead(tiltPin) == LOW;

  // --- Buzzer Logic ---
  if (soilValue < 400 || gasValue > 500 || tilted) {
    tone(buzzerPin, 2000, 500);
  }

  // --- LCD Display ---
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature, 1);
  lcd.print("C G:");
  lcd.print(gasValue / 10); // scaled for LCD width

  lcd.setCursor(0, 1);
  lcd.print("S:");
  lcd.print(soilValue < 400 ? "Dry " : "Wet ");
  lcd.print("T:");
  lcd.print(tilted ? "Yes" : "No ");

  delay(2000);
}
