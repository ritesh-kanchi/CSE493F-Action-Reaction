const unsigned char heart_bitmap[] PROGMEM = {
  0x3c, 0xf0, 0x3c, 0xf0, 0xff, 0x0c, 0xff, 0x0c, 0xff, 0xcc, 0xff, 0xcc, 0x3f, 0xf0, 0x3f, 0xf0,
  0x0f, 0xc0, 0x0f, 0xc0, 0x03, 0x00, 0x03, 0x00
};

bool end_buttonPressed = false;

void ending(int gameIndex, char* STR, int hearts) {
  display.setTextSize(2);
  drawTitle(STR);
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