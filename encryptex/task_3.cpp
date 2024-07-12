#include <bits/stdc++.h>

using namespace std;

// Initialize the current player to 'X'
char currentPlayer = 'X';
// Initialize a 3x3 board for the game
char board[3][3];

// Function to switch turns between players
char alterTurn()
{
    if(currentPlayer == 'X')
    {
        return currentPlayer = 'O'; // If current player is 'X', switch to 'O'
    }
    else if (currentPlayer == 'O') 
    {
        return currentPlayer = 'X'; // If current player is 'O', switch to 'X'
    }
    
    return currentPlayer; // Return the current player
}

// Function to reset the board to the initial empty state
void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' '; // Set all cells to empty
        }
    }
}

// Function to check if the current player has won the game
bool isWin()
{
    // Check for a diagonal win
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
    {
        return true;
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) 
    {
        return true;
    }
    // Check for a row or column win
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
        {
            return true;
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
        {
            return true;
        }
    }

    return false; // No win found
}

// Function to check if the game is a draw
bool isDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return false; // If any cell is empty, it's not a draw
            }
        }
    }
    
    return true; // All cells are filled and no winner, it's a draw
}

// Function to display the board
void displayBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if (j < 2)
            {
                cout << " | "; // Print separator between columns
            }
        }
        cout << endl;
        if (i < 2)
        {
            cout << "--|---|--" << endl; // Print separator between rows
        }    
    }
}

// Main game function to play Tic-Tac-Toe
void ticTacToe()
{
    int row, column;
    while (1)
    {
        displayBoard(); // Show the current board
        cout << "Player '" << currentPlayer << "' please enter your move in the form of Row and Column: ";
        cin >> row >> column; // Get the player's move
        if (row < 0 || column < 0 || row > 2 || column > 2)
        {
            cout << "The move is invalid, please try again" << endl; // Check for invalid moves
            continue;
        }
        else if (board[row][column] != ' ' )
        {
            cout << "This move is already completed, please try again" << endl; // Check if the cell is already filled
            continue;
        }
        board[row][column] = currentPlayer; // Place the player's move on the board

        if (isWin())
        {
            displayBoard();
            cout << "Player " << currentPlayer << " won the match" << endl; // Announce the winner
            break; 
        }
        if (isDraw())
        {
            displayBoard();
            cout << "The match is draw" << endl; // Announce a draw
            break;
        }
        
        alterTurn(); // Switch turns
    }
}

// Main function to start the game
int main()
{
    char playAgain;
    do
    {
        resetBoard(); // Initialize the board
        ticTacToe(); // Start the game
        cout << "Press Y or y to play again. Any other key to exit: ";
        cin >> playAgain; // Ask if the player wants to play again
    } while (playAgain == 'Y' || playAgain == 'y');
        
    return 0;
}
