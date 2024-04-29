bool showedInstructions = false;

void miniGamePlayLoop() {
  if(!showedInstructions) {
    gameInstructions();
    showedInstructions = true;
  }

  display.setTextSize(1);

  if(_miniGameState == GAME_ONE) {
   if(mg1_round <= 3 && mg1_health > 0) {
    miniGameOne();
   } else if (mg1_health <= 0) {
    // game over
    drawTitle("GAME OVER!");
   } else {
    // great job
    drawTitle("GREAT JOB!");
   }
  } else if (_miniGameState == GAME_TWO) {
    miniGameTwo();
  } else if (_miniGameState == GAME_THREE) {
    miniGameThree();
  }
}

void gameInstructions() {

  display.clearDisplay();
  drawTitle("Now playing:");

  int16_t x1, y1;
  uint16_t w1, h1;

  display.getTextBounds(GAMES[miniGameIndex], 0, 0, &x1, &y1, &w1, &h1);
  display.setCursor((centerHor - w1 / 2) - 22, 20);
  display.setTextSize(2);
  display.print(GAMES[miniGameIndex]);

  int16_t x2, y2;
  uint16_t w2, h2;

  display.getTextBounds(GAME_INSTRUCTIONS[miniGameIndex], 0, 0, &x2, &y2, &w2, &h2);
  display.setCursor((centerHor - w2 / 2) + 14, 42);
  display.setTextSize(1);
  display.print(GAME_INSTRUCTIONS[miniGameIndex]);

  display.display();

  delay(5000);
}

void resetMiniGames() {
  mg1_reset();
  mg2_reset();
  mg3_reset();
}
