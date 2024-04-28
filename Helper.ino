void drawTitle(char* STR) {
  int16_t x1, y1;
  uint16_t w, h;

  display.getTextBounds(STR, 0, 0, &x1, &y1, &w, &h);
  display.setCursor(display.width() / 2 - w / 2, 4);
  display.print(STR);
}