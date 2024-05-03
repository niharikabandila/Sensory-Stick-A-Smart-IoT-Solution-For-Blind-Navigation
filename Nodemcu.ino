#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

HTTPClient http;
WiFiClient client;// NEW LINE ADDED FOR NEW VERSION OF LIBRARY

int a,b,c,d,e;
int count;
char f; String data;
void setup()
{

WiFi.disconnect();
delay(2000);

WiFi.begin("project","12345678"); // HOTSPOT ID AND PASSWORD
while ((!(WiFi.status() == WL_CONNECTED)))
{
delay(300);
}

Serial.begin(9600);
Serial.println("Wifi- Connected");
}

void loop()
{

 while(Serial.available())
  {
    delay(10);
    f = Serial.read();
    if (f == '@')              
    {    
     a = data.toInt();
     data="";
    }
    else if (f == '#')              
    {
     b = data.toInt();
     break;
    }
    else
    {
    data +=f;
    }
    }    
   
   if (data.length() > 0)
   {
    Serial.println(a); // humidity
    Serial.println(b); // temperature
    Serial.println("");
    upload();
    data="";
   }  
}

void upload()
{
    String link="http://blynk.cloud/external/api/update?token=7O9Ue0lSKihbAqgKAVsSQZp-ye4ApAz4&v0="; // 
    link=String(link+b);
    http.begin(client,link); // MODIFY SYNTAX FOR NEW VERSION OF LIBRARY ESP AND BLYNK
    http.GET();
    http.end();
    delay(300);
    
    String link1="http://blynk.cloud/external/api/update?token=7O9Ue0lSKihbAqgKAVsSQZp-ye4ApAz4&v1="; // 
    link1=String(link1+a);
    http.begin(client,link1); // MODIFY SYNTAX FOR NEW VERSION OF LIBRARY ESP AND BLYNK
    http.GET();
    http.end();
    delay(300);


 
}