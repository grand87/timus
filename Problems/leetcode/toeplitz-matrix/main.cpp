#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() < 2)
            return true;

        const int rows = matrix.size();
        const int columns = matrix[0].size();

        const int diagonalsCount = rows + columns - 1;

        bool result = true;
        for (int diagonal = 0; diagonal < diagonalsCount; diagonal++) {
            
            //calculate the start position for diagonal
            int diagonalX = diagonal < rows ? 0 : diagonal - rows + 1;
            int diagonalY = diagonal < rows ? rows - diagonal - 1: 0;

            //store the initial value in the diagonal
            const int value = matrix[diagonalY][diagonalX];

            for (diagonalY++, diagonalX++; diagonalY < rows && diagonalX < columns; diagonalY++, diagonalX++) {
                if (matrix[diagonalY][diagonalX] != value) {
                    result = false;
                    break;
                }
            }
            if (!result)
                break;
        }

        return result;
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

        int n, m;
        cin >> n >> m;

        vector<vector<int>> matrix(n);
        for (int j = 0; j < n; j++) {
            matrix[j].resize(m);
            for (int k = 0; k < m; k++) {
                cin >> matrix[j][k];
            }
        }

        Solution s;
        cout << (s.isToeplitzMatrix(matrix) ? "True" : "False") << endl;
    }
}