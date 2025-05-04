#include <array>

enum class Cell { Empty, Red, Yellow };

class Board {
    static constexpr int ROWS = 6;
    static constexpr int COLS = 7;
    std::array<std::array<Cell,COLS>,ROWS> grid;
public:
    Board();
    // drop a token into column return -1 if full
    int drop(int c, Cell token);
    // check if last move made token win
    bool checkWin(int r, int c) const;
    bool isFull() const;
    void print() const;
};
