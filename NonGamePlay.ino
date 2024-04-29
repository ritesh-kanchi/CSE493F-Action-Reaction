void nonGamePlayLoop() {

  const char STR_PRESS_BUTTON_TO_PLAY[] = "Press button to play";

  int buttonVal = digitalRead(BUTTON_PIN);
  int16_t x1, y1;
  uint16_t w, h;

  Serial.println(buttonVal);

  if(_gameState == NEW_GAME) {
    display.clearDisplay();

    display.getTextBounds(STR_PRESS_BUTTON_TO_PLAY, 0, 0, &x1, &y1, &w, &h);
    display.setCursor(display.width() / 2 - w / 2, 40);
    display.print(STR_PRESS_BUTTON_TO_PLAY);
    display.display();

    if(buttonVal == LOW) {
      _gameState = PLAYING;
    }

  } else if (_gameState == GAME_OVER) {
    Serial.println("Game over!");
  }
}