#include <iostream>
#include <fstream>
#include <queue>
#include <functional>
#include <algorithm>
#ifdef LOCAL_TEST
#include <utils.h>
#else
template <typename T>
void readMatrix(int x, int y, std::vector<std::vector<T>> &matrix) {
    matrix.resize(y);
    for (int r = 0; r < y; r++) {
        matrix[r].resize(x);
        for (int c = 0; c < x; c++) {
            std::cin >> matrix[r][c];
        }
    }
}
#endif

using namespace std;

typedef function<void(int, int)> OnCellEnter;

bool isValid(int w, int h, int x, int y) {
    return x >= 0 && y >= 0 && x < w && y < h;
}

typedef pair<int, int> Point;
constexpr Point PointsToVisit[] = {
    { 0, 1},
    { 1, 0 },
    { 0, -1 },
    { -1, 0 },
};
constexpr int PointCount = 4;

int bfs(int n, vector<vector<int>> &m) {
    vector<vector<int>> visited = m;
    for (int i = 0; i < n; i++)
        fill(visited[i].begin(), visited[i].end(), 0);

    vector<vector<int>> cost(m);

    queue<Point> verts;
    verts.push(make_pair(0, 0));
    visited[0][0] = 1;

    while (!verts.empty()) {
        const Point p = verts.front();
        verts.pop();

        for (int i = 0; i < PointCount; i++) {
            const int nx = p.first + PointsToVisit[i].first;
            const int ny = p.second + PointsToVisit[i].second;

            if (isValid(n, n, nx, ny)) {
                if (visited[ny][nx] == 0) {
                    visited[ny][nx] = 1;
                    verts.push(make_pair(nx, ny));
                    cost[ny][nx] = cost[p.second][p.first] + m[ny][nx];
                } else {
                    if (cost[p.second][p.first] + m[ny][nx] < cost[ny][nx]) {
                        cost[ny][nx] = cost[p.second][p.first] + m[ny][nx];
                        //re-evaluate all associated vertexes
                        //TODO: it is better do based on set - if the vert already in set - just skip or insert otherwise
                        verts.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
    return cost[n-1][n-1];
}

int getMinPathCost(int n, vector<vector<int>> &m) {
    int res = bfs(n, m);
    return res;
}

int main()
{
#ifdef LOCAL_TEST
    fstream inputData("input.txt");
    cin.set_rdbuf(inputData.rdbuf());
#endif
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;

        vector<vector<int>> m;
        readMatrix(n, n, m);
//#ifdef LOCAL_TEST
//        printMatrix(n, n, m);
//        cout << "START\n\n\n";
//#endif
        cout << getMinPathCost(n, m) << endl;
    }
    return 0;
}
