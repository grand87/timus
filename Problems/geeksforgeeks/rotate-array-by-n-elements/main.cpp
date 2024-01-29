#include <iostream>

using namespace std;

void reverse(int* array, int start, int end) {
    while (start < end) {
        swap(array[start], array[end]);
        start++;
        end--;
    }
}

void rotate(int* array, int dist, int size) {
    reverse(array, 0, dist - 1);
    reverse(array, dist, size - 1);
    reverse(array, 0, size - 1);
}

int dataArray[10000000];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, sh;
        cin >> n >> sh;

        for (int j = 0; j < n; j++)
            cin >> dataArray[j];

        rotate(dataArray, sh, n);

        for (int j = 0; j < n; j++)
            cout << dataArray[j] << " ";
        cout << endl;
    }
    return 0;
}