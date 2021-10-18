/*
####################################################
#THIS IS DEPRECATED, NEW VERSION In serialData.ino  #
#####################################################
*/
#define ECHOPIN 10
#define TRIGPIN 9
int HT;
int state_ultra = 0;
String berat;
float distance = 0.0;
String y = "";
void setup() {
 Serial.begin(9600);
 pinMode(ECHOPIN,INPUT);
 pinMode(TRIGPIN,OUTPUT);
 //pinMode(led,OUTPUT);
 //delay(1000);
 HT = 200;
 //Serial.setTimeout(1);
}
void loop() {
  while (Serial.available()){
    String x = Serial.readString();
    //Serial.println(x);
    x.trim();
   y = y+x;
  }

  //Serial.print(y);
  if (y == "tinggi"){
    digitalWrite(TRIGPIN,LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGPIN,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGPIN,LOW);
    distance = pulseIn(ECHOPIN,HIGH);
    distance = (distance*0.0343)/2;
    int body = (181-distance);
    int H2=HT-distance;
    //delay(3000);
    Serial.print(H2);
    y = "";
    H2 = -1;
  }
  // i know this potentially buffer overflow and other bugs, (REMEMBER THIS IS PROTOTYPE)
  else if (y.startsWith("pesan;")){
    //do parsing
    for (int l=0;l<=y.length();l++){
      //Serial.println(y[l]);
      if(String(y[l]) == ";"){
        //Serial.print("YA");
        for(int k=l+1;k<=y.length();k++){
            berat = berat + String(y[k]);
            //berat.trim();
          }
          Serial.print(berat);
          break;
        }
       }
       y="";
     }
  else{
  y="";}
}
