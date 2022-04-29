/*
* Zachary Kawa, Tanner Heise
* CPSC 3620 Final Project
*/
#ifndef SLIDINGSOLVER_H
#define SLIDINGSOLVER_H

#include "BoardTile.h"
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <queue>

class Sliding_Solver {
 public:

  /*
  * Constructor, takes in the initial and final configurations of the puzzle
  */
  Sliding_Solver(std::string startConfig, std::string endConfig);

  /*
  * Solves the puzzle using A* Search
  */
  void Solve_Puzzle();

  /*
  * Uses Board_Tile::nextConfigs to generate and push the Board_Tiles onto the
  * minHeap tileQueue
  */
  void makeHeap(std::vector<Board_Tile> list);

 private:

  std::priority_queue<Board_Tile, std::vector<Board_Tile>, std::greater<Board_Tile>> tileQueue;

};

#endif /* SLIDING_SOLVER */
