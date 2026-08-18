#include "chess/Board.h"

Board::Board(){}

Piece* Board::pieceAt(Position pos)const {
	return squares[index(pos)].get();
}

void Board::setPiece(Position pos, std::unique_ptr<Piece>piece) {
	squares[index(pos)] = std::move(piece);
}
bool Board::isEmpty(Position pos)const {
	return squares[index(pos)] == nullptr;
}