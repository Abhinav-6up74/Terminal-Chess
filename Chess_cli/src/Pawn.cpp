#include "chess/Board.h"
#include "chess/Pawn.h"

std::vector<Position>Pawn::pseudoLegalMoves(const Board& board, Position from)const {
	std::vector<Position>moves;
	int direction = (color() == Color::White) ? 1 : -1;
	int startingRank = (color() == Color::White) ? 1 : 6;
	Position oneForward(from.file, from.rank + direction);
	if (oneForward.isValid() && board.pieceAt(oneForward) == nullptr) {
		moves.push_back(oneForward);
		if (from.rank == startingRank) {
			Position twoForward(from.file, from.rank + direction * 2);
			if (twoForward.isValid() && board.pieceAt(twoForward) == nullptr) {
				moves.push_back(twoForward);
			}
		}
	}
	for (int df : {1, -1}) {
		Position diag(from.file + df, from.rank + direction);
		if (!diag.isValid())continue;
		Piece* occupant = board.pieceAt(diag);
		if (occupant!=nullptr&&occupant->color() != color()) {
			moves.push_back(diag);
		}
	}
	return moves;
}