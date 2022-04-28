/*
* Zachary Kawa, Tanner Heise
* CPSC 3620 Final Project
*/
#include "BoardTile.h"
#include <iostream>
#include <string>
#include <vector>


   Board_Tile::Board_Tile(const std::string& start) {
     config = start;
     movesFromStart = "";
   }

   std::vector<Board_Tile> Board_Tile::nextConfigs() {
     std::vector<Board_Tile> boardList;
     std::cout << "Current Board: " << config << std::endl;
     for (unsigned int i = 0; i < 3; i++) {
       //Generate the next potential boards and put them into the vector
       //Don't include the previous move or moves that go off the board!
     }
   }

   int Board_Tile::numMoves() {
     int moves;
     moves = movesFromStart.length();
     return moves;
   }

   int Board_Tile::Manhattan_Distance(const Board_Tile& goalconfig) {
     int manDist = 0;
     std::string goalString = goalconfig.getConfig();
     for (unsigned int i = 0; i < 9; i++) {
       for (unsigned int j = 0; j < 9; j++) {
         // The "missing" tile isn't counted in Manhattan Distance calculations
         if (goalString.at(2*i) == "0" || goalString.at(2*i) == config.at(2*i)) {
           manDist += 0;
         }
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
     return manDist;
   }

   std::string Board_Tile::getConfig() {
     return config;
   }

   void Board_Tile::print() {
   	std::cout << "string: " << config << std::endl;
   	std::cout << config.at(0) << " " << config.at(2) << " " << config.at(4) << std::endl;
   	std::cout << config.at(6) << " " << config.at(8) << " " << config.at(10) << std::endl;
   	std::cout << config.at(12) << " " << config.at(14) << " " << config.at(16) << std::endl << std::endl;
   }

   int Board_Tile::findBlank() {
   	return config.find("0");
   }

   void Board_Tile::moveLeft(int blank) {
   	char temp = config.at(blank - 2);
   	char empty = config.at(blank);
   	config.erase(blank, 1);
   	config.insert(blank, 1, temp);
   	config.erase(blank - 2, 1);
   	config.insert(blank - 2, 1, empty);
    movesFromStart.append(L);
   }

   void Board_Tile::moveRight(int blank) {
   	char temp = config.at(blank + 2);
   	char empty = config.at(blank);
   	config.erase(blank, 1);
   	config.insert(blank, 1, temp);
   	config.erase(blank + 2, 1);
   	config.insert(blank + 2, 1, empty);
    movesFromStart.append(R);
   }

   void Board_Tile::moveUp(int blank) {
   	char temp = config.at(blank - 6);
   	char empty = config.at(blank);
   	config.erase(blank, 1);
   	config.insert(blank, 1, temp);
   	config.erase(blank - 6, 1);
   	config.insert(blank - 6, 1, empty);
    movesFromStart.append(U);
   }

   void Board_Tile::moveDown(int blank) {
   	char temp = config.at(blank + 6);
   	char empty = config.at(blank);
   	config.erase(blank, 1);
   	config.insert(blank, 1, temp);
   	config.erase(blank + 6, 1);
   	config.insert(blank + 6, 1, empty);
    movesFromStart.append(D);
   }
