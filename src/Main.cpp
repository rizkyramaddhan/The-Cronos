#include "raylib.h"
#include "./core/Board.hpp"

#include <iostream>

int main(){
    
    Board board;
    board.setupInitialPosision();
    board.printBoard();
    
    std::cin.get();
    return 0;
}