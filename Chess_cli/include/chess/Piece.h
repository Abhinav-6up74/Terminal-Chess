#pragma once

#include<vector>
#include "chess/PieceType.h"
#include "chess/Position.h"

class Board;

class Piece {
public:
	Piece(Color color) :pieceColor(color) {}
	virtual ~Piece() = default;
	virtual std::vector<Position>pseudoLegalMoves(const Board& board, Position from)const = 0;
	virtual PieceType type() const = 0;
	virtual char symbol() const = 0;
	Color color() const { return pieceColor;}
protected:
	Color pieceColor;
};