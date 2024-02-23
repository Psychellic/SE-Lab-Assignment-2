#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N; // Size of the chessboard

// Check if a queen can be placed safely 
bool isSafe(vector<vector<int>>& board, int row, int col) {
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve the N-Queens problem 
bool solveNQUtil(vector<vector<int>>& board, int col) {
    // Base case: If all queens placed -> solution found
    if (col >= N)
        return true;

    // Try placing queen in all rows of the current column
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // Place the queen 

            // Recur to place the rest of the queens
            if (solveNQUtil(board, col + 1))
                return true;

            // If placing queen in board[i][col] doesn't work, backtrack.
            board[i][col] = 0;  
        }
    }
    
    // If no safe position in the column, return false 
    return false;
}

// Helper function to print the board
void printSolution(vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

int main() {
    cout << "Enter the size of the chessboard (N): ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0)); // Initialize board

    if (solveNQUtil(board, 0) == false) {
        cout << "Solution does not exist" << endl;
        return 0;
    }

    printSolution(board);
    return 0;
}
