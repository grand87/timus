#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
    void transpose(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void reverseRows(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            swap(matrix[i], matrix[n - 1 - i]);
        }
    }

    void reverseColumns(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
    }

public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose matrix
        transpose(matrix);

        //reverse rows
        reverseColumns(matrix);
    }
};

void readMatrix(vector<vector<int>> &matrix, int n) {
    matrix.resize(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

void dumpMatrix(vector<vector<int>> &matrix) {
    const int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
#endif

   int t = 0;
   cin >> t;
   for (int i = 0; i < t; i++) {

       vector<vector<int>> matrix;
       int n;
       cin >> n;
       readMatrix(matrix, n);

       Solution s;
       s.rotate(matrix);
       dumpMatrix(matrix);
   }
}