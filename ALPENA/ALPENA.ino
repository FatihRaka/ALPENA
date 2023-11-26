// ALPENA
// Alat Pendeteksi Warna
// Modified by: Fatih Raka Ksatria


#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,16,4);

#define S0 8
#define S1 9
#define S2 11
#define S3 12
#define sensorOut 10
byte frequency = 0;
byte a=0;
byte b=0;
byte c=0;

//set nilai kalibrasi tiap warna
byte Ra=25;
byte Rb=90;
byte Rc=70;

byte Ga=47;
byte Gb=40;
byte Gc=55;

byte Ba=43;
byte Bb=44;
byte Bc=26;

byte Ya=14;
byte Yb=20;
byte Yc=23;

byte Pa=38;
byte Pb=64;
byte Pc=28;

byte Oa=20;
byte Ob=66;
byte Oc=61;

byte Bla=150;
byte Blb=180;
byte Blc=120;

byte i=15; //set interval pembacaan

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
  lcd.begin();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" Sensor TCS3200 ");
}

void loop() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  a=frequency;
  delay(100);

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  b=frequency;
  delay(100);

  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  c=frequency;
  delay(100);
 
  if ((a>(Ra-i) && a<(Ra+i)) & (b>(Rb-i) && b<(Rb+i)) & (c>(Rc-i) && c<(Rc+i)))
  {
    Serial.println("Merah");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" Sensor TCS3200 ");
    lcd.setCursor(0,1);
    lcd.print(" Sensor: Merah ");
    }
  else if ((a>(Ga-i) && a<(Ga+i)) & (b>(Gb-i) && b<(Gb+i)) & (c>(Gc-i) && c<(Gc+i)))
  {
    Serial.println("Hijau");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" Sensor TCS3200 ");
    lcd.setCursor(0,1);
    lcd.print(" Sensor: Hijau ");
    }
  else if ((a>(Ba-i) && a<(Ba+i)) & (b>(Bb-i) && b<(Bb+i)) & (c>(Bc-i) && c<(Bc+i)))
  {
    Serial.println("Biru");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" Sensor TCS3200 ");
    lcd.setCursor(0,1);
    lcd.print(" Sensor: Biru ");
    }
    else if ((a>(Ya-i) && a<(Ya+i)) & (b>(Yb-i) && b<(Yb+i)) & (c>(Yc-i) && c<(Yc+i)))
  {
    Serial.println("Kuning");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" Sensor TCS3200 ");
    lcd.setCursor(0,1);
    lcd.print(" Sensor: Kuning ");
    }
    else if ((a>(Pa-i) && a<(Pa+i)) & (b>(Pa-i) && b<(Pb+i)) & (c>(Pc-i) && c<(Pc+i)))
  {
    Serial.println("Ungu");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" Sensor TCS3200 ");
    lcd.setCursor(0,1);
    lcd.print(" Sensor: Ungu ");
    }
    else if ((a>(Oa-i) && a<(Oa+i)) & (b>(Oa-i) && b<(Ob+i)) & (c>(Oc-i) && c<(Oc+i)))
  {
    Serial.println("Oranye");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" Sensor TCS3200 ");
    lcd.setCursor(0,1);
    lcd.print(" Sensor: Oranye ");
    }
    else if ((a>(Bla-i) && a<(Bla+i)) & (b>(Blb-i) && b<(Blb+i)) & (c>(Blc-i) && c<(Blc+i)))
  {
    Serial.println("Hitam");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" Sensor TCS3200 ");
    lcd.setCursor(0,1);
    lcd.print(" Sensor: Hitam ");
    }
  else
  {
    Serial.println(" ");
    }
  delay(50);
}
