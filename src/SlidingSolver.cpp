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
    Board_Tile* bt = new Board_Tile(sc, ec);
    tileQueue.push(bt);
}



void Sliding_Solver::Solve_Puzzle() {
    Board_Tile* currentBT = new Board_Tile(sc, ec);
    std::vector<Board_Tile*> currentQueue;
    while (!tileQueue.empty()) {
        currentBT = tileQueue.top();
        tileQueue.pop();
        if (currentBT->getConfigFluid() == currentBT->getEndConfig()) {
            currentBT->print();
            std::cout << "End conficuration: " << std::endl;
            std::cout << "Solved in: " << currentBT->numMoves() << " moves." << std::endl;
            std::cout << "Solution: " << currentBT->getMovesFromStart() << std::endl;
            break;
        }
        currentQueue = currentBT->nextConfigs();
        for (Board_Tile* temp : currentQueue) {
            tileQueue.push(temp);
        }
        //delete currentBT;
    }
    //delete currentBT;
}
/*
void Sliding_Solver::Solve_Puzzle() {
    Board_Tile* currentBT = new Board_Tile(sc, ec);
    currentBT = tileQueue.top();
    while (!tileQueue.empty()) {
        tileQueue.pop();
    }
    if (currentBT->getConfigFluid() != currentBT->getEndConfig()) {
        this->makeHeap(currentBT->nextConfigs());
        this->Solve_Puzzle();
    }
    else {
        std::cout << "Start configuration: " << std::endl;
        currentBT->print();
        std::cout << "End conficuration: " << std::endl;
        std::cout << "Solved in: " << currentBT->numMoves() << " moves." << std::endl;
        std::cout << "Solution: " << currentBT->getMovesFromStart() << std::endl;
        delete currentBT;
        return;
    }
    delete currentBT;
    return;
}
*/

void Sliding_Solver::makeHeap(std::vector<Board_Tile*> list) {
    //for each Board_Tile in the list of next possible configurations, push
    //each to the heap using it's MD as a key
    for (unsigned int i = 0; i < list.size(); i++) {
        tileQueue.push(list.at(i));
    }
}
