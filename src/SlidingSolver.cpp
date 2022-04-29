/*
* Zachary Kawa, Tanner Heise
* CPSC 3620 Final Project
*/
#include "SlidingSolver.h"
#include "BoardTile.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>


Sliding_Solver::Sliding_Solver(std::string startConfig, std::string endConfig) {
    sc = startConfig;
    ec = endConfig;
}

void Sliding_Solver::Solve_Puzzle() {
    Board_Tile currentBT(sc);
    currentBT = tileQueue.top();
    while (!tileQueue.empty()) {
        tileQueue.pop();
    }
    if (currentBT.getConfigFluid() != currentBT.getEndConfig()) {
        this->makeHeap(currentBT.nextConfigs());
    }
}

void Sliding_Solver::makeHeap(std::vector<Board_Tile> list) {
    int key;
    //for each Board_Tile in the list of next possible configurations, push
    //each to the heap using it's MD as a key
    for (unsigned int i = 0; i < list.size(); i++) {
        tileQueue.push(list.at(i));
    }
}
