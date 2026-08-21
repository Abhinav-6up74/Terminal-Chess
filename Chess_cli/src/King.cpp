#include "chess/Board.h"
#include "chess/King.h"

std::vector<Position>King::pseudoLegalMoves(const Board& board, Position from)const {
	std::vector<Position>moves;
	static const int directions[8][2] = {
		{0,1},{0,-1},{1,0},{-1,0},
		{1,1},{-1,1},{-1,-1},{1,-1}
	};
	for (const auto& dir : directions) {
		Position current(from.file + dir[0], from.rank + dir[1]);
		if (!current.isValid())continue;
		Piece* occupant = board.pieceAt(current);
		if (occupant == nullptr || occupant->color() != color()) {
			moves.push_back(current);
		}
	}
	return moves;
}