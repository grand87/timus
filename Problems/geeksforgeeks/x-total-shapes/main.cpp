#include <iostream>

using namespace std;

void scanAdjencents(bool matrix[51][51], int rows, int columns, int matrixGroups[51][51], int row, int col, int groupID) {
    if (!matrix[row][col])
        return;
    if (matrixGroups[row][col] != 0)
        return;
    
    matrixGroups[row][col] = groupID;

    if(row > 0)
        scanAdjencents(matrix, rows, columns, matrixGroups, row - 1, col, groupID);
    if (col > 0)
        scanAdjencents(matrix, rows, columns, matrixGroups, row, col - 1, groupID);
    if (row + 1 < rows)
        scanAdjencents(matrix, rows, columns, matrixGroups, row + 1, col, groupID);
    if (col + 1 < columns)
        scanAdjencents(matrix, rows, columns, matrixGroups, row, col + 1, groupID);
}

int countShapes(bool matrix[51][51], int rows, int columns) {
    int groups = 0;
    int matrixGroups[51][51] = { 0 };

    for(int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] && matrixGroups[i][j] == 0) {
                //located new shape - need to scan
                scanAdjencents(matrix, rows, columns, matrixGroups, i, j, ++groups);
            }
        }

    return groups;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    bool matrix[51][51] = { false };
    char row[51] = { 0 };

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int m, n;
        cin >> n >> m;

        for (int r = 0; r < n; r++) {
            cin >> row;
            for (int c = 0; c < m; c++) {
                matrix[r][c] = row[c] == 'X';
            }
        }

        int res = countShapes(matrix, n, m);
        cout << res << endl;
    }
    return 0;
}