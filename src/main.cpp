/*
* Zachary Kawa, Tanner Heise
* CPSC 3620 Final Project
*/
#include "BoardTile.h"
#include "SlidingSolver.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>

int main(int argc, char const* argv[]) {
	std::string initConfig = "0 1 2 3 4 5 6 7 8";
	std::string endConfig = "1 0 2 3 4 5 6 7 8";

	std::cout << "Please enter the starting config for the puzzle:" << std::endl;
	std::cout << "(Example: 0 1 2 3 4 5 6 7 8)" << std::endl;
	std::cin >> initConfig;
	std::cout << "Please enter the ending config:" << std::endl;
	std::cin >> endConfig;
	std::cout << "-------------------------------------" << std::endl;

	Board_Tile starter(initConfig);
	Board_Tile ender(endConfig);

	Sliding_Solver ss(initConfig, endConfig);

	ss.makeHeap(starter.nextConfigs());

	ss.Solve_Puzzle();

	return 0;
}
