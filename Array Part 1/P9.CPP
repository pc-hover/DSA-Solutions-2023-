#include <iostream>
#include <vector>

using namespace std;

int countSolutions = 0;

bool isSafe(vector<vector<int>> &board, int row, int col, int N)
{
    for (int i = 0; i < row; ++i)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
        if (col - i >= 0 && board[row - i][col - i] == 1)
        {
            return false;
        }
        if (col + i < N && board[row - i][col + i] == 1)
        {
            return false;
        }
    }
    return true;
}

void printSolution(vector<vector<int>> &board, int N)
{
    cout << "Solution #" << ++countSolutions << ":\n";
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}

void solveNQueensUtil(vector<vector<int>> &board, int row, int N)
{
    if (row == N)
    {
        printSolution(board, N);
        return;
    }
    for (int col = 0; col < N; ++col)
    {
        if (isSafe(board, row, col, N))
        {
            board[row][col] = 1;
            solveNQueensUtil(board, row + 1, N);
            board[row][col] = 0; // backtrack
        }
    }
}

void solveNQueens(int N)
{
    vector<vector<int>> board(N, vector<int>(N, 0));
    solveNQueensUtil(board, 0, N);
}

int main()
{
    int N;
    cout << "Enter the number of Queen's (N) : ";
    cin >> N;
    solveNQueens(N);
    cout << "Total Solution for " << N << " Queen's problem=" << countSolutions << endl;
    return 0;
}
