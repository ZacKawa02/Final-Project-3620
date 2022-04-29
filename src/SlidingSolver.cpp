/*
* Zachary Kawa, Tanner Heise
* CPSC 3620 Final Project
*/
#include "SlidingSolver.h"
#include "BoardTile.h"
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <queue>


  Sliding_Solver::Sliding_Solver(std::string startConfig, std::string endConfig) {

  }

  void Sliding_Solver::Solve_Puzzle() {

  }

  void Sliding_Solver::makeHeap(std::vector<Board_Tile> list) {
    int key;
    //for each Board_Tile in the list of next possible configurations, push
    //each to the heap using it's MD as a key
    for (unsigned int i = 0; i < list.size(); i++) {
      key = list.at(i);
      tileQueue.push();
    }
  }
