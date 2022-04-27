/*
* Zachary Kawa, Tanner Heise
* CPSC 3620 Final Project
*/
#ifndef BOARDTILE_H
#define BOARDTILE_H

#include <iostream>
#include <string>
#include <vector>

class Board_Tile {
 public:

  /*
  * Constructor takes a beginning configuration and creates the starting board
  */
  Board_Tile(const std::string& start);

  /*
  * Returns a list of all possible next moves (excluding useless moves that
  * would return the board to it's previous state)
  */
  std::vector<Board_Tile> nextConfigs();

  /*
  * returns the number of steps so far
  */
  int numMoves();

  /*
  * Calculates and returns the manhattan distance of the current board as
  * compared to the desired final configuration of the board
  */
  int Manhattan_Distance(const Board_Tile& goalconfig);

  /*
  * returns the string stored in config
  */
  std::string getConfig();

 private:

  std::string config;
  std::string movesFromStart;

};

#endif /* BOARD_TILE */
