#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = 255;
  c.green = 255;
  c.blue = 255;

  clear_screen(s);

  //Freedom tower
  draw_line(225, 25, 225, 350, s, c);
  draw_line(275, 25, 275, 350, s, c);
  draw_line(225, 25, 275, 25, s, c);
  draw_line(225, 350, 250, 365, s, c);
  draw_line(250, 365, 275, 350, s, c);
  draw_line(225, 25, 250, 365, s, c);
  draw_line(275, 25, 250, 365, s, c);
  draw_line(237, 357, 237, 370, s, c);
  draw_line(263, 357, 263, 370, s, c);
  draw_line(237, 370, 263, 370, s, c);
  draw_line(250, 370, 250, 425, s, c);
  printf("FILE NAME: lines.png\n");

  //display(s);
  save_extension(s, "lines.png");
}
