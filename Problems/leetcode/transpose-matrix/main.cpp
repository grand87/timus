#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void readMatrix(vector<vector<int>> &matrix, int n, int m) {
    matrix.resize(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
}

void dumpMatrix(vector<vector<int>> &matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if (A.size() == A[0].size()) {
            for (int y = 1; y < A.size(); y++) {
                for (int x = 0; x < y; x++) {
                    swap(A[y][x], A[x][y]);
                }
            }
            return A;
        }
        else {
            vector<vector<int>> res(A[0].size());
            for (int y = 0; y < A[0].size(); y++) {
                res[y].resize(A.size());
                for (int x = 0; x < A.size(); x++) {
                    res[y][x] = A[x][y];
                }
            }
            return res;
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

        int n, m;
        cin >> n >> m;

        vector<vector<int>> imgA;
        readMatrix(imgA, n, m);

        Solution s;
        imgA = s.transpose(imgA);
        dumpMatrix(imgA, m, n);
    }
}