#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>

// Configuration parameters for Access Point
char *ssid_ap = "Edge_network_2";
char *password_ap = "123456789";
IPAddress ip(192, 168, 11,
             4); // arbitrary IP address (doesn't conflict w/ local network)
IPAddress gateway(192, 168, 11, 1);
IPAddress subnet(255, 255, 255, 0);

// Set up the server object
ESP8266WebServer server;

// Keep track of the sensor data that's going to be sent by the client
String sensor_value;

void blynk(int times_);
bool Data_validator(String tempstr);
#define USER_ID_LENGTH strlen("SKdRiOAIL4NMiAkgrfmq")
#define NO_OF_EXCLAMATION 4
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(ip, gateway, subnet);
  WiFi.softAP(ssid_ap, password_ap);
  // Print IP Address as a sanity check
  Serial.begin(9600);
  // Serial.println();
  // Serial.print("IP Address: ");
  // Serial.println(WiFi.localIP());
  // Configure the server's routes
  server.on(
      "/",
      handleIndex); // use the top root path to report the last sensor value
  server.on("/update",
            handleUpdate); // use this route to update the sensor value
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}

void handleIndex() {
  server.send(200, "text/plain",
              String(sensor_value)); // we'll need to refresh the page for
                                     // getting the latest value
}

void handleUpdate() {
  // The value will be passed as a URL argument
  sensor_value = server.arg("value");
  Serial.println(sensor_value);
  server.send(200, "text/plain", "Updated");
  blynk(3);
}
void blynk(int times_) {
  for (; times_ > 0; times_--) {
    pinMode(LED_BUILTIN, HIGH);
    delay(50);
    pinMode(LED_BUILTIN, LOW);
    delay(50);
  }
}
bool Data_validator(String tempstr) {
  // Serial.println("Working on : " + tempstr);
  String user_id = "";
  int first_at = tempstr.indexOf('@');
  if ((first_at + 1) == USER_ID_LENGTH) {
    user_id = tempstr.substring(0, first_at);
    if (USER_ID_LENGTH == strlen(user_id)) {
      // int loop_ = 0, new_address = 0;
      // do {
      //   if (tempstr.indexOf('!', new_address) == -1) {
      //     new_address = tempstr.indexOf('!', new_address);
      //     loop_++;
      //   } else {
      //     Serial.println("NO_OF_EXCLAMATION : " + String(NO_OF_EXCLAMATION) +
      //                    " loop_ : " + String(loop_));
      //     return false;
      //   }
      // } while (loop_ < NO_OF_EXCLAMATION);
      if (tempstr.count('!') == NO_OF_EXCLAMATION) {
        return true;
      } else {
        Serial.println("NO_OF_EXCLAMATION : " + String(NO_OF_EXCLAMATION) +
                       " tempstr.count('!') : " + String(tempstr.count('!')));
        return false;
      }
    } else {
      Serial.println("USER_ID_LENGTH : " + String(USER_ID_LENGTH) +
                     " strlen(user_id) : " + String(strlen(user_id)));
      return false;
    }
  } else {
    Serial.println("first at : " + String(first_at) +
                   " USER_ID_LENGTH : " + String(USER_ID_LENGTH));
    return false;
  }
}