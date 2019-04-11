#include <iostream>
#include <unordered_set>

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

int buf[10000];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m, k;
        cin >> n >> m >> k;
        readArray(buf, n);

        unordered_set<int> buf2;

        for (int j = 0; j < m; j++) {
            int val;
            cin >> val;
            buf2.insert(val);
        }

        int absentCount = 0;
        for (int j = 0; j < n; j++) {
            if (buf2.find(buf[j]) == buf2.end()) {
                ++absentCount;
                if (absentCount == k) {
                    cout << buf[j] << endl;
                    break;
                }
            }
        }
        if (absentCount != k) {
            cout << "-1" << endl;
        }
    }
    return 0;
}