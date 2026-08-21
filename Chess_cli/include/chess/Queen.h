#pragma once
#include "chess/Piece.h"

class Queen :public Piece {
public:
	Queen(Color color) :Piece(color) {}
	std::vector<Position>pseudoLegalMoves(const Board& board, Position from)const override;
	PieceType type()const override { return PieceType::Queen; }
	char symbol()const override { return 'Q'; }
};