#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& A) {
    const int y = A.size();
    const int x = A[0].size();

    if (A[0][0] == 1)
        return 0;

    vector<vector<int>> m(y);
    for (int i = 0; i < A.size(); i++) {
        m[i].resize(x);
    }

    for (int i = 0; i < x; i++) {
        if (A[0][i] == 0)
            m[0][i] = 1;
        else
            break;
    }

    for (int i = 0; i < y; i++) {
        if (A[i][0] == 0)
            m[i][0] = 1;
        else
            break;
    }
    
    for (int posY = 1; posY < y; posY++)
                for (int posX = 1; posX < x; posX++) {
                    if (A[posY][posX] == 0) {
                        // it is accessable point - we can get to here from top or from left
                        m[posY][posX] = m[posY - 1][posX] + m[posY][posX - 1];
                    }
                }

        return m[y - 1][x - 1];
    }

    int main() {
#ifdef LOCAL_TEST
        ifstream f("input.txt");
        cin.set_rdbuf(f.rdbuf());
#endif

        int t = 0;
        cin >> t;
        for (int i = 0; i < t; i++) {
            int m, n;
            cin >> m >> n;

            vector<vector<int>> board;
            readMatrix(n, m, board);

            cout << uniquePathsWithObstacles(board) << endl;
        }
    }