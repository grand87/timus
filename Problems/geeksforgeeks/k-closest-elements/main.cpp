#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int arr[1000] = {0};

vector<int> getClosest(int* arr, int size, int k, int x) {
    vector<pair<int, int>> data(size);
    int valueNumber = 0;
    for (int i = 0; i < size; i++) {
        const int diff = abs(arr[i] - x);;
        if (diff > 0) {
            data[valueNumber].first = arr[i];
            data[valueNumber].second = diff;
            valueNumber++;
        }
    }
    data.resize(valueNumber);
    sort(data.begin(), data.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {return a.second < b.second; });

    vector<int> res(k);
    for (int i = 0; i < k; i++) {
        res[i] = data[i].first;
    }
    return res;
}

vector<int> getClosestPosition(const int* arr, int size, int k, int x) {
    const int pos = find(arr, arr + size, x) - arr;
    const int range_start = min(max(pos - k / 2, 0), size - k - 1);


    vector<int> res;
    res.reserve(k);
    for (int i = 0; i < k + 1; i++) {
        if (range_start + i == pos)
            continue;
        res.push_back(arr[range_start + i]);
    }
    return res;
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

        int k, x;
        cin >> k >> x;

        vector<int> res = getClosestPosition(arr, n, k, x);
        for (int j = 0; j < k; j++)
            cout << res[j] << " ";
        cout << endl;
    }
    return 0;
}