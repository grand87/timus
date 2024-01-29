#include<iostream>
#include<algorithm>

using namespace std;

template<typename T>
void readArray(T* data, int size) {
    for (int i = 0; i < size; i++)
        cin >> data[i];
}

template<typename T>
void printArray(T* data, int size) {
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
}

long long arr[10000000];

template<typename T>
void reverseArray(T* data, int pos, int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(data[pos + i], data[pos + size - 1 - i]);
    }
}


int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, r;
        cin >> n >> r;

        r = min(n, r);

        readArray(arr, n);

        for (int pos = 0; pos < n; pos += r) {
            int rCor = r + min(0, n - pos - r);
            reverseArray(arr, pos, rCor);
        }

        printArray(arr, n);
    }
    return 0;
}
