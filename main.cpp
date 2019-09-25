#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Ships.h"
#include "Grid.h"
using namespace std;


int main() {

    srand(time(0));

    Grid user;
    Grid cpu;
    Grid trackingGrid;
    Ships cpuShips;
    bool keepPlaying = true;
    string answer;
    ifstream infile("myshipplacement.csv");

   try {
        user.readInUserShips(infile);
    }                               //reading in and placing the user's ships

    catch(StartingOverlap)
    {
        cout << "ERROR: SHIP STARTING LOCATION OVERLAP!" << endl; //using exception handling to catch input errors from infile
        //will terminate the program when game is fully implemented.
    }

    catch(OutOfBounds)
    {
        cout << "ERROR: SHIP OUT OF BOUNDS!" << endl;

    }

    catch(ShipOverlap)
    {
        cout << "ERROR: SHIP OVERLAP!" << endl;

    }
    catch(...)
    {
        cout << "ERROR: DATA FIELD INCOMPLETE!"; //catch all means one of the input fields was blank
    }

    cout << endl << "Now placing CPU ships..." << endl;

    cpu.placeCpuCarrier();         //placing each ship for the CPU opponent randomly
    cpu.placeCpuBattleship();
    cpu.placeCpuCruiser();
    cpu.placeCpuSubmarine();
    cpu.placeCpuDestroyer();

    cout << endl << "Fire the missiles!" << endl;

    while(!user.userGameWon() || !cpu.gameWon() || keepPlaying) //checking if anyone won the game or if player wants to quit
    {
        user.userGuess(cpu, trackingGrid);
        cpu.cpuGuess(user);
        if(cpu.gameWon())
        {
            break; //break out if cpu's board is cleared
        }
        if(user.userGameWon())
        {
            break; //break out if player's board is cleared
        }
        cout << "Continue playing? (y/n)" << endl;
        cin >> answer;
        if(answer == "y" || answer == "Y")
        {
            keepPlaying = true; //repeat the process
        } else if (answer == "n" || answer == "N")
            {
                keepPlaying = false;
                cout << "Thanks for playing! Here are the results." << endl; //display results to player and break out if player wants to quit
                cout << "Your grid:" << endl;
                user.printGrid();
                cout << endl << "Your tracking grid: " << endl;
                trackingGrid.printGrid();
                cout << endl << "The opponent's grid: " << endl;
                cpu.printGrid();
                break;

            }

    }
    if(cpu.gameWon()) //if cpu's board is clear of any ships, player wins
        {
            cout << "Game over! You win!" << endl;
            cout << "Thanks for playing! Here are the results." << endl; //display results with a congrats message
            cout << "Your grid:" << endl;
            user.printGrid();
            cout << endl << "Your tracking grid: " << endl;
            trackingGrid.printGrid();
            cout << endl << "The opponent's grid: " << endl;
            cpu.printGrid();
        }
    else
       {
        cout << "Game over! You lose!" << endl; //else, player must have lost
        cout << "Thanks for playing! Here are the results." << endl;
        cout << "Your grid:" << endl;
        user.printGrid();
        cout << endl << "Your tracking grid: " << endl; //display results with loss message
        trackingGrid.printGrid();
        cout << endl << "The opponent's grid: " << endl;
        cpu.printGrid();
        }

    if(!keepPlaying)
    {
        cout << "Goodbye!" << endl; //goodbye message if player quit
    }


    return 0;
}