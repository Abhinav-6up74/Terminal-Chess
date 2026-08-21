#include "chess/Board.h"
#include <vector>
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

bool Board::isSquareAttacked(Position square, Color attackColor)const {
	for (int rank = 0;rank < 8;rank++) {
		for (int file = 0;file < 8;file++) {
			Position pos(file, rank);
			Piece* piece = pieceAt(pos);
			if (piece == nullptr || piece->color() != attackColor)continue;
			std::vector<Position>moves = piece->pseudoLegalMoves(*this, pos);
			for (const auto& move : moves) {
				if (move == square)return true;
			}
		}
	}
	return false;
}