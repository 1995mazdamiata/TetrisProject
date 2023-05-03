/*
Authors: Nicholas Storti, Alex Truitt, Jacob Meyer, Olivia Calusinski,
Jackson Davidson, Aidan Highsmith, and Piya Patel
Assignment Description: A group project using various classes and structures
that create a slightly more difficult version of tetris.
Date Created: 4/15/2023
Due Date: 5/4/2023
Date Last Modified: 5/4/2023
*/

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
    score += 100;
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
    if(score >= 500) {
        speed = 2.25;
    }
    if(score >= 1000) {
        speed = 2;
    }
    if(score >= 1500) {
        speed = 1.75;
    }
    if(score >= 2200) {
        speed = 1.5;
    }
    if(score >= 3000) {
        speed = 1;
    }
    if(score >= 3700) {
        speed = 0.8;
    }
    if(score >= 4200) {
        speed = 0.6;
    }
    if(score >= 5000) {
        speed = 0.5;
    }
    if(score >= 6000) {
        speed = 0.25;
    }
    if(score >= 7000) {
        speed = 0.125;
    }
    if(score >= 8000) {
        speed = 0.1;
    }
    if(score >= 10000) {
        speed = 0.05;
    }
}
