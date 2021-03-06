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
	Board_Tile(const std::string& start, std::string end);

	/*
	* Constructor that passes the move history
	*/
	Board_Tile(const std::string& start, std::string mfs, std::string end);

	/*
	* Returns a list of all possible next moves (excluding useless moves that
	* would return the board to it's previous state)
	*/
	std::vector<Board_Tile*> nextConfigs();

	/*
	* returns the number of steps so far
	*/
	int numMoves();

	/*
	* Calculates and returns the manhattan distance of the current board as
	* compared to the desired final configuration of the board
	*/
	int Manhattan_Distance(Board_Tile goalconfig);

	/*
	* returns the string stored in config
	*/
	std::string getConfig();

	/*
	* pritns out our tiles all nice like for the user
	*/
	void print();

	void printFinal();

	/*
	* finds where the blank space (0) is in config
	*/
	int findBlank();

	/*
	* finds where the blank space (0) is in configFluid
	*/
	int findBlankFluid();

	/*
	* Moves the blank space (0) left
	*/
	void moveLeft(int blank);

	/*
	* Moves the blank space (0) right
	*/
	void moveRight(int blank);

	/*
	* Moves the blank space (0) up
	*/
	void moveUp(int blank);

	/*
	* Moves the blank space (0) down
	*/
	void moveDown(int blank);

	/*
	* returns manhattanDistance
	*/
	int getmanhattanDistance();

	std::string getConfigFluid();

	std::string getEndConfig();

	std::string getMovesFromStart();

	/*
	* overloaded < operator to compare Board_Tiles directly in minHeap
	*/
	bool operator> (Board_Tile bt);

private:

	std::string config;
	std::string configFluid;
	std::string movesFromStart;
	int manhattanDistance;
	std::string endConfig;

};

#endif /* BOARD_TILE */
