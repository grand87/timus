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

long long buf[101];

void precalculate() {
    buf[0] = 1;
    buf[1] = 1;
    buf[2] = 1;
    for (int i = 3; i <= 100; i++) {
        buf[i] = (buf[i - 2] + buf[i - 3]) % 1000000007;
    }
}

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    precalculate();
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << buf[n] << endl;
    }
    return 0;
}