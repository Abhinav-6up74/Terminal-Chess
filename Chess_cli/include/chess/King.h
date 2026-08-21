#pragma once
#include "chess/Piece.h"

class King :public Piece {
public:
	King(Color color) :Piece(color) {}
	std::vector<Position>pseudoLegalMoves(const Board& board, Position from)const override;
	PieceType type()const override { return PieceType::King; }
	char symbol()const override { return 'K'; }
};