
#include <ArduinoJson.h>
#include <FirebaseArduino.h>
#include <WiFi.h>
#include <SoftwareSerial.h>
SoftwareSerial espSerial =  SoftwareSerial(10,12);     
#include <DHT.h>        

#define DHTPIN 2               
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

#define FIREBASE_HOST "embedded-f7e4b-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "bLdOolfNx0e85inULDVtM6cEs0X0oYmOZG4RTls9"
#define WIFI_SSID "Not Connected"
#define WIFI_PASSWORD "#khong#noi@_@"

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); 
  
  dht.begin(); 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
  delay(100);
  }
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  delay(10);  
}

void loop() {
  // put your main code here, to run repeatedly:
 float t = dht.readTemperature();
   float h = dht.readHumidity();
      if (isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  else 
  {
      Firebase.setString("nhiet do",String(t));
      delay(20);
  }

  Firebase.setString("do am",String(h));
  delay(20);
}
