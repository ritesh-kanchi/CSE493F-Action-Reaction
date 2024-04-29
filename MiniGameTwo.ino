int mg2_round = 1;
int mg2_health = 3;

bool mg2_buttonPressed = false;


int randomThiefX = random(0, display.width() - mg1_fieldSize);
int randomThiefY = random(10, display.height() - mg1_fieldSize);

void miniGameTwo() {
 display.clearDisplay();

  int spotlightW = 20;
  int spotlightH = 15;
  int xPos = map(analogRead(JOYSTICK_LEFTRIGHT_PIN), 0, 1023, spotlightW, display.width() - spotlightW);
  int yPos = map(analogRead(JOYSTICK_UPDOWN_PIN), 0, 1023, spotlightH, display.height() - spotlightH);

  Serial.println(xPos);
  Serial.println(yPos);

  drawEllipsis(xPos, yPos, spotlightW, spotlightH);
  display.drawRect(xPos, yPos, spotlightW, spotlightH, WHITE);

 if(mg2_buttonPressed) {
 
 } else if(mg2_buttonPressed) {

 }

 display.display();

  int buttonVal = digitalRead(BUTTON_PIN);
  if (buttonVal == LOW) {
    mg2_buttonPressed = true; // Set button state to pressed
  }

 delay(10);
}

void mg2_reset() {
 mg2_round = 1;
 mg2_health = 3;
 mg2_buttonPressed = false;
}


void drawEllipsis(int x0, int y0, int a, int b) {
  int x = 0, y = b;
  long a2 = a * a;
  long b2 = b * b;
  long twoa2 = 2 * a2;
  long twob2 = 2 * b2;
  long d = b2 - a2 * b + 0.25 * a2;

  while (b2 * (x + 1) < a2 * (y - 0.5)) {
    if (d < 0) {
      d += b2 * (2 * x + 3);
    } else {
      d += b2 * (2 * x + 3) + a2 * (-2 * y + 2);
      y--;
    }
    x++;
    drawEllipsisPoints(x0, y0, x, y);
  }

  d = b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2;

  while (y > 0) {
    if (d < 0) {
      d += b2 * (2 * x + 2) + a2 * (-2 * y + 3);
      x++;
    } else {
      d += a2 * (-2 * y + 3);
    }
    y--;
    drawEllipsisPoints(x0, y0, x, y);
  }
}

void drawEllipsisPoints(int x0, int y0, int x, int y) {
  display.drawPixel(x0 + x, y0 + y, WHITE);
  display.drawPixel(x0 - x, y0 + y, WHITE);
  display.drawPixel(x0 + x, y0 - y, WHITE);
  display.drawPixel(x0 - x, y0 - y, WHITE);
}