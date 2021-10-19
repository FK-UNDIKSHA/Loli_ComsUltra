#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);

#define ECHOPIN 10
#define TRIGPIN 9
int HT;
int state_ultra = 0;
String berat;
String berat2;
float distance = 0.0;
String y = "";
void setup() {
 Serial.begin(9600);
 lcd.begin(16, 2);
 pinMode(ECHOPIN,INPUT);
 pinMode(TRIGPIN,OUTPUT);
 //pinMode(led,OUTPUT);
 //delay(1000);
 HT = 198;
 lcd.setBacklight(255);
 lcd.home(); lcd.clear();
 lcd.print("Starting System...");
 delay(1000);
 lcd.clear();
 lcd.setCursor(00, 0);
 lcd.print("    Welcome");
 lcd.setCursor(00, 1);
 lcd.print("Waiting Input...");
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
  else if (y.startsWith("pesan1;")){
    int angka1 = 0;
    //do parsing
    for (int l=0;l<=y.length();l++){
      //Serial.println(y[l]);
      if(String(y[l]) == ";"){
        //Serial.print("YA");
        for(int k=l+1;k<=y.length();k++){
            berat = berat + String(y[k]);
            angka1++;
            //berat.trim();
          }
          Serial.print(berat);
          lcd.setCursor(00, 00);
          lcd.print(berat);
          for(int zelda=angka1-1; zelda<=20;zelda++){
            lcd.setCursor(zelda,0);
            lcd.print(" ");
          }
          //lcd.clear();
          break;
        }
       }
       y="";
       berat="";
     }
  else if (y.startsWith("pesan2;")){
    //do parsing
    int angka2=0;
    for (int l=0;l<=y.length();l++){
      //Serial.println(y[l]);
      if(String(y[l]) == ";"){
        //Serial.print("YA");
        for(int k=l+1;k<=y.length();k++){
            berat2 = berat2 + String(y[k]);
            angka2++;
            //berat.trim();
          }
          Serial.print(berat2);
          lcd.setCursor(00, 1);
          lcd.print(berat2);
          for(int zelda=angka2-1; zelda<=20;zelda++){
            lcd.setCursor(zelda,1);
            lcd.print(" ");
          }
          //lcd.clear();
          //lcd.print(berat2);
          break;
        }
       }
       y="";
       berat2="";
     }
  else if (y.startsWith("clear1mon")){
    //clearmon1
      Serial.print("Monitor 1 Cleared");
      lcd.setCursor(00, 00);
      lcd.print("                    ");
       y="";
     }
  else if (y.startsWith("clear2mon")){
    //clearmon1
      Serial.print("Monitor 2 Cleared");
      lcd.setCursor(00, 1);
      lcd.print("                    ");
       y="";
     }
  else{
  y="";}
}
