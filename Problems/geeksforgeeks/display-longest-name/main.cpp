#include<iostream>
#include<string.h>

using namespace std;

void readArray(int* data, int size) {
    for (int i = 0; i < size; i++)
        cin >> data[i];
}

void readStrings(char buf[10][1010], int size) {
    for (int i = 0; i < size; i++)
        cin >> buf[i];
}

char names[10][1010];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        readStrings(names, n);

        int maxLen = 0;
        int maxLenIndex = -1;
        for (int j = 0; j < n; j++) {
            const int len = strlen(names[i]);
            if (len > maxLen) {
                maxLen = len;
                maxLenIndex = j;
            }
        }

        cout << names[maxLenIndex] << endl;

    }
    return 0;
}