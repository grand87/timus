#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <utils.h>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int > wordsFreq;

        for (auto w : words) {
            wordsFreq[w]++;
        }

        vector<vector<string>> buckets(words.size() + 1);

        int maxFreq = 0;
        for (auto wf : wordsFreq) {
            buckets[wf.second].push_back(wf.first);
            maxFreq = max(maxFreq, wf.second);
        }

        vector<string> result;

        int count = 0;
        for (vector<vector<string>>::reverse_iterator it = buckets.rbegin(); it != buckets.rend(); it++) {
            if (it->size() > 0)
                sort(it->begin(), it->end());
            for (string w : *it) {
                result.push_back(w);
                if (result.size() == k)
                    return result;
            }
        }
        return result;
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
        vector<string> values(vals);
        readVector<string>(cin, values, vals);

        Solution s;
        values = s.topKFrequent(values, k);
        printVector<string>(cout, values);

        cout << endl;
    }
}