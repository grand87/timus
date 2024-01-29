#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <utils.h>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> charFreq;
        int maxCharID = 0;
        for (char c : s) {
            charFreq[c]++;
        }

        vector<vector<char>> freqs(s.size() + 1);
        int maxFreq = 0;
        for (auto rec : charFreq) {
            freqs[rec.second].push_back(rec.first);
            maxFreq = max(maxFreq, rec.second);
        }

        string res;
        for (int i = maxFreq; i >= 0; i--) {
            for (int c = 0; c < freqs[i].size(); c++) {
                for (int r = 0; r < i; r++) {
                    res.append(&freqs[i][c], 1);
                }
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
        char buf[1024];
        cin >> buf;
        Solution s;
        cout << s.frequencySort(string(buf)).c_str() << endl;
    }
}