#include <assert.h>
#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <utils.h>

using namespace std;

class Solution {
    typedef pair<int, int> freq;

    freq getFreqFor(const string& str) {
        freq res(0, 0);
        for (char c : str) {
            if (c == '0')
                res.first++;
            else
                res.second++;
        }
        return res;
    }

    void select(const vector<freq>& freqs, int element, int m, int n, int count) {
        if (element == freqs.size() || (m == 0 && n == 0)) {
            maxCount = max(maxCount, count);
        } else {
            const freq& sample = freqs[element];
            if (sample.first <= m && sample.second <= n) {
                // take freqs[i] if possible
                select(freqs, element + 1, m - sample.first, n - sample.second, count + 1);
            }

            // do not take freqs[i]
            select(freqs, element + 1, m, n, count);
        }
    }

    int maxCount;

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<freq> freqs(strs.size());
        for (vector<string>::size_type i = 0; i < strs.size(); i++) {
            freqs[i] = getFreqFor(strs[i]);
        }

        sort(freqs.begin(), freqs.end(), [](freq& a, freq& b) -> bool {
            if (a.first < b.first)
                return true;
            if (a.first == b.first)
                return a.second < b.second;
            return false;
        });

        // based on backtracking approach let's calculate the max amount of strings that could be created based on strs
        // set and limitations
        maxCount = 0;
        select(freqs, 0, m, n, 0);
        return maxCount;
    }
};

int main() {
#ifdef LOCAL_TEST
    std::ifstream in("input.txt");
    cin.set_rdbuf(in.rdbuf());
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int s, m, n;
        cin >> s >> m >> n;

        vector<string> strArray(s);
        readVector(cin, strArray, s);

        Solution sln;
        cout << sln.findMaxForm(strArray, m, n) << endl;
    }
    return 0;
}
