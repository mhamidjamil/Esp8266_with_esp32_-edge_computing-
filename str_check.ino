void blynk(int times_);
// 3a2v3Vlb5UD6RFx0Eyg3@35.154!Spine_position!2.151,450670.54,2.12!2.79!#
bool Data_validator(String tempstr);
int USER_ID_LENGTH = 20;
#define NO_OF_EXCLAMATION 4
#define NO_OF_COMMAS 2
int count_presence(String testStr, char toBeFound);
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  String testStr = "";
  if (Serial.available() > 0) {
    testStr = Serial.readString();
    Serial.println("testStr : " + testStr);
    if (Data_validator(testStr)) {
      Serial.println("Valid");
    } else {
      Serial.println("Invalid");
    }
    delay(1000);
  }
  // put your main code here, to run repeatedly:
  // server.handleClient();
}

bool Data_validator(String tempstr) {
  // Serial.println("Working on : " + tempstr);
  String user_id = "";
  int first_at = tempstr.indexOf('@');
  if (first_at == USER_ID_LENGTH) {
    user_id = tempstr.substring(0, first_at);
    if (USER_ID_LENGTH == user_id.length()) {
      if (count_presence(tempstr, '!') == NO_OF_EXCLAMATION) {
        if (count_presence(tempstr, ',') == NO_OF_COMMAS) {
          if (count_presence(tempstr, '#') == 1) {
            if (count_presence(tempstr, '@') == 1) {
              return true;
            } else {
              Serial.println("NO_OF_AT : 1, Found in input : " +
                             String(count_presence(tempstr, '@')));
              return false;
            }
          } else {
            Serial.println("NO_OF_HASH : 1, Found in input : " +
                           String(count_presence(tempstr, '#')));
            return false;
          }
        } else {
          Serial.println(
              "NO_OF_COMMAS : " + String(NO_OF_COMMAS) +
              " Found in input : " + String(count_presence(tempstr, ',')));
          return false;
        }
      } else {
        Serial.println(
            "NO_OF_EXCLAMATION : " + String(NO_OF_EXCLAMATION) +
            " Found in input : " + String(count_presence(tempstr, '!')));
        return false;
      }

    } else {
      Serial.println("USER_ID_LENGTH : " + String(USER_ID_LENGTH) +
                     " strlen(user_id) : " + String(user_id.length()));
      return false;
    }
  } else {
    Serial.println("first at : " + String(first_at) +
                   " USER_ID_LENGTH : " + String(USER_ID_LENGTH));
    return false;
  }
  //   return
}
int count_presence(String testStr, char toBeFound) {
  int count = 0;
  for (int i = 0; i < testStr.length(); i++) {
    if (testStr[i] == toBeFound) {
      count++;
    }
  }
  return count;
}