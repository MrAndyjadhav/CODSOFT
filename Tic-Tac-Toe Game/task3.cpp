#include <iostream>
#include <cstdlib> // for system("clear") or system("cls")
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

void drawBoard() {
    system("clear"); // For Windows use "cls"
    cout << "  Tic-Tac-Toe Game" << endl;
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (j != 0)
                cout << " | ";
            cout << board[i][j];
        }
        if (i != SIZE - 1)
            cout << "\n---------\n";
    }
    cout << "\n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / SIZE;
    int col = (slot - 1) % SIZE;
    if (slot < 1 || slot > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }
    board[row][col] = currentPlayer;
    return true;
}

bool checkWin() {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

bool checkTie() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    int slot;
    bool gameOver = false;

    while (!gameOver) {
        drawBoard();
        cout << "Player " << currentPlayer << ", enter a number (1-9): ";
        cin >> slot;

        if (placeMarker(slot)) {
            if (checkWin()) {
                drawBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            } else if (checkTie()) {
                drawBoard();
                cout << "It's a tie!" << endl;
                gameOver = true;
            } else {
                switchPlayer();
            }
        } else {
            cout << "Invalid move, try again." << endl;
        }
    }

    return 0;
}
