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

int main() {
    Board boardr;
    Position d4r = Position::fromAlgebraic("d4");
    boardr.setPiece(d4r, std::make_unique<Rook>(Color::White));

    // Put a friendly pawn... well, we don't have Pawn yet, so use a Knight as a stand-in blocker
    boardr.setPiece(Position::fromAlgebraic("d6"), std::make_unique<Knight>(Color::White));
    boardr.setPiece(Position::fromAlgebraic("f4"), std::make_unique<Knight>(Color::Black));

    Piece* rook = boardr.pieceAt(d4r);
    std::vector<Position> movesr = rook->pseudoLegalMoves(boardr, d4r);

    std::cout << "Rook on d4 can move to: ";
    for (const auto& m : movesr) {
        std::cout << m.toAlgebraic() << " ";
    }
    std::cout << std::endl;
    Board boardb;
    Position d4b = Position::fromAlgebraic("d4");
    boardb.setPiece(d4b, std::make_unique<Bishop>(Color::White));
    boardb.setPiece(Position::fromAlgebraic("f6"), std::make_unique<Knight>(Color::White));
    boardb.setPiece(Position::fromAlgebraic("a1"), std::make_unique<Knight>(Color::Black));

    Piece* bishop = boardb.pieceAt(d4b);
    std::vector<Position> movesb = bishop->pseudoLegalMoves(boardb, d4b);

    std::cout << "Bishop on d4 can move to: ";
    for (const auto& m : movesb) {
        std::cout << m.toAlgebraic() << " ";
    }
    std::cout << std::endl;
    return 0;
}