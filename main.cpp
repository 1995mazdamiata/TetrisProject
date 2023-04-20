#include <iostream>
#include <cmath>
#include "SDL_Plotter.h"
#include "tile.h"
#include "block.h"
#include "constants.h"

using namespace std;

int main(int argc, char ** argv)
{

    SDL_Plotter g(NUM_ROW, NUM_COL);
    char key;

    Block b(square);
    b.setSize(g.getCol() / 12);

    /*
    tile a;
    a.setColor(RED);
    a.setSize(g.getCol() / 12);
    */

    while (!g.getQuit()){
		if(g.kbhit()){
            key = g.getKey();
            switch(key) {
                case RIGHT_ARROW:
                    b.moveRight();
                    break;
                case LEFT_ARROW:
                    b.moveLeft();
                    break;
                case UP_ARROW:
                    b.rotate();
                    break;
            }
		}

        b.move();
        b.draw(g);
		g.update();
		g.Sleep(10);

    }
}
