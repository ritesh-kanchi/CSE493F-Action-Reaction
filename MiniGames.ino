bool showedInstructions = false;

void miniGamePlayLoop() {
  if(!showedInstructions) {
    gameInstructions();
    showedInstructions = true;
  }

  display.setTextSize(1);

  if(_miniGameState == GAME_ONE) {
    miniGameOne();
  } else if (_miniGameState == GAME_TWO) {
    miniGameTwo();
  } else if (_miniGameState == GAME_THREE) {
    miniGameThree();
  }
}

void gameInstructions() {
  int16_t x1, y1;
  uint16_t w, h;

  display.clearDisplay();
  drawTitle("Now playing:");

  display.getTextBounds(GAMES[miniGameIndex], 0, 0, &x1, &y1, &w, &h);
  display.setCursor(display.width() / 2 - w / 2, 12);
  display.setTextSize(2);
  display.print(GAMES[miniGameIndex]);

  display.display();

  delay(5000);
}