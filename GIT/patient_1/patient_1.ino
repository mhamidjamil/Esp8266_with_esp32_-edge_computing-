#include <ESP8266WiFi.h>

// Initialize network parameters
const char *ssid = "Edge_network_2";
const char *password = "123456789";
const char *host = "192.168.11.4"; // as specified in server.ino

// Set up the client objet
WiFiClient client;

// Configure deep sleep in between measurements
// const int sleepTimeSeconds = 2;
void blynk(int times_);
void setup() {
  // Connect to the server
  pinMode(LED_BUILTIN, OUTPUT);
  WiFi.begin(ssid, password);
  Serial.begin(9600);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    blynk(5);
    delay(500);
  }
  Serial.println();
  Serial.print("IP Address (AP): ");
  Serial.println(WiFi.localIP());
}

void loop() {
  String patient_data = "";
  if (Serial.available() > 0) {
    patient_data = Serial.readStringUntil('#');
    if (client.connect(host, 80)) {
    }
    // put your main code here, to run repeatedly:
    // {
    //   String url = "/update?value=";
    //   url += String(
    //       "SKdRiOAIL4NMiAkgrfmq@35.18!Supine_position!1.23,2.34,3.67!1.32!#");
    //   client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host +
    //                "\r\n" +
    //                "Connection: keep-alive\r\n\r\n"); // minimum set of
    //                required
    //                                                   // URL headers}
    //   delay(10);
    //   // Read all the lines of the response and print them to Serial
    //   Serial.println("Response: ");
    //   while (client.available()) {
    //     String line = client.readStringUntil('\r');
    //     Serial.print(line);
    //   }
    // }

    Serial.println("");
    blynk(2);
    Serial.println(patient_data);
    String url = "/update?value=";
    url += patient_data + "#";
    client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host +
                 "\r\n" +
                 "Connection: keep-alive\r\n\r\n"); // minimum set of required
                                                    // URL headers}
    delay(10);
    // Read all the lines of the response and print them to Serial
    Serial.println("Response: ");
    while (client.available()) {
      String line = client.readStringUntil('\r');
      Serial.print(line);
      blynk(3);
      // delay(3000);
    }
  }
}
void blynk(int times_) {
  for (; times_ > 0; times_--) {
    pinMode(LED_BUILTIN, HIGH);
    delay(50);
    pinMode(LED_BUILTIN, LOW);
    delay(50);
  }
}