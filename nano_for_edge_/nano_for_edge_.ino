
// 4-1-2023 7:35 PM
// in this code nano will genarate data for two patients
#include <SoftwareSerial.h>

SoftwareSerial patient_1(2, 3);
SoftwareSerial patient_2(4, 5);

SoftwareSerial patient_3(6, 7); // buggy output generator for P1
SoftwareSerial patient_4(8, 9); // Patient ID : ZDwZTcwWNkCb0ESwLSuw
int bugNumber = 0;
// 1 for @ missing
// 2 for ! missing
// 3 for # missing
// 4 for , missing
// 5 for ID length missing

// 6 for ID extended with @
// 7 for extra !
// 8 for extra #
// 9 for extra ,
// 10 for extra ID
void dataSender(int patient_number);
void setup() {
  Serial.begin(9600);
  patient_1.begin(9600);
  patient_2.begin(9600);

  patient_3.begin(9600); // buggy output generator for P1
  patient_4.begin(9600); // Patient ID : ZDwZTcwWNkCb0ESwLSuw
}
void loop() {
  dataSender(1);
  delay(2000);
  dataSender(2);
  delay(2500);
  dataSender(3);
  if (bugNumber < 10) {
    bugNumber++;
  } // increment bug number
  else {
    bugNumber = 1;
  }
  delay(1500);
  dataSender(4);
  delay(2000);
}
void dataSender(int patient_number) {
  if (patient_number == 1) {
    Serial.println("Patient 1");
    patient_1.print("SKdRiOAIL4NMiAkgrfmq@");

    // temperature
    patient_1.print(random(35, 37));
    patient_1.print(".");
    patient_1.print(random(1, 100));
    patient_1.print("!");

    // position
    patient_1.print("spine_position");
    patient_1.print("!");

    // GSR
    patient_1.print(random(1, 3));
    patient_1.print(".");
    patient_1.print(random(1, 1000));

    patient_1.print(",");

    patient_1.print(random(100000, 999999));
    patient_1.print(".");
    patient_1.print(random(1, 100));

    patient_1.print(",");

    patient_1.print(random(0, 3));
    patient_1.print(".");
    patient_1.print(random(1, 100));
    patient_1.print("!");

    // snore
    patient_1.print(random(1, 3));
    patient_1.print(".");
    patient_1.print(random(1, 100));
    patient_1.print("!");
    patient_1.println("#");

  } else if (patient_number == 2) {
    Serial.println("Patient 2");
    patient_2.print("3a2v3Vlb5UD6RFx0Eyg3@");

    // temperature
    patient_2.print(random(35, 37));
    patient_2.print(".");
    patient_2.print(random(1, 100));
    patient_2.print("!");

    // position
    patient_2.print("Spine_position");
    patient_2.print("!");

    // GSR
    patient_2.print(random(1, 3));
    patient_2.print(".");
    patient_2.print(random(1, 1000));

    patient_2.print(",");

    patient_2.print(random(100000, 999999));
    patient_2.print(".");
    patient_2.print(random(1, 100));

    patient_2.print(",");

    patient_2.print(random(0, 3));
    patient_2.print(".");
    patient_2.print(random(1, 100));
    patient_2.print("!");

    // snore
    patient_2.print(random(1, 3));
    patient_2.print(".");
    patient_2.print(random(1, 100));
    patient_2.print("!");
    patient_2.println("#");
  } else if (patient_number == 3) {
    Serial.println("patient 1 with bug no: " + String(bugNumber));
    if (bugNumber == 1) { // ID without @ symbol
      patient_3.print("SKdRiOAIL4NMiAkgrfmq");
    } else if (bugNumber == 5) { // uncomplete ID length
      patient_3.print("SKdRiOAIL4NMiAkgrfm@");
    } else if (bugNumber == 6) { // with extra @ symbol
      patient_3.print("SKdRiOAIL4NMiAkgrfmq@@");
    } else if (bugNumber == 7) { // with extra ! symbol
      patient_3.print("SKdRiOAIL4NMiAkgrfmq@!");
    } else if (bugNumber == 10) { // with
      patient_3.print("SKdRiOAIL4NMiAkgrfmqq@");
    } else { // stable output
      patient_3.print("SKdRiOAIL4NMiAkgrfmq@");
    }

    // temperature
    patient_3.print(random(35, 37));
    patient_3.print(".");
    patient_3.print(random(1, 100));
    patient_3.print("!");

    // position
    patient_3.print("Spine_position");
    patient_3.print("!");

    // GSR
    patient_3.print(random(1, 3));
    patient_3.print(".");
    patient_3.print(random(1, 1000));

    patient_3.print(",");

    patient_3.print(random(100000, 999999));
    patient_3.print(".");
    patient_3.print(random(1, 100));
    if (bugNumber == 4) { // bug => ',' missing
      // patient_3.print(",");
    } else if (bugNumber == 9) { // bug => ',' missing
      patient_3.print(",,");
    } else {
      patient_3.print(",");
    }

    patient_3.print(random(0, 3));
    patient_3.print(".");
    patient_3.print(random(1, 100));
    if (bugNumber == 2) { // bug => '!' missing
      // patient_3.print("!");
    } else {
      patient_3.print("!");
    }
    // snore
    patient_3.print(random(1, 3));
    patient_3.print(".");
    patient_3.print(random(1, 100));
    patient_3.print("!");
    if (bugNumber == 3) { // bug => '#' missing
      // patient_3.println("#");
    } else if (bugNumber == 8) { // bug => extra '#' symbol
      patient_3.println("##");
    } else {
      patient_3.println("#");
    }

  } else if (patient_number == 4) {
    Serial.println("Patient 4");
    patient_4.print("ZDwZTcwWNkCb0ESwLSuw@");

    // temperature
    patient_4.print(random(35, 37));
    patient_4.print(".");
    patient_4.print(random(1, 100));
    patient_4.print("!");

    // position
    patient_4.print("Spine_positioN");
    patient_4.print("!");

    // GSR
    patient_4.print(random(1, 3));
    patient_4.print(".");
    patient_4.print(random(1, 1000));

    patient_4.print(",");

    patient_4.print(random(100000, 999999));
    patient_4.print(".");
    patient_4.print(random(1, 100));

    patient_4.print(",");

    patient_4.print(random(0, 3));
    patient_4.print(".");
    patient_4.print(random(1, 100));
    patient_4.print("!");

    // snore
    patient_4.print(random(1, 3));
    patient_4.print(".");
    patient_4.print(random(1, 100));
    patient_4.print("!");
    patient_4.println("#");
  } else {
    Serial.println("Invalid patient number");
  }
}