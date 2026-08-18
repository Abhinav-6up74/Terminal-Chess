#include "chess/Position.h"
#include "chess/PieceType.h"
#include "chess/Move.h"
#include "chess/Piece.h"
#include <iostream>
#include <memory>
#include "chess/Board.h"
#include "chess/Knight.h"


int main() {
    Board board;
    Position b1(1, 0);   // b1
    board.setPiece(b1, std::make_unique<Knight>(Color::White));

    Piece* knight = board.pieceAt(b1);
    std::vector<Position> moves = knight->pseudoLegalMoves(board, b1);

    std::cout << "Knight on b1 can move to: ";
    for (const auto& m : moves) {
        std::cout << m.toAlgebraic() << " ";
    }
    std::cout << std::endl;
    return 0;
}