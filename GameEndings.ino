const unsigned char heart_bitmap[] PROGMEM = {
  0x3c, 0xf0, 0x3c, 0xf0, 0xff, 0x0c, 0xff, 0x0c, 0xff, 0xcc, 0xff, 0xcc, 0x3f, 0xf0, 0x3f, 0xf0,
  0x0f, 0xc0, 0x0f, 0xc0, 0x03, 0x00, 0x03, 0x00
};

bool end_buttonPressed = false;

void winGame(int gameIndex, int hearts) {
  display.setTextSize(2);
  drawTitle("GREAT JOB!");
  display.setTextSize(1);

  for (int i = 0; i < hearts; i++) {
    display.drawBitmap(36 + (i * 20), 26, heart_bitmap, 14, 12, WHITE);
  }

  drawBottomTitle("Press BUTTON for more");

  if (end_buttonPressed) {
    end_buttonPressed = false;
    backToSelection();
  }

  if (digitalRead(BUTTON_PIN) == LOW && !end_buttonPressed) {
    end_buttonPressed = true;
  }

  delay(100);
}

void gameOver(int gameIndex) {
  display.setTextSize(2);
  drawTitle("GAME OVER");
  display.setTextSize(1);


  int16_t x1, y1;
  uint16_t w1, h1;

  // display.getTextBounds(GAME_LOSING[miniGameIndex], 0, 0, &x1, &y1, &w1, &h1);
  // display.setCursor((centerHor - w1 / 2) + 26, 24);
  // display.print(GAME_LOSING[miniGameIndex]);

  drawBottomTitle("Press BUTTON for more");



  if (end_buttonPressed) {
    end_buttonPressed = false;
    backToSelection();
  }

  // Serial.println(digitalRead(BUTTON_PIN));

  if (digitalRead(BUTTON_PIN) == LOW && !end_buttonPressed) {
    end_buttonPressed = true;
  }

  delay(100);
}