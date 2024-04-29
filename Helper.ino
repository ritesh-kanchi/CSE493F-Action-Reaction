void drawTitle(char* STR) {
  int16_t x1, y1;
  uint16_t w, h;

  display.getTextBounds(STR, 0, 0, &x1, &y1, &w, &h);
  display.setCursor(centerHor - w / 2, 4);
  display.print(STR);
}

void reset() {
  _gameState = NEW_GAME;
  _joystickState = NO_MOVEMENT;
  _miniGameState = NO_GAME;
  miniGameIndex = -1;
  gameSelected = false;
}
