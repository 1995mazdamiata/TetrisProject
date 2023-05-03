/*
Authors: Nicholas Storti, Alex Truitt, Jacob Meyer, Olivia Calusinski,
Jackson Davidson, Aidan Highsmith, and Piya Patel
Assignment Description: A group project using various classes and structures
that create a slightly more difficult version of tetris.
Date Created: 4/15/2023
Due Date: 5/4/2023
Date Last Modified: 5/4/2023
*/

#include "Board.h"


board::board() {
    for(int r = 0; r < HEIGHT_IN_TILES; r++) {
        for(int c = 0; c < WIDTH_IN_TILES; c++) {
            filledTiles[r][c] = false;
            data[r][c].setColor(BACKGROUND);
        }
    }
}

void board::replaceBlockWithTiles(Block b) {
    point p;
    color c;
    int row;
    int col;
    int size = b.getTile(0).getSize();
    for(int i = 0; i < NUM_TILES; i++) {
        p = b.getTile(i).getLocation();
        c = b.getTile(i).getColor();
        col = p.x / size;
        row = p.y / size;
        data[row][col].setLocation(p);
        data[row][col].setColor(c);
        data[row][col].setSize(size);
        filledTiles[row][col] = true;
    }
}

void board::drawBoard(SDL_Plotter& g) {
    for(int r = 0; r < HEIGHT_IN_TILES; r++) {
        for(int c = 0; c < WIDTH_IN_TILES; c++) {
            if(filledTiles[r][c]) {
                data[r][c].draw(g);
            }
            else {
                data[r][c].erase(g);
            }
        }
    }
}

void updateBoard(board& a, SDL_Plotter& g, scoreCounter& c) {
    int count;
    for (int r = 0; r < HEIGHT_IN_TILES; r++) {
        count = 0;
        for (int c = 0; c < WIDTH_IN_TILES; c++) {
            if (a.filledTiles[r][c] == true) {
                count++;
            }
        }
        if (count == 12) {
            a.deleteRow(r);
            a.dropRows(r);
            c.incScoreRow();
            c.gameSpeed();
        }
    }
}

void board::deleteRow(int row) {
    for(int c = 0; c < WIDTH_IN_TILES; c++) {
        filledTiles[row][c] = false;
    }
}


void board::dropRows(int row) {
    for (int r = row; r > 0; r--) {
        for (int c = 0; c < WIDTH_IN_TILES; c++) {
            filledTiles[r][c] = filledTiles[r-1][c];
        }
    }
}

bool board::collision(Block b) {
    bool collision = false;
    int size = b.getSize();
    for(int r = 0; r < HEIGHT_IN_TILES; r++) {
        for(int c = 0; c < WIDTH_IN_TILES; c++) {
            if(filledTiles[r][c] && !filledTiles[r - 1][c]) {
                for(int i = 0; i < NUM_TILES; i++) {
                    if((abs(b.getTile(i).getLocation().x
                       - data[r][c].getLocation().x) < size)
                       && (abs(b.getTile(i).getLocation().y
                       - data[r][c].getLocation().y) < size)) {
                        collision = true;
                    }
                }
            }
        }
    }
    return collision;
}

bool board::lateralCollisionRight(Block b) {
    bool collision = false;
    int size = b.getSize();
    for(int r = 0; r < HEIGHT_IN_TILES; r++) {
        for(int c = 0; c < WIDTH_IN_TILES; c++) {
            if(filledTiles[r][c] &&
              !filledTiles[r][c - 1]) {
                for(int i = 0; i < NUM_TILES; i++) {
                    if((abs(b.getTile(i).getLocation().x
                      - data[r][c].getLocation().x) < size + 1)
                      && (abs(b.getTile(i).getLocation().y
                      - data[r][c].getLocation().y) < size)) {
                        collision = true;
                    }
                }
            }
        }
    }
    return collision;
}

bool board::lateralCollisionLeft(Block b) {
    bool collision = false;
    int size = b.getSize();
    for(int r = 0; r < HEIGHT_IN_TILES; r++) {
        for(int c = 0; c < WIDTH_IN_TILES; c++) {
            if(filledTiles[r][c] &&
              !filledTiles[r][c + 1]) {
                for(int i = 0; i < NUM_TILES; i++) {
                    if((abs(b.getTile(i).getLocation().x
                      - data[r][c].getLocation().x) < size + 1)
                      && (abs(b.getTile(i).getLocation().y
                      - data[r][c].getLocation().y) < size)) {
                        collision = true;
                    }
                }
            }
        }
    }
    return collision;
}

bool board::bottom(Block b) {
    bool bottomed = false;
    int size = b.getSize();
    for(int i = 0; i < NUM_TILES; i++) {
        if(b.getTile(i).getLocation().y > NUM_ROW - size - 2) {
            bottomed = true;
        }
    }
    return bottomed;
}

bool board::endGame() {
    bool over = false;
    int count = 0;
    int row = 0;
    for(int c = 0; c < WIDTH_IN_TILES; c++) {
        if(filledTiles[row][c]) {
            count++;
        }
    }
    if(count > 1) {
        over = true;
    }
    return over;
}

void board::resetBoard(SDL_Plotter& g) {
    for(int r = 0; r < HEIGHT_IN_TILES; r++) {
        for(int c = 0; c < WIDTH_IN_TILES; c++) {
            filledTiles[r][c] = false;
            data[r][c].setColor(BACKGROUND);
        }
    }
}

void drawBackground(SDL_Plotter& g ,color c) {
    for(int i = 0; i < NUM_COL; i++) {
        for(int j = 0; j < NUM_ROW; j++) {
            g.plotPixel(i, j, c);
        }
    }
}

blockType randomBlock() {
    blockType type;
    int num;

    srand(time(0));
    num = rand() % 6;

    switch(num) {
    case 0:
        type = square;
        break;
    case 1:
        type = l_shape1;
        break;
    case 2:
        type = l_shape2;
        break;
    case 3:
        type = bar;
        break;
    case 4:
        type = t_shape;
        break;
    case 5:
        type = z_shape;
        break;
    }
    return type;
}
