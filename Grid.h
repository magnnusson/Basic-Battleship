//
// Created by Alen Handukic on 2019-03-13.
//

#ifndef OOPFINALPROJECT_GRID_H
#define OOPFINALPROJECT_GRID_H
#include "Ships.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Where the game is played.
const int GRID_SIZE = 10;


class Grid: public Ships {
private:
    string grid[10][10];
public:
    Grid():Ships(), grid{{".",".",".",".",".",".",".",".",".","."},{".",".",".",".",".",".",".",".",".","."},{".",".",".",".",".",".",".",".",".","."},{".",".",".",".",".",".",".",".",".","."},{".",".",".",".",".",".",".",".",".","."},
                         {".",".",".",".",".",".",".",".",".","."},{".",".",".",".",".",".",".",".",".","."},{".",".",".",".",".",".",".",".",".","."},{".",".",".",".",".",".",".",".",".","."},{".",".",".",".",".",".",".",".",".","."}}{}
    void readInUserShips(ifstream& infile); //pregame functions (part 1)
    void placeCpuCarrier();
    void placeCpuBattleship();
    void placeCpuCruiser();
    void placeCpuSubmarine();
    void placeCpuDestroyer();
    void placeVertically(int shipLength);
    void placeHorizontally(int shipLength);

    void printGrid(); //display a grid

    void userGuess(Grid &cpu, Grid& trackingGrid); //game play functions (part 2)
    void cpuGuess(Grid &user);
    bool gameWon();
    bool userGameWon();

};

class StartingOverlap {}; //exception classes for catching input file errors, if not blank
class OutOfBounds {};
class ShipOverlap {};


#endif //OOPFINALPROJECT_GRID_H
