#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <utils.h>

using namespace std;

//constexpr int connectedVerts[] = {0, 1, 0, -1, 0};
//const int connectedVertsCount = getArrayLength(connectedVerts) - 1;

template<typename T, int size>
int getArrayLength(T(&)[size]) {
    return size;
}

constexpr int connectedVerts[] = { 0, 1, 1, -1, -1, 1, 0, -1, 0 };
const int connectedVertsCount = getArrayLength(connectedVerts) - 1;


inline bool testPoint(int x, int y, const vector<int> matrix[], int startX, int startY) {
    const bool res = startX >= 0 && startX < x && startY >= 0 && startY < y && matrix[startY][startX] == 1;
//#ifdef LOCAL_TEST
//    cout << "test " << startX << ":" << startY << " = "<< res <<endl;
//#endif
    return res;
}

void scanIsland(int x, int y, vector<int> matrix[], int startX, int startY, int color) {
    // traversa all connected verticies and color them into color
    typedef pair<int, int> point;

    queue<point> toProces;
    toProces.push(make_pair(startX, startY));

    while (!toProces.empty()) {
        point current = toProces.front();
        toProces.pop();
        matrix[current.second][current.first] = color;

        //evaluate connected verticies
//#ifdef LOCAL_TEST
//        cout << "evaluate connected verticies " << current.first << ":" << current.second << endl;
//#endif
        for (int p = 0; p < connectedVertsCount; p++) {
            const int nx = current.first + connectedVerts[p + 1];
            const int ny = current.second + connectedVerts[p];
            if (testPoint(x, y, matrix, nx, ny)) {
                matrix[ny][nx] = color;
                toProces.push(make_pair(nx, ny));
            }
        }
    }
}

void printMatrix(vector<int> matrix[], int x, int y) {
    for (int r = 0; r < y; r++) {
        for (int c = 0; c < x; c++) {
            cout << matrix[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int findIslands(vector<int> matrix[], int y, int x) {
    int result = 0;
    int markId = 2;

    for (int r = 0; r < y; r++) {
        for (int c = 0; c < x; c++) {
            if (matrix[r][c] == 1) {
                //located new island - evaluate it & mark
                scanIsland(x, y, matrix, c, r, markId);
#ifdef LOCAL_TEST
                printMatrix(matrix, x, y);
#endif
                markId++;
                result++;
            }
        }
    }

    return result;
}

int main()
{
#ifdef LOCAL_TEST
    fstream inputData("input.txt");
    cin.set_rdbuf(inputData.rdbuf());
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> y >> x;

        vector<vector<int>> matrix;
        readMatrix(x, y, matrix);

        int count = findIslands(&matrix[0], y, x);

        cout << count << endl;
    }
    return 0;
}