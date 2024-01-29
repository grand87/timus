#include <iostream>
#include <vector>
#include <algorithm>

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

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        vector<int> buf(n);
        readArray(&buf[0], n);
        sort(buf.begin(), buf.end());
        int l = 0, p = 0;

        while (l < n - 1) {
            const int diff = k + buf[l] - 1;
            //due to array is sorted locate in array to the right position where elements would be bigger than required diff and count how many elemts are between
            auto pos = upper_bound(buf.begin() + l + 1, buf.end(), diff);
            if (pos == buf.end())
                p += n - (l + 1);
            else
                p += pos - (buf.begin() + l + 1);
            l++;
        }

        cout << p << endl;
    }
    return 0;
}