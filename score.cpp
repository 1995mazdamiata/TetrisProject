#include "score.h"

scoreCounter::scoreCounter() {
    score = 0;
    speed = 10;
}

scoreCounter::scoreCounter(int x, int y) {
    score = x;
    speed = y;
}

void scoreCounter::incScoreRow(int numLines) {
    if(numLines == 1) {
        score += 100;
    }
    else if(numLines == 2) {
        score += 300;
    }
    else if(numLines == 3) {
        score += 450;
    }
    else if(numLines == 4) {
        score += 600;
    }
}

void scoreCounter::incScoreBlock() {
    int increment;
    srand(time(0));
    increment += rand()%11 + 25;
    score += increment;
}

int scoreCounter::getScore() {
    return score;
}

int scoreCounter::getSpeed() {
    return speed;
}

void scoreCounter::gameSpeed() {
    if(score >= 5000) {
        speed = 7;
    }
    if(score >= 12500) {
        speed = 5;
    }
    if(score >= 22500) {
        speed = 3;
    }
    if(score >= 35000) {
        speed = 1;
    }
}
