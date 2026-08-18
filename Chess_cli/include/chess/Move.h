#pragma once

#include<optional>
#include "chess/Position.h"
#include "chess/PieceType.h"

struct Move {
	Position from, to;
	PieceType movedPiece;
	std::optional<PieceType>capturedPiece;
	bool isEnPassant = false, isCastleKingside = false, isCastleQueenside = false;
	std::optional<PieceType>promotion;
	Move(Position f, Position t, PieceType piece) : from(f), to(t), movedPiece(piece) {}
};