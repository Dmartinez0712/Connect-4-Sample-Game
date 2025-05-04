#include "Board.h"
#include <iostream>

Board::Board() {
    for (auto& row : grid)
        row.fill(Cell::Empty);
}
//drop token
int Board::drop(int c, Cell token) {
    for (int r = ROWS - 1; r >= 0; --r) {
        if (grid[r][c] == Cell::Empty) {
            grid[r][c] = token;
            return r;
        }
    }
    return -1;
}

// implement checks for tokens
bool Board::checkWin(int r, int c) const {
    const int directions[4][2] = {{0,1},{1,0},{1,1},{1,-1}};
    Cell t = grid[r][c];
    for (auto& d : directions) {
        int count = 1;
        for (int sign : {1, -1}) {
            int dr = d[0]*sign, dc = d[1]*sign;
            int rr = r+dr, cc = c+dc;
            while (rr>=0 && rr<ROWS && cc>=0 && cc<COLS && grid[rr][cc]==t) {
                count++; rr+=dr; cc+=dc;
            }
        }
        if (count >= 4) return true;
    }
    return false;
}
//check of column to see if its full
bool Board::isFull() const {
    for (int c = 0; c < COLS; ++c)
        if (grid[0][c] == Cell::Empty) return false;
    return true;
}

void Board::print() const {
    for (auto& row : grid) {
        for (auto& cell : row) {
            char ch = (cell==Cell::Red ? 'R' : cell==Cell::Yellow ? 'Y' : '.');
            std::cout << ch << ' ';
        }
        std::cout << "\n";
    }
    std::cout << "0 1 2 3 4 5 6\n\n";
}
