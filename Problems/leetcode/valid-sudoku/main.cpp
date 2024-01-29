#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <assert.h>
#include <utils.h>

using namespace std;

class Solution {
    const char EMPTY_CELL = '.';

    const int subs[9][2] = {
        //Y X
        { 0, 0 },
        { 3, 0 },
        { 6, 0 },
        { 0, 3 },
        { 3, 3 },
        { 6, 3 },
        { 0, 6 },
        { 3, 6 },
        { 6, 6 },
    };

public:

    void readSudoku(vector<vector<char>>& board) const {
        board.resize(9);
        for (int r = 0; r < 9; r++) {
            board[r].resize(9);
            for (int c = 0; c < 9; c++) {
                cin >> board[r][c];
            }
        }
    }

    bool isRowValid(const vector<vector<char>>& board, int row) {
        bool mask[10] = { false };
        for (int i = 0; i < 9; i++) {
            if (board[row][i] != EMPTY_CELL) {
                const int digit = board[row][i] - '0';
                if (mask[digit])
                    return false;
                mask[digit] = true;
            }
        }

        return true;
    }

    bool isColValid(const vector<vector<char>>& board, int col) {
        bool mask[10] = { false };
        for (int i = 0; i < 9; i++) {
            if (board[i][col] != EMPTY_CELL) {
                const int digit = board[i][col] - '0';
                if (mask[digit])
                    return false;
                mask[digit] = true;
            }
        }

        return true;
    }


    bool isSubMatrxiValid(const vector<vector<char>>& board, int row, int col) {
        bool mask[10] = { false };
        
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (board[row + r][col + c] != EMPTY_CELL) {
                    const int digit = board[row + r][col + c] - '0';
                    if (mask[digit])
                        return false;
                    mask[digit] = true;
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        for (int r = 0; r < 9; r++) {
            if (isRowValid(board, r) == false)
                return false;
        }

        for (int r = 0; r < 9; r++) {
            if (isColValid(board, r) == false)
                return false;
        }

        for (int i = 0; i < 9; i++) {
            if (isSubMatrxiValid(board, subs[i][0], subs[i][1]) == false)
                return false;
        }

        return true;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        Solution s;
        vector<vector<char>> board;
        s.readSudoku(board);
        cout << s.isValidSudoku(board);
    }
}