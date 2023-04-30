#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include <cmath>
#include <time.h>
#include <vector>

#include "block.h"
#include "constants.h"
#include "score.h"

using namespace std;

struct board{

    bool filledTiles[HEIGHT_IN_TILES][WIDTH_IN_TILES];
    tile data[HEIGHT_IN_TILES][WIDTH_IN_TILES];

    board();
    void replaceBlockWithTiles(Block b);
    void drawBoard(SDL_Plotter& g);
    void deleteRow(int row);
    void dropRows(int row);
    bool collision(Block b);
    bool lateralCollisionRight(Block b);
    bool lateralCollisionLeft(Block b);
    bool bottom(Block b);
    bool endGame();
    void resetBoard(SDL_Plotter& g);

};

blockType randomBlock();
void drawBackground(SDL_Plotter& g, color c);
void updateBoard(board& a, SDL_Plotter& g, scoreCounter& c);

#endif // BOARD_H_INCLUDED
