#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "utils.h"

using namespace std;

constexpr int MAX_SIZE = 6;

int processPattern(const vector<vector<int>>& buffer, int row, int col) {
    static const int pattern[3][3] = {{1, 1, 1}, {0, 1, 0}, {1, 1, 1}};
    int res = 0;

    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            res += buffer[row + r][col + c] * pattern[r][c];

    return res;
}

int solve(const vector<vector<int>>& buffer) {
    int maxSum = numeric_limits<int>::min();
    for (int r = 0; r < 4; r++)
        for (int c = 0; c < 4; c++) {
            const int sum = processPattern(buffer, r, c);
            maxSum = max(maxSum, sum);
        }
    return maxSum;
}

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    int tests;
    cin >> tests;

    vector<vector<int>> buffer;

    for (int t = 0; t < tests; ++t) {
        readMatrix(MAX_SIZE, MAX_SIZE, buffer);

        int ans;
        cin >> ans;

        const int res = solve(buffer);
        cout << res << (res == ans ? " - OK" : " - Fail") << endl;
    }
    return 0;
}