#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#include <cstdlib>
#include <time.h>

using namespace std;

class scoreCounter {
    private:
        int score;
        double speed;

    public:
        scoreCounter();
        scoreCounter(int, int);

        void incScoreRow();
        void incScoreBlock();

        int getScore();
        int getSpeed();

        void setSpeed(double s) {
            speed = s;
        }
        void setScore(int s) {
            score = s;
        }

        void gameSpeed();
};

#endif // SCORE_H_INCLUDED
