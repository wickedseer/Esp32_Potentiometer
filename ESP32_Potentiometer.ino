#define POTENTIOMETER_PIN  34  // GPIO 34 (Analog pin)
#define RED_PIN            16  // GPIO 16
#define GREEN_PIN          17  // GPIO 17
#define BLUE_PIN           5 // GPIO 5
int potValue; // do not change
float voltage =0; // do not change

void setup() {
  Serial.begin(115200);
  pinMode(RED_PIN, OUTPUT); // set ESP32 pin to output mode
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  int analogValue = analogRead(POTENTIOMETER_PIN);      // read the input on analog pin
  float voltage = floatMap(analogValue, 0, 1023, 0, 5); // Rescale to potentiometer's voltage
  
  // read the input on analog pin:
  potValue = analogRead(POTENTIOMETER_PIN);
  voltage = (3.3/4095.0) * potValue;
  Serial.print("potValue:");
  Serial.print(potValue);
   
  Serial.print(" Voltage:");
  Serial.print(voltage);
  Serial.println("V");  
  delay(50); // delay in between reads for stability
  
  if (voltage > 0 && voltage <= 1.1) {
    digitalWrite(GREEN_PIN, LOW);  
    digitalWrite(BLUE_PIN, LOW);
    digitalWrite(RED_PIN, HIGH); // turn on Red LED
  }

  if (voltage > 1.1 && voltage <= 2.2){
    digitalWrite(RED_PIN, LOW); 
    digitalWrite(BLUE_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);  // turn on Green LED
  }

  if (voltage > 2.2 ){
    digitalWrite(RED_PIN, LOW); 
    digitalWrite(GREEN_PIN, LOW);  
    digitalWrite(BLUE_PIN, HIGH); // turn on Blue LED
  }

}

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
