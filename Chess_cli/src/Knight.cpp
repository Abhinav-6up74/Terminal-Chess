#include "chess/Knight.h"
#include "chess/Board.h"

std::vector<Position> Knight::pseudoLegalMoves(const Board& board, Position from)const {
	static const int offsets[8][2] = {
		{1,2},{2,1},{2,-1},{1,-2},
		{-1,2},{-2,1},{-1,-2},{-2,-1}
	};
	std::vector<Position>moves;
	for (const auto& offset : offsets) {
		Position target(from.file + offset[0], from.rank + offset[1]);
		if (!target.isValid())continue;
		Piece* occupant = board.pieceAt(target);
		if (occupant == nullptr || occupant->color() != color()) {
			moves.push_back(target);
		}
	}
	return moves;
}