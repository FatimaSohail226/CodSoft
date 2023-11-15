#include <iostream>
#include <vector>
using namespace std;

// Function to initialize the game board
void initializeBoard(vector<vector<char>>& board) {
    board = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
}

// Function to display the game board
void displayBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check for a win
bool checkWin(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }
    return false;
}

// Function to check for a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Function to update the board with the player's move
bool makeMove(vector<vector<char>>& board, int move, char player) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
        return true;
    }
    return false;
}

int main() {
    vector<vector<char>> board;
    char currentPlayer = 'X';
    int move;
    bool playAgain = true;

    while (playAgain) {
        initializeBoard(board);
        bool gameOver = false;

        while (!gameOver) {
            displayBoard(board);
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (makeMove(board, move, currentPlayer)) {
                if (checkWin(board)) {
                    displayBoard(board);
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    gameOver = true;
                } else if (checkDraw(board)) {
                    displayBoard(board);
                    cout << "It's a draw!" << endl;
                    gameOver = true;
                } else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }

        cout << "Play again? (1 for yes, 0 for no): ";
        cin >> playAgain;
    }

    return 0;
}
