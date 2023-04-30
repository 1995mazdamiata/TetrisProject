#include <iostream>
#include <cmath>
#include "SDL_Plotter.h"
#include "tile.h"
#include "block.h"
#include "constants.h"
#include "Board.h"
#include "score.h"

using namespace std;



int main(int argc, char ** argv)
{
    SDL_Plotter g(NUM_ROW, NUM_COL + SCORE_HEIGHT);
    char key;
    point origin(45*5, 0);
    Block b;
    vector<board> boards;
    board Board1;
    int count = 0;
    scoreCounter counter;
    bool collided = false;
    bool start = false;
    bool initialize = true;
    bool gameOver = false;


    while (!g.getQuit()){
        if(!start) {
            drawBackground(g, BLACK);
            //start screen here

            if(g.kbhit()) {
                start = true;
            }
            g.update();
        }
        else if(initialize){
            boards.push_back(Board1);
            drawBackground(g, BACKGROUND);
            counter.setSpeed(0.25);
            counter.setScore(0);
            b.setSize(NUM_COL / 12);
            b.setType(randomBlock());
            b.setLoc(origin);
            initialize = false;
        }
        else if(!gameOver){
            if(g.kbhit()){
                key = g.getKey();
                switch(key) {
                    case RIGHT_ARROW:
                        if(!boards[count].lateralCollisionRight(b)) {
                         b.moveRight();
                        }
                        break;
                    case LEFT_ARROW:
                        if(!boards[count].lateralCollisionLeft(b)) {
                            b.moveLeft();
                        }
                        break;
                    case UP_ARROW:
                        if(!boards[count].lateralCollisionLeft(b) &&
                           !boards[count].lateralCollisionRight(b)) {
                            b.rotate();
                        }
                        break;
                }
            }
            if(!boards[count].collision(b)) {
                b.move();
            }
            else {
                collided = true;
            }
            b.draw(g);

            if(boards[count].bottom(b) || collided) {
                if(boards[count].endGame()) {
                    boards[count].resetBoard(g);
                    gameOver = true;
                    collided = false;
                }
                else {
                    boards[count].replaceBlockWithTiles(b);
                    b.setType(randomBlock());
                    b.setLoc(origin);
                    updateBoard(boards[count], g, counter);
                    collided = false;
                }
            }
            boards[count].drawBoard(g);
            g.Sleep(counter.getSpeed());
            g.update();
        }
        else if(gameOver) {
            drawBackground(g, BLUE);
            //game over screen here

            if(g.kbhit()) {
                key = g.getKey();
                if(key = DOWN_ARROW) {
                    gameOver = false;
                    start = false;
                    initialize = true;
                    count++;
                }
            }
            g.update();
            g.Sleep(100);
        }
    }
}
