#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void readArray(int* data, long long size) {
    for (long long i = 0; i < size; i++)
        cin >> data[i];
}

void printArray(int* data, long long size) {
    for (long long i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
}

int buf[10000000];

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
        sort(buf, buf + n);
        const int median = (n - 1) / 2;
        int result = buf[median];
        if (n % 2 == 0) {
            result += buf[median + 1];
            result /= 2;
        }

        cout << result << endl;
    }
    return 0;
}