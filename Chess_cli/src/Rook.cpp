#include "chess/Rook.h"
#include "chess/Board.h"

std::vector<Position> Rook::pseudoLegalMoves(const Board& board, Position from)const {
	std::vector<Position>moves;
	static const int directions[4][2] = {
		{0,1},{1,0},{-1,0},{0,-1}
	};
	for (const auto& dir : directions) {
		Position current(from.file + dir[0], from.rank + dir[1]);
		while (current.isValid()) {
			Piece* occupant = board.pieceAt(current);
			if (occupant == nullptr) {
				moves.push_back(current);
			}
			else {
				if (occupant->color() != color()) {
					moves.push_back(current);
				}
				break;
			}
			current = Position(current.file + dir[0], current.rank + dir[1]);
		}
	}
	return moves;
}