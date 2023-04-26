#include "tile.h"

void tile::move()
{
    point p = getLocation();
    p.y++;
    setLocation(p);
}

void tile::moveLeft()
{
   point p = getLocation();
   p.x -= size;
   setLocation(p);
}

void tile::moveRight()
{
    point p = getLocation();
    p.x += size;
    setLocation(p);
}

// "::" attaches the draw method to the tile object
void tile::draw(SDL_Plotter& g)
{
    color currColor;
    //erase
    for(int r = 0; r < size; r++) {
        for(int c = 0; c < size; c++) {
            g.plotPixel(prevLoc.x + c, prevLoc.y + r, BACKGROUND);
        }
    }

    //draw
    for(int r = 0; r < size; r++) {
        for(int c = 0; c < size; c++) {
            currColor = shade;
            if((c == 0) || (r == 0) || (r == size - 1) || (c == size - 1)) {
                currColor = BLACK;
            }
            g.plotPixel(loc.x + c, loc.y + r, currColor);
        }
    }
    prevLoc = loc;
}

void tile::erase(SDL_Plotter& g) {
    for(int r = 0; r < size; r++) {
        for(int c = 0; c < size; c++) {
            g.plotPixel(loc.x + c, loc.y + r, BACKGROUND);
        }
    }
}

point tile::getLocation() const
{
    return loc;
}

color tile::getColor() const
{
    return shade;
}

int tile::getSize() const
{
    return size;
}

void tile::setLocation(const point& p)
{
    if((p.x >= 0) && (p.y >= 0) &&
       (p.x < NUM_COL - size) && (p.y < NUM_ROW - size)) {
           loc = p;
    }
}

void tile::setColor(const color& c)
{
    shade = c;
}

void tile::setSize(int s)
{
    size = s;
}

bool tile::isCollide(const tile& other) const {
    bool collide = false;
    if((abs(getLocation().x - other.getLocation().x) < 2*size)  &&
       (abs(getLocation().y - other.getLocation().y) < 2*size)) {
        collide = true;
    }
    return collide;
}
