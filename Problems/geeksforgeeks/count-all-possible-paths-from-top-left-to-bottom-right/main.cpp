#include<iostream>
using namespace std;

const int maxSize = 101;

unsigned long long matrix[maxSize][maxSize];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int m, n;
        cin >> m >> n;

        matrix[0][0] = 0;

        for (int k = 1; k < n; k++) {
            matrix[0][k] = 1;
        }
        for (int k = 1; k < m; k++) {
            matrix[k][0] = 1;
        }

        int ff = 5 / 10;

        for (int c = 1; c < m; c++) {
            for (int r = 1; r < n; r++) {
                matrix[c][r] = (matrix[c - 1][r] + matrix[c][r - 1]) % (1000000000 + 7);
            }
        }

        unsigned long long result = matrix[m - 1][n - 1];

        cout << result << endl;
    }
    return 0;
}