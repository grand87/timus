#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct cell {
    int x;
    int y;
    bool isAlive;
};

int checkNeighbor(const vector<vector<int>>& board, int x, int y, int w, int h) {
    if (x >= 0 && x < w && y >= 0 && y < h) {
return board[y][x];
    }
    return 0;
}

int countNeighbors(const vector<vector<int>>& board, int x, int y) {
    static const int directionsCount = 8;
    static const int directions[] { 0, 1, 0, -1, 1, 1, -1, -1, 0 };

    const int h = board.size();
    const int w = board[0].size();

    int res = 0;
    for (int i = 0; i < directionsCount; i++) {
        res += checkNeighbor(board, x + directions[i + 1], y + directions[i], w, h);
    }
    return res;
}

bool applyRulesForLive(cell& aCell, int neighbors) {
    if (neighbors < 2) {
        aCell.isAlive = false;
        return true;
    }
    else if (neighbors > 3) {
        aCell.isAlive = false;
        return true;
    }
    return false;
}

bool applyRulesForDead(cell& aCell, int neighbors) {
    if (neighbors == 3) {
        aCell.isAlive = true;
        return true;
    }
    return false;
}

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        const int h = board.size();
        if (h == 0)
            return;
        const int w = board[0].size();

        //will contain only diffs
        vector<cell> cells(h * w);

        int cellsCount = 0;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                const int res = countNeighbors(board, x, y); // TODO: speed up based on sum table
                bool toUpdate = false;
                if (board[y][x] == 1) {
                    toUpdate = applyRulesForLive(cells[cellsCount], res);
                } else {
                    toUpdate = applyRulesForDead(cells[cellsCount], res);
                }
                if (toUpdate) {
                    cells[cellsCount].x = x;
                    cells[cellsCount].y = y;
                    cellsCount++;
                }
            }
        }
        for (int i = 0; i < cellsCount; i++) {
            const cell &c = cells[i];
            board[c.y][c.x] = c.isAlive;
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
        s.gameOfLife(board);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cout << board[j][k] << " ";
            }
            cout << endl;
        }

        cout << endl;
    }
}