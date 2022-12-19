void blynk(int times_);
bool Data_validator(String tempstr);
int USER_ID_LENGTH = 20;
#define NO_OF_EXCLAMATION 4
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
    // int tempLength = user_id.length();
    if (USER_ID_LENGTH == user_id.length()) {
      int loop_ = 0, new_address = 0;
      for (int i = 0; i < NO_OF_EXCLAMATION + 1; i++) {
        if (i <= NO_OF_EXCLAMATION) {
          if (new_address < tempstr.length()) {
            new_address = tempstr.indexOf('!', new_address + 1);
            loop_++;
          } else {
            Serial.println("new_address : " + String(new_address) +
                           " tempstr.length() : " + String(tempstr.length()));
            return false;
          }
        }
      }
      if (loop_ == NO_OF_EXCLAMATION + 1) {
        return true;
      } else {
        Serial.println("loop_ : " + String(loop_) +
                       " NO_OF_EXCLAMATION : " + String(NO_OF_EXCLAMATION));
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