#include<iostream>
#include<algorithm>

using namespace std;

void dump(int matrix[10][10], int size) {
    for (int j = 0; j < size; j++) {
        for (int k = 0; k < size; k++) {
            cout << matrix[j][k] << " ";
        }
        cout << endl;
    }
}

void transpose(int matrix[10][10], int size) {
    for (int j = 0; j < size - 1; j++)
        for (int k = j; k < size; k++) {
            swap(matrix[j][k], matrix[k][j]);
        }
}

void reverseColumn(int matrix[10][10], int size, int column) {
    for (int j = 0; j < size / 2; j++) {
        swap(matrix[j][column], matrix[size - j - 1][column]);
        dump(matrix, size);
    }
}

void reverseRows(int matrix[10][10], int size, int row) {
    for (int j = 0; j < size / 2; j++) {
        swap(matrix[row][j], matrix[row][size - j - 1]);
        dump(matrix, size);
    }
}

void rotate(int matrix[10][10], int size) {
    transpose(matrix, size);
    for (int j = 0; j < size; j++)
        reverseRows(matrix, size, j);
}

int matrix[10][10];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;

        unsigned long result = 0;
        for(int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) {
                cin >> matrix[j][k];
            }

        rotate(matrix, n);

        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) {
                cout << matrix[j][k] << " ";
            }
        cout << endl;
    }
    return 0;
}