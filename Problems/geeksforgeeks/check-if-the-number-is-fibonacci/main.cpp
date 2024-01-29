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

int fibNumbers[100];

int precalculateFibNumbers(int *a, int maxVal) {
    int i = 0;
    a[i++] = 0;
    a[i++] = 1;
    a[i++] = 1;
    do {
        a[i] = a[i - 2] + a[i - 1];
    } while (a[i++] <= maxVal);
    return i;
}

bool locateIntInArray(int* a, int size, int val) {
    return binary_search(a, a + size, val);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    const int nums = precalculateFibNumbers(fibNumbers, 100);
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;
        if (locateIntInArray(fibNumbers, nums, n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}