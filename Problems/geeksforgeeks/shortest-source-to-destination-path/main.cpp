#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
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

//TODO: rewrite based on printVector
template <typename T>
void printMatrix(int x, int y, std::vector<std::vector<T>> &matrix) {
    for (int r = 0; r < y; r++) {
        for (int c = 0; c < x; c++) {
            cout << matrix[r][c] << " ";
        }
        cout << endl;
    }
}

constexpr int pointsToNavigate[] = { 0, 1, 0, -1,0 };
constexpr int pointsToNavigateCount = 4;

bool validatePoint(int w, int h, std::vector<std::vector<int>> &matrix, int x, int y) {
    return x >= 0 && x < w && y >= 0 && y < h && matrix[y][x] == 1;
}

int findPath(int w, int h, std::vector<std::vector<int>> &matrix, int x, int y) {
    if (matrix[0][0] == 0)
        return -1;

    std::vector<std::vector<int>> matrixPath(h);
    for (int i = 0; i < h; i++) {
        matrixPath[i].resize(w);
        fill(matrixPath[i].begin(), matrixPath[i].end(), -1);
    }

    matrixPath[0][0] = 0;

    typedef pair<int, int> point;
    queue<point> verts;
    verts.push(make_pair(0, 0));

    while (!verts.empty()) {
        point p = verts.front();
        verts.pop();

        if (p.first == x && p.second == y) {
            break;
        }

        //evaluate neibhors for this pair
        for (int i = 0; i < pointsToNavigateCount; i++) {
            const int nx = p.first + pointsToNavigate[i + 1];
            const int ny = p.second + pointsToNavigate[i];
            if (validatePoint(w, h, matrix, nx, ny)) {
                const bool wasVisited = matrixPath[ny][nx] != -1;
                if (!wasVisited) {
                    verts.push(make_pair(nx, ny));
                    matrixPath[ny][nx] = matrixPath[p.second][p.first] + 1;
                }
            }
        }
#ifdef LOCAL_TEST
        printMatrix(w, h, matrixPath);
        cout << endl;
#endif
    }
    return matrixPath[y][x];
}

int main()
{
#ifdef LOCAL_TEST
    fstream inputData("input.txt");
    cin.set_rdbuf(inputData.rdbuf());
#endif

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;

        vector<vector<int>> matrix;
        readMatrix(n, m, matrix);

        printMatrix(n, m, matrix);
        cout << endl;

        int x, y;
        cin >> y >> x;

        int path = findPath(n, m, matrix, x, y);
        cout << path << endl;
    }
    return 0;
}