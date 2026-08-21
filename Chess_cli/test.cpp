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

int main() {
    {
        Board board;
        Position e4 = Position::fromAlgebraic("e4");
        board.setPiece(e4, std::make_unique<King>(Color::White));
        board.setPiece(Position::fromAlgebraic("e5"), std::make_unique<Knight>(Color::White));
        board.setPiece(Position::fromAlgebraic("f5"), std::make_unique<Knight>(Color::Black));

        Piece* king = board.pieceAt(e4);
        std::vector<Position> moves = king->pseudoLegalMoves(board, e4);

        std::cout << "King on e4 can move to: ";
        for (const auto& m : moves) std::cout << m.toAlgebraic() << " ";
        std::cout << std::endl;
    }
    return 0;
}