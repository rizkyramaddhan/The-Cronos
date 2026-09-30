#ifndef BOARD_HPP
#define BOARD_HPP

#include "raylib.h"

#include <vector>

// Enum untuk warna bidak
enum class pieceColor {
    none = 0, white, black
};

// Enum untuk jenis bidak
enum class pieceType {
    none = 0, pawn, knight, bishop, rook, queen, king
};

// struct ringan untuk presentasi ukuran 1 bidak
struct piece {
    pieceType type;
    pieceColor color;

    // hellper untuk mengecek apakah ada bidak di kotak
    bool isEmpty() const{
        return type == pieceType::none;
    }
};  

class Board {
    private :
        // Array 1D yang berisi tepat 64 elemen
        // index 0 adalah pojok kiri atas (a8) dan index 63 adalah pojok kanan bawah (h1)
        std::vector<piece> squares;

    public :
        // Constructor
        Board();
        // menginisialisasi posisi awal standar catur
        void setupInitialPosision();
        // fungsi helper membersikan seluruh board menjadi kosong
        void clearBoard();
        // fungsi helper untuk mendapatkan bidak berdasarkan baris & kolom (0 - 63)
        piece getPiece(int index) const;
        // fungsi helper untuk mendapatkan bidak berdasarkan baris & kolom (0 - 7)
        piece getPiece(int row, int col) const;
        // debugging : menampilkan papan ke console 
        void printBoard() const;

};


#endif