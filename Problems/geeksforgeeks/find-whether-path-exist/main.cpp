#include <iostream>
#include <fstream>
#include <queue>
#include <functional>
//#include <utils.h>

using namespace std;

template <typename T>
void readMatrix(int x, int y, std::vector<std::vector<T>> &matrix) {
    matrix.resize(y);
    for (int r = 0; r < y; r++) {
        matrix[r].resize(x);
        for (int c = 0; c < x; c++) {
            cin >> matrix[r][c];
        }
    }
}

enum class CellType : uint8_t{
    WALL = 0,
    SOURCE = 1,
    DEST = 2,
    BLANK = 3,
    VISITED = 4
};

void operator >> (istream& s, CellType& ct) {
    int val;
    s >> val;
    if (val < 4)
        ct = static_cast<CellType>(val);
    else
        ct = CellType::WALL;
}

typedef function<void(int, int)> OnCellEnter;

bool isValid(int w, int h, int x, int y, vector<vector<CellType>> &m) {
    return x >= 0 && y >= 0 && x < w && y < h && (m[y][x] == CellType::BLANK || m[y][x] == CellType::DEST);
}

typedef pair<int, int> Point;

constexpr Point PointsToVisit[] = {
    { 0, 1},
    { 1, 0 },
    { 0, -1 },
    { -1, 0 },
};
constexpr int PointCount = 4;

bool bfs(int n, int x, int y, vector<vector<CellType>> &m, OnCellEnter onEnterHandler) {
    

    queue<Point> verts;
    verts.push(make_pair(x,y));

    while (!verts.empty()) {

        const Point p = verts.front();
        verts.pop();

        for (int i = 0; i < PointCount; i++) {
            const int nx = p.first + PointsToVisit[i].first;
            const int ny = p.second + PointsToVisit[i].second;

            if (isValid(n, n, nx, ny, m)) {
                if (m[ny][nx] == CellType::DEST) {
                    return true;
                }
                verts.push(make_pair(nx, ny));
                m[ny][nx] = CellType::VISITED;
            }
        }
    }
    return false;
}

bool isPathExists(int n, vector<vector<CellType>> &m) {
    // locate where source is

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] == CellType::SOURCE) {
                //run bfs from the source point
                return bfs(n, j, i, m, nullptr);
            }
        }
    }

    return false;
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

        vector<vector<CellType>> m;
        readMatrix(n, n, m);

        cout << isPathExists(n, m) << endl;
    }
    return 0;
}
