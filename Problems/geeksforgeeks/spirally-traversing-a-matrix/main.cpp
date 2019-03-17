#include <iostream>

int matrix[100][100];

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int m, n;
        cin >> m >> n;
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                cin >> matrix[j][k];
            }
        }

        int y0 = 0;
        int x0 = 0;

        int y1 = m - 1;
        int x1 = n - 1;

        int xDir = 1;
        int yDir = 0;

        int x = x0;
        int y = y0;

        while (x0 <= x1 && y0 <= y1) {
            cout << matrix[y][x] << " ";

            if (x + xDir > x1) {
                xDir = 0;
                yDir = 1;
                y0++;
            }

            if (x + xDir < x0) {
                xDir = 0;
                yDir = -1;
                y1--;
            }

            if (y + yDir > y1) {
                xDir = -1;
                yDir = 0;
                x1--;
            }

            if (y + yDir < y0) {
                xDir = 1;
                yDir = 0;
                x0++;
            }

            x += xDir;
            y += yDir;
        }
        cout << endl;
    }
    return 0;
}
