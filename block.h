/*
Authors: Nicholas Storti, Alex Truitt, Jacob Meyer, Olivia Calusinski,
Jackson Davidson, Aidan Highsmith, and Piya Patel
Assignment Description: A group project using various classes and structures
that create a slightly more difficult version of tetris.
Date Created: 4/15/2023
Due Date: 5/4/2023
Date Last Modified: 5/4/2023
*/
#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include "tile.h"
#include "SDL_Plotter.h"
#include "constants.h"


/* 
Description: A block class that contains private variables and
public functions that arrange tiles together into blocks.
Precondition: The game must be started and the player must not have
lost yet.
Postcondition: Functions allow the block to be moved and acted on in other ways.
Return: Point, color, blockType, int, tile, or void
*/

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
    /* 
    Description: A constructor function that sets the blockType
    to the square tetris block.
    Precondition: A block object must exist.
    Postcondition: The default block type is set to square.
    Return: Block
    */
    void setLoc(const point&);
    /*
    Description: Function that sets the location of a block.
    Precondition: A block object and a constant point
    object must exist.
    Postcondition: The location of the block is set based
    on the locations of the individual locations of the tiles
    of the block and the point remains unchanged.
    Return: Void
    */
    void setColor(const color&);
    /* 
    Description: Function that sets the color of a tetris block.
    Precondition: A block object and a color object must exist
    Postcondition: The color of a block is set to a certain color
    by coloring each tile of the block and the color remains the same.
    Return: Void
    */
    void setType(const blockType);
    /* 
    Description: Function that sets the type and based on the type,
    the color as well.
    Precondition: A block object and a blockType enum must exist.
    Postcondition: The block type and color based on the block type are set
    while also setting the rotation variables of the blocks based on type.
    Return: Void
    */
    void setSize(const int);
    /* 
    Description: Function that sets the size of the tiles of the block.
    Precondition: A block object and a constant integer must
    exist.
    Postcondition: The size of the tiles of a block are set to an integer
    size.
    Return: Void
    */
    point getLoc() const;
    /* 
    Description: Function that returns the location of a block.
    Precondition: A block object must exist.
    Postcondition: The point location of a block is returned.
    Return: Point
    */
    color getShade() const;
    /*
    Description: Function that returns the color of a block.
    Precondition: A block object must exist.
    Postcondition: The color value of a block is returned.
    Return: Color
    */
    blockType getType() const;
    /*
    Description: Function that returns the type of a block.
    Precondition: A block object must exist.
    Postcondition: The type of a block is returned.
    Return: blockType
    */
    int getSize() const;
    /*
    Description: Function that returns the size of a block.
    Precondition: A block object must exist.
    Postcondition: The integer value of the size of the tiles
    of a bloack is returned.
    Return: Integer
    */
    tile getTile(int index) const;
    /*
    Description: Function that returns a tile based on an integer
    index.
    Precondition: A block object and an integer value must
    exist.
    Postcondition: The function returns a tile from an array at element
    index.
    Return: Tile
    */
    void draw(SDL_Plotter& g);
    /* 
    Description: Function that draws the block.
    Precondition: A block object & a SDL Plotter
    object must exist.
    Postcondition: Function draws a tetris block by drawing the
    individual tiles of the block.
    Return: Void
    */
    void move();
    /*
    Description: Function that moves the blocks
    Precondition: A block object must exist.
    Postcondition: The movement of a block is determined by its Block type
    and individual tiles and this function allows for the movement of the
    individual tiles of the block to be synchronized.
    Return: Void
    */
    void moveRight();
    /* 
    Description: Function that moves a block to the right.
    Precondition: A block object must exist.
    Postcondition: This function allows for the rightward movement of all
    tetris blocks by moving each individual tile of the blocks to the right.
    Return: Void
    */
    void moveLeft();
    /* 
    Description: Function that moves a block to the left.
    Precondition: A block object must exist.
    Postcondition: This function allows for the leftward movement of all
    tetris blocks by moving each individual tile of the blocks to the left.
    Return: Void
    */
    void rotate();
    /*
    Description: Function that rotates a block.
    Precondition: A block object must exist.
    Postcondition: This function rotates a tetris block by rotating the tiles
    of a tetris block in a certain way based on the block type and the type
    and position of the rotation.
    Return: Void
    */

};

#endif // BLOCK_H_INCLUDED
