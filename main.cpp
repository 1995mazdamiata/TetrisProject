#include <iostream>
#include <cmath>
#include "SDL_Plotter.h"
#include "tile.h"
#include "block.h"
#include "constants.h"
#include "Board.h"

using namespace std;



int main(int argc, char ** argv)
{
    SDL_Plotter g(NUM_ROW, NUM_COL);
    char key;
    point origin(45*5, 0);
    Block b;
    board Board1;
    bool collided = false;

    drawBackground(g, BACKGROUND);
    b.setType(randomBlock());
    b.setSize(g.getCol() / 12);
    b.setLoc(origin);

    b.setType(randomBlock());
    b.setLoc(origin);

    while (!g.getQuit()){
		if(g.kbhit()){
            key = g.getKey();
            switch(key) {
                case RIGHT_ARROW:
                    if(!Board1.collision(b)) {
                     b.moveRight();
                    }
                    else {
                        collided = true;
                    }
                    break;
                case LEFT_ARROW:
                    if(!Board1.collision(b)) {
                        b.moveLeft();
                    }
                    else {
                        collided = true;
                    }
                    break;
                case UP_ARROW:
                    if(!Board1.collision(b)) {
                        b.rotate();
                    }
                    else {
                        collided = true;
                    }
                    break;
            }
        }
        if(!Board1.collision(b)) {
            b.move();
        }
        else {
            collided = true;
        }
        b.draw(g);
		g.update();

        if((b.getLoc().y > NUM_ROW - (2*b.getSize()))
           || collided) {
            Board1.replaceBlockWithTiles(b);
            b.setType(randomBlock());
            b.setLoc(origin);
            updateBoard(Board1, g);
            collided = false;
        }
        Board1.drawBoard(g);

		g.Sleep(5);

    }
}
