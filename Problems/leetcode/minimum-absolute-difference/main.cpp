#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;

        if (arr.size() == 1)
            return res;

        sort(arr.begin(), arr.end());

        if (arr.size() == 2) {
            res.push_back({arr[0], arr[1]});
            return res;
        }

        vector<int> diffs(arr.size() - 1);

        for (int i = 1; i < arr.size(); i++) {
            diffs[i - 1] = arr[i] - arr[i - 1];
        }

        sort(diffs.begin(), diffs.end());
        const int minDiff = abs(diffs[0]);

        for (int i = 1; i < arr.size(); i++) {
            if (abs(arr[i] - arr[i - 1]) == minDiff) {
                res.push_back({arr[i - 1], arr[i]});
            }
        }

        return res;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        readVector(cin, arr, n);

        Solution s;
        vector<vector<int>> res = s.minimumAbsDifference(arr);

        for (auto vec : res) {
            cout << "[";
            for (int a : vec) {
                cout << a << " ";
            }
            cout << "]" << endl;
        }
    }
    return 0;
}