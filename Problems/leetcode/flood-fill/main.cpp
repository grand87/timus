#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {

    const int directions[4][2] = {
        { 0, -1 }, // up
        { 0,  1 }, // down
        { -1, 0 }, // left
        { 1,  0 }, // right
    };

    typedef pair<int, int> vert;

    typedef stack<vert> VertList;
    
    bool addVert(vector<vector<int>>& grid, VertList& verts, int x, int y, int w, int h, int id, int targetColor) {
        if (x >= 0 && x < w && y >= 0 && y < h) {
            if (grid[y][x] == targetColor) {
                verts.push(make_pair(x, y));
                grid[y][x] = id;
                return true;
            }
        }
        return false;
    }

    void markIsland(vector<vector<int>>& grid, int x, int y, int w, int h, int id) {
        //based on wave algorithm update id of all neibhors
        int targetColor = grid[y][x];
        if (targetColor == id)
            return;

        VertList verticiesToCheck;
        addVert(grid, verticiesToCheck, x, y, w, h, id, targetColor);
        int totalFreeSides = 0;
        while (verticiesToCheck.size()) {
            vert current = verticiesToCheck.top();
            verticiesToCheck.pop();
            for (int i = 0; i < 4; i++) {
                addVert(grid, verticiesToCheck, current.first + directions[i][0], current.second + directions[i][1], w, h, id, targetColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        const int h = image.size();
        int perimiter = 0;
        if (h > 0) {
            const int w = image[0].size();
            markIsland(image, sc, sr, w, h, newColor);
        }
        return image;
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

        int x, y, color;
        cin >> x >> y >> color;

        Solution s;
        s.floodFill(matrix, x, y, color);

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cout << matrix[j][k] << " ";
            }
            cout << endl;
        }
    }
}