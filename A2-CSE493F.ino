#include <Shape.hpp>;
#include <ParallaxJoystick.hpp>;

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

const int JOYSTICK_UPDOWN_PIN = A4;
const int JOYSTICK_LEFTRIGHT_PIN = A5;
const int JOYSTICK_BUTTON_PIN = 7;
const int MAX_ANALOG_VAL = 1023;
const enum JoystickYDirection JOYSTICK_Y_DIR = RIGHT;

const int BUTTON_PIN = 4;

ParallaxJoystick _analogJoystick(JOYSTICK_UPDOWN_PIN, JOYSTICK_LEFTRIGHT_PIN, MAX_ANALOG_VAL, JOYSTICK_Y_DIR);

const int TONE_OUTPUT_PIN = 8;
// const int VIBROMOTOR_OUTPUT_PIN = 9;

enum GameState {
  NEW_GAME,
  PLAYING,
  GAME_OVER
};

enum JoystickState {
  MOVING_LEFT,
  MOVING_RIGHT,
  NO_MOVEMENT
};

enum MiniGameState {
  GAME_ONE,
  GAME_TWO,
  GAME_THREE,
  NO_GAME
};

GameState _gameState = NEW_GAME;
JoystickState _joystickState = NO_MOVEMENT;
MiniGameState _miniGameState = NO_GAME;
int miniGameIndex = -1;

bool gameSelected = false;

const int DELAY_LOOP_MS = 5;

const char* GAMES[] = {"BallCatch", "Spotlight", "Game 3"};
const char* GAME_INSTRUCTIONS[] = {"Press the BUTTON\n  to catch the ball.","Use the JOYSTICK & BUTTON to the find the thief.","Spinner"};

const int centerHor = display.width()/2;
const int centerVer = display.height()/2;

void setup() {
  Serial.begin(9600);

  pinMode(POT_INPUT_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(JOYSTICK_BUTTON_PIN, INPUT_PULLUP);

  initializeOledAndShowStartupScreen();
  randomSeed(analogRead(A0));
}

void loop() {
  display.clearDisplay();

  if(digitalRead(JOYSTICK_BUTTON_PIN) == LOW) {
    reset();
  }

  if(_gameState == NEW_GAME || _gameState == GAME_OVER) {
    nonGamePlayLoop();
  } else if (_gameState == PLAYING && _miniGameState == NO_GAME) {
    gameSelectionLoop();
  } else if(_miniGameState != NO_GAME) {
    miniGamePlayLoop();
  }

  display.display();

  if (DELAY_LOOP_MS > 0) {
    delay(DELAY_LOOP_MS);
  }
}