#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid     = "Vitorelo";
const char *password = "setembro1309";

WiFiUDP ntpUDP;

NTPClient timeClient(ntpUDP, "NTP.br", 3600, 90000);

void setup(){
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
}

void loop() {
  timeClient.update();

  if(timeClient.getHours()<10)
  { Serial.print("0"); }
  Serial.print(timeClient.getHours()-4);
  Serial.print ( ":" );
  if(timeClient.getMinutes()<10)
  { Serial.print("0"); }
  Serial.print (timeClient.getMinutes());
  Serial.print ( ":" );
  if(timeClient.getSeconds()<10)
  { Serial.print("0"); }
  Serial.print (timeClient.getSeconds());
  Serial.println ();
  delay(1000);
}
