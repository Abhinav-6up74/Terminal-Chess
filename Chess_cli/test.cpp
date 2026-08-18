#include "chess/Position.h"
#include "chess/PieceType.h"
#include "chess/Move.h"
#include "chess/Piece.h"
#include <iostream>
#include <memory>
#include "chess/Board.h"

// Fake piece, just for testing Piece.h - not part of the real project.
class TestKnight : public Piece {
public:
    TestKnight(Color c) : Piece(c) {}

    std::vector<Position> pseudoLegalMoves(const Board& /*board*/, Position from) const override {
        return { Position(0, 0), Position(1, 2) };
    }
    PieceType type() const override { return PieceType::Knight; }
    char symbol() const override { return 'N'; }
};

int main() {
    // Piece p(Color::White);   // <-- would fail to compile: Piece is abstract

    std::unique_ptr<Piece> piece = std::make_unique<TestKnight>(Color::White);
    std::cout << "symbol: " << piece->symbol() << std::endl;
    std::cout << "color is white: " << (piece->color() == Color::White ? "yes" : "no") << std::endl;
    Board board;
    Position e4(4, 3);
    std::cout << "e4 is empty: " << (board.isEmpty(e4) ? "yes" : "no") << std::endl;
    return 0;
}