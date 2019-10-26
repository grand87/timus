#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

char isMatchHelper(const string& A, const string& B, int aPos, int bPos, vector<vector<char>>& dp) {
    if (aPos == A.size() && bPos == B.size())
        return 1;

    //if B symbol is not an mask
    switch (B[bPos]) {
    case '*':
        // we could sqash all consecutive starts
        while (B[bPos + 1] == '*')
            bPos++;

        //if there no more symbols after * - we are ok, for ex 'aaaa*'
        if (bPos + 1 == B.size())
            return 1;
        
        //here we need to iterate through all possible prefixes
        for (int i = 0; i < A.size() - aPos; ++i) {
            int res = 0;
            if (aPos + i < dp.size() && bPos + 1 < dp[aPos + i].size() && dp[aPos + i][bPos + 1] != -1)
                res = dp[aPos + i][bPos + 1];
            else {
                res = isMatchHelper(A, B, aPos + i, bPos + 1, dp);
                if (aPos + i < dp.size() && bPos + 1 < dp[aPos + i].size())
                    dp[aPos + i][bPos + 1] = res;
            }
            if (res == 1) // we located good prefix
                return 1;
        }
        return 0;
        break;
    case '?': {
        if (aPos >= A.size()) //must be a symbol in position
            return false;

        //it could be any symbol in position A[aPos] - so just skipping it and moving to compare next symbols
        int res = 0;
        if (aPos + 1 < dp.size() && bPos + 1 < dp[aPos + 1].size()) {
            if (dp[aPos + 1][bPos + 1] != -1)
                res = dp[aPos + 1][bPos + 1];
            else {
                res = isMatchHelper(A, B, aPos + 1, bPos + 1, dp);
                dp[aPos + 1][bPos + 1] = res;
            }
        }
        else
            res = isMatchHelper(A, B, aPos + 1, bPos + 1, dp);
        return res;
        break;
    }
    default: {
        if (A[aPos] != B[bPos])
            return 0;
        int res = 0;
        if (aPos + 1 < dp.size() && bPos + 1 < dp[aPos + 1].size()) {
            if (dp[aPos + 1][bPos + 1] != -1)
                res = dp[aPos + 1][bPos + 1];
            else {
                res = isMatchHelper(A, B, aPos + 1, bPos + 1, dp);
                dp[aPos + 1][bPos + 1] = res;
            }
        } else 
            res = isMatchHelper(A, B, aPos + 1, bPos + 1, dp);
        return res;
        break;
    }
    }

    return 0;
}

int isMatch(const string A, const string B) {
    vector<vector<char>> dp(A.size());
    for (auto &d : dp) {
        d.resize(B.size());
        fill(d.begin(), d.end(), -1);
    }


    if (B.size() == 0 && A.size() != 0) {
        return 0;
    }
    return isMatchHelper(A, B, 0, 0, dp);
}

int main() {
#ifdef LOCAL_TEST

    
    assert(isMatch("aaccbbab", "*cc?*b?b*") == 1);


    assert(isMatch("addddb", "*******?******b") == 1);
    assert(isMatch("a", "*******?******") == 1);
    assert(isMatch("a", "*?") == 1);
    assert(isMatch("a", "*?*") == 1);
    assert(isMatch("a", "*") == 1);
    assert(isMatch("a", "*******") == 1);
    assert(isMatch("a", "*******?") == 1);
    assert(isMatch("", "?") == 0);
    assert(isMatch("", "*") == 1);
    assert(isMatch("a", "b") == 0);

    assert(isMatch("bacb", "b**c*?*") == 1);
    assert(isMatch("aab", "c*a*b") == 0);
    assert(isMatch("a", "*") == 1);
    assert(isMatch("ab", "*") == 1);
    assert(isMatch("abc", "*") == 1);
    assert(isMatch("abc", "*c") == 1);
    assert(isMatch("abcd", "*c") == 0);
    assert(isMatch("abcd", "a*c") == 0);
    assert(isMatch("abcd", "a*d") == 1);
    assert(isMatch("abcd", "ab*") == 1);
    assert(isMatch("abcd", "a*") == 1);
    assert(isMatch("abcd", "a*c*") == 1);
    assert(isMatch("acd", "a*c*") == 1);

    assert(isMatch("ab", "??") == 1);
    assert(isMatch("ab", "b?") == 0);
    assert(isMatch("abc", "?b?") == 1);
    assert(isMatch("abc", "?a?") == 0);
    assert(isMatch("abc", "ab?") == 1);
    assert(isMatch("abc", "ac?") == 0);
    assert(isMatch("abc", "a?c") == 1);
    assert(isMatch("abc", "a?c?") == 0);
    assert(isMatch("abc", "a?cd") == 0);
    assert(isMatch("abcd", "a?c?") == 1);
    assert(isMatch("abcd", "??cd") == 1);
    assert(isMatch("abcd", "a??d") == 1);


    assert(isMatch("aa", "aa") == 1);
    assert(isMatch("aa", "a") == 0);
    assert(isMatch("aa", "aaa") == 0);
    assert(isMatch("aaa", "aab") == 0);
    assert(isMatch("aab", "aaa") == 0);
    assert(isMatch("a", "?") == 1);
    assert(isMatch("ab", "a?") == 1);

    ifstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << isMatch(s1, s2) << endl;
    }
}