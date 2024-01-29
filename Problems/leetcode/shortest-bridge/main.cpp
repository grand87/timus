#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct vert {
    int x;
    int y;

    vert(int ax = 0, int ay = 0) : x(ax), y(ay) {

    }

    vert& operator+=(const vert& v1) {
        this->x += v1.x;
        this->y += v1.y;
        return *this;
    }

    vert& operator-=(const vert& v1) {
        this->x -= v1.x;
        this->y -= v1.y;
        return *this;
    }
};

vert operator+(const vert& v1, const vert& v2) {
    vert temp(v1);
    return temp += v2;
}

vert operator-(const vert& v1, const vert& v2) {
    vert temp(v1);
    return temp -= v2;
}

typedef vector<vert> shape;
typedef stack<vert> VerticiesStack;

const vert directions[4] = {
    { -1, 0 }, // up
    { 1, 0 }, // down
    { 0, -1 }, // left
    { 0, 1 }, // right
};


class Solution2 {

    void addVert(vector<vector<int>>& A, VerticiesStack &s, const vert& v, int w, int h, int id) {
        if (v.x >= 0 && v.x < w && v.y >= 0 && v.y < h) {
            if(A[v.y][v.x] != id)
                s.push(v);
        }
    }

    shape locateIsland(vector<vector<int>>& A, int x, int y, int id) {
        const int h = A.size();
        const int w = A[0].size();

        VerticiesStack toValidate;

        shape result;
        vert current(x, y);
        
        addVert(A, toValidate, current, h, w, id);

        while (toValidate.size() > 0) {
            current = toValidate.top();
            toValidate.pop();

            if (A[current.y][current.x] == 1) {
                A[current.y][current.x] = id;
                result.push_back(current);
                for (int i = 0; i < 4; i++) {
                    addVert(A, toValidate, current + directions[i], h, w, id);
                }
            }
        }

        return result;
    }

    vector<shape> locateIslands(vector<vector<int>>& A) {
        const int h = A.size();
        const int w = A[0].size();

        vector<shape> result;

        int islandId = 1000;

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (A[y][x] == 1) {
                    //located island based on DFS locate all its points
                    shape island = locateIsland(A, x, y, islandId);
                    result.push_back(island);
                    islandId++;
                }
            }
        }

        return result;
    }
    
    int locatePath(const vert& v1, const vert& v2, const vector<vector<int>>& A) {
        vert diff = v2 - v1;
        return abs(diff.x) + abs(diff.y) - 1;
    }
  

public:
    int shortestBridge(vector<vector<int>>& A) {
        if (A.size() > 0 && A[0].size() > 0) {
            //1. locate islands
            vector<shape> islands = locateIslands(A);

            //2. identify distance between every pair of bounding box points
            int distance = 10001000;
            for (int i = 0; i < islands[0].size(); i++) {
                for (int j = 0; j < islands[1].size(); j++) {
                    distance = min(distance, locatePath(islands[0][i], islands[1][j], A));
                }
            }
            return distance;
        }
        return 0;
    }
};


class Solution {

    void addVert(vector<vector<int>>& A, VerticiesStack &s, const vert& v, int w, int h, int id) {
        if (v.x >= 0 && v.x < w && v.y >= 0 && v.y < h) {
            if (A[v.y][v.x] != id)
                s.push(v);
        }
    }

    bool isValid(int x, int y, int w, int h) {
        return x >= 0 && x < w && y >= 0 && y < h;
    }

    bool extendIsland(vector<vector<int>>& A, int x, int y, int w, int h, int id) {
        if (x >= 0 && x < w && y >= 0 && y < h) {
            if (A[y][x] == 1) {
                //located island
                return true;
            }

            if(A[y][x] == 0)
                A[y][x] = id;
        }
        return false;
    }

    void locateIsland(vector<vector<int>>& A, int x, int y, int id) {
        const int h = A.size();
        const int w = A[0].size();

        VerticiesStack toValidate;

        vert current(x, y);

        addVert(A, toValidate, current, h, w, id);

        while (toValidate.size() > 0) {
            current = toValidate.top();
            toValidate.pop();

            if (A[current.y][current.x] == 1) {
                A[current.y][current.x] = id;
                for (int i = 0; i < 4; i++) {
                    addVert(A, toValidate, current + directions[i], h, w, id);
                }
            }
        }
    }

    void locateIslands(vector<vector<int>>& A) {
        const int h = A.size();
        const int w = A[0].size();

        int islandId = 2;

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (A[y][x] == 1) {
                    //located island based on DFS locate all its points
                    locateIsland(A, x, y, islandId);
                    //we located first island - now it is marked as 2
                    return;
                }
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>>& A) {
        if (A.size() > 0 && A[0].size() > 0) {
            //1. locate & diffirentiate islands
            locateIslands(A);

            //2. expand island 2 until we reach island 1
            const int h = A.size();
            const int w = A[0].size();

            int range = 2;
            while (true) {
                for (int y = 0; y < h; y++) {
                    for (int x = 0; x < w; x++) {
                        if (A[y][x] == range) {
                            //located current border of second island - extend the border
                            for (int i = 0; i < 4; i++) {
                                if(extendIsland(A, x + directions[i].x, y + directions[i].y, w, h, range + 1))
                                    return range - 2;
                            }
                        }
                    }
                }
                range++;
            }

            int distance = 1;

        }
        return 0;
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
        cout << s.shortestBridge(matrix) << endl;
    }
}