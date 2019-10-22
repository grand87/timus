#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

    string smallestStringWithSwapsHelp(string s, vector<vector<int>>& pairs) {
        
        for (int i = 0; i < pairs.size(); i++) {
        
        }

    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        bool wasSwap = false;
        
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            if (a[0] < b[0])
                return true;
            if (a[0] > b[0])
                return false;

            return a[1] < b[1];
        });

        //do {
        //    wasSwap = false;
        //    for (auto& p : pairs) {
        //        if (s[p[0]] > s[p[1]]) {
        //            swap(s[p[0]], s[p[1]]);
        //            wasSwap = true;
        //        }
        //    }
        //} while (wasSwap);

        return smallestStringWithSwapsHelp(s, pairs);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;

        int n;
        cin >> n;

        vector<vector<int>> pairs(n);
        for (int p = 0; p < n; p++) {
            int a, b;
            cin >> a >> b;
            pairs[p] = {a, b};
        }

        Solution solution;
        cout << solution.smallestStringWithSwaps(s, pairs) << endl;
    }
    return 0;
}