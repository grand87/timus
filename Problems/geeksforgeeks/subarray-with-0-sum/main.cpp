#include<iostream>
#include<unordered_map>

using namespace std;

int arr[10000];

bool isZeroSubArray(int *arr, int size) {
    unordered_map<int, int> sums;
    int sum = 0;
    sums[0] = 1;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        if (sums.find(sum) != sums.end())
            return true;
        sums[sum]++;
    }
    return false;
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

        for (int j = 0; j < n; j++)
            cin >> arr[j];

        if (isZeroSubArray(arr, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}