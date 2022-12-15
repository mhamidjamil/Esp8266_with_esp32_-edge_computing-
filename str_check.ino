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
      //   int loop_ = 0, new_address = 0;
      //   do {
      //     if (tempstr.indexOf('!', new_address) != -1) {
      //       new_address = tempstr.indexOf('!', new_address);
      //       loop_++;
      //     } else if (tempstr.indexOf('#', new_address) != -1) {
      //       if (loop_ == NO_OF_EXCLAMATION) {
      //         return true;
      //       } else {
      //         Serial.println(
      //             "1_NO_OF_EXCLAMATION : " + String(NO_OF_EXCLAMATION) +
      //             " loop_ : " + String(loop_));
      //         return false;
      //       }
      //     } else {
      //       Serial.println("NO_OF_EXCLAMATION : " + String(NO_OF_EXCLAMATION)
      //       +
      //                      " loop_ : " + String(loop_));
      //       return false;
      //     }
      //   } while (loop_ <= NO_OF_EXCLAMATION);
      //   if (loop_ == NO_OF_EXCLAMATION) {
      return true;
      //   } else {
      //     Serial.println("2_NO_OF_EXCLAMATION : " + String(NO_OF_EXCLAMATION)
      //     +
      //                    " loop_ : " + String(loop_));
      //     return false;
      //   }
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