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
    int step = 1;
    int pos = 0;
    for (int i = 0; i < size; i++) {
        while (true) {
            cout << data[i][pos] << " ";
            pos += step;
            if (step > 0) {
                if (pos == size)
                    break;
            } else {
                if (pos == -1)
                    break;
            }
        } 
        if (pos == -1) {
            pos = 0;
            step = 1;
        } else {
            pos = size - 1;
            step = -1;
        }
    }
    cout << endl;
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
        printMatrix(buf, n);
    }
    return 0;
}