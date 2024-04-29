// mini game one
int mg1_xBall = centerHor;
int mg1_yBall = centerVer;
int mg1_xSpeed = 2;
int mg1_ySpeed = 2;

int mg1_round = 1;
int mg1_health = 3;

int mg1_ballRadius = 4;
int mg1_fieldSize = 32;

int mg1_timer_max = 1000;
int mg1_timer = 0;

int randomFieldX = random(0, display.width() - mg1_fieldSize);
int randomFieldY = random(10, display.height() - mg1_fieldSize);

bool mg1_buttonPressed = false;

void miniGameOne() {
  display.clearDisplay();
  drawStatus(mg1_round, mg1_health);

  // drawTitle(GAMES[0]);
  mg1_xBall += mg1_xSpeed;
  mg1_yBall += mg1_ySpeed;

  if (mg1_xBall - mg1_ballRadius <= randomFieldX + mg1_fieldSize && mg1_xBall + mg1_ballRadius >= randomFieldX && mg1_yBall - mg1_ballRadius <= randomFieldY + mg1_fieldSize && mg1_yBall + mg1_ballRadius >= randomFieldY && mg1_buttonPressed) {
    mg1_buttonPressed = false;  // Reset button state
    vibrate(1000);

    mg1_round++;  // Increase round number if ball is inside the field and button is pressed

    if (mg1_round <= 3) {
      randomFieldX = random(20, display.width() - mg1_fieldSize);
      randomFieldY = random(10, display.height() - mg1_fieldSize);

      mg1_xBall = centerHor;
      mg1_yBall = centerVer;

      mg1_xSpeed *= mg1_round;
      mg1_ySpeed *= mg1_round;
      mg1_fieldSize = mg1_fieldSize - ((mg1_round - 1) * 4);

      mg1_timer_max -= (mg1_round - 1) * 150;
    }
  } else if (mg1_buttonPressed) {
    mg1_buttonPressed = false;
    mg1_health--;
  }

  if (mg1_xBall - mg1_ballRadius <= 0 || mg1_xBall + mg1_ballRadius >= display.width()) {
    mg1_xSpeed *= -1;
    vibrate(10);
  }

  if (mg1_yBall - mg1_ballRadius <= 0 || mg1_yBall + mg1_ballRadius >= display.height()) {
    mg1_ySpeed *= -1;
    vibrate(10);
  }

  display.fillCircle(mg1_xBall, mg1_yBall, mg1_ballRadius, WHITE);

  display.drawRoundRect(randomFieldX, randomFieldY, mg1_fieldSize, mg1_fieldSize, 4, WHITE);
  display.display();


  int buttonVal = digitalRead(BUTTON_PIN);
  if (buttonVal == LOW) {
    mg1_buttonPressed = true;  // Set button state to pressed
  }

   if (mg1_timer > mg1_timer_max) {
    randomFieldX = random(20, display.width() - mg1_fieldSize);
    randomFieldY = random(10, display.height() - mg1_fieldSize);
    mg1_timer = 0;
  }
  mg1_timer += 10;

  delay(10);
}

void mg1_reset() {
  mg1_xBall = centerHor;
  mg1_yBall = centerVer;
  mg1_xSpeed = 2;
  mg1_ySpeed = 2;

  mg1_round = 1;

  mg1_ballRadius = 4;
  mg1_fieldSize = 32;

  randomFieldX = random(20, display.width() - mg1_fieldSize);
  randomFieldY = random(10, display.height() - mg1_fieldSize);

  mg1_buttonPressed = false;

  mg1_timer = 0;
  mg1_timer_max = 1000;
}