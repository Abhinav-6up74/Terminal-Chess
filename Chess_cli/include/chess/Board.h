#pragma once

#include<array>
#include<memory>
#include"chess/Position.h"
#include"chess/Piece.h"

class  Board {
public:
	Board();
	Piece* pieceAt(Position pos)const;
	void setPiece(Position pos, std::unique_ptr<Piece>piece);
	bool isEmpty(Position pos)const;
private:
	static int index(Position pos) { return pos.rank * 8 + pos.file; }
	std::array<std::unique_ptr<Piece>, 64>squares;
};