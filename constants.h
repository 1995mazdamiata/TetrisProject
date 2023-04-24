#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#include "SDL_Plotter.h"

const int NUM_ROW = 765;
const int NUM_COL = 541;
const int HEIGHT_IN_TILES = 17;
const int WIDTH_IN_TILES = 8;

const int NUM_TILES = 4;

const color RED = color(220, 20, 20);
const color GREEN = color(20, 220, 20);
const color BLUE = color(20, 20 ,220);
const color YELLOW = color(220, 220, 20);
const color PURPLE = color(160, 32, 240);
const color ORANGE = color(255, 165, 0);
const color BLACK = color(0,0,0);
const color GRAY = color(127, 127, 127);
const color BACKGROUND = GRAY;

enum blockType {bar, square, l_shape1, l_shape2, t_shape, z_shape};
//enum direction (north, east, south, west);

#endif // CONSTANTS_H_INCLUDED
