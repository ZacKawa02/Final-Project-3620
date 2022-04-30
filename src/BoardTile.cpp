/*
* Zachary Kawa, Tanner Heise
* CPSC 3620 Final Project
*/
#include "BoardTile.h"
#include <iostream>
#include <string>
#include <vector>


Board_Tile::Board_Tile(const std::string& start, std::string end) {
    config = start;
    configFluid = start;
    endConfig = end;
    movesFromStart = "";
    manhattanDistance = 1;
}

Board_Tile::Board_Tile(const std::string& start, std::string mfs, std::string end) {
    config = start;
    configFluid = start;
    endConfig = end;
    movesFromStart = mfs;
}


std::vector<Board_Tile*> Board_Tile::nextConfigs() {
    std::vector<Board_Tile*> boardList;
    if (this->findBlankFluid() != 12 && this->findBlankFluid() != 14 && this->findBlankFluid() != 16) {
        Board_Tile* moveD = new Board_Tile(configFluid, movesFromStart);
        moveD->moveDown(moveD->findBlankFluid());
        boardList.push_back(moveD);
    }
    if (this->findBlankFluid() != 0 && this->findBlankFluid() != 2 && this->findBlankFluid() != 4) {
        Board_Tile* moveU = new Board_Tile(config, movesFromStart);
        moveU->moveUp(moveU->findBlankFluid());
        boardList.push_back(moveU);
    }
    if (this->findBlankFluid() != 0 && this->findBlankFluid() != 6 && this->findBlankFluid() != 12) {
        Board_Tile* moveL = new Board_Tile(config, movesFromStart);
        moveL->moveLeft(moveL->findBlankFluid());
        boardList.push_back(moveL);
    }
    if (this->findBlankFluid() != 4 && this->findBlankFluid() != 10 && this->findBlankFluid() != 16) {
        Board_Tile* moveR = new Board_Tile(config, movesFromStart);
        moveR->moveRight(moveR->findBlankFluid());
        boardList.push_back(moveR);
    }
    return boardList;
}


int Board_Tile::numMoves() {
    int moves;
    moves = movesFromStart.length();
    return moves;
}

int Board_Tile::Manhattan_Distance(Board_Tile goalconfig) {
    int manDist = 0;
    std::string goalString = goalconfig.getConfig();
    for (unsigned int i = 0; i < 9; i++) {
        for (unsigned int j = 0; j < 9; j++) {
            // The "missing" tile isn't counted in Manhattan Distance calculations
            // and if the tile is already in position add 0 to MD total
            if (goalString.at(2 * i) == '0' || goalString.at(2 * i) == config.at(2 * i)) {
                manDist += 0;
            }
            // Find how far away the tiles are in their string representation
            // then use that number to calculate how far away they are in MD
            else if (goalString.at(2 * j) == config.at(2 * i)) {
                int distDefine = j - i;
                //Find distance from ending position of current tile
                switch (distDefine) {
                case 1:
                case -1:
                    manDist += 1;
                    break;
                case 2:
                case -2:
                    manDist += 2;
                    break;
                case 3:
                case -3:
                    manDist += 1;
                    break;
                case 4:
                case -4:
                    manDist += 2;
                    break;
                case 5:
                case -5:
                    manDist += 3;
                    break;
                case 6:
                case -6:
                    manDist += 2;
                    break;
                case 7:
                case -7:
                    manDist += 3;
                    break;
                case 8:
                case -8:
                    manDist += 4;
                    break;
                }
            }
        }
    }
    manhattanDistance = manDist;
    return manDist;
}

std::string Board_Tile::getConfig() {
    return config;
}

void Board_Tile::print() {
    std::cout << config.at(0) << " " << config.at(2) << " " << config.at(4) << std::endl;
    std::cout << config.at(6) << " " << config.at(8) << " " << config.at(10) << std::endl;
    std::cout << config.at(12) << " " << config.at(14) << " " << config.at(16) << std::endl << std::endl;
}

void Board_Tile::printFinal() {
    std::cout << endConfig.at(0) << " " << endConfig.at(2) << " " << endConfig.at(4) << std::endl;
    std::cout << endConfig.at(6) << " " << endConfig.at(8) << " " << endConfig.at(10) << std::endl;
    std::cout << endConfig.at(12) << " " << endConfig.at(14) << " " << endConfig.at(16) << std::endl << std::endl;
}

int Board_Tile::findBlank() {
    return config.find("0");
}

int Board_Tile::findBlankFluid() {
    return configFluid.find("0");
}

void Board_Tile::moveLeft(int blank) {
    char temp = configFluid.at(blank - 2);
    char empty = configFluid.at(blank);
    configFluid.erase(blank, 1);
    configFluid.insert(blank, 1, temp);
    configFluid.erase(blank - 2, 1);
    configFluid.insert(blank - 2, 1, empty);
    movesFromStart.append("L");
}

void Board_Tile::moveRight(int blank) {
    char temp = configFluid.at(blank + 2);
    char empty = configFluid.at(blank);
    configFluid.erase(blank, 1);
    configFluid.insert(blank, 1, temp);
    configFluid.erase(blank + 2, 1);
    configFluid.insert(blank + 2, 1, empty);
    movesFromStart.append("R");
}

void Board_Tile::moveUp(int blank) {
    char temp = configFluid.at(blank - 6);
    char empty = configFluid.at(blank);
    configFluid.erase(blank, 1);
    configFluid.insert(blank, 1, temp);
    configFluid.erase(blank - 6, 1);
    configFluid.insert(blank - 6, 1, empty);
    movesFromStart.append("U");
}

void Board_Tile::moveDown(int blank) {
    char temp = configFluid.at(blank + 6);
    char empty = configFluid.at(blank);
    configFluid.erase(blank, 1);
    configFluid.insert(blank, 1, temp);
    configFluid.erase(blank + 6, 1);
    configFluid.insert(blank + 6, 1, empty);
    movesFromStart.append("D");
}

int Board_Tile::getmanhattanDistance() {
    return manhattanDistance;
}

std::string Board_Tile::getConfigFluid() {
    return configFluid;
}

std::string Board_Tile::getEndConfig() {
    return endConfig;
}

bool Board_Tile::operator> (Board_Tile bt) {
    Board_Tile endBoard(config, endConfig);
    if (manhattanDistance > bt.Manhattan_Distance(endBoard)) {
        return true;
    }
    else if (manhattanDistance < bt.Manhattan_Distance(endBoard)) {
        return false;
    }
    else {
        return true;
    }
}

std::string Board_Tile::getMovesFromStart() {
    return movesFromStart;
}
