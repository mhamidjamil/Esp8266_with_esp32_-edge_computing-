#include <SoftwareSerial.h>

SoftwareSerial patient_1(15, 13);
SoftwareSerial patient_2(12, 14);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  patient_1.begin(9600);
  patient_2.begin(9600);
}

void loop() {

  String patient_data_1 = "";
  String patient_data_2 = "";
  // put your main code here, to run repeatedly:
  if (patient_1.available() > 0) {
    patient_data_1 = patient_1.readStringUntil('#');
    Serial.println(patient_data_1);
  }
  if (patient_2.available() > 0) {
    patient_data_2 = patient_2.readStringUntil('#');
    Serial.println(patient_data_2);
  }
}