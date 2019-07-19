#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <limits>

using namespace std;

class Solution {
    void markColRor(vector<vector<int>>& matrix, int x, int y, int val, int w, int h) {
        for (int i = 0; i < h; i++)
            if(matrix[i][x] != 0)
                matrix[i][x] = val;
        for (int i = 0; i < w; i++)
            if (matrix[y][i] != 0)
                matrix[y][i] = val;
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int h = matrix.size();
        if (h == 0)
            return;
        const int w = matrix[0].size();

        int maskValue = 2;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++) {
                if (matrix[y][x] > maskValue)
                    maskValue = matrix[y][x];
            }
        if (numeric_limits<int>::max() == maskValue) {
            // we could not use the biggest positive value - need to saerch for the smallest negative
            maskValue = -1;
            for (int y = 0; y < h; y++)
                for (int x = 0; x < w; x++) {
                    if (matrix[y][x] < maskValue)
                        maskValue = matrix[y][x];
                }
            if (numeric_limits<int>::min() == maskValue) {
                // and we could not use the smallest positive value - will use some magic number
                maskValue = -52187407;
            }
            else
                maskValue--;
        }
        else
            maskValue++;

        for(int y = 0; y < h; y++)
            for (int x = 0; x < w; x++) {
                if (matrix[y][x] == 0) {
                    markColRor(matrix, x, y, maskValue, w, h);
                }
            }
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++) {
                if (matrix[y][x] == maskValue) {
                    matrix[y][x] = 0;
                }
            }
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

        int n = 0, m = 0;
        cin >> n >> m;

        vector<vector<int>> board(n);
        for (int j = 0; j < n; j++) {
            board[j].resize(m);
            for (int k = 0; k < m; k++) {
                cin >> board[j][k];
            }
        }

        Solution s;
        s.setZeroes(board);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cout << board[j][k] << " ";
            }
            cout << endl;
        }

        cout << endl;
    }
}