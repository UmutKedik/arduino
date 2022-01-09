//defining pins
int trigPin = 2; //common trig pin
int sens1echoPin = 3; //Sensor 1 group 1
int sens2echoPin = 4; //Sensor 2 group 1
int sens3echoPin = 5; //Sensor 3 group 1

int sens4echoPin = 6; //Sensor 4 group 2
int sens5echoPin = 7; //Sensor 5 group 2
int sens6echoPin = 8; //Sensor 6 group 2
int sens7echoPin = 9; //Sensor 7 group 2

int sens8echoPin = 10; //Sensor 8 group 3
int sens9echoPin = 11; //Sensor 9 group 3
int sens10echoPin = 12; //Sensor 10 group 3
int sens11echoPin = 13; //Sensor 11 group 3

float durationSens1, distanceSens1;
float durationSens2, distanceSens2;
float durationSens3, distanceSens3;
float durationSens4, distanceSens4;
float durationSens5, distanceSens5;
float durationSens6, distanceSens6;
float durationSens7, distanceSens7;
float durationSens8, distanceSens8;
float durationSens9, distanceSens9;
float durationSens10, distanceSens10;
float durationSens11, distanceSens11;
float minGroup1, minGroup2, minGroup3;

void setup() {
  Serial.begin(9600);
  //output-input assignments of pins 
  pinMode(trigPin, OUTPUT);
  pinMode(sens1echoPin, INPUT);
  pinMode(sens2echoPin, INPUT);
  pinMode(sens3echoPin, INPUT);
  pinMode(sens4echoPin, INPUT);
  pinMode(sens5echoPin, INPUT);
  pinMode(sens6echoPin, INPUT);
  pinMode(sens7echoPin, INPUT);
  pinMode(sens8echoPin, INPUT);
  pinMode(sens9echoPin, INPUT);
  pinMode(sens10echoPin, INPUT);
  pinMode(sens11echoPin, INPUT);

  //group 1 resistor selection
  for (int i = 14; i < 24; i++)
    pinMode(i, OUTPUT);
  //group 1 resistor selection end

  //group 2 resistor selection
  for (int j = 24; j < 34; j++)
    pinMode(j, OUTPUT);
  //group 2 resistor selection end

  //group 3 resistor selection start
  for (int k = 34; k < 44; k++)
    pinMode(k, OUTPUT);
  //group 3 resistor selection end
}

void loop() {
  //trigger pin activation and conversion to distance
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20); 
  durationSens1 = pulseIn(sens1echoPin, HIGH);
  distanceSens1 = (durationSens1 / 2) * 0.000343; //343 meter per second speed of light
  delay(30);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  durationSens2 = pulseIn(sens2echoPin, HIGH);
  distanceSens2 = (durationSens2 / 2) * 0.000343;
  delay(30);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  durationSens3 = pulseIn(sens3echoPin, HIGH);
  distanceSens3 = (durationSens3 / 2) * 0.000343;
  delay(30);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  durationSens4 = pulseIn(sens4echoPin, HIGH);
  distanceSens4 = (durationSens4 / 2) * 0.000343;
  delay(30);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  durationSens5 = pulseIn(sens5echoPin, HIGH);
  distanceSens5 = (durationSens5 / 2) * 0.000343;
  delay(30);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  durationSens6 = pulseIn(sens6echoPin, HIGH);
  distanceSens6 = (durationSens6 / 2) * 0.000343;
  delay(30);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  durationSens7 = pulseIn(sens7echoPin, HIGH);
  distanceSens7 = (durationSens7 / 2) * 0.000343;
  delay(30);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  durationSens8 = pulseIn(sens8echoPin, HIGH);
  distanceSens8 = (durationSens8 / 2) * 0.000343;
  delay(30);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  durationSens9 = pulseIn(sens9echoPin, HIGH);
  distanceSens9 = (durationSens9 / 2) * 0.000343;
  delay(30);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  durationSens10 = pulseIn(sens10echoPin, HIGH);
  distanceSens10 = (durationSens10 / 2) * 0.000343;
  delay(30);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  durationSens11 = pulseIn(sens11echoPin, HIGH);
  distanceSens11 = (durationSens11 / 2) * 0.000343;
  delay(30);

  minGroup1 = min(distanceSens1, min(distanceSens2, distanceSens3));  //group 1 selecting minimum sensor distance
  minGroup2 = min(distanceSens4, min(distanceSens5, min(distanceSens6, distanceSens7))); //group 2 selecting minimum sensor distance
  minGroup3 = min(distanceSens8, min(distanceSens9, min(distanceSens10, distanceSens11))); //group 3 selecting minimum sensor distance

  Serial.print("Group 1 minimum distance: ");
  Serial.print(minGroup1);
  Serial.println(" meter");


  Serial.print("Group 2 minimum distance: ");
  Serial.print(minGroup2);
  Serial.println(" meter");


  Serial.print("Group 3 minimum distance: ");
  Serial.print(minGroup3);
  Serial.println(" meter");

  
  //group 1 resistor selector by distance 
  int ledCount1 = mapd(minGroup1, 0, 4, 0, 10); //converting 0-4 meter to 0-10 V
  for (int i = 14; i < 24; i++)
    digitalWrite(i, LOW);
  for (int i = 14; i < ledCount1 + 14; i++)
    digitalWrite(i, HIGH);

  //group 3 resistor selector by distance 
  int ledCount2 = mapd(minGroup2, 0, 4, 0, 10); //converting 0-4 meter to 0-10 V
  for (int j = 24; j < 34; j++)
    digitalWrite(j, LOW);
  for (int j = 24; j < ledCount2 + 24; j++)
    digitalWrite(j, HIGH);

  //group 3 resistor selector by distance  
  int ledCount3 = mapd(minGroup3, 0, 4, 0, 10); //converting 0-4 meter to 0-10 V
  for (int k = 34; k < 44; k++)
    digitalWrite(k, LOW);
  for (int k = 34; k < ledCount3 + 34; k++)
    digitalWrite(k, HIGH);
  delay(100);

}
double mapd(double x, double in_min, double in_max, double out_min, double out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
