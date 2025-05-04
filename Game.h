#include "Board.h"

class Game {
    Board board;
    Cell turn = Cell::Red;
public:
    void run();                     // main loop
    void switchTurn();              
    Cell currentPlayer() const;     
};
