#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];
char currentPlayer;

void initializeBoard() 
{
    for (int i = 0; i < SIZE; ++i)
 {
        for (int j = 0; j < SIZE; ++j)
 {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() 
{
    cout << "\n";
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j) 
        {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << "\n";
        if (i < SIZE - 1) cout << "--+---+--\n";
    }
    cout << "\n";
}

bool isValidMove(int row, int col)
{
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ');
}

void playerInput() 
{
    int row, col;
    cout << "Player " << currentPlayer << ", enter your move (row and column): ";
    cin >> row >> col;
    while (!isValidMove(row - 1, col - 1)) 
{
        cout << "Invalid move. Try again: ";
        cin >> row >> col;
}
    board[row - 1][col - 1] = currentPlayer;
}

bool checkWin() 
{
    
    for (int i = 0; i < SIZE; ++i) 
    {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
        {
            return true;
        }
    }
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) 
    {
        return true;
    }
    return false;
}

bool checkDraw()
 {
    for (int i = 0; i < SIZE; ++i) 
   {
        for (int j = 0; j < SIZE; ++j) 
        {
            if (board[i][j] == ' ') 
            {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() 
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void displayResult(bool win, bool draw) 
{
    if (win) 
    {
        cout << "Player " << currentPlayer << " wins!\n";
    } 
    else if (draw) 
    {
        cout << "The game is a draw.\n";
    }
    else 
    {
        cout << "The game is ongoing.\n";
    }
}

bool playAgain() 
{
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int main() 
{
    bool play = true;
    while (play) 
    {
        initializeBoard();
        currentPlayer = 'X';
        bool win = false, draw = false;

        while (!win && !draw) 
       {
            displayBoard();
            playerInput();
            win = checkWin();
            draw = checkDraw();
            if (!win && !draw) switchPlayer();
        }

        displayBoard();
        displayResult(win, draw);
        play = playAgain();
    }
    return 0;
}
