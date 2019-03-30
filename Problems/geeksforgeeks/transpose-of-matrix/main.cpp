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

void printMatrix(int data[1000][1000], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cout << data[i][j] << " ";
    cout << endl;
}

void transpose(int data[1000][1000], int size) {

    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            int tmp = data[i][j];
            data[i][j] = data[j][i];
            data[j][i] = tmp;
        }
    }
}

int buf[1000][1000];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        readMatrix(buf, n);
        transpose(buf, n);
        printMatrix(buf, n);
    }
    return 0;
}