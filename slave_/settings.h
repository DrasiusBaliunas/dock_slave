// ------ DEBUG ------ //
#define DEBUG_SERIAL

#ifdef DEBUG_SERIAL
  #define DBGS_BEGIN(data)  SerialDebug.begin(data)
  #define DBGS(data)        SerialDebug.print(data)
  #define DBGS_HEX(data)    SerialDebug.print(data, HEX)
#endif

// ------ VERSION ------ //
#define software_version "0.1.1" // major.minor[.build[.revision]]

// ------ Serial ------ //
#define SerialDebug Serial
#define DEBUG_BAUD_RATE 115200

// ------ LED ------ //
#define GREEN_LED D6      // TODO busenai [12]
#define RED_LED D5        // TODO onHold busenai [14]

// ------ I2C ------ //
#define SLAVE_I2C_ADR 0x08
#define REQUEST_LENGHT 5
#define I2C_ARRAY_LENGHT 10

// ---- Stepper ---- //
#define stepsPerRevolution 2048
#define stepsPerEvent 1450
