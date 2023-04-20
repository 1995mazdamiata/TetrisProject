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
    int xrotation;
    int yrotation;
    int rotCount;
    blockType type;


public:
    Block(blockType);

    void setLoc(const point&);
    void setColor(const color&);
    void setType(const blockType);
    void setSize(const int);

    point getLoc() const;
    color getShade() const;
    blockType getType() const;
    int getSize();

    void draw(SDL_Plotter& g);
    void move();
    void moveRight();
    void moveLeft();
    void rotate();

};

#endif // BLOCK_H_INCLUDED
