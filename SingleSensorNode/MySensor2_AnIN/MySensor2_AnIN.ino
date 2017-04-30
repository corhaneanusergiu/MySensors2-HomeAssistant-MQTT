// Get analog value from defined Analog_PIN and send it to the gateway
#define MY_DEBUG
#define MY_RADIO_RF24
#define MY_NODE_ID 1000
//#define MY_OTA_FIRMWARE_FEATURE
//#define MY_REPEATER_FEATURE
//#define MY_PARENT_NODE_ID 0
//#define MY_RAM_ROUTING_TABLE_FEATURE
//#define MY_SMART_SLEEP_WAIT_DURATION_MS (500ul)
//#define MY_RF24_ENABLE_ENCRYPTION

#define MY_SIGNING_SOFT
#define MY_SIGNING_SOFT_RANDOMSEED_PIN 7
#define MY_SIGNING_REQUEST_SIGNATURES

#include <SPI.h>
#include <MySensor.h>;

#define CHILD_ID_Analog1 1

#define Analog_PIN A0

int InA1;

MyMessage msgAnalog(CHILD_ID_Analog1, V_VAR1); //24 .. 28

const unsigned long tUpdate=60000; //update interval
unsigned long t0;

void presentation()  {
  sendSketchInfo("Analog Sensor", "1.0", true);
  present(CHILD_ID_Analog1, S_CUSTOM, true);
}
void setup() {
  t0=millis();
}

void loop() {
  if ((millis()-t0) > tUpdate) ServerUpdate();
}

void ServerUpdate() {
  InA1=analogRead(Analog_PIN);
  send(msgAnalog.set(InA1), true);
  t0=millis();
}
