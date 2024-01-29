#include <iostream>
#include <algorithm>

using namespace std;

int arr[10000001] = {0};

void readArray(int* data, int size) {
    for (int i = 0; i < size; i++)
        cin >> data[i];
}

void printArray(int* data, int size) {
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
}

bool test(int a, int b, int c) {
    return a + b > c && a + c > b && b + c > a;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;
        readArray(arr, n);
        sort(arr, arr + n);

        int count = 0;
        for (int j = 0; j < n - 2; j++) {
            for (int k = j + 1; k < n - 1; k++) {
                int m = k + 1;
                while (m < n && test(arr[j], arr[k], arr[m])) {
                    m++;
                }
                count += m - k - 1;
            }
        }

        cout << count << endl;
    }
    return 0;
}