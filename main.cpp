#include <iostream>
using namespace std;

char board[3][3]; // the 3x3 grid

// Fill the board with blank spaces at the start
void initializeBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// Print the board nicely
void printBoard()
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " \n";
        if (i < 2)
            cout << "---+---+---\n";
    }
    cout << "\n";
}

// Check if a specific player has won
bool checkWin(char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

bool isBoardFull()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main()
{
    initializeBoard();
    char currentPlayer = 'X';
    int row, col;

    cout << "TIC-TAC-TOE (Player 1 = X, Player 2 = O)\n";
    cout << "Enter row and column as: row col (values 1, 2, or 3 each)\n";

    while (true)
    {
        printBoard();
        cout << "Player " << currentPlayer << ", enter your move (row col): ";
        cin >> row >> col;

        int r = row - 1;
        int c = col - 1;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[r][c] != ' ')
        {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[r][c] = currentPlayer;

        if (checkWin(currentPlayer))
        {
            printBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isBoardFull())
        {
            printBoard();
            cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}