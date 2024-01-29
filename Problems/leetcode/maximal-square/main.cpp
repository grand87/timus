#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
    int calcSquareSize2(vector<vector<char>>& matrix, int x, int y) {
        int size = 1;

        if (y + size >= height)
            return size;
        if (x + size >= width)
            return size;

        while (matrix[y + size][x] == '1' && matrix[y][x + size] == '1') {
            for (int pos = 1; pos <= size; pos++) {
                if (matrix[y + size][x + pos] != '1')
                    return size * size;
            }
            for (int pos = 1; pos <= size; pos++) {
                if (matrix[y + pos][x + size] != '1')
                    return size * size;
            }
            size++;
            if (y + size >= height)
                break;
            if (x + size >= width)
                break;
        }
        return size * size;
    }

    int height;
    int width;

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        height = matrix.size();
        if (height == 0)
            return 0;
        width = matrix[0].size();

        int maxSize = 0;

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (matrix[y][x] == '1') {
                    // located piece of potential square - evaluate the size
                    const int size = calcSquareSize2(matrix, x, y);
                    maxSize = max(maxSize, size);
                }
            }
        }

        return maxSize;
    }
};

class SolutionDP {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int height = matrix.size();
        if (height == 0)
            return 0;
        const int width = matrix[0].size();
        if (height == 1) {
            for (int i = 0; i < width; i++) {
                if (matrix[0][i] == '1')
                    return 1;
            }
            return 0;
        }

        vector<vector<int>> dp(height);
        for (int i = 0; i < height; i++) {
            dp[i].resize(width);
            fill(dp[i].begin(), dp[i].end(), 0);
        }

        dp[0][0] = matrix[0][0] == '1';
        int maxSize = 0;
        for (int i = 1; i < width; i++) {
            dp[0][i] = matrix[0][i] == '1';
            maxSize |= dp[0][i];
        }
        for (int i = 1; i < height; i++) {
            dp[i][0] = matrix[i][0] == '1';
            maxSize |= dp[i][0];
        }

        for (int y = 1; y < height; y++) {
            for (int x = 1; x < width; x++) {
                if (matrix[y][x] == '1') {
                    dp[y][x] = min(dp[y - 1][x - 1], min(dp[y][x - 1], dp[y - 1][x])) + 1;
                    maxSize = max(maxSize, dp[y][x]);
                }
            }
        }

        return maxSize * maxSize;
    }
};

int main() {
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> matrix;
        readMatrix(n, m, matrix);

        SolutionDP s;
        cout << s.maximalSquare(matrix) << endl;
    }
}