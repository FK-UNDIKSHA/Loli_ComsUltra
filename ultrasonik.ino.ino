#define ECHOPIN 9
#define TRIGPIN 8
int HT;
float distance = 0.0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ECHOPIN,INPUT);
  pinMode(TRIGPIN,OUTPUT);
  //pinMode(led,OUTPUT);
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
  distance = pulseIn(ECHOPIN,HIGH);
  distance = (distance*0.0343)/2;
  int body = (181-distance);
  int H2=HT-distance;
  Serial.println(H2);

}
