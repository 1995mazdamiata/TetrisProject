#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include "SDL_Plotter.h"
#include "tile.h"
#include "block.h"
#include "constants.h"
#include "Board.h"
#include "score.h"
#include "font.h"

using namespace std;



int main(int argc, char ** argv)
{
    SDL_Plotter g(NUM_ROW, NUM_COL + SCORE_HEIGHT);
    Block b;
    vector<board> boards;
    board Board1;
    scoreCounter counter;
    point origin(45*5, 0);
    stringstream ss;
    int count = 0;
    int scoreInt;
    string scoreStr;
    bool collided = false;
    bool start = false;
    bool initialize = true;
    bool gameOver = false;
    char key;


    while (!g.getQuit()){
        if(!start) {
            drawBackground(g, START);
            displayString(g, "TETRIS", 145,300,3);
            displayString(g, "PRESS ANY KEY TO BEGIN", 120,375,1);
            displayString(g, "UP ARROW TO ROTATE", 145,600,1);
            displayString(g,"LEFT AND RIGHT ARROWS TO MOVE", 75,650,1);
            if(g.kbhit()) {
                start = true;
            }
            g.update();
        }
        else if(initialize){
            boards.push_back(Board1);
            drawBackground(g, BACKGROUND);
            counter.setSpeed(2.5);
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

            ss.clear();
            ss.str("");
            scoreInt = counter.getScore();
            ss << scoreInt;
            ss >> scoreStr;

            for(int c = NUM_COL; c < NUM_COL + SCORE_HEIGHT; c++) {
                for(int r = 0; r < NUM_ROW; r++) {
                    g.plotPixel(c, r, WHITECOLOR);
                }
            }
            displayString(g, "SCORE", 560, 300, 1);
            displayString(g, scoreStr, 560, 330, 1);

            g.update();

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
        }
        else if(gameOver) {
            drawBackground(g, RED);
            displayString(g, "GAME OVER", 100, 300, 3);
            displayString(g, "PRESS ANY KEY TO CONTINUE", 120,375,1);

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
