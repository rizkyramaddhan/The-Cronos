#include "Board.hpp"

#include <iostream>

Board::Board(){
    // inisialisasi vector dengan 64 kotak kosong 
    squares.resize(64, {pieceType::none, pieceColor::none});
    setupInitialPosision();
}

void Board::clearBoard(){
    for (int i = 0; i < 64; i++){
        squares[i] = {pieceType::none, pieceColor::none};
    }
}

void Board::setupInitialPosision(){
    clearBoard();

    // bidak hitam
    squares[0] = {pieceType::rook, pieceColor::black};
    squares[1] = {pieceType::knight, pieceColor::black};
    squares[2] = {pieceType::bishop, pieceColor::black};
    squares[3] = {pieceType::queen, pieceColor::black};
    squares[4] = {pieceType::king, pieceColor::black};
    squares[5] = {pieceType::bishop, pieceColor::black};
    squares[6] = {pieceType::knight, pieceColor::black};
    squares[7] = {pieceType::rook, pieceColor::black};

    // pion hitam
    for(int i = 8; i < 16; i++){
        squares[i] = {pieceType::pawn, pieceColor::black};
    }

    // pion putih
    for(int i = 48; i < 56; i++){
        squares[i] = {pieceType::pawn, pieceColor::white};
    }

    // bidak putih
    squares[56] = {pieceType::rook, pieceColor::white};
    squares[57] = {pieceType::knight, pieceColor::white};
    squares[58] = {pieceType::bishop, pieceColor::white};
    squares[59] = {pieceType::queen, pieceColor::white};
    squares[60] = {pieceType::king, pieceColor::white};
    squares[61] = {pieceType::bishop, pieceColor::white};
    squares[62] = {pieceType::knight, pieceColor::white};
    squares[63] = {pieceType::rook, pieceColor::white};
}

piece Board::getPiece(int index) const{
    if (index >= 0 && index <= 64) return squares[index];
    return {pieceType::none, pieceColor::none};
}

piece Board::getPiece(int row, int col) const{
    int index = row * 8 + col; // rumus untuk mengubah array 2D jadi 1D
    return getPiece(index);
}

void Board::printBoard() const{
    std::cout << "\n=== CHESS BOARD ===" << std::endl;
    for(int row = 0; row < 8; row++){
        std::cout << (8 - row) << " ";
        for(int col = 0; col < 8; col++){
            piece p = getPiece(row, col);
            if(p.isEmpty()){
                std::cout << "- ";
            }else{
                char symbol = '?';
                if (p.type == pieceType::pawn) symbol = 'P';
                else if (p.type == pieceType::knight) symbol = 'N';
                else if (p.type == pieceType::bishop) symbol = 'B';
                else if (p.type == pieceType::rook) symbol = 'R';
                else if (p.type == pieceType::queen) symbol = 'Q';
                else if (p.type == pieceType::king) symbol = 'K';

                // bidak hitam di cetak huruf kecil
                if (p.color == pieceColor::black){
                    symbol = tolower(symbol);
                }

                std::cout << symbol << " ";
            }
        }
        std::cout << std::endl;
   }

   std::cout << "  a b c d e f g h\n" << std::endl;
}