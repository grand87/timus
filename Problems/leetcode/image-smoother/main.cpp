#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int const h = M.size();
        int const w = M[0].size();
        vector<vector<int>> res = M;

        if (h == 1) {
            //smooth single row
            if(w == 1)
                return res;
            //corners
            res[0][0] = (M[0][0] + M[0][1]) / 2;
            res[0][w - 1] = (M[0][w - 1] + M[0][w - 2]) / 2;
            //inner
            for(int x = 1; x < w - 1; x++)
                res[0][x] = (M[0][x] + M[0][x - 1] + M[0][x + 1]) / 3;
            return res;
        } else if (w == 1) {
            //smooth single column

            //corners
            res[0][0] = (M[0][0] + M[1][0]) / 2;
            res[h-1][0] = (M[h-1][0] + M[h-2][0]) / 2;

            //inner
            for (int y = 1; y < h - 1; y++)
                res[y][0] = (M[y][0] + M[y - 1][0] + M[y+1][0]) / 3;

            return res;
        }
        
        //smooth corners
        res[0][0] = (M[0][0] + M[1][1] + M[0][1] + M[1][0]) / 4; //left top
        res[0][w - 1] = (M[0][w - 1] + M[1][w - 2] + M[0][w - 2] + M[1][w - 1]) / 4; //right top
        res[h - 1][w - 1] = (M[h - 1][w - 1] + M[h - 2][w - 2] + M[h - 2][w - 1] + M[h - 1][w - 2]) / 4; //right bottom
        res[h - 1][0] = (M[h - 1][0] + M[h - 2][1] + M[h - 2][0] + M[h - 1][1]) / 4; //left bottom

        //smooth edges - left
        for (int y = 1; y < h - 1; y++) {
            res[y][0] = (M[y][0] + M[y - 1][0] + M[y + 1][0] + M[y - 1][1] + M[y + 1][1] + M[y][1]) / 6;
        }
        //smooth edges - right
        for (int y = 1; y < h - 1; y++) {
            res[y][w-1] = (M[y][w-1] + M[y - 1][w-1] + M[y + 1][w-1] + M[y - 1][w-2] + M[y + 1][w-2] + M[y][w-2]) / 6;
        }
        //smooth edges - top
        for (int x = 1; x < w - 1; x++) {
            res[0][x] = (M[0][x] + M[0][x - 1] + M[0][x + 1] + M[1][x] + M[1][x - 1] + M[1][x + 1]) / 6;
        }
        //smooth edges - bottom
        for (int x = 1; x < w - 1; x++) {
            res[h - 1][x] = (M[h - 1][x] + M[h - 1][x - 1] + M[h - 1][x + 1] + M[h - 2][x] + M[h - 2][x - 1] + M[h - 2][x + 1]) / 6;
        }

        //smooth inner
        for (int y = 1; y < h - 1; y++) {
            for (int x = 1; x < w - 1; x++) {
                res[y][x] = (M[y][x] + M[y-1][x-1] + M[y+1][x+1] + M[y-1][x+1] + M[y+1][x-1] + M[y+1][x]+ M[y-1][x]+ M[y][x+1] + M[y][x-1]) / 9;
            }
        }

        return res;
    }
};

void readMatrix(vector<vector<int>> &matrix, int n, int m) {
    matrix.resize(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
}

void dumpMatrix(vector<vector<int>> &matrix, int m) {
    const int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
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
        int n, m;
        cin >> n >> m;
        readMatrix(matrix, n, m);

        Solution s;
        matrix = s.imageSmoother(matrix);
        dumpMatrix(matrix, m);
    }
}