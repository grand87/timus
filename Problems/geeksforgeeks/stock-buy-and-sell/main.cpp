#include<iostream>

using namespace std;

void readArray(unsigned long* data, int size) {
    for (int i = 0; i < size; i++)
        cin >> data[i];
}

unsigned long buf[10000];

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
        int start = 0, end = 0;
        int count = 0;
        for (int j = 1; j < n; j++) {
            if (buf[j] > buf[j - 1]) {
                end++;
                if (j + 1 == n) {
                    cout << "(" << start << " " << end << ") ";
                    count++;
                }
            } else {
                if (end > start) {
                    cout << "(" << start << " " << end << ") ";
                    count++;
                }
                start = j;
                end = j;
            }
        }
        if (count == 0) {
            cout << "No Profit";
        }
        cout << endl;
    }
    return 0;
}
