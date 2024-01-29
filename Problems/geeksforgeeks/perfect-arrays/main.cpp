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

bool isPerfect(int* data, int size) {
    const int mid = size / 2;
    for (int i = 0; i < mid; i++) {
        if (data[i] != data[size - i - 1])
            return false;
    }
    return true;
}

int buf[100];

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
        if (isPerfect(buf, n))
            cout << "PERFECT" << endl;
        else
            cout << "NOT PERFECT" << endl;
    }
    return 0;
}