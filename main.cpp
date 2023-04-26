#include <iostream>
#include <cmath>
#include "SDL_Plotter.h"
#include "tile.h"
#include "block.h"
#include "constants.h"
#include "StartScreen.h"

using namespace std;



int main(int argc, char ** argv)
{
    start s;
    s.openScreen();

    SDL_Plotter g(NUM_ROW, NUM_COL);
    char key;

    for(int i = 1; i <= NUM_COL; i++) {
        for(int j = 1; j <= NUM_ROW; j++) {
            g.plotPixel(i, j, BACKGROUND);
        }
    }

    Block b;
    b.setType(l_shape2);
    b.setSize(g.getCol() / 12);

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
