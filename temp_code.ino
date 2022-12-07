#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#include <ESP8266WiFiMulti.h>
ESP8266WiFiMulti WiFiMulti;

const char *ssid = "Edge_network";
const char *password = "123456789";

// Your IP address or domain name with URL path
const char *serverNameTemp = "http://192.168.4.1/temperature";
const char *serverNameHumi = "http://192.168.4.1/humidity";
const char *serverNamePres = "http://192.168.4.1/pressure";
const char *serverPatientData = "http://192.168.4.1/data";

// #include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>

// #define SCREEN_WIDTH 128 // OLED display width, in pixels
// #define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// #define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

String temperature;
String humidity;
String pressure;
String patient_data;

unsigned long previousMillis = 0;
const long interval = 5000;

void setup() {
  Serial.begin(115200);
  Serial.println();

  //   // Address 0x3C for 128x64, you might need to change this value (use an
  //   I2C scanner) if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
  //     Serial.println(F("SSD1306 allocation failed"));
  //     for(;;); // Don't proceed, loop forever
  //   }
  //   display.clearDisplay();
  //   display.setTextColor(WHITE);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected to WiFi");
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // Check WiFi connection status
    if ((WiFiMulti.run() == WL_CONNECTED)) {
      //   temperature = httpGETRequest(serverNameTemp);
      //   humidity = httpGETRequest(serverNameHumi);
      //   pressure = httpGETRequest(serverNamePres);
      patient_data = httpGETRequest(serverPatientData);
      //   Serial.println("Temperature: " + temperature + " *C - Humidity: " +
      //                  humidity + " % - Pressure: " + pressure + " hPa,
      //                  Patient data : "+patient_data);
      Serial.println("Patient data : " + patient_data);
      previousMillis = currentMillis;
    } else {
      Serial.println("WiFi Disconnected");
    }
  }
}

String httpGETRequest(const char *serverName) {
  WiFiClient client;
  HTTPClient http;

  // Your IP address with path or Domain name with URL path
  http.begin(client, serverName);

  // Send HTTP POST request
  int httpResponseCode = http.GET();

  String payload = "--";

  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  } else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}