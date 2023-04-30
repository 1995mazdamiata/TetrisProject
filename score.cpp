#include "score.h"

scoreCounter::scoreCounter() {
    score = 0;
    speed = 10;
}

scoreCounter::scoreCounter(int x, int y) {
    score = x;
    speed = y;
}

void scoreCounter::incScoreRow() {
    score += 1000;
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
        speed = 4;
    }
    if(score >= 10000) {
        speed = 3;
    }
    if(score >= 15000) {
        speed = 2;
    }
    if(score >= 20000) {
        speed = 1.5;
    }
    if(score >= 25000) {
        speed = 1;
    }
    if(score >= 30000) {
        speed = 0.8;
    }
    if(score >= 35000) {
        speed = 0.6;
    }
    if(score >= 40000) {
        speed = 0.5;
    }
    if(score >= 45000) {
        speed = 0.25;
    }
}
