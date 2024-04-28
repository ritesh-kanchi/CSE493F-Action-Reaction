#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int POT_INPUT_PIN = A1;

const int TONE_OUTPUT_PIN = 8;
// const int VIBROMOTOR_OUTPUT_PIN = 9;

enum GameState {
  NEW_GAME,
  PLAYING,
  GAME_OVER
};

GameState _gameState = NEW_GAME;

const int DELAY_LOOP_MS = 5;

int PLAYER_HEALTH = 3;

void setup() {
  Serial.begin(9600);

  pinMode(POT_INPUT_PIN, INPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  showLoadScreen();
}

void loop() {
  display.clearDisplay();

  if(_gameState == NEW_GAME || _gameState == GAME_OVER) {
    nonGamePlayLoop();
  } else if (_gameState == PLAYING) {
    gamePlayLoop();
  } else {
    Serial.println("OUT???");
  }

    display.display();

  if (DELAY_LOOP_MS > 0) {
    delay(DELAY_LOOP_MS);
  }
}



const char STR_PRESS_FLAP_TO_PLAY[] = "Press flap to play";

void nonGamePlayLoop() {
  int16_t x1, y1;
  uint16_t w, h;
  if(_gameState == NEW_GAME) {
    display.clearDisplay();
    Serial.println("New game!");

    display.getTextBounds(STR_PRESS_FLAP_TO_PLAY, 0, 0, &x1, &y1, &w, &h);
    display.setCursor(display.width() / 2 - w / 2, 15);
    display.print(STR_PRESS_FLAP_TO_PLAY);

    display.display();

  } else if (_gameState == GAME_OVER) {
    Serial.println("Game over!");
  }
}

void gamePlayLoop() {
  Serial.println("In game play!");
  if(PLAYER_HEALTH < 1) {
    _gameState = GAME_OVER;
  }
}