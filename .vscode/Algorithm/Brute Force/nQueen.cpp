#include <bits/stdc++.h>
using namespace std;

bool checkSafe(int n, int col, int row, vector<vector<bool>>& board) {
    // check row
    for (int i = col; i >= 0; --i) {
        if (board[row][i]) {
            return false;
        }
    }

    // check upper diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j]) {
            return false;
        }
    }

    // check lower diagonal
    for (int i = row, j = col; i < n && j >= 0; ++i, --j) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

void findSolution(int& ans, int n, int col, vector<vector<bool>>& board) {
    if (col == n) {
        ++ans;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (checkSafe(n, col, i, board)) {
            board[i][col] = true;
            findSolution(ans, n, col + 1, board);
            board[i][col] = false;
        }
    }
    return;
}

int main() {
    int boardSize;
    cin >> boardSize;
    vector<vector<bool>> board(boardSize, vector<bool>(boardSize, false));
    int ans = 0;
    findSolution(ans, boardSize, 0, board);
    cout << ans;
}