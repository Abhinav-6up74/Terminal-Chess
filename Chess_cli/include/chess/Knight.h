#pragma once
#include "chess/Piece.h"

class Knight :public Piece {
public:
	Knight(Color color) :Piece(color) {}
	std::vector<Position>pseudoLegalMoves(const Board& board, Position from) const override;
	PieceType type()const override { return PieceType::Knight; }
	char symbol() const override { return 'N'; }
};