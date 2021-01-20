#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
#define LED 8 //attach pin D9 Arduino to the LED Anode
#define trigger 6

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
bool triggered= false;//variable to indicate triggered status



void setup() {
  pinMode(LED, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Security Camera Project"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  // the if statement checks if there is an object within 50 cm from the sensor
  if (distance <= 50 && triggered==false){
    analogWrite(LED, 255);
    triggered = true;
    digitalWrite(trigger, HIGH);
  }else if(distance >=50 && triggered== true){
    triggered = false;          // whenecer its not within 50 cm it sets triggered to false
    digitalWrite(trigger, LOW);
    analogWrite(LED, 0);
  }
  
}
