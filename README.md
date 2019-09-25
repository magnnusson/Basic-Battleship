# Basic-Battleship
Simulated game of Battleship coded in C++ as part of a school project.
The game is played between a human player and the computer using a rudimentary coded GUI involving a 10x10 board.

The game begins by reading a .csv file that is used to place the different types of ships on the player's board. This involves
error checking to make sure all ships fit on the board and do not overlap. 

The user goes first by taking a guess from A1 to J10 and is then informed if they got a hit or not on the CPU player's randomly
placed ships. The CPU then makes a random guess and the user's ships may or may not be hit. This goes on until all ships are sunk
or the user decides to quit. A ship is considered sunk if it is only hit once.

The program isn't flawless in execution and does contain some bugs in placing the CPU's ships and checking for hits.
