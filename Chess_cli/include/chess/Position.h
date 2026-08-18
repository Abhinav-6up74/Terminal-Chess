#pragma once

#include <string>
#include <stdexcept>

// file: 0-7 for columns a-h
// rank: 0-7 for rows 1-8
struct Position {
    int file;
    int rank;
    Position(int f, int r) : file(f), rank(r) {}
    bool isValid() const {
        return file >= 0 && file < 8 && rank >= 0 && rank < 8;
    }
    bool operator==(const Position& other) const {
        return file == other.file && rank == other.rank;
    }
    bool operator!=(const Position& other) const {
        return !(*this == other);
    }
    std::string toAlgebraic() const {
        if (!isValid()) {
            throw std::out_of_range("Position::toAlgebraic: position out of range");
        }
        std::string result;
        result += char('a' + file);
        result += char('1' + rank);
        return result;
    }

    static Position fromAlgebraic(const std::string& square) {
        if (square.size() != 2) {
            throw std::invalid_argument("Position::fromAlgebraic: invalid square '" + square + "'");
        }
        int f = square[0] - 'a';
        int r = square[1] - '1';
        Position pos(f, r);
        if (!pos.isValid()) {
            throw std::invalid_argument("Position::fromAlgebraic: invalid square '" + square + "'");
        }
        return pos;
    }
};