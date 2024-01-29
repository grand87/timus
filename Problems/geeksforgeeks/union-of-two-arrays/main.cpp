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

        bool mask[100001] = { false };
        int n, m;
        cin >> n >> m;
        readArray(buf, n);
        for (int j = 0; j < n; j++) {
            mask[buf[j]] = true;
        }
        readArray(buf, m);
        for (int j = 0; j < m; j++) {
            mask[buf[j]] = true;
        }
        for (int j = 0; j < 100000; j++) {
            if (mask[j])
                cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
