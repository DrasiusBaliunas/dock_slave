// Last update 2019.04.28
// ToDo:
//      Sutvarkyt global
//      Servo --> dc arba step
//      enum
//      normalius du state padaryt

// I2C
#include <Wire.h>

// Stepper
#include <Stepper.h>

// Settings
#include "Settings.h"

// ------ Global's ------ //
String value;
char i2c_data[I2C_ARRAY_LENGHT];
int pos = 0;    // servo
uint8_t openLock = 3;

Stepper myStepper(stepsPerRevolution, 8, 10, 11, 9);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  myStepper.setSpeed(10);
  // start serial for debuging
  DBGS_BEGIN(DEBUG_BAUD_RATE);
  DBGS("SERIAL [ready]\n");
  DBGS("Software version: ");
  DBGS(software_version);
  DBGS("\n");

  // join i2c bus
  Wire.begin(SLAVE_I2C_ADR);      
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
}

void loop() {
  stepperControl();
  delay(100);
}
