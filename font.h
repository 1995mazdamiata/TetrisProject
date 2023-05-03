/*
Authors: Nicholas Storti, Alex Truitt, Jacob Meyer, Olivia Calusinski,
Jackson Davidson, Aidan Highsmith, and Piya Patel
Assignment Description: A group project using various classes and structures
that create a slightly more difficult version of tetris.
Date Created: 4/15/2023
Due Date: 5/4/2023
Date Last Modified: 5/4/2023
*/

#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

#include <fstream>
#include <ostream>
#include <string>
#include <cassert>
#include "SDL_Plotter.h"

using namespace std;

const int MAX_FONT_SIZE = 25;

class font{
    public:
        font() {;}

        /*
         * description: initializes a font file. opens a file
         *         with the specific letter
         * return: nothing
         * precondition: name of font file passed as argument. The font
         *         file exists and has properly formatted data
         * postcondition: The data from the font file is stored in
         *         a class array.
         */
        void init(string fname) {
            ifstream input;
            input.open(fname);
            assert(input);

            input >> row >> col;
            for (int r = 0; r < row; r++) {
                for (int c = 0; c < col; c++) {
                    input >> data[r][c];
                }
            }
            input.close();
        }

        /*
         * description: displays a letter to the pixel drawing with a font
         * return: nothing
         * precondition: takes a plotter object, x and y coordinates, and
         *         size as arguments. the class data object has the letter
         *         data
         * postcondition: The letter is drawn on the pixel drawing.
         */
        void display(SDL_Plotter& g, int x, int y, int size) {
            for (int r = 0; r < row; r++) {
                for (int c = 0; c < col; c++) {
                    if (data[r][c] == '1') {
                         for (int xoff = 0; xoff < size; xoff++) {
                            for (int yoff = 0; yoff < size; yoff++) {
                                g.plotPixel(xoff + x + (c*size), yoff + y + (r*size), BLACK);
                            }
                         }
                    }
                }
            }
        }

        /*
         * description: function sets the size of displayed letter
         * return: nothing
         * precondition: integer parameter passed as argument
         * postcondition: class variable size set to value of
         *         integer argument
         */
        void setSize(int n) {
            if (n >= 1) {
                size = n;
            }
        }


    private:
        int row = 0, col = 0;
        char data[MAX_FONT_SIZE][MAX_FONT_SIZE];
        int size = 1;
};

/*
 * description: function finds files for special characters
 * return: string
 * precondition: character passed as argument. font file exists
 * postcondition: font file name returned as a string.
 */
string findFont(char c) {
    string Font;

    if (isalnum(c)) {
        Font = c;
        Font += ".txt";
    }
    else if (c == ':') {
        Font = "colon.txt";
    }
    else if (isspace(c)) {
        Font = "space.txt";
    }
    else {
        Font = "A.txt";
    }

    return Font;
}

/*
 * description: function displays a string to the screen in a given font
 * return: nothing
 * precondition: plotter object, string to be displayed, x and y
 *         coordinates, and size passed as arguments. A font file for
 *         each character in the string exists.
 * postcondition: A string is drawn to the pixel drawing according
 *         to the parameters passed as arguments
 */
void displayString(SDL_Plotter& g, string s, int x, int y, int size) {
        int prev = 0;
        font curr;
        for (unsigned int i = 0; i < s.size(); i++) {
            string letter = "fonts// .txt";
            char let;
            let = s.at(i);
            if(!isspace(let)){
                letter.at(7) = let;
                curr.init(letter);
                curr.display(g, x+prev, y, size);
                prev += (14 * size);
            }
            else{
                x = x + 14 * size;
            }
        }
}

#endif // FONT_H_INCLUDED
