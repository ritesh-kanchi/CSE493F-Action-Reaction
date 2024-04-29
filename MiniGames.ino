bool showedInstructions = false;

bool startedMG1 = false;
bool startedMG2 = false;
bool startedMG3 = false;

void miniGamePlayLoop() {
  if (!showedInstructions) {
    gameInstructions();
    showedInstructions = true;
  }

  display.setTextSize(1);

  if (_miniGameState == GAME_ONE) {
    if (mg1_round <= 3 && mg1_health > 0) {
      if (!startedMG1) {
        delay(500);
        startedMG1 = true;
      }
      miniGameOne();
    } else if (mg1_health <= 0) {
      gameOver(0);
    } else {
      winGame(0, mg1_health);
    }
  } else if (_miniGameState == GAME_TWO) {
    if (mg2_round <= 3 && mg2_health > 0) {
      if (!startedMG2) {
        delay(500);
        startedMG2 = true;
      }
      miniGameTwo();
    } else if (mg2_health <= 0) {
      gameOver(1);
    } else {
      winGame(1, mg2_health);
    }
  } else if (_miniGameState == GAME_THREE) {
    if (mg2_round <= 3 && mg3_health > 0) {
      if (!startedMG3) {
        delay(500);
        startedMG3 = true;
      }
      miniGameThree();
    } else if (mg3_health <= 0) {
      gameOver(2);
    } else {
      winGame(2, mg3_health);
    }
  }
}

void gameInstructions() {

  display.clearDisplay();
  drawTitle("Now playing:");

  int16_t x1, y1;
  uint16_t w1, h1;

  display.getTextBounds(GAMES[miniGameIndex], 0, 0, &x1, &y1, &w1, &h1);
  display.setCursor((centerHor - w1 / 2) - 24, 20);
  display.setTextSize(2);
  display.print(GAMES[miniGameIndex]);

  int16_t x2, y2;
  uint16_t w2, h2;

  display.getTextBounds(GAME_INSTRUCTIONS[miniGameIndex], 0, 0, &x2, &y2, &w2, &h2);
  display.setCursor((centerHor - w2 / 2) + 14, 40);
  display.setTextSize(1);
  display.print(GAME_INSTRUCTIONS[miniGameIndex]);

  display.display();

  delay(5000);
}

void resetMiniGames() {
  mg1_reset();
  mg2_reset();
  mg3_reset();
  startedMG3 = false;
  startedMG2 = false;
  startedMG1 = false;
}
