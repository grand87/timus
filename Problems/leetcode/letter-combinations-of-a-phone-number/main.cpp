#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

class Solution {
    const vector<vector<char>> letters{
        { ' ' },  // 0
        { 0 },  // 1
        { 'a','b','c' },        // 2
        { 'd','e','f' },        // 3
        { 'g','h','i' },        // 4
        { 'j','k','l' },        // 5
        { 'm','n','o' },        // 6
        { 'p','q','r','s' },    // 7
        { 't','u','v' },        // 8
        { 'w','x','y','z' },    // 9
    };

    void generateCombinations(const string &digits, int pos, vector<string> &res, string tmp) {

        if (pos == digits.size()) {
            res.push_back(tmp);
            return;
        }

        const int digit = digits[pos] - '0';
        for (int i = 0; i < letters[digit].size(); i++) {
            generateCombinations(digits, pos + 1, res, tmp + letters[digit][i]);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;

        if (digits.size() > 0) {
            string tmp;
            generateCombinations(digits, 0, res, tmp);
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
        string digits;
        cin >> digits;

        Solution sol;
        vector<string> res = sol.letterCombinations(digits);
        for (auto s : res) {
            cout << '[' << s << ']';
        }
        cout << endl;
    }
}