/*
Authors: Nicholas Storti, Alex Truitt, Jacob Meyer, Olivia Calusinski,
Jackson Davidson, Aidan Highsmith, and Piya Patel
Assignment Description: A group project using various classes and structures
that create a slightly more difficult version of tetris.
Date Created: 4/15/2023
Due Date: 5/4/2023
Date Last Modified: 5/4/2023
*/

#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include <cmath>

#include "SDL_Plotter.h"
#include "constants.h"

/*
Description: Tile class that has functions and variables
that allow for a tile to be created and perform various
functions.
Precondition: A tile object must exist.
Postcondition: Tile class allows for the creation,
movement, coloring, etc of a tile.
Return: Point, Color, Void, Tile, and Bool
*/

class tile{
    private:
        point loc;
        point prevLoc;
        color shade;
        int   size;

    public:
        tile()
        {
            size = 45;
        }
        /* 
        Description: Constructor function that initializes size.
        Precondition: A tile object must exist.
        Postcondition: Function sets size of a tile to 45.
        Return: Tile
        */
        //access functions
        point getLocation() const;
        /* 
        Description: Function that returns the location
        of a tile.
        Precondition: A tile object must exist.
        Postcondition: Function returns the location of a tile.
        Return: Point
        */
        color getColor() const;
        /* 
        Description: Function that returns the color of a color.
        Precondition: A tile object must exist.
        Postcondition: Function returns the color of a tile.
        Return: Color
        */
        int getSize() const;
        /* 
        Description: Function that returns the size of a tile.
        Precondition: A tile object must exist.
        Postcondition: Function returns the size of a tile.
        Return: Integer
        */
        //mutator functions
        void setLocation(const point&);
        /* 
        Description: Function that sets the location of a tile.
        Precondition: A tile object and a point object must exist.
        Postcondition: Function sets the location of a tile
        if the tile exists within the parameters of the screen.
        Return: Void
        */
        void setColor(const color&);
        /* 
        Description: Function that sets the color of a tile.
        Precondition: A tile object and a color object
        must exist.
        Postcondition: Function sets the color of a tile
        to the color object parameter.
        Return: Void
        */
        void setSize(int);
        /*
        Description: Function that sets the size of a tile.
        Precondition: A tile object and an integer
        value must exist.
        Postcondition: Function sets the size of a tile to
        the integer value parameter.
        Return: Void
        */
        void draw(SDL_Plotter& g);
        /*
        Description: Function that draws a tile to the screen.
        Precondition: A tile object and a SDL Plotter
        object must exist.
        Postcondition: Function draws a tile to the screen while erasing
        its previous location.
        Return: Void
        */
        void erase(SDL_Plotter& g);
        /* 
        Description: Function that erases a tile from the screen.
        Precondition: A tile object and a SDL Plotter
        object must exist.
        Postcondition: Function erases a tile from the screen
        when called.
        Return: Void
        */
        void move();
        /* 
        Description: Function that allows for the movement
        of a tile.
        Precondition: A tile object must exist.
        Postcondition: Function moves a tile.
        Return: Void
        */
        void moveRight();
        /* 
        Description: Function that moves a tile to the right.
        Precondition: A tile object must exist.
        Postcondition: Function moves tile to the right when
        called.
        Return: Void
        */
        void moveLeft();
        /* 
        Description: Function that moves a tile to the left.
        Precondition: A tile object must exist.
        Postcondition: Function moves tile to the left when
        called.
        Return: Void
        */
        bool isCollide(const tile&) const;
        /* 
        Description: Function that tells whether a tile collides
        with another tile or not.
        Precondition: Two tile objects must exist.
        Postcondition: Function returns a boolean value of true
        if two tiles collide and false if they do not touch, and
        the other tile must remain unchanged.
        Return: Bool
        */
};

#endif // TILE_H_INCLUDED
