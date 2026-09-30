#include "raylib.h"
#include "./core/Board.hpp"

int main(){
    InitWindow(800, 600, "The Cronos");
    SetTargetFPS(60);

    Board chessBoard;
    chessBoard.initBoard();

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            chessBoard.drawBoard();
        EndDrawing();
    }

    CloseWindow();
    return 0;
    
}