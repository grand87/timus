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
    
    void addVert(vector<vector<int>>& grid, VertList& verts, int x, int y, int w, int h, int id) {
        if (x >= 0 && x < w && y >= 0 && y < h && grid[y][x] == 1) {
            verts.push(make_pair(x, y));
            grid[y][x] = id;
        }
    }

    // will return the area of the island
    int markIsland(vector<vector<int>>& grid, int x, int y, int w, int h, int id) {
        //based on wave algorithm update id of all neibhors
        VertList verticiesToCheck;
        addVert(grid, verticiesToCheck, x, y, w, h, id);

        int area = 0;
        while (verticiesToCheck.size()) {
            area++;
            vert current = verticiesToCheck.top();
            verticiesToCheck.pop();
            for (int i = 0; i < 4; i++) {
                addVert(grid, verticiesToCheck, current.first + directions[i][0], current.second + directions[i][1], w, h, id);
            }
        }
        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int h = grid.size();
        int maxArea = 0;
        if (h > 0) {
            const int w = grid[0].size();
            int cl = 2;
            for (int y = 0; y < h; y++) {
                for (int x = 0; x < w; x++) {
                    if (grid[y][x] == 1) { //located some island
                        maxArea = max(maxArea, markIsland(grid, x, y, w, h, cl));
                        cl++;
                    }
                }
            }
        }
        return maxArea;
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
        cout << s.maxAreaOfIsland(matrix) << endl;
    }
}