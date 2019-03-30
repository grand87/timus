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

void solution(int* src, int* dst, int size) {
    //move all zeros first
    int offset = size - 1;
    for (int i = 0; i < size; i++) {
        if (src[i] == 0) {
            dst[offset] = 0;
            offset--;
        }
    }
    offset = 0;
    for (int i = 0; i < size; i++) {
        if (src[i] != 0) {
            dst[offset] = src[i];
            offset++;
        }
    }
}

int buf[1000];
int bufMod[1000];

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
        solution(buf, bufMod, n);
        printArray(bufMod, n);
    }
    return 0;
}