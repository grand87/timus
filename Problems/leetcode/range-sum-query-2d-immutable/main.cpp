#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void dump(const vector<vector<int>>& matrix) {
    const int height = matrix.size();
    const int width = matrix[0].size();

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}

class NumMatrix {
    vector<vector<int>> matrixSum;

public:
    NumMatrix(vector<vector<int>>& matrix) : matrixSum(matrix.size()) {
        if (matrix.size() > 0) {
            const int height = matrix.size();
            const int width = matrix[0].size();

            for (int i = 0; i < height; i++) {
                matrixSum[i].resize(width);
            }

            matrixSum[0][0] = matrix[0][0];

            for (int j = 1; j < width; j++) {
                matrixSum[0][j] = matrixSum[0][j - 1] + matrix[0][j];
            }

            for (int j = 1; j < height; j++) {
                matrixSum[j][0] = matrixSum[j - 1][0] + matrix[j][0];
            }

            for (int i = 1; i < height; i++) {
                for (int j = 1; j < width; j++) {
                    matrixSum[i][j] = matrixSum[i][j - 1] + matrixSum[i - 1][j] + matrix[i][j] - matrixSum[i - 1][j - 1];
                }
            }
        }
#ifndef ONLINE_JUDGE
        dump(matrixSum);
#endif
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 > 0 && col1 == 0)
            return matrixSum[row2][col2] - matrixSum[row1 - 1][col2];

        if (row1 == 0 && col1 > 0)
            return matrixSum[row2][col2] - matrixSum[row2][col1 - 1];

        if(row1 > 0 && col1 > 0)
            return matrixSum[row2][col2] - matrixSum[row1 - 1][col2] - matrixSum[row2][col1 - 1] + matrixSum[row1 - 1][col1 - 1];

        return matrixSum[row2][col2];
    }
};

/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix* obj = new NumMatrix(matrix);
* int param_1 = obj->sumRegion(row1,col1,row2,col2);
*/

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
#endif

   int t = 0;
   cin >> t;
   for (int i = 0; i < t; i++) {

       int n = 0, m = 0, q = 0;
       cin >> n >> m >> q;

       vector<vector<int>> matrix(n);
       for (int j = 0; j < n; j++) {
           matrix[j].resize(m);
           for (int k = 0; k < m; k++) {
               cin >> matrix[j][k];
           }
       }

       vector<int> queries(q * 4);
       for (int j = 0; j < q; j++) {
           for (int k = 0; k < 4; k++)
               cin >> queries[j * 4 + k];
       }

       NumMatrix* obj = new NumMatrix(matrix);
       for (int j = 0; j < q; j++) {
           int base = j * 4;
           cout << obj->sumRegion(queries[base], queries[base + 1], queries[base + 2], queries[base + 3]) << endl;
       }
   }
}