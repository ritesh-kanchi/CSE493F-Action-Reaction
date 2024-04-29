// 'thief1', 11x16px
const unsigned char thief1_bitmap [] PROGMEM = {
	0xf1, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xf1, 0xe0, 0xfb, 0x80, 0xfb, 0x60, 0xf2, 0xe0, 
	0xe9, 0xe0, 0xdb, 0xe0, 0x3b, 0xe0, 0xfb, 0xe0, 0xf5, 0xe0, 0xee, 0xe0, 0xdf, 0x60, 0xbf, 0xa0
};
// 'thief2', 5x9px
const unsigned char thief2_bitmap [] PROGMEM = {
	0x88, 0x88, 0x88, 0xd8, 0x90, 0x48, 0xd8, 0xa8, 0x70
};
// 'thief3', 3x6px
const unsigned char thief3_bitmap [] PROGMEM = {
	0x80, 0x80, 0xa0, 0x00, 0xa0, 0x40
};

const unsigned char* thief_bitmaps[3] = {
	thief1_bitmap,
	thief2_bitmap,
	thief3_bitmap
};

const int thief_bitmap_sizes[3][2] = {{11,16},{5,9},{3,6}};

int mg2_round = 1;
int mg2_health = 3;

bool mg2_buttonPressed = false;


int randomThiefX = random(0, display.width() - thief_bitmap_sizes[mg2_round - 1][0]);
int randomThiefY = random(10, display.height() - thief_bitmap_sizes[mg2_round - 1][1]);

void miniGameTwo() {
 display.clearDisplay();

  drawStatus(mg2_round, mg2_health);

  int spotlightW = 16; // Constant width
  int spotlightMaxH = 12; // Maximum height
  int spotlightMinH = 6; // Minimum height near the edges

  // Map joystick position to spotlight position
  int xPos = map(analogRead(JOYSTICK_LEFTRIGHT_PIN), 0, 1023, spotlightW, display.width() - spotlightW);
  int yPos = map(analogRead(JOYSTICK_UPDOWN_PIN), 0, 1023, 0, display.height());

  // Calculate spotlight height based on position
  int spotlightH = map(abs(yPos - display.height() / 2), 0, display.height() / 2, spotlightMaxH, spotlightMinH);
  yPos = map(analogRead(JOYSTICK_UPDOWN_PIN), 0, 1023, spotlightH, display.height() - spotlightH - 1);

  fillEllipsis(xPos, yPos, spotlightW, spotlightH);

  display.drawBitmap(randomThiefX, randomThiefY, thief_bitmaps[mg2_round - 1], thief_bitmap_sizes[mg2_round - 1][0],  thief_bitmap_sizes[mg2_round - 1][1], BLACK);

  display.display();

  int buttonVal = digitalRead(BUTTON_PIN);
  if (buttonVal == LOW) {
    mg2_buttonPressed = true; // Set button state to pressed
  }

 delay(10);
}

void mg2_reset() {
 mg2_round = 1;
 mg2_health = 3;
 mg2_buttonPressed = false;
}

void fillEllipsis(int x0, int y0, int a, int b) {
  int x = 0, y = b;
  long a2 = a * a;
  long b2 = b * b;
  long twoa2 = 2 * a2;
  long twob2 = 2 * b2;
  long d = b2 - a2 * b + 0.25 * a2;

  while (b2 * (x + 1) < a2 * (y - 0.5)) {
    if (d < 0) {
      d += b2 * (2 * x + 3);
    } else {
      d += b2 * (2 * x + 3) + a2 * (-2 * y + 2);
      y--;
    }
    x++;
    drawEllipsisLine(x0, y0, x, y);
  }

  d = b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2;

  while (y > 0) {
    if (d < 0) {
      d += b2 * (2 * x + 2) + a2 * (-2 * y + 3);
      x++;
    } else {
      d += a2 * (-2 * y + 3);
    }
    y--;
    drawEllipsisLine(x0, y0, x, y);
  }
}

void drawEllipsisLine(int x0, int y0, int x, int y) {
  display.drawFastHLine(x0 - x, y0 - y, 2 * x, WHITE);
  display.drawFastHLine(x0 - x, y0 + y, 2 * x, WHITE);
}


// void drawEllipsis(int x0, int y0, int a, int b) {
//   int x = 0, y = b;
//   long a2 = a * a;
//   long b2 = b * b;
//   long twoa2 = 2 * a2;
//   long twob2 = 2 * b2;
//   long d = b2 - a2 * b + 0.25 * a2;

//   while (b2 * (x + 1) < a2 * (y - 0.5)) {
//     if (d < 0) {
//       d += b2 * (2 * x + 3);
//     } else {
//       d += b2 * (2 * x + 3) + a2 * (-2 * y + 2);
//       y--;
//     }
//     x++;
//     drawEllipsisPoints(x0, y0, x, y);
//   }

//   d = b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2;

//   while (y > 0) {
//     if (d < 0) {
//       d += b2 * (2 * x + 2) + a2 * (-2 * y + 3);
//       x++;
//     } else {
//       d += a2 * (-2 * y + 3);
//     }
//     y--;
//     drawEllipsisPoints(x0, y0, x, y);
//   }
// }

// void drawEllipsisPoints(int x0, int y0, int x, int y) {
//   display.drawPixel(x0 + x, y0 + y, WHITE);
//   display.drawPixel(x0 - x, y0 + y, WHITE);
//   display.drawPixel(x0 + x, y0 - y, WHITE);
//   display.drawPixel(x0 - x, y0 - y, WHITE);
// }