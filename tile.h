#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include <cmath>

#include "SDL_Plotter.h"
#include "constants.h"

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

        //access functions
        point getLocation() const;
        color getColor() const;
        int getSize() const;

        //mutator functions
        void setLocation(const point&);
        void setColor(const color&);
        void setSize(int);

        void draw(SDL_Plotter& g);
        void erase(SDL_Plotter& g);
        void move();
        void moveRight();
        void moveLeft();

        bool isCollide(const tile&) const;
};

#endif // TILE_H_INCLUDED
