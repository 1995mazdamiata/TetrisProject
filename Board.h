#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include <cmath>

#include "block.h"
#include "constants.h"

using namespace std;

struct board{

    bool filledTiles[HEIGHT_IN_TILES][WIDTH_IN_TILES];

    void deleteRow(int row);
    void dropRows(int row);

};

void drawBackground(SDL_Plotter& g, color c);
void updateBoard(board& a/*int& score?*/);

#endif // BOARD_H_INCLUDED
