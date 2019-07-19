#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <functional>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second > b.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;

        int maxFreq = 0;

        for (int val : nums) {
            freqMap[val]++;
            maxFreq = max(maxFreq, freqMap[val]);
        }

        vector<vector<int>> freqInOrder(maxFreq + 1);
        for (auto rec : freqMap) {
            freqInOrder[rec.second].push_back(rec.first);
        }

        vector<int> res;

        for (auto i = freqInOrder.rbegin(); i != freqInOrder.rend(); i++) {
            for (auto el : *i) {
                res.push_back(el);
                if (res.size() == k)
                    return res;
            }
        }
        
        return res;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {

        int vals, k;
        cin >> vals >> k;
        vector<int> values(vals);

        for (int j = 0; j < vals; j++)
            cin >> values[j];

        Solution s;
        vector<int> res = s.topKFrequent(values, k);
     
        for (int val : res)
            cout << val << " ";
        cout << endl;
    }
}