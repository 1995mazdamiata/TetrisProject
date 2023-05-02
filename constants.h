#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#include "SDL_Plotter.h"

const int NUM_ROW = 766;
const int NUM_COL = 541;
const int SCORE_HEIGHT = 100;
const int HEIGHT_IN_TILES = 17;
const int WIDTH_IN_TILES = 12;

const int NUM_TILES = 4;

const color RED = color(255, 0, 0);
const color ORANGE = color(255, 127, 0);
const color YELLOW = color(255, 255, 0);
const color GREEN = color(0, 255, 0);
const color LIGHTBLUE = color(0, 255, 255);
const color BLUE = color(0, 0 ,255);
const color PURPLE = color(160, 32, 240);
const color BLACK = color(0,0,0);
const color GRAY = color(127, 127, 127);
const color WHITECOLOR = color(255, 255, 255);
const color BACKGROUND = GRAY;
const color START = color(36, 128, 156);

enum blockType {bar, square, l_shape1, l_shape2, t_shape, z_shape};

#endif // CONSTANTS_H_INCLUDED
