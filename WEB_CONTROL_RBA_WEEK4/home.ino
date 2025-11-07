void HomePos() {
  Home = 1;
  if (Home == 1) {
    //set home position servo1
    if (Home == 1 && pos1 <= 90) {
      pos1++;
      delay(1);
      idektep.setPWM(servo1, 0, angleToPulse(pos1));
      if (pos1 == 90) {
        pos1 = 90;
        idektep.setPWM(servo1, 0, angleToPulse(pos1));
      }
    }
    if (Home == 1 && pos1 >= 90) {
      pos1--;
      delay(1);
      idektep.setPWM(servo1, 0, angleToPulse(pos1));
      if (pos1 == 90) {
        pos1 = 90;
        idektep.setPWM(servo1, 0, angleToPulse(pos1));
      }
    }
    //set home position servo2
    if (Home == 1 && pos2 <= 90) {
      pos2++;
      delay(1);
      idektep.setPWM(servo2, 0, angleToPulse(pos2));
      if (pos2 == 90) {
        pos2 = 90;
        idektep.setPWM(servo2, 0, angleToPulse(pos2));
      }
    }
    if (Home == 1 && pos2 >= 90) {
      pos2--;
      delay(1);
      idektep.setPWM(servo2, 0, angleToPulse(pos2));
      if (pos2 == 90) {
        pos2 = 90;
        idektep.setPWM(servo2, 0, angleToPulse(pos2));
      }
    }
    //set home position servo3
    if (Home == 1 && pos3 <= 90) {
      pos3++;
      delay(1);
      idektep.setPWM(servo3, 0, angleToPulse(pos3));
      if (pos3 == 90) {
        pos3 = 90;
        idektep.setPWM(servo3, 0, angleToPulse(pos3));
      }
    }
    if (Home == 1 && pos3 >= 90) {
      pos3--;
      delay(1);
      idektep.setPWM(servo3, 0, angleToPulse(pos3));
      if (pos3 == 90) {
        pos3 = 90;
        idektep.setPWM(servo3, 0, angleToPulse(pos3));
      }
    }
    //set home position servo4
    if (Home == 1 && pos4 <= 90) {
      pos4++;
      delay(1);
      idektep.setPWM(servo4, 0, angleToPulse(pos4));
      if (pos4 == 90) {
        pos4 = 90;
        idektep.setPWM(servo4, 0, angleToPulse(pos4));
      }
    }
    if (Home == 1 && pos4 >= 90) {
      pos4--;
      delay(1);
      idektep.setPWM(servo4, 0, angleToPulse(pos4));
      if (pos4 == 90) {
        pos4 = 90;
        idektep.setPWM(servo4, 0, angleToPulse(pos4));
      }
    }
    //set home position servo5
    if (Home == 1 && pos5 <= 90) {
      pos5++;
      delay(1);
      idektep.setPWM(servo5, 0, angleToPulse(pos5));
      if (pos5 == 90) {
        pos5 = 90;
        idektep.setPWM(servo5, 0, angleToPulse(pos5));
      }
    }
    if (Home == 1 && pos5 >= 90) {
      pos5--;
      delay(1);
      idektep.setPWM(servo5, 0, angleToPulse(pos5));
      if (pos5 == 90) {
        pos5 = 90;
        idektep.setPWM(servo5, 0, angleToPulse(pos5));
      }
    }
  }
}