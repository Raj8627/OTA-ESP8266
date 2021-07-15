

#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>

const char* ssid = "Your Network Name";
const char* password = "Your Network Password";

void setup() {

  Serial.begin(9600);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

 
  Serial.println();
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  ArduinoOTA.begin();
}

void loop() {
  ArduinoOTA.handle();
  
}
