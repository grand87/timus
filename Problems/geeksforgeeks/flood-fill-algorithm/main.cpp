#include <fstream>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

template <typename T>
void readMatrix(int x, int y, std::vector<std::vector<T>>& matrix) {
    matrix.resize(y);
    for (int r = 0; r < y; r++) {
        matrix[r].resize(x);
        for (int c = 0; c < x; c++) {
            cin >> matrix[r][c];
        }
    }
}

// TODO: rewrite based on printVector
template <typename T>
void printMatrix(int x, int y, std::vector<std::vector<T>>& matrix) {
    for (int r = 0; r < y; r++) {
        for (int c = 0; c < x; c++) {
            cout << matrix[r][c] << " ";
        }
    }
}

const int pos[] = {0, 1, 0, -1, 0};
const int posCount = 4;

inline int isValid(int sizeX, int sizeY, int x, int y, const vector<vector<int>>& matrix, int color) {
    return x >= 0 && x < sizeX && y >= 0 && y < sizeY && matrix[y][x] == color;
}

void floodFill(int sizeX, int sizeY, vector<vector<int>>& matrix, int x, int y, int color) {
    typedef pair<int, int> point;
    queue<point> verts;

    verts.push(make_pair(x, y));
    
    const int lookUpColor = matrix[y][x];

    while (!verts.empty()) {
        const point p = verts.front();
        verts.pop();
        matrix[p.second][p.first] = color;

        for (int i = 0; i < posCount; i++) {
            const int npx = p.first + pos[i];
            const int npy = p.second + pos[i + 1];

            if (isValid(sizeX, sizeY, npx, npy, matrix, lookUpColor))
                verts.push(make_pair(npx, npy));
        }
    }
}

// Position this line where user code will be pasted.
int main() {
#ifdef LOCAL_TEST
    std::ifstream in("input.txt");
    cin.set_rdbuf(in.rdbuf());
#endif
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> y >> x;
        vector<vector<int>> matrix;
        readMatrix(x, y, matrix);

        int px, py, color;
        cin >> px >> py >> color;
#ifdef LOCAL_TEST
        printMatrix(x, y, matrix);
        cout << endl;
#endif
        floodFill(x, y, matrix, py, px, color);

        printMatrix(x, y, matrix);
        cout << endl;
    }

    return 0;
}
