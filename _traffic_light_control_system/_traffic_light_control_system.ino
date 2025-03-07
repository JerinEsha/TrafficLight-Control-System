
// Define pin numbers for traffic lights
int red1 = 2;
int yellow1 = 3;
int green1 = 4;
int red2 = 5;
int yellow2 = 6;
int green2 = 7;
int red3 = 8;
int yellow3 = 9;
int green3 = 10;
int red4 = 11;
int yellow4 = 12;
int green4 = 13;

// IR sensor pins
int ir1 = A0;
int ir2 = A1;
int ir3 = A2;
int ir4 = A3;

// LDR pin
const int ldrPin = A4;  // LDR connected to A4
const int ledPin = A5;  // Common rail for all LEDs

void setup() {
  // Initialize traffic light pins as OUTPUT
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(red3, OUTPUT);
  pinMode(yellow3, OUTPUT);
  pinMode(green3, OUTPUT);
  pinMode(red4, OUTPUT);
  pinMode(yellow4, OUTPUT);
  pinMode(green4, OUTPUT);

  // Initialize IR sensor pins as INPUT
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);

  // Initialize LED pin as OUTPUT
  pinMode(ledPin, OUTPUT); 
  digitalWrite(ledPin, LOW); // Ensure LEDs are initially off

  // Initialize LDR pin as INPUT
  pinMode(ldrPin, INPUT);
  
  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  controlLEDs(); // Control the LEDs based on LDR
  changeLights(); // Change traffic lights based on IR sensors
}

void controlLEDs() {
  int ldrValue = digitalRead(ldrPin); // Read the LDR value as digital (0 or 1)
  
  Serial.println(ldrValue); // Print the LDR value to the serial monitor

  // If LDR value is LOW (dark), turn on LEDs
  if (ldrValue == LOW) { 
    digitalWrite(ledPin, LOW); // Turn on all LEDs (lights on)
  } else {
    digitalWrite(ledPin, HIGH); // Turn off all LEDs (lights off)
  }
}

void changeLights() {
  // Check if IR sensors 1 or 3 detect an object
  if (digitalRead(ir1) == LOW || digitalRead(ir3) == LOW) {
    // If object is detected by either sensor
    digitalWrite(green1, HIGH);   // 1st road green
    digitalWrite(yellow1, LOW);
    digitalWrite(red1, LOW);
    
    digitalWrite(green3, HIGH);   // 3rd road green
    digitalWrite(yellow3, LOW);
    digitalWrite(red3, LOW);
    
    digitalWrite(red2, HIGH);      // 2nd road red
    digitalWrite(yellow2, LOW);
    digitalWrite(green2, LOW);
    
    digitalWrite(red4, HIGH);      // 4th road red
    digitalWrite(yellow4, LOW);
    digitalWrite(green4, LOW);
    
    delay(15000); // Keep green for 1st and 3rd roads for 15 seconds
    return; // Exit the function to avoid executing the normal sequence
  }

  // Check if IR sensors 2 or 4 detect an object
  if (digitalRead(ir2) == LOW || digitalRead(ir4) == LOW) {
    // If object is detected by either sensor
    digitalWrite(green2, HIGH);   // 2nd road green
    digitalWrite(yellow2, LOW);
    digitalWrite(red2, LOW);
    
    digitalWrite(green4, HIGH);   // 4th road green
    digitalWrite(yellow4, LOW);
    digitalWrite(red4, LOW);
    
    digitalWrite(red1, HIGH);      // 1st road red
    digitalWrite(yellow1, LOW);
    digitalWrite(green1, LOW);
    
    digitalWrite(red3, HIGH);      // 3rd road red
    digitalWrite(yellow3, LOW);
    digitalWrite(green3, LOW);
    
    delay(15000); // Keep green for 2nd and 4th roads for 15 seconds
    return; // Exit the function to avoid executing the normal sequence
  }
  
  // Normal traffic light sequence if no object is detected
  digitalWrite(green1, LOW);
  digitalWrite(yellow1, HIGH);
  digitalWrite(red1, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(yellow2, HIGH);
  digitalWrite(red2, LOW);
  digitalWrite(green3, LOW);
  digitalWrite(yellow3, HIGH);
  digitalWrite(red3, LOW);
  digitalWrite(green4, LOW);
  digitalWrite(yellow4, HIGH);
  digitalWrite(red4, LOW);
  delay(3000);

  digitalWrite(yellow1, LOW);
  digitalWrite(green1, HIGH);
  digitalWrite(red1, LOW);
  digitalWrite(yellow2, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(yellow3, LOW);
  digitalWrite(green3, HIGH);
  digitalWrite(red3, LOW);
  digitalWrite(yellow4, LOW);
  digitalWrite(green4, LOW);
  digitalWrite(red4, HIGH);
  delay(5000);

  digitalWrite(yellow1, HIGH);
  digitalWrite(red1, LOW);
  digitalWrite(green1, LOW);
  digitalWrite(yellow2, HIGH);
  digitalWrite(red2, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(yellow3, HIGH);
  digitalWrite(red3, LOW);
  digitalWrite(green3, LOW);
  digitalWrite(yellow4, HIGH);
  digitalWrite(red4, LOW);
  digitalWrite(green4, LOW);
  delay(3000);

  digitalWrite(red1, HIGH);
  digitalWrite(yellow1, LOW);
  digitalWrite(green1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(yellow2, LOW);
  digitalWrite(green2, HIGH);
  digitalWrite(red3, HIGH);
  digitalWrite(yellow3, LOW);
  digitalWrite(green3, LOW);
  digitalWrite(red4, LOW);
  digitalWrite(yellow4, LOW);
  digitalWrite(green4, HIGH);
  delay(5000);
}


