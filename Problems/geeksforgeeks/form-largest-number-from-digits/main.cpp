#include<iostream>

using namespace std;

void readArray(int* data, int size) {
    for (int i = 0; i < size; i++)
        cin >> data[i];
}

void printArray(int* data, int size) {
    for (int i = 0; i < size; i++)
        cout << data[i];
    cout << endl;
}

int buf[10000000];

void sortReverse(int* data, int size) {
    int map[10] = { 0 };
    for (int i = 0; i < size; i++) {
        map[data[i]]++;
    }

    for (int i = 9; i >= 0; i--)
        for (int j = 0; j < map[i]; j++)
            cout << i;
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        readArray(buf, n);
        sortReverse(buf, n);
    }
    return 0;
}