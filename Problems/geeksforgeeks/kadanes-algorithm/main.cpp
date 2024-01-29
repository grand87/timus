#include <iostream>

using namespace std;

int arr[1001];

int findMaxSubArray(int* arr, int arrSize) {
    int maxCurrent = arr[0];
    int maxTotal = arr[0];

    for (int i = 1; i < arrSize; i++) {
        maxCurrent = max(arr[i], maxCurrent + arr[i]);
        maxTotal = max(maxTotal, maxCurrent);
    }
    return maxTotal;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> arr[j];

        cout << findMaxSubArray(arr, n) << endl;
    }
    return 0;
}