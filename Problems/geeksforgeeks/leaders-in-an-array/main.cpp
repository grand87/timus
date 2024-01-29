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

int buf[10000000];
int res[10000000];

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        readArray(buf, n);

        int leaders = 0;

        int currentMax = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (buf[j] >= currentMax) {
                res[leaders++] = buf[j];
                currentMax = buf[j];
            }
        }

        for (int j = leaders - 1; j >= 0; j--) {
            cout << res[j] << " ";
        }

        cout << endl;
    }
    return 0;
}
