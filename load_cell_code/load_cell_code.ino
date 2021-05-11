#include "HX711.h"
 
// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 4;
const int LOADCELL_SCK_PIN = 5;
 
HX711 scale;
 
void setup() {
  Serial.begin(57600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}
 
void loop() {
 
  if (scale.is_ready()) {
    long reading = (scale.read()*480)+15000.0 ;
    float grams = (float)reading / 10000.0;
    grams = (grams +1500.0)/1000.0;
    Serial.print("HX711 reading: ");
    Serial.print(grams);
    Serial.println(" kg");
  } else {
    Serial.println("HX711 not found.");
  }
 
  delay(1000);
}
  
