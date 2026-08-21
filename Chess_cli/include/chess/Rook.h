#pragma once
#include "chess/Piece.h"

class Rook : public Piece {
public:
	Rook(Color color) :Piece(color) {}
	std::vector<Position>pseudoLegalMoves(const Board& board, Position from)const override;
	PieceType type()const override { return PieceType::Rook; }
	char symbol() const override { return 'R'; }
};