#define ECHOPIN 7
#define TRIGPIN 8
void setup() {
  // put your setup code here, to run once:
  pinMode(ECHOPIN,INPUT);
  pinMode(TRIGPIN,OUTPUT);
  pinMode(led,OUTPUT);
  delay(1000);
  HT = 200;

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIGPIN,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,LOW);
  int distance = pulseIn(ECHOPIN,HIGH);
  distance = distance/58;
  H2=HT-distance;
  Serial.print(H2);

}
