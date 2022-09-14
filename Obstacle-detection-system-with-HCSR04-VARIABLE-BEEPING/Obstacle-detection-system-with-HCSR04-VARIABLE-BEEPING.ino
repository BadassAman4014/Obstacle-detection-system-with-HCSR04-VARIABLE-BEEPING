  #define echoPin 4
  #define trigPin 3
  int buz=1;
  int buz1=0; 
  void setup() 
  {   
  pinMode(buz, OUTPUT);   
  pinMode(buz1, OUTPUT);   
  }   
  void loop()   
  {   
  long duration, cm;   
  pinMode(trigPin, OUTPUT);   
  digitalWrite(trigPin, LOW);   
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);   
  delayMicroseconds(5);   
  digitalWrite(trigPin, LOW);   
  pinMode(echoPin , INPUT);   
  duration = pulseIn(echoPin, HIGH);   
  cm = microsecondsToCentimeters(duration);   
  if(cm<=125 && cm>0)   
  {   
  int d= map(cm, 1, 200, 10, 600);   
  digitalWrite(buz, HIGH);  
  digitalWrite(buz1, HIGH);   
  delay(50);   
  digitalWrite(buz, LOW);   
  digitalWrite(buz1, LOW);   
  delay(d);  
  }   
  delay(40);   
  }   
  long microsecondsToCentimeters(long microseconds)   
  {   
  return microseconds / 29 / 2;   
  }   
