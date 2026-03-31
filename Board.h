#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    Board();
    void display();
    bool makeMove(int row, int col, char symbol);
    bool checkWin(char symbol);
};

#endif