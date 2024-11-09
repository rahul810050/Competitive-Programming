#include <iostream>
#include <vector>
#include <string>

using namespace std;


bool isSafe(const vector<string>& board, int row, int col, int n) {
    
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false; 
        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 'Q') return false; 
        if (col + (row - i) < n && board[i][col + (row - i)] == 'Q') return false; // Right diagonal
    }
    return true;
}

// Recursive function to solve the N-Queens problem
void solveNQueens(vector<vector<string>>& solutions, vector<string>& board, int row, int n) {
    if (row == n) {
        solutions.push_back(board); // Found a solution
        return;
    }
    
    // Try placing a queen in each column of the current row
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q'; // Place the queen
            solveNQueens(solutions, board, row + 1, n); // Recurse to the next row
            board[row][col] = '.'; // Backtrack
        }
    }
}

// Main function to initialize the board and start solving
vector<vector<string>> nQueens(int n) {
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.')); // Create an empty board
    solveNQueens(solutions, board, 0, n);
    return solutions;
}

// Helper function to print solutions
void printSolutions(const vector<vector<string>>& solutions) {
    for (const auto& solution : solutions) {
        for (const string& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    vector<vector<string>> solutions = nQueens(n);
    
    cout << "Number of solutions: " << solutions.size() << endl;
    printSolutions(solutions);
    
    return 0;
}