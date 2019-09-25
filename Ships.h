//
// Created by Alen Handukic on 2019-03-12.
//

#ifndef OOPFINALPROJECT_SHIP_H
#define OOPFINALPROJECT_SHIP_H
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


class Ships {
protected:
    string shipType;
    int column;
    int row;
    string direction;
    string loc;
public:
    Ships();
    void setShipType(string type){shipType = type;}
    void setColumn(int col){column = col;}
    void setRow(int _row){row = _row;}
    void setDirection(string dir){direction = dir;}
    void setLocation(string location){loc = location;}  //normal getter and setter functions
    string getShipType(){return shipType;}
    int getColumn(){return column;}
    int getRow(){return row;}
    string getDirection(){return direction;}
    string getLocation(){return loc;}

    char getRowVal(){return loc[0];}
    char getColumnVal(){return loc[1];}  //these getters are used for accessing the location value at specific indices...
    char getColumnValTwo(){return loc[2];} //...in order to separate the row and column value needed for grid access


};


#endif //OOPFINALPROJECT_SHIP_H
