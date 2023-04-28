#include <NewPing.h>

#define echoPin 4
#define trigPin 3
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(trigPin, echoPin, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

const int BUZZER_PIN = 1;
const int BUZZER1_PIN = 0;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUZZER1_PIN, OUTPUT);
}

void loop() {
  delay(50); // Wait 50ms between pings (about 20 pings/s). 29ms should be the shortest delay between pings.

  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  unsigned int distance = uS / US_ROUNDTRIP_CM; // Convert ping time to distance (in cm).
  
  if (distance <= 125 && distance > 0) { // If distance is less than or equal to 125 cm
    int d = map(distance, 1, 200, 10, 600);
    digitalWrite(BUZZER_PIN, HIGH);  
    digitalWrite(BUZZER1_PIN, HIGH);   
    delay(50);   
    digitalWrite(BUZZER_PIN, LOW);   
    digitalWrite(BUZZER1_PIN, LOW);   
    delay(d);  
  } 
}
