#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int arr[10000] = {0};

int maxSumLessThanK(int arr[], int n, int k)
{
    //now the task is to find the longest sub array with sum k
    int sum = 0;
    int len = 0;
    int start = 0;
    for (int j = 0; j < n; j++) {
        sum += arr[j];

        if (sum > k) {
            //need to remove the extra items
            for (int i = start; i <= j; i++) {
                sum -= arr[i];
                if (sum <= k) {
                    start = i + 1;
                    break;
                }
            }
        }

        if (sum <= k && sum > len)
            len = sum;
    }

    //need to return the pair with the biggest diff
    return len;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        int k;
        cin >> k;

        cout << maxSumLessThanK(arr, n, k) << endl;
    }
    return 0;
}