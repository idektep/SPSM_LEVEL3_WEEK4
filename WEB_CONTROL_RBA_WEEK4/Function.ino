//--------------------------------------------------------------Robot Arm Control Function----------------------------------------------------------------//
void processRobotArmMovement() {
  if (hold_flag == "TURN_RIGHT_RM") {
    M1_2();
  } else if (hold_flag == "TURN_LEFT_RM") {
    M1_1();
  } else if (hold_flag == "EXTEND") {
    M2_1();
  } else if (hold_flag == "RESTACK") {
    M2_2();
  } else if (hold_flag == "UPPER") {
    M3_1();
  } else if (hold_flag == "LOWER") {
    M3_2();
  } else if (hold_flag == "UPPER_G") {
    M4_2();
  } else if (hold_flag == "LOWER_G") {
    M4_1();
  } else if (hold_flag == "GRIP") {
    M5_2();
  } else if (hold_flag == "UN_GRIP") {
    M5_1();
  } else if (hold_flag == "home") {
    HomePos();
  }
}