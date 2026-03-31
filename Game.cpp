#include "Game.h"
#include <iostream>
using namespace std;

// Constructor
Game::Game() : player1("Player 1", 'X'), player2("Player 2", 'O') {
    currentPlayer = &player1;
}

// Switch player
void Game::switchPlayer() {
    if(currentPlayer == &player1)
        currentPlayer = &player2;
    else
        currentPlayer = &player1;
}

// Start game
void Game::start() {
    int row, col;

    while(true) {
        board.display();

        cout << currentPlayer->getName() << " ("
             << currentPlayer->getSymbol() << ") turn: ";

        cin >> row >> col;

        if(board.makeMove(row, col, currentPlayer->getSymbol())) {

            if(board.checkWin(currentPlayer->getSymbol())) {
                board.display();
                cout << currentPlayer->getName() << " WINS!\n";
                break;
            }

            switchPlayer();
        } else {
            cout << "Invalid move! Try again.\n";
        }
    }
}