#pragma once
#include "chess/Piece.h"

class Bishop :public Piece {
public:
	Bishop(Color color) :Piece(color) {}
	std::vector<Position> pseudoLegalMoves(const Board& board, Position from)const override;
	PieceType type()const override { return PieceType::Bishop; }
	char symbol()const override { return 'B'; }
};