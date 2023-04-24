#include "Board.h"


void updateBoard(board& a/*int& score?*/) {
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
            //
            // Score += 100
            // Maybe add wait function to increase effect?
        }
    }
    // Draw function maybe? could also take erase function
}

void board::deleteRow(int row) {
    for (int c = 0; c < WIDTH_IN_TILES; c++) {
        filledTiles[row][c] = false;
    }
    // Use erase function for row
}


void board::dropRows(int row) {
    for (int r = row; r > 0; r--) {
        for (int c = 0; c < WIDTH_IN_TILES; c++) {
            filledTiles[r][c] = filledTiles[r+1][c];
            // Also transfer graphic value here
        }
    }
}

/* CURRENTLY NOT ATTACHED TO ANY FUNCTION CALLS
for (int r = 0; r < HEIGHT_IN_TILES; r++) {
    tile t;
    for (int c = 0; c < WIDTH_IN_TILES; c++) {
        if (a[r][c] == true) {
            // Draw tile
        }
        else {
            // Erase
        }
        // This may not be the most efficient, but because it redraws the board based on how it is filled,
        // but I think it should work well
    }
}
*/
