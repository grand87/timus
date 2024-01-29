#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {

    /*
    0 1  - right
    1 0  - down
    0 -1 - left
    -1 0 - up
    */

    const int directions[5] { 0, 1, 0, -1, 0 };

    int width;
    int height;

    bool flipRegion(vector<vector<char>>& board, int y, int x) const {
        //if there are no cells on edge lines - this is valid region and we need to mark it
        
        typedef pair<int, int> vert;

        vector<vert> area;
        area.reserve(100);

        stack<vert> verts;
        verts.push(make_pair(y, x));
        area.push_back(make_pair(y, x));

        bool cellOnEdge = false;

        while (verts.size() > 0) {
            vert c = verts.top();
            verts.pop();
            board[c.first][c.second] = 'C';
            if (!cellOnEdge && (c.first == 0 || c.first == height - 1 || c.second == 0 || c.second == width - 1)) {
                cellOnEdge = true;
                // all this area should be marked with 'Z' as invalid
            }

            //evaluate neighbor
            for (int i = 0; i < 4; i++) {
                const vert n = make_pair(c.first + directions[i], c.second + directions[i + 1]);
                if (n.first >= 0 && n.first < height && n.second >= 0 && n.second < width) {
                    if (board[n.first][n.second] == 'O') {
                        verts.push(n);
                        area.push_back(n);
                    }
                }
            }
        }
        // unmark all touched cells from 'C' to 'Z'
        char markSymbol = 'Z';
        if (!cellOnEdge)
            markSymbol = 'X'; 

        for (int i = 0; i < area.size(); i++) {
            board[area[i].first][area[i].second] = markSymbol;
        }
        return !cellOnEdge;
    }

public:
    void solve(vector<vector<char>>& board) {

        height = board.size();
        if (!height)
            return;
        width = board[0].size();

        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                if (board[j][k] == 'O') {
                    flipRegion(board, j, k);
                }
            }
        }

        //wrong areas marked with 'Z'
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                if (board[j][k] == 'Z')
                    board[j][k] = 'O';
            }
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

       vector<vector<char>> area(n);
       for (int j = 0; j < n; j++) {
           area[j].resize(m);
           for (int k = 0; k < m; k++) {
               cin >> area[j][k];
           }
       }

       Solution s;
       s.solve(area);
       for (int j = 0; j < n; j++) {
           cout << endl;
           for (int k = 0; k < m; k++) {
               cout << area[j][k];
           }
       }

       cout << endl;
   }
}