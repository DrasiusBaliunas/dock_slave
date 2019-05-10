void stepperEventOpen(){
  DBGS("\nOpening...");
  myStepper.step(stepsPerEvent);
  delay(50);
  DBGS(" [DONE]\n");
  openLock = 2;
}


void stepperEventClose(){
  DBGS("\nClosing...");
  myStepper.step(-stepsPerEvent);
  delay(50);
  DBGS(" [DONE]\n");
  openLock = 2;
}

void stepperControl(){
  switch (openLock) {
    case 0:
      stepperEventClose();
      break;
    case 1:
      stepperEventOpen();
      break;
    default:
      break;
  }
}
