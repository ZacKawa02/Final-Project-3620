/*
* Zachary Kawa, Tanner Heise
* CPSC 3620 Final Project
*/
#include "BoardTile.h"
#include "SlidingSolver.h"
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

int main(int argc, char const *argv[]) {
  std::string initConfig = "012345678";
  std::string endConfig = "102345678";

  std::cout << "Please enter the starting config for the puzzle:" << std::endl;
  std::cin >> initConfig;
  std::cout << "Please enter the ending config:" << std::endl;
  std::cin >> endConfig;
  std::cout << "-------------------------------------" << std::endl;

  Board_Tile starter(initConfig);
  Board_Tile ender(endConfig);

  cout << Manhattan_Distance(ender);

  return 0;
}
