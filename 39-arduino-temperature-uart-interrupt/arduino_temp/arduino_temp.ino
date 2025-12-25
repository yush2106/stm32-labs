#include <SoftwareSerial.h>

SoftwareSerial MySerial(6,7);    //RX for D6, TX for D7

int TemperaturePin = 0;    //tempereature pin 0
int val, temp;
float Temperature;
String Temp_String;

void setup() {
  // put your setup code here, to run once:
  MySerial.begin(9600);    //baund rate
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(TemperaturePin);    //read temperature value
  Temperature = val * 5000.0 / 1024.0;    //convert value
  Temperature = (Temperature - 500.0) / 10.0;
  temp = (int)Temperature;    //convert to integer

  //convert string
  if(temp < 10) {
    Temp_String = "0" + String(temp);
  }
  else {
    Temp_String = String(temp);
  }

  MySerial.print(Temp_String);    //transmit data
  Serial.println(Temp_String);
  delay(1000);    //delay
}
