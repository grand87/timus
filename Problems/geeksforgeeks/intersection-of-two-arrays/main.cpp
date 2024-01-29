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

int buf[100000] = { 0 };

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {

        int mask[100001] = { 0 };
        int n, m;
        cin >> n >> m;
        readArray(buf, n);
        int min = 100000, max = 0;
        for (int j = 0; j < n; j++) {
            mask[buf[j]]++;
            if (buf[j] < min)
                min = buf[j];
            if (buf[j] > max)
                max = buf[j];
        }
        readArray(buf, m);
        for (int j = 0; j < m; j++) {
            mask[buf[j]]++;
            if (buf[j] < min)
                min = buf[j];
            if (buf[j] > max)
                max = buf[j];
        }
        int count = 0;
        for (int j = min; j <= max; j++) {
            if (mask[j] > 1) {
                count++;
                cout << j << " ";
            }
        }
        if (count == 0) {
            cout << "Zero";
        }
        cout << endl;
    }
    return 0;
}
