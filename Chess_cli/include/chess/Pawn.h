#pragma once
#include "chess/Piece.h"

class Pawn :public Piece {
public:
	Pawn(Color color) :Piece(color) {}
	std::vector<Position>pseudoLegalMoves(const Board& board, Position from)const override;
	PieceType type()const override { return PieceType::Pawn; }
	char symbol()const override { return 'P'; }
};