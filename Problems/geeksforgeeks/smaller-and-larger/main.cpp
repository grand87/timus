#include<iostream>
#include<algorithm>

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

int buffer[100];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, v;
        cin >> n >> v;

        readArray(buffer, n);

        int smaller = 0;
        int greater = 0;

        for (int j = 0; j < n; j++) {
            if (buffer[j] <= v)
                smaller++;
            if (buffer[j] >= v)
                greater++;
        }
        cout << smaller << " " << greater << endl;
    }
    return 0;
}