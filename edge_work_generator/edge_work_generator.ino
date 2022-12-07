// * data generator
#include "ESPAsyncWebServer.h"
#include <ESP8266WiFi.h>

// Set your access point network credentials
const char *ssid = "Edge_network";
const char *password = "123456789";

AsyncWebServer server(80);

String writeTemp() {
  //   return String(bme.writeTemperature());
  return String(random(0, 50));
  // return String(1.8 * bme.writeTemperature() + 32);
}

String writeHumi() {
  // return String(bme.writeHumidity());
  return String(random(50, 100));
}

String writePres() {
  // return String(bme.writePressure() / 100.0F);
  return String(random(100, 150));
}

String user_data =
    "SKdRiOAIL4NMiAkgrfmq@35.214!spine_position!2.406,608013.35,2.19!2.61!";
String patient_data() {
  // return data read from patient module
  return user_data;
}

void setup() {
  // Serial port for debugging purposes
  Serial.begin(115200);
  Serial.println();

  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", writeTemp().c_str());
  });
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", writeHumi().c_str());
  });
  server.on("/pressure", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", writePres().c_str());
  });
  server.on("/data", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/plain", patient_data().c_str());
  });

  server.begin();
}

void loop() {

  if (Serial.available() > 0) {
    user_data = Serial.readStringUntil('#');
    Serial.println(user_data);
  }
}
