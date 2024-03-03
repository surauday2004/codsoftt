#include <iostream>
#include <vector>
using namespace std;
void displayBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Check rows
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Check columns
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Check main diagonal
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Check anti-diagonal
    }
    return false;
}
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}
void getPlayerMove(char player, vector<vector<char>>& board) {
    int row, col;
    cout << "Player " << player << ", enter your move (row and column): ";
    cin >> row >> col;
    board[row][col] = player;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); 
    char currentPlayer = 'X';
      cout << "Welcome to Tic-Tac-Toe!" << endl;
    while (true) {
        displayBoard(board);
        getPlayerMove(currentPlayer, board);
        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        if (checkDraw(board)) {
            cout << "It's a draw!" << endl;
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    displayBoard(board);

    return 0;
}