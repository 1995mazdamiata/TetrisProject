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
