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

void updateValues(bool* a, int v) {
    while (v != 0) {
        a[v % 10] = true;
        v /= 10;
    }
}

bool isFascinating(int n) {
    bool buf[10] = { 0 };
    
    updateValues(buf, n);
    updateValues(buf, n * 2);
    updateValues(buf, n * 3);

    for (int i = 1; i < 10; i++) {
        if (buf[i] == 0)
            return false;
    }
    return true;
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
        if (n >= 1000)
            continue;
        cout << isFascinating(n) << endl;;
    }
    return 0;
}