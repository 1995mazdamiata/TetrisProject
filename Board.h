#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include <cmath>
#include "SDL_Plotter.h"
#include "tile.h"
#include "block.h"
#include "constants.h"
#include "EndScreen.h"
#include "Board.h"

using namespace std;



struct board{

    bool filledTiles[HEIGHT_IN_TILES][WIDTH_IN_TILES];

    void deleteRow(int row);
    void dropRows(int row);

};

void updateBoard(board& a/*int& score?*/);

#endif // BOARD_H_INCLUDED
