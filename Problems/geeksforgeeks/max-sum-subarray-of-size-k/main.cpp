#include <iostream>

using namespace std;

long long arr[1000001] = {0};
long long sums[1000001] = { 0 };

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n, k;
        cin >> n >> k;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        sums[0] = arr[0];
        for (int j = 1; j < n; j++) {
            sums[j] = arr[j] + sums[j - 1];
        }

        int maxSum = sums[k - 1];
        for (int j = k; j < n; j++) {
            if (sums[j] - sums[j - k] > maxSum)
                maxSum = sums[j] - sums[j - k];
        }

        cout << maxSum << endl;
    }
    return 0;
}