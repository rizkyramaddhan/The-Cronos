#ifndef BOARD_HPP
#define BOARD_HPP

#include "raylib.h"

enum PiceType {
    EMPTY = 0, W_PAWN, W_ROOK, W_KNIGHT, W_BISHOP, W_QUEEN, W_KING,
            B_PAWN, B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, 
};


class Board {
    private :
        int grid [8][8];
        Texture2D BoardTexture;
        Texture2D piecesTexture;

    public :
        Board();
        void initBoard();
        void drawBoard();
};


#endif