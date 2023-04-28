// Author: Olivia Calusinski, Alex Truitt,
// Aiden Highsmith, Jackson Davidson,
// Jacob Meyer, Nick Storti, Piya Patel
// Assignment Title: Tetris
// Assignment Description: Tetris
// Due Date: 5/3/2023
// Date Created: 4/3/2023
// Date Last Modified: 5/3/2023

#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#include <cstdlib>
#include <time.h>
using namespace std;

class scoreCounter {
    private:
        int score, speed;

    public:
        scoreCounter();
        scoreCounter(int, int);

        void incScoreRow(int);
        void incScoreBlock();

        int getScore();
        int getSpeed();

        void gameSpeed();
};

#endif // SCORE_H_INCLUDED
