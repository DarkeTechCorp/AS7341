#include "AS7341.h"
#include <Wire.h>

AS7341 as7341;

void setup() {
  Serial.begin(115200);
  as7341.begin();
  as7341.PowerOn();

}

void loop() {
  Channels channels;
  as7341.ReadLight(&channels);
  Serial.print("ADC0/F1-");
  Serial.println(channels.F1);
  Serial.print("ADC1/F2-");
  Serial.println(channels.F2);
  Serial.print("ADC2/F3-");
  Serial.println(channels.F3);
  Serial.print("ADC3/F4-");
  Serial.println(channels.F4);
  Serial.print("ADC0/F5-");
  Serial.println(channels.F5);
  Serial.print("ADC1/F6-");
  Serial.println(channels.F6);
  Serial.print("ADC2/F7-");
  Serial.println(channels.F7);
  Serial.print("ADC3/F8-");
  Serial.println(channels.F8);
  Serial.print("ADC4/Clear-");
  Serial.println(channels.CLEAR);
  Serial.print("ADC5/NIR-");
  Serial.println(channels.NIR);
  Serial.println("");
  Serial.println("");
  Serial.println("");
  delay(1000);

}
