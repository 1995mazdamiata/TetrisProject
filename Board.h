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

/* 
Description: A board Structure that contains private variables and
functions that deal with the area of the game, tracking positions
of all blocks and collisions.
Precondition: The game must be started and the player must not have
lost yet.
Postcondition: Functions in the class return a bool or void
value that deals with the makings of the game grind.
certain things while not changing values that should not be changed.
Return: Bool or Void
*/

struct board{

    bool filledTiles[HEIGHT_IN_TILES][WIDTH_IN_TILES];
    tile data[HEIGHT_IN_TILES][WIDTH_IN_TILES];

    board();
    /* Board()
    Description: Constructor function that initializes the
    filled tile matrix to false and the data matrix all to background tiles.
    Precondition: A member of board must exist.
    Postcondition: Functions initializes fillied tile matrix to false
    and the data matrix to background tiles.
    certain things while not changing values that should not be changed.
    Return: Board
    */
    void replaceBlockWithTiles(Block b);
    /*
    Description: Function that converts blocks to tiles so that the board
    can redraw the tiles after a row has been deleted.
    Precondition: A member of board and a tetris block must exist.
    Postcondition: Function converts a tetris block to individual tiles.
    Return: Void
    */
    void drawBoard(SDL_Plotter& g);
    /*
    Description: Function that draws all the tiles in the board, checking
    for filled tiles to draw tetris blocks.
    Precondition: A member of board and an SDL_Plotter object
    must exist.
    Postcondition: Function draws the board, drawing tetris blocks
    and background tiles when necessary.
    Return: Void
    */
    void deleteRow(int row);
    /*
    Description: Function that sets the filled tiles of a row to
    false.
    Precondition: A member of board must exist.
    Postcondition: Function converts the filled tiles of a row to false
    so that the board redraws the row as background and allows for tiles
    above to drop.
    Return: Void
    */
    void dropRows(int row);
    /* 
    Description: Function that drops a row of tiles after a row is deleted
    due to the whole row being filled.
    Precondition: A member of board must exist.
    Postcondition: Function drops a whole row of tiles after a the row below
    was deleted.
    Return: Void
    */
    bool collision(Block b);
    /* 
    Description: Function that checks for collision of tiles on the
    bottom of tiles.
    Precondition: A member of board must exist.
    Postcondition: Checks the current moving tiles with the filled tiles
    of the board for a collision and returns true if a collision occurs.
    Return: Bool
    */
    bool lateralCollisionRight(Block b);
    /*
    Description: A function that checks whether tiles collide laterally on
    the right side of the tiles.
    Precondition: A block object must exist.
    Postcondition: Function returns true if two tiles laterally collide
    on the right and false if not.
    Return: Bool
    */
    bool lateralCollisionLeft(Block b);
    /*
    Description: A function that checks whether tiles collide laterally on
    the left side of the tiles.
    Precondition: A block object must exist.
    Postcondition: Function returns true if two tiles laterally collide
    on the left and false if not.
    Return: Bool
    */
    bool bottom(Block b);
    /* 
    Description: Function that checks whether a block has reached the bottom
    of the board.
    Precondition: A board object and a tetris block must exist.
    Postcondition: Function returns a boolean value of true if the bottom
    of the board has been reached and false if not.
    Return: Bool
    */
    bool endGame();
    /*
    Description: Function that checks whether a tile touches the roof
    of the display and thus game over.
    Precondition: A game must exist.
    Postcondition: Function returns true if a tile touches the roof of the 
    board and false if not.
    Return: Bool
    */
    void resetBoard(SDL_Plotter& g);
    /*
    Description: Function that resets the board to the background.
    Precondition: A SDL_Plotter object must exist.
    Postcondition: Function resets the board back to the background
    display.
    Return: Void
    */

};

blockType randomBlock();
/* 
Description: Function that randomizes the block type of blocks.
Precondition: A blockType enum must exist.
Postcondition: Function returns one of the enumerated block types based
on a seeded random value generator.
Return: blockType
*/
void drawBackground(SDL_Plotter& g, color c);
/*
Description: Function that draws the background of the board.
Precondition: A SDL Plotter object and color object must exist.
Postcondition: The entire board is covered with a background color.
Return: Void
*/
void updateBoard(board& a, SDL_Plotter& g, scoreCounter& c);
/* UpdateBoard()
Description: Function that updates the board based on new
blocks and scores.
Precondition: A board object, SDL Plotter object, and
a scoreCounter object must exist.
Postcondition: Function redraws the current board to update the new
tetris blocks and positions of deleted/dropped blocks.
Return: Void
*/
#endif // BOARD_H_INCLUDED
