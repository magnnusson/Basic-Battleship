//
// Created by Alen Handukic on 2019-03-13.
//

#include "Grid.h"
#include "Ships.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;


void Grid::readInUserShips(ifstream &infile)
{
    string type;
    string location;
    string dir;
    Ships newShip;
    Ships carrier, battleship, cruiser, submarine, destroyer;
    if(!infile)
        cout << "Unable to open the file.";
    else
    {
        while(infile.good())
        {
            getline(infile, type, ',');
            newShip.setShipType(type);
            getline(infile, location, ',');  //using the temp variable newShip to hold all necessary information about the ship...
            newShip.setLocation(location);      //...before storing it into a specific kind of ship.
            getline(infile, dir, '\n');
            newShip.setDirection(dir);

            if(newShip.getRowVal() == 'A')
                newShip.setRow(0);
            else if(newShip.getRowVal() == 'B')
                newShip.setRow(1);
            else if(newShip.getRowVal() == 'C')
                newShip.setRow(2);
            else if(newShip.getRowVal() == 'D')
                newShip.setRow(3);
            else if(newShip.getRowVal() == 'E')
                newShip.setRow(4);
            else if(newShip.getRowVal() == 'F')    //converting row values to the appropriate row number using getters/setters
                newShip.setRow(5);
            else if(newShip.getRowVal() == 'G')
                newShip.setRow(6);
            else if(newShip.getRowVal() == 'H')
                newShip.setRow(7);
            else if(newShip.getRowVal() == 'I')
                newShip.setRow(8);
            else if(newShip.getRowVal() == 'J')
                newShip.setRow(9);


            if(newShip.getColumnVal() == '1' && newShip.getColumnValTwo() == '0')
                newShip.setColumn(9);
            else if(newShip.getColumnVal() == '1')
                newShip.setColumn(0);
            else if(newShip.getColumnVal() == '2')
                newShip.setColumn(1);
            else if(newShip.getColumnVal() == '3')
                newShip.setColumn(2);
            else if(newShip.getColumnVal() == '4')
                newShip.setColumn(3);
            else if(newShip.getColumnVal() == '5')  //converting column values to the appropriate column number using getters/setters
                newShip.setColumn(4);
            else if(newShip.getColumnVal() == '6')
                newShip.setColumn(5);
            else if(newShip.getColumnVal() == '7')
                newShip.setColumn(6);
            else if(newShip.getColumnVal() == '8')
                newShip.setColumn(7);
            else if(newShip.getColumnVal() == '9')
                newShip.setColumn(8);


            if(newShip.getShipType() == "Carrier")
                carrier = newShip;
            else if(newShip.getShipType() == "Battleship")
                battleship = newShip;
            else if(newShip.getShipType() == "Cruiser")  //assigning each ship type to newShip, so we have 5 ship objects
                cruiser = newShip;
            else if(newShip.getShipType() == "Submarine")
                submarine = newShip;
            else if(newShip.getShipType() == "Destroyer")
                destroyer = newShip;
        }
        cout << "Here are your ships: " << endl << endl;
        cout << carrier.getShipType() << ", " << carrier.getLocation() << ", " << carrier.getDirection() << endl;
        cout << battleship.getShipType() << ", " << battleship.getLocation() << ", " << battleship.getDirection() << endl;
        cout << cruiser.getShipType() << ", " << cruiser.getLocation() << ", " << cruiser.getDirection() << endl;
        cout << submarine.getShipType() << ", " << submarine.getLocation() << ", " << submarine.getDirection() << endl;
        cout << destroyer.getShipType() << ", " << destroyer.getLocation() << ", " << destroyer.getDirection() << endl << endl;
        cout << "Now attempting to place ships..." << endl;


        //if-else statements to check ship placements at grid[i][j] using getRow and getColumn getters and proper incrementation

        cout << "Attempting carrier placement..." << endl;


        if(carrier.getDirection() == "H\r") //horizontal placement
        {
            if(carrier.getColumn() + 5 < GRID_SIZE) {

                for (int i = 0; i < 5; i++) {
                    grid[carrier.getRow()][carrier.getColumn() + i] = "5";  //CARRIER PLACEMENT
                }
                printGrid();
                cout << endl;
            }else {
                throw OutOfBounds(); //can only be out of bounds since it's the first ship being placed

            }

        }
        else if(carrier.getDirection() == "V\r")    //vertical placement
        {
            if(carrier.getRow() + 5 < GRID_SIZE)
            {
                for(int i = 0; i < 5; i++)
                {
                    grid[carrier.getRow() + i][carrier.getColumn()] = "5";
                }
                printGrid();
                cout << endl;
            } else {
                throw OutOfBounds(); //can only be out of bounds since it's the first ship being placed

            }
        }

        cout << "Attempting battleship placement..." << endl;           //BATTLESHIP PLACEMENT

        if(battleship.getDirection() == "H\r") //horizontal placement
        {
            if(grid[battleship.getRow()][battleship.getColumn()] == grid[carrier.getRow()][carrier.getColumn()])
            {
                throw StartingOverlap();

            }
            if(battleship.getColumn() + 4 < GRID_SIZE) {

                for (int i = 0; i < 4; i++) {
                    grid[battleship.getRow()][battleship.getColumn() + i] = "4";
                    if(grid[battleship.getRow()][battleship.getColumn() + i] == "5")
                    {
                        cout << "ERROR: SHIP OVERLAP" << endl; //checking if ship sizes overlap
                        return;
                    }
                }
                printGrid();
                cout << endl;
            }

            else{
                throw OutOfBounds(); //otherwise, ship is out of bounds

                }

        }
        else if(battleship.getDirection() == "V\r") //vertical placement
        {
            if(grid[battleship.getRow()][battleship.getColumn()] == grid[carrier.getRow()][carrier.getColumn()])
            {
                throw StartingOverlap(); //now checking if initial location overlaps with other ship

            }
            if (battleship.getRow() + 4 < GRID_SIZE)
            {
                for (int i = 0; i < 4; i++) {
                    grid[battleship.getRow() + i][battleship.getColumn()] = "4";
                    if(grid[battleship.getRow() + i][battleship.getColumn()] == "5")
                    {
                        throw ShipOverlap(); //checking if ship sizes overlap

                    }
                }
                printGrid();
                cout << endl;
            }
            else {
                throw OutOfBounds(); //otherwise, ship is out of bounds

            }

        }

        cout << "Attempting cruiser placement..." << endl;          //CRUISER PLACEMENT

        if(cruiser.getDirection() == "H\r") //horizontal placement
        {
            if(grid[cruiser.getRow()][cruiser.getColumn()] == grid[carrier.getRow()][carrier.getColumn()] || grid[cruiser.getRow()][cruiser.getColumn()] ==
            grid[battleship.getRow()][battleship.getColumn()])
            {
                throw StartingOverlap(); //now checking if initial location overlaps with other ship

            }
            if(cruiser.getColumn() + 3 < GRID_SIZE) {

                for (int i = 0; i < 3; i++) {
                    grid[cruiser.getRow()][cruiser.getColumn() + i] = "C";
                    if(grid[cruiser.getRow()][cruiser.getColumn() + i] == "5" || grid[cruiser.getRow()][cruiser.getColumn() + i] == "4")
                    {
                        throw ShipOverlap(); //checking if ship sizes overlap

                    }

                }
                printGrid();
                cout << endl;
            }
            else {
                throw OutOfBounds(); //otherwise, ship is out of bounds

            }

        }
        else if(cruiser.getDirection() == "V\r") //vertical placement
        {
            if(grid[cruiser.getRow()][cruiser.getColumn()] == grid[carrier.getRow()][carrier.getColumn()] || grid[cruiser.getRow()][cruiser.getColumn()] ==
            grid[battleship.getRow()][battleship.getColumn()])
            {
                throw StartingOverlap(); //now checking if initial location overlaps with other ship

            }
            if (cruiser.getRow() + 3 < GRID_SIZE)
            {
                for (int i = 0; i < 3; i++) {
                    grid[cruiser.getRow() + i][cruiser.getColumn()] = "C";
                    if(grid[cruiser.getRow() + i][cruiser.getColumn()] == "5" || grid[cruiser.getRow() + i][cruiser.getColumn()] == "4")
                    {
                        throw ShipOverlap(); //checking if ship sizes overlap

                    }
                }


                printGrid();
                cout << endl;
            }

            else {
                throw OutOfBounds(); //otherwise, ship is out of bounds

            }

        }

        cout << "Attempting submarine placement..." << endl;        //SUBMARINE PLACEMENT

        if(submarine.getDirection() == "H\r")
        {
            if(grid[submarine.getRow()][submarine.getColumn()] == grid[carrier.getRow()][carrier.getColumn()] || grid[submarine.getRow()][submarine.getColumn()] ==
            grid[battleship.getRow()][battleship.getColumn()] || grid[submarine.getRow()][submarine.getColumn()] == grid[cruiser.getRow()][cruiser.getColumn()])
            {
                throw StartingOverlap(); //now checking if initial location overlaps with other ship

            }
            if(submarine.getColumn() + 3 < GRID_SIZE) {

                for (int i = 0; i < 3; i++) {
                    grid[submarine.getRow()][submarine.getColumn() + i] = "3";
                    if(grid[submarine.getRow()][submarine.getColumn() + i] == "4" || grid[submarine.getRow()][submarine.getColumn() + i] == "4"||
                    grid[submarine.getRow()][submarine.getColumn() + i] == "C")
                    {
                        throw ShipOverlap(); //checking if ship sizes overlap

                    }
                }

                printGrid();
                cout << endl;
            }

            else {
                throw OutOfBounds(); //otherwise, ship is out of bounds

            }

        }
        else if(submarine.getDirection() == "V\r") //vertical placement
        {
            if(grid[submarine.getRow()][submarine.getColumn()] == grid[carrier.getRow()][carrier.getColumn()] || grid[submarine.getRow()][submarine.getColumn()] ==
            grid[battleship.getRow()][battleship.getColumn()] || grid[submarine.getRow()][submarine.getColumn()] == grid[cruiser.getRow()][cruiser.getColumn()])
            {
                throw StartingOverlap(); //now checking if initial location overlaps with other ship

            }
            if (submarine.getRow() + 3 < GRID_SIZE)
            {
                for (int i = 0; i < 3; i++) {
                    grid[submarine.getRow() + i][submarine.getColumn()] = "3";
                    if(grid[submarine.getRow() + i][submarine.getColumn()] == "5" || grid[submarine.getRow()+ i][submarine.getColumn()] == "4"||
                       grid[submarine.getRow() + i][submarine.getColumn()] == "C")
                    {
                        throw ShipOverlap(); //checking if ship sizes overlap

                    }
                }

                printGrid();
                cout << endl;
            }
            else {
                throw OutOfBounds(); //otherwise, ship is out of bounds

            }

        }

        cout << "Attempting destroyer placement..." << endl;        // DESTROYER PLACEMENT

        if(destroyer.getDirection() == "H\r") //horizontal placement
        {
            if(grid[destroyer.getRow()][destroyer.getColumn()] == grid[carrier.getRow()][carrier.getColumn()] || grid[destroyer.getRow()][destroyer.getColumn()] ==
            grid[battleship.getRow()][battleship.getColumn()] || grid[destroyer.getRow()][destroyer.getColumn()] == grid[cruiser.getRow()][cruiser.getColumn()] ||
               grid[destroyer.getRow()][destroyer.getColumn()] == grid[submarine.getRow()][submarine.getColumn()])
            {
                throw StartingOverlap(); //error checking if starting position overlaps

            }
            if(destroyer.getColumn() + 2 < GRID_SIZE) {

                for (int i = 0; i < 2; i++) {
                    grid[destroyer.getRow()][destroyer.getColumn() + i] = "2";
                    if(grid[destroyer.getRow()][destroyer.getColumn() + i] == "5" || grid[destroyer.getRow()][destroyer.getColumn() + i] == "4"||
                       grid[destroyer.getRow()][destroyer.getColumn() + i] == "C" || grid[destroyer.getRow()][destroyer.getColumn() + i] == "3")
                    {
                        throw ShipOverlap(); //error checking if ship sizes overlap

                    }
                }

                printGrid();
                cout << endl;
            }

            else {
                throw OutOfBounds(); //otherwise, the ship is out of bounds

            }

        }
        else if(destroyer.getDirection() == "V\r") //vertical placement
        {
            if(grid[destroyer.getRow()][destroyer.getColumn()] == grid[carrier.getRow()][carrier.getColumn()] || grid[destroyer.getRow()][destroyer.getColumn()] ==
            grid[battleship.getRow()][battleship.getColumn()] || grid[destroyer.getRow()][destroyer.getColumn()] == grid[cruiser.getRow()][cruiser.getColumn()] ||
            grid[destroyer.getRow()][destroyer.getColumn()] == grid[submarine.getRow()][submarine.getColumn()])
            {
                throw StartingOverlap(); //error checking if starting position overlaps

            }
            if (destroyer.getRow() + 2 < GRID_SIZE)
            {
                for (int i = 0; i < 2; i++) {
                    grid[destroyer.getRow() + i][destroyer.getColumn()] = "2";
                    if(grid[destroyer.getRow() + i][destroyer.getColumn()] == "5" || grid[destroyer.getRow() + i][destroyer.getColumn()] == "4"||
                       grid[destroyer.getRow() + i][destroyer.getColumn()] == "C" || grid[destroyer.getRow() + i][destroyer.getColumn()] == "3")
                    {
                        throw ShipOverlap(); //error checking if ship sizes overlap

                    }
                }

                printGrid();
                cout << endl;
            }

            else {
                throw OutOfBounds(); //otherwise, the ship is out of bounds

            }

        }
        cout << "All ships placed successfully. Game can now begin!" << endl;

    }
}

void Grid::placeCpuCarrier() //first randomizing direction and then using the placeHorizontally and placeVertically functions with appropriate ship size
{

    int dir;

    cout << "Placing CPU Carrier...";

    dir = rand() % 2;

    if(dir == 0)
    {
        placeHorizontally(5);
    }
    else if(dir == 1)
    {
        placeVertically(5);
    }

}

void Grid::placeCpuBattleship() //first randomizing direction and then using the placeHorizontally and placeVertically functions with appropriate ship size
{
    int dir;

    cout << "Placing CPU Battleship...";

    dir = rand() % 2;

    if(dir == 0)
    {
        placeHorizontally(4);
    }
    else if(dir == 1)
    {
        placeVertically(4);
    }
}

void Grid::placeCpuCruiser() //first randomizing direction and then using the placeHorizontally and placeVertically functions with appropriate ship size
{
    int dir;

    cout << "Placing CPU Cruiser...";

    dir = rand() % 2;

    if(dir == 0)
    {
        placeHorizontally(3);
    }
    else if(dir == 1)
    {
        placeVertically(3);
    }
}

void Grid::placeCpuSubmarine() //first randomizing direction and then using the placeHorizontally and placeVertically functions with appropriate ship size
{
    int dir;

    cout << "Placing CPU Submarine...";

    dir = rand() % 2;

    if(dir == 0)
    {
        placeHorizontally(3);
    }
    else if(dir == 1)
    {
        placeVertically(3);
    }
}

void Grid::placeCpuDestroyer() //first randomizing direction and then using the placeHorizontally and placeVertically functions with appropriate ship size
{
    int dir;

    cout << "Placing CPU Destroyer...";

    dir = rand() % 2;

    if(dir == 0)
    {
        placeHorizontally(2);
    }
    else if(dir == 1)
    {
        placeVertically(2);
    }
}

void Grid::placeHorizontally(int shipLength)
{
    int rowIndex;
    int columnIndex;

    stringstream length;
    length << shipLength;
    string shiplength = length.str();





    rowIndex = rand() % 10;
    columnIndex = rand() % 10; //randomize the row and column values to be between 1-10

    if(columnIndex + shipLength < 10) //checking if the ship is out of bounds. if so, recursively call the function to start over
    {


            if(grid[rowIndex][columnIndex] == ".") //checking if there is no initial overlap. if so, recursively call the function
            {
                for(int i = 0; i < shipLength; i++)
                {

                    if(grid[rowIndex][columnIndex + i] == "5" || grid[rowIndex][columnIndex + i] == "4" ||
                       grid[rowIndex][columnIndex + i] == "3" || grid[rowIndex][columnIndex + i] == "2") //checking if ship length overlaps horizontally with other ships
                    {                                                                                // if so, recursively call the function


                        placeHorizontally(shipLength);




                    } else
                        grid[rowIndex][columnIndex + i] = shiplength; //place the ship horizontally if no problems arise


                }
                cout << "Ship is placed." << endl;




            } else
                {

                    placeHorizontally(shipLength);
                }



    } else
        {

            placeHorizontally(shipLength);
        }


}

void Grid::placeVertically(int shipLength)
{
    int rowIndex;
    int columnIndex;

    stringstream length;
    length << shipLength;
    string shiplength = length.str();



    rowIndex = rand() % 10;
    columnIndex = rand() % 10; //randomize the row and column values to be between 1-10

    if(rowIndex + shipLength < 10) //checking if the ship is out of bounds. if so, recursively call the function to start over
    {


            if(grid[rowIndex][columnIndex] == ".") //checking if there is no initial overlap. if so, recursively call the function
            {
                for(int i = 0; i < shipLength; i++)
                {
                    if(grid[rowIndex + i][columnIndex] == "5" || grid[rowIndex + i][columnIndex] == "4" ||
                       grid[rowIndex + i][columnIndex] == "3" || grid[rowIndex + i][columnIndex] == "2") //checking if ship length overlaps horizontally with other ships
                    {                                                                               // if so, recursively call the function


                        placeVertically(shipLength);


                    }
                    else
                        grid[rowIndex + i][columnIndex] = shiplength; //place the ship vertically if no problems arise
                }

                cout << "Ship is placed." << endl;


            } else
                placeVertically(shipLength);


    } else
        placeVertically(shipLength);

}

void Grid::userGuess(Grid& cpu, Grid& trackingGrid)
{
    string guessRow;
    int rowNum;
    string guessCol;
    int colNum;

    cout << "Which row would you like to fire in? (A-J)" << endl; //ask user for row
    cin >> guessRow;
    cout << "Which column would you like to fire in? (1-10)" << endl; //ask user for column
    cin >> guessCol;


    if(guessRow == "A" || guessRow == "a")
        rowNum = 0;
    else if(guessRow == "B" || guessRow == "b")
        rowNum = 1;
    else if(guessRow == "C" || guessRow == "c")
        rowNum = 2;
    else if(guessRow == "D" || guessRow == "d")
        rowNum = 3;
    else if(guessRow == "E" || guessRow == "e")  //converting each user input into appropriate row index
        rowNum = 4;
    else if(guessRow == "F" || guessRow == "f")
        rowNum = 5;
    else if(guessRow == "G" || guessRow == "g")
        rowNum = 6;
    else if(guessRow == "H" || guessRow == "h")
        rowNum = 7;
    else if(guessRow == "I" || guessRow == "i")
        rowNum = 8;
    else if(guessRow == "J" || guessRow == "j")
        rowNum = 9;
    else
        {
        cout << "Enter a valid Row Letter!" << endl; //error checking input through recursion
        userGuess(cpu, trackingGrid);
        }



    if(guessCol == "1")
        colNum = 0;
    else if(guessCol == "2")
        colNum = 1;
    else if(guessCol == "3")
        colNum = 2;
    else if(guessCol == "4")
        colNum = 3;
    else if(guessCol == "5") //converting each user input into appropriate column index
        colNum = 4;
    else if(guessCol == "6")
        colNum = 5;
    else if(guessCol == "7")
        colNum = 6;
    else if(guessCol == "8")
        colNum = 7;
    else if(guessCol == "9")
        colNum = 8;
    else if(guessCol == "10")
        colNum = 9;
    else
        {
        cout << "Enter a valid Column Number!" << endl; //error checking through recursion
        userGuess(cpu, trackingGrid);
        }


        if (cpu.grid[rowNum][colNum] == "5") //checking if the cpu grid at user's guess matches the ship's symbol
        {
            cout << "You sunk the opponent's Carrier!" << endl; //if so, tell user that ship was sunk
            for(int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 10; j++)
                {
                    if(cpu.grid[i][j] == "5") //mark spaces where ship was with an O
                    {
                        cpu.grid[i][j] = "O";
                    }
                }
            }
            trackingGrid.grid[rowNum][colNum] = "O"; //mark user's tracking grid with an O, and display it
            trackingGrid.printGrid();

        }

        else if(cpu.grid[rowNum][colNum] == "4") //same process
        {
            cout << "You sunk the opponent's Battleship!" << endl;
            for(int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 10; j++)
                {
                    if(cpu.grid[i][j] == "4")
                    {
                        cpu.grid[i][j] = "O";
                    }
                }
            }
            trackingGrid.grid[rowNum][colNum] = "O";
            trackingGrid.printGrid();

        }
        else if(cpu.grid[rowNum][colNum] == "3") //same process
        {
            cout << "You sunk the opponent's Submarine or Cruiser!" << endl;
            for(int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 10; j++)
                {
                    if(cpu.grid[i][j] == "3")
                    {
                        cpu.grid[i][j] = "O";
                    }
                }
            }
            trackingGrid.grid[rowNum][colNum] = "O";
            trackingGrid.printGrid();

        }

        else if(cpu.grid[rowNum][colNum] == "2") //same process
        {
            cout << "You sunk the opponent's Destroyer!" << endl;
            for(int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 10; j++)
                {
                    if(cpu.grid[i][j] == "2")
                    {
                        cpu.grid[i][j] = "O";
                    }
                }
            }
            trackingGrid.grid[rowNum][colNum] = "O";
            trackingGrid.printGrid();

        }

        else if(cpu.grid[rowNum][colNum] == ".") //otherwise, if user's input hits a blank on cpu grid
         {
        cout << "You missed!" << endl; //failure message
        trackingGrid.grid[rowNum][colNum] = "X"; //mark the user's tracking grid with an X and display it
        trackingGrid.printGrid();
         }


}

void Grid::cpuGuess(Grid& user)
{
    int rowNum;
    int colNum;

    rowNum = rand() % 10; //generate random row and column indexes to be 0-9
    colNum = rand() % 10;

    if (user.grid[rowNum][colNum] == "5") //same process as the user guess checking, but reversed between the cpu grid and user grid.
    {
        cout << "They sunk your Carrier!" << endl;
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(user.grid[i][j] == "5")
                {
                    user.grid[i][j] = "O";
                }
            }
        }
        user.printGrid(); //only difference is displaying the user's grid to represent sunk ships
    }
   else if (user.grid[rowNum][colNum] == "4") //same process
    {
        cout << "They sunk your Battleship!" << endl;
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(user.grid[i][j] == "4")
                {
                    user.grid[i][j] = "O";
                }
            }
        }
        user.printGrid();
    }
    else if (user.grid[rowNum][colNum] == "3") //same process
    {
        cout << "They sunk your Submarine!" << endl;
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(user.grid[i][j] == "3")
                {
                    user.grid[i][j] = "O";
                }
            }
        }
        user.printGrid();
    }
    else if (user.grid[rowNum][colNum] == "C") //same process
    {
        cout << "They sunk your Cruiser!" << endl;
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(user.grid[i][j] == "C")
                {
                    user.grid[i][j] = "O";
                }
            }
        }
        user.printGrid();
    }
    else if (user.grid[rowNum][colNum] == "2") //same process
    {
        cout << "They sunk your Destroyer!" << endl;
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(user.grid[i][j] == "2")
                {
                    user.grid[i][j] = "O";
                }
            }
        }
        user.printGrid();
    }
    else if(user.grid[rowNum][colNum] == ".") //if cpu's guess missed,
    {
        cout << "They missed!" << endl; //tell user that cpu missed
        user.grid[rowNum][colNum] = "X"; //and place an X on user's primary grid and display it to indicate a miss
        user.printGrid();
    }

}

bool Grid::gameWon() //used for checking if cpu's board is clear by simple iteration and if statement checking
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(grid[i][j] == "5" || grid[i][j] == "4" || grid[i][j] == "3" || grid[i][j] == "2")
            {
                return false;
            }

        }
    }
    return true;
}

bool Grid::userGameWon() //used for checking if user's board is clear by simple iteration and if statement checking
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(grid[i][j] == "5" || grid[i][j] == "4" || grid[i][j] == "3" || grid[i][j] == "C" || grid[i][j] == "2")
            {
                return false;
            }
        }
    }
    return true;
}

void Grid::printGrid() //printing the grid with letters and numbers to simulate a battleship board
{
    char letter = 'A';

    cout << "   [1][2][3][4][5][6][7][8][9][10]" << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << "[" << letter << "]";
        letter++;

        for(int j = 0; j < 10; j++)
        {

            cout << "|" << grid[i][j] << "|";

        }

        cout << endl;
    }
}
