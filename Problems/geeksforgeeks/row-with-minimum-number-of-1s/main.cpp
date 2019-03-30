#include<iostream>

using namespace std;

void readArray(int* data, int size) {
    for (int i = 0; i < size; i++)
        cin >> data[i];
}

void printArray(int* data, int size) {
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
}

void readMatrix(int data[1000][1000], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> data[i][j];
}

void readMatrix(int data[1000][1000], int sizeX, int sizeY) {
    for (int i = 0; i < sizeY; i++)
        for (int j = 0; j < sizeX; j++)
            cin >> data[i][j];
}

void printMatrix(int data[1000][1000], int sizeX, int sizeY) {
    for (int i = 0; i < sizeY; i++)
        for (int j = 0; j < sizeX; j++)
            cout << data[i][j] << " ";
    cout << endl;
}

int solution(int data[1000][1000], int sizeX, int sizeY) {
    //due to rows are sorted - count 1's from right to left
    int minCount = sizeX + 1;
    int minRow = -1;
    for (int i = 0; i < sizeY; i++) {
        int count = 0;
        for (int j = sizeX - 1; j >= 0; j--) {
            if (data[i][j] == 1)
                count++;
            else
                break;
        }
        if (count > 0 && count < minCount) {
            minCount = count;
            minRow = i;
        }
    }
    return minRow;
}

int buf[1000][1000];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> m >> n;
        readMatrix(buf, n, m);
        cout << solution(buf, n, m) << endl;
    }
    return 0;
}