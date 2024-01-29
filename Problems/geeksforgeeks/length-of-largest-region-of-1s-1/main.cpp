#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <functional>

using namespace std;

#define SIZE 100

void printMatrix(int x, int y, int g[SIZE][SIZE]) {
    for (int r = 0; r < y; r++) {
        for (int c = 0; c < x; c++) {
            cout << g[r][c] << " ";
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

bool validatePoint(int w, int h, int matrix[SIZE][SIZE], int x, int y) {
    return x >= 0 && x < w && y >= 0 && y < h && matrix[y][x] == 1;
}

typedef function<void(int, int)> VertexProcessor;

void bfs(int w, int h, int startx, int starty, int matrix[SIZE][SIZE], VertexProcessor vertProc) {
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

int findAreaUtil(int h, int w, int matrix[SIZE][SIZE], bool vis[SIZE][SIZE]) {
    int maxRegionSize = 0;
    int regionId = 2;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
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
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int g[SIZE][SIZE];
        bool vis[SIZE][SIZE];

        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<m; j++)
                cin >> g[i][j];
        }

#ifdef LOCAL_TEST
        printMatrix(m, n, g);
        cout << endl;
#endif
        memset(vis, 0, sizeof(vis));
        cout << findAreaUtil(n, m, g, vis) << endl;
    }

    return 0;
}
