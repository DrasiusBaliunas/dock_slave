void receiveEvent(int howMany) {
  byte x = Wire.read();    // receive byte as an integer

  DBGS("DataFromMaster: ");
  DBGS_HEX(x);

  switch (x) {
    case 0x01:
      value = "CLOSE";
      digitalWrite(LED_BUILTIN, HIGH);
      openLock = 0;
      break;
    case 0x02:
      value = "OPEN ";
      digitalWrite(LED_BUILTIN, LOW);
      openLock = 1;
      break;
    case 0x03:
      value = digitalRead(LED_BUILTIN) ? "CLOSE" : "OPEN ";
      break;
    default:
      value = "ERROR";
      break;
  }

  DBGS("\nState: ");
  DBGS(value);
  DBGS("\n");
}
