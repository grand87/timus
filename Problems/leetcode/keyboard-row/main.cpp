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
    mutable unordered_map<char, int> charRows = {
        {'a', 1},
        {'b', 2},
        {'c', 2},
        {'d', 1},
        {'e', 0},
        {'f', 1},
        {'g', 1},
        {'h', 1},
        {'i', 0},
        {'j', 1},
        {'k', 1},
        {'l', 1},
        {'m', 2},
        {'n', 2},
        {'o', 0},
        {'p', 0},
        {'q', 0},
        {'r', 0},
        {'s', 1},
        {'t', 0},
        {'u', 0},
        {'v', 2},
        {'w', 0},
        {'x', 2},
        {'y', 0},
        {'z', 2}
    };

    bool testWord(const string& w) const {
        const int r = charRows[tolower(w[0])];
        for (char c : w) {
            if (charRows[tolower(c)] != r)
                return false;
        }
        return true;
    }

public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for (auto w : words) {
            if (testWord(w))
                res.push_back(w);
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

        int vals;
        cin >> vals;
        vector<string> values(vals);
        readVector<string>(cin, values, vals);

        Solution s;
        values = s.findWords(values);
        printVector<string>(cout, values);

        cout << endl;
    }
}