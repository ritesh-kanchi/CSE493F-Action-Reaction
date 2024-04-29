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

  resetMiniGames();
}

void backToSelection() {
  _gameState = PLAYING;
  _joystickState = NO_MOVEMENT;
  _miniGameState = NO_GAME;
  miniGameIndex = -1;
  gameSelected = false;

  resetMiniGames();
}

void drawBottomTitle(char* STR) {
  int16_t x1, y1;
  uint16_t w, h;

  display.getTextBounds(STR, 0, 0, &x1, &y1, &w, &h);
  display.setCursor(centerHor - w / 2, 52);
  display.print(STR);
}

void drawStatus(int round, int health) {
  display.setCursor(0, 0);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.print("Round:");
  display.print(round);
  display.print(" | Health: ");
  display.println(health);

}
