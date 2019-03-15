#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int arr[100] = {0};

int maxLen(int arr[], int n)
{
    int arrMod[100] = { 0 };
    for (int j = 0; j < n; j++) {
        if (arr[j] == 0)
            arrMod[j] = -1;
        else 
            arrMod[j] = 1;
    }

    //now the task is to find the longest sub array with sum 0
    unordered_map<int, int> sums;
    int sum = 0;
    int len = 0;

    for (int j = 0; j < n; j++) {
        sum += arrMod[j];

        if(sum == 0)
            len = max(j + 1, len);

        if (sums.find(sum) != sums.end()) {
            //need to get the biggest range which forms this sum
            len = max(j - sums[sum], len);
        }
        else
            sums[sum] = j;
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

        cout << maxLen(arr, n) << endl;
    }
    return 0;
}