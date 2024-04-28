void gameSelectionLoop() {
  static int selectedGame = 0;
  static int lastjoystickState = NO_MOVEMENT; // Store the last joystick state
  int x_dir = analogRead(JOYSTICK_LEFTRIGHT_PIN);
  int _joystickState = NO_MOVEMENT; // Initialize joystick state

  int16_t x1, y1;
  uint16_t w, h;

  if (x_dir > 503 + 100) {
    _joystickState = MOVING_RIGHT;
  } else if (x_dir < 503 - 100) {
    _joystickState = MOVING_LEFT;
  }

  if (_joystickState != lastjoystickState) { // Only update if there's a change in joystick state
    if (_joystickState == MOVING_RIGHT) {
      selectedGame = (selectedGame + 1) % 3;
    } else if (_joystickState == MOVING_LEFT) {
      selectedGame = (selectedGame - 1 + 3) % 3; // Ensuring positive modulo
    }
    lastjoystickState = _joystickState; // Update last joystick state
    Serial.println(selectedGame);
  }

  int buttonVal = digitalRead(BUTTON_PIN);
  if (buttonVal == LOW) { // Assuming LOW means the button is pressed
    // Do something with the selected game
    miniGameIndex = selectedGame;
    if(selectedGame == 0) {
      _miniGameState = GAME_ONE;
    } else if (selectedGame == 1) {
      _miniGameState = GAME_TWO;
    } else if (selectedGame == 2) {
      _miniGameState = GAME_THREE;
    }
  }

  display.clearDisplay();
  drawTitle("Choose a game!");

  for(int i = 0; i < 3; i++) {
    drawGameRect(i, selectedGame == i, (i*40)+(i*2), GAMES[i]);
  }

  display.display();

  display.setTextColor(WHITE);

  delay(50);
}

void drawGameRect(int num, bool selected, int x, char* STR_GAME_NAME) {

  int16_t x1, y1;
  uint16_t w, h;

  int width = 40;
  int height = 48;

  int y = 16;

  if(selected) {
    display.fillRect(x, y, width, height, WHITE);
    display.setTextColor(BLACK);
    display.getTextBounds(STR_GAME_NAME, 0, 0, &x1, &y1, &w, &h);
    display.setCursor(x+3, 36);
    display.print(STR_GAME_NAME);
  } else {
    display.drawRect(x, y, width, height, WHITE);
    display.setTextColor(WHITE);
    display.getTextBounds(STR_GAME_NAME, 0, 0, &x1, &y1, &w, &h);
    display.setCursor(x+3, 36);
    display.print(STR_GAME_NAME);
  }
}