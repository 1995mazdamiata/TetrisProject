/*
Authors: Nicholas Storti, Alex Truitt, Jacob Meyer, Olivia Calusinski,
Jackson Davidson, Aidan Highsmith, and Piya Patel
Assignment Description: A group project using various classes and structures
that create a slightly more difficult version of tetris.
Date Created: 4/15/2023
Due Date: 5/4/2023
Date Last Modified: 5/4/2023
*/

#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#include <cstdlib>
#include <time.h>

using namespace std;

/* 
Description: Class that increments the game score and
the speed of the game based on the score.
Precondition: A scoreCounter object must exist.
Postcondition: Functions in the class increment score of the game
and change the speed of the game as well.
Return: Integer, Void, scoreCounter
*/

class scoreCounter {
    private:
        int score;
        double speed;

    public:
        scoreCounter();
        /* 
        Description: Constructor function that sets the initial score
        of the game to 0 and the speed to 10.
        Precondition: A scoreCounter object must exist.
        Postcondition: Function initializes the score to 0 and the
        speed to 10.
        Return: scoreCounter
        */
        scoreCounter(int, int);
        /* 
        Description: Constructor function that sets the initial score
        of the game to an integer and the speed to an integer as well.
        Precondition: A scoreCounter object must exist and two
        integers must exist.
        Postcondition: Function initializes the score to an integer value
        and the speed of the game to a different integer value.
        Return: scoreCounter
        */
        void incScoreRow();
        /* 
        Description: Function that increases the score if a complete
        row of tiles is accomplished.
        Precondition: A scoreCounter object must exist and an integer
        value must exist.
        Postcondition: Function increments the score by 100 for every row
        that is completely filled at a time.
        Return: Void
        */
        void incScoreBlock();
        /* 
        Description: Function that increments a random value
        for a block being dropped.
        Precondition: A scoreCounter object must exist.
        Postcondition: Function adds a random value modulas 11
        to the score
        Return: Void
        */
        int getScore();
        /* 
        Description: Function that returns the value of the
        game score.
        Precondition: A scoreCounter object must exist.
        Postcondition: Function returns the integer value
        of the score
        Return: Integer
        */
        int getSpeed();
        /* 
        Description: Function that returns the value of the
        game speed.
        Precondition: A scoreCounter object must exist.
        Postcondition: Function returns the integer value
        of the speed.
        Return: Integer
        */
        void setSpeed(double s) {
            speed = s;
        }
        /* 
        Description: Function that sets the value of the
        game speed.
        Precondition: A scoreCounter object must exist and a double
        value must exist.
        Postcondition: Function set the value of speed to 
        a double value.
        Return: Void
        */
        void setScore(int s) {
            score = s;
        }
        /* 
        Description: Function that sets the value of the
        game score.
        Precondition: A scoreCounter object must exist and an
        integer value must exist.
        Postcondition: Function set the value of speed to 
        an integer value.
        Return: Void
        */
        void gameSpeed();
        /* 
        Description: Function that changes the game speed based 
        on a players score.
        Precondition: A scoreCounter object must exist.
        Postcondition: Function increases the speed of the game
        if the player reaches certain score thresholds.
        Return: Void
        */
};

#endif // SCORE_H_INCLUDED
