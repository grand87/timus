#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <functional>

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

typedef pair<int, int> Point;

constexpr Point pointsToNavigate[] = {
    // X,  Y
    {  0,  1 },
    {  0, -1 },
    {  1,  0 },
    { -1,  0 },
    {  1,  1 },
    {  1, -1 },
    { -1,  1 },
    { -1, -1 },
};
constexpr int pointsToNavigateCount = 8;

bool validatePoint(int w, int h, std::vector<std::vector<int>> &matrix, int x, int y) {
    return x >= 0 && x < w && y >= 0 && y < h && matrix[y][x] == 1;
}


//typedef void(*VertexProcessor)(int x, int y);
typedef function<void(int, int)> VertexProcessor;

void bfs(int w, int h, int startx, int starty, std::vector<std::vector<int>> &matrix, VertexProcessor vertProc) {
    queue<Point> verts;
    verts.push(make_pair(startx, starty));

    vertProc(startx, starty);

    while (!verts.empty()) {
        Point p = verts.front();
        verts.pop();

        //evaluate neibhors for this pair
        for (int i = 0; i < pointsToNavigateCount; i++) {
            const int nx = p.first + pointsToNavigate[i].first;
            const int ny = p.second + pointsToNavigate[i].second;
            if (validatePoint(w, h, matrix, nx, ny)) {
                verts.push(make_pair(nx, ny));
                vertProc(nx, ny);
            }
        }
    }
}

int findLargestRegion(int w, int h, std::vector<std::vector<int>> &matrix) {
    int maxRegionSize = 0;
    int regionId = 2;

    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            if (matrix[y][x] == 1) {
                int currentregionSize = 0;
                //located new region - start bfs from this point
                bfs(w, h, x, y, matrix, [&matrix, regionId, &currentregionSize](int px, int py) {
                    matrix[py][px] = regionId;
                    currentregionSize++;
                });
                //all vertex of this region are processed
                regionId++;

                maxRegionSize = max(maxRegionSize, currentregionSize);

#ifdef LOCAL_TEST
                printMatrix(w, h, matrix);
                cout << endl;
#endif
            }
        }
    }
    
    return maxRegionSize;
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
        int x, y;
        cin >> y >> x;

        vector<vector<int>> matrix;
        readMatrix(x, y, matrix);
#ifdef LOCAL_TEST
        printMatrix(x, y, matrix);
        cout << endl;
#endif

        const int res = findLargestRegion(x, y, matrix);
        cout << res << endl;
    }
    return 0;
}