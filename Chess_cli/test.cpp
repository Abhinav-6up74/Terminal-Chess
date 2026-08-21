#include "chess/Position.h"
#include "chess/PieceType.h"
#include "chess/Move.h"
#include "chess/Piece.h"
#include <iostream>
#include <memory>
#include "chess/Board.h"
#include "chess/Knight.h"
#include "chess/Rook.h"
#include "chess/Bishop.h"
#include "chess/Queen.h"
#include "chess/King.h"
#include "chess/Pawn.h"

int main() {
    {
        Board board;
        Position e2 = Position::fromAlgebraic("e2");
        board.setPiece(e2, std::make_unique<Pawn>(Color::White));
        board.setPiece(Position::fromAlgebraic("d3"), std::make_unique<Knight>(Color::Black));

        Piece* pawn = board.pieceAt(e2);
        std::vector<Position> moves = pawn->pseudoLegalMoves(board, e2);

        std::cout << "Pawn on e2 can move to: ";
        for (const auto& m : moves) std::cout << m.toAlgebraic() << " ";
        std::cout << std::endl;
    }
    return 0;
}