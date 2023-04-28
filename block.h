// Author: Olivia Calusinski, Alex Truitt,
// Aiden Highsmith, Jackson Davidson,
// Jacob Meyer, Nick Storti, Piya Patel
// Assignment Title: Tetris
// Assignment Description: Tetris
// Due Date: 5/3/2023
// Date Created: 4/3/2023
// Date Last Modified: 5/3/2023

#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include "tile.h"
#include "SDL_Plotter.h"
#include "constants.h"

class Block{
private:
    tile data[NUM_TILES];
    point loc;
    point prevLoc;
    color shade;
    int size;
    int xrotation[NUM_TILES];
    int yrotation[NUM_TILES];
    int rotCount = 0;
    blockType type;


public:
    Block();

    void setLoc(const point&);
    void setColor(const color&);
    void setType(const blockType);
    void setSize(const int);

    point getLoc() const;
    color getShade() const;
    blockType getType() const;
    int getSize() const;
    tile getTile(int index) const;

    void draw(SDL_Plotter& g);
    void move();
    void moveRight();
    void moveLeft();
    void rotate();


};

#endif // BLOCK_H_INCLUDED
