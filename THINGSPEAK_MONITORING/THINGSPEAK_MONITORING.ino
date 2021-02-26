/***************************************************************************************************************
 * IoT DHT Temp/Hum and Soil Moister Station using NodeMCU ESP-12 Develop Kit V1.0
 *  DHT connected to NodeMCU pin D3
 *  Soil Moister Sensor connected to A0
 *  Sensor Data on local OLED Display
 *  Sensor data sent to Thingspeak Channel: https://thingspeak.com/channels/CHANNEL_ID 
 *  Developed by MJRovai 12 October 2017
 ********************************************************************************************************************************/
#define SW_VERSION " ThinkSpeak.com" // SW version will appears at innitial LCD Display

/* ESP12-E & Thinkspeak*/
#include <ESP8266WiFi.h>
WiFiClient client;
const char* MY_SSID = "AndroidAP35A9";
const char* MY_PWD = "hnrb2394";
const char* TS_SERVER = "api.thingspeak.com";
String TS_API_KEY ="QCFQF56S891M9E7V";
const int AnalogIn  = A0;
int d = 0;
int t = 0;


/***************************************************
 * Connecting WiFi
 **************************************************/
void connectWifi()
{
  Serial.print("Connecting to "+ *MY_SSID);
  WiFi.begin(MY_SSID, MY_PWD);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println("");  
}


/***************************************************
 * Sending Data to Thinkspeak Channel
 **************************************************/
void sendDataTS(void)
{
   //readingIn = analogRead(AnalogIn);
   Serial.println(d);
   delay(1000);   
   
   if (client.connect(TS_SERVER, 80)) 
   { 
     String postStr = TS_API_KEY;
     postStr += "&field1=";
     postStr += String(d);
     postStr += "\r\n\r\n";

   
     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");
     client.print("Connection: close\n");
     client.print("X-THINGSPEAKAPIKEY: " + TS_API_KEY + "\n");
     client.print("Content-Type: application/x-www-form-urlencoded\n");
     client.print("Content-Length: ");
     client.print(postStr.length());
     client.print("\n\n");
     client.print(postStr);
     delay(1000); 
   }
   client.stop();
}



void setup() 
{
  pinMode(D0,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,INPUT);
  Serial.begin(115200);
  delay(10);
  connectWifi();
}

void loop() 
{
  digitalWrite(D2,HIGH);
  delayMicroseconds(10);
  digitalWrite(D2,LOW);
  t=pulseIn(D3,HIGH);
  d=0.034*t/2;
  Serial.println(d);

  sendDataTS();
  delay(16000); 
}
