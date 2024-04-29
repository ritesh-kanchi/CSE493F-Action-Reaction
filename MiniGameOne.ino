// mini game one
int mg1_xBall = centerHor;
int mg1_yBall = centerVer;
int mg1_xSpeed = 4;
int mg1_ySpeed = 4;

int mg1_round = 1;

int mg1_ballRadius = 4;
int mg1_fieldSize = 16;

int randomFieldX = random(0, display.width() - mg1_fieldSize);
int randomFieldY = random(0, display.height() - mg1_fieldSize);

void miniGameOne() {
  display.clearDisplay();
  // drawTitle(GAMES[0]);
  mg1_xSpeed *= mg1_round;
  mg1_ySpeed *= mg1_round;
  mg1_fieldSize = mg1_fieldSize - ((mg1_round - 1) * 4);

  mg1_xBall += mg1_xSpeed;
  mg1_yBall += mg1_ySpeed;

  if(mg1_xBall - mg1_ballRadius <= 0 || mg1_xBall + mg1_ballRadius >= display.width()) {
    mg1_xSpeed *= -1;
  }

  if(mg1_yBall - mg1_ballRadius <= 0 || mg1_yBall + mg1_ballRadius >= display.height()) {
    mg1_ySpeed *= -1;
  }

  display.fillCircle(mg1_xBall, mg1_yBall, mg1_ballRadius, WHITE);

  display.drawRect(randomFieldX, randomFieldY, mg1_fieldSize, mg1_fieldSize, WHITE);
  display.display();
}