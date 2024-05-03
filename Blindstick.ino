#include<SoftwareSerial.h>                                                           
SoftwareSerial mySerial(A0,A1);
#include <dht.h>
dht DHT;
#define DHT11_PIN A2  // DIGITAL PIN A2
String finalCode;
String a1, b1, c1, d1, e1;
// HCSR04 - ULTRA SONIC SENSOR 3
const int trigPin1 = 2;  // TRIGGER PIN 
const int echoPin1 = 3;  // ECHO PION
const int trigPin2 = 4;  // TRIGGER PIN 
const int echoPin2 = 5;  // ECHO PION
const int trigPin3 = 6;  // TRIGGER PIN 
const int echoPin3 = 7;  // ECHO PION
int moisture=0,sw=0;
long duration1;
int distance1;
long duration2;
int distance2;
long duration3;
int distance3;
void setup() 
{
pinMode(trigPin1, OUTPUT);  // Sets the trigPin as an Output
pinMode(echoPin1, INPUT);   // Sets the echoPin as an Input
pinMode(trigPin2, OUTPUT);  // Sets the trigPin as an Output
pinMode(echoPin2, INPUT);   // Sets the echoPin as an Input
pinMode(trigPin3, OUTPUT);  // Sets the trigPin as an Output
pinMode(echoPin3, INPUT);   // Sets the echoPin as an Input

Serial.begin(9600);        // Starts the serial communication
mySerial.begin(9600);

pinMode(8,INPUT); // SWITCH
pinMode(13,OUTPUT);// BUZZER
digitalWrite(13,LOW);

pinMode(9,OUTPUT); // VOICE OUTPUT
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);
digitalWrite(11,HIGH);
digitalWrite(12,HIGH);
}
void loop() 
{
usdistance1();
usdistance2();
usdistance3();

sw=digitalRead(8);
int chk = DHT.read11(DHT11_PIN);
senddata();// send data to nodemcu
moisture=analogRead(A3);

if(moisture>512)
{
  digitalWrite(12,LOW);
  delay(1000);
  digitalWrite(12,HIGH);
  delay(1000);
}

if(distance1<5)
{
digitalWrite(9,LOW);
delay(1000);
digitalWrite(9,HIGH);
delay(1000);
}
if(distance2<5)
{
digitalWrite(10,LOW);
delay(1000);
digitalWrite(10,HIGH);
delay(1000);
}

if(distance3<5)
{
digitalWrite(11,LOW);
delay(1000);
digitalWrite(11,HIGH);
delay(1000);
}

if(sw==LOW)
{ 
  digitalWrite(13,HIGH); // buzzer on
  
      mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
      delay(1000);  // Delay of 1000 milli seconds or 1 second
      mySerial.println("AT+CMGS=\"+9191XXXXXXXX\"\r"); // Replace x with mobile number
      delay(1000);
      mySerial.println("PERSON IT AT LOCATION : ");// The SMS text you want to send
      delay(100);
      mySerial.print("http://www.google.com/maps/place/"); // GMAP LINK
      delay(100);
      mySerial.print("17.0894972"); // LATITUDE
      delay(100);
      mySerial.print(",");
      delay(100);
      mySerial.print("82.0647349"); // LONGITUDE
      delay(100);
      mySerial.println((char)26);// ASCII code of CTRL+Z
      delay(1000);

   digitalWrite(13,LOW);
  
}


}

void usdistance1()
{

digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH);
distance1= duration1*0.034/2;

if(distance1<100)  // IF DISTANCE IS GREATER THAN 100, THAN DISPLAY "OUT OF RANGE"
{
Serial.print("USS Distance1: ");
Serial.println(distance1);
delay(100);
}  
}

void usdistance2()
{

digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
duration2 = pulseIn(echoPin2, HIGH);
distance2= duration2*0.034/2;

if(distance2<100)  // IF DISTANCE IS GREATER THAN 100, THAN DISPLAY "OUT OF RANGE"
{
Serial.print("USS Distance2: ");
Serial.println(distance2);
delay(100);
}  
}

void usdistance3()
{

digitalWrite(trigPin3, LOW);
delayMicroseconds(2);
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin3, LOW);
duration3 = pulseIn(echoPin3, HIGH);
distance3= duration3*0.034/2;

if(distance3<100)  // IF DISTANCE IS GREATER THAN 100, THAN DISPLAY "OUT OF RANGE"
{
Serial.print("USS Distance: ");
Serial.println(distance3);
delay(100);
}  
}

void senddata()
 {
   // SEND DATA TO NODE MCU
 
   a1=String(DHT.humidity); //
   b1=String(DHT.temperature);
   finalCode = a1 + "@" + b1 + "#";
   Serial.print(finalCode);
    
 }
