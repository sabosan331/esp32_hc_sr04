
// PIN number
const int trigPin = 2;
const int echoPin = 5;
const int moterPIN1 = 4;
const int moterPIN2 = 15;

// for mesure distance
long duration;
int distance;

int measure_distance() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  return distance;
}

void setup()
{ 
  pinMode(trigPin, OUTPUT); // for sensor
  pinMode(echoPin, INPUT);   
  pinMode(moterPIN1,OUTPUT); // for motor
  pinMode(moterPIN2,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int distance = measure_distance();
  if(distance < 10){
      digitalWrite(moterPIN1,LOW);
      digitalWrite(moterPIN2,LOW);
  }else{
    digitalWrite(moterPIN1,HIGH);
    digitalWrite(moterPIN2,LOW);
  }
}
