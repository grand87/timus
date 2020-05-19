#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <unordered_set>

using namespace std;

class Solution {
    int helper(vector<int>& coins, int amount, vector<int>& count) {
        if (amount < 0)
            return -1;
        if (amount == 0)
            return 0;

        if (count[amount - 1] != 0)
            return count[amount - 1];

        int min = numeric_limits<int>::max();
        for (int c : coins) {
            int res = helper(coins, amount - c, count);
            if (res >= 0 && res < min)
                min = 1 + res;
        }
        if (min == numeric_limits<int>::max())
            count[amount - 1] = -1;
        else
            count[amount - 1] = min;

        return count[amount - 1];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 1;
        vector<int> dp(amount);
        sort(coins.begin(), coins.end(), greater<>());
        int res = helper(coins, amount, dp);
        return res;
    }
};

int main() {
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    Solution s;

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int amount, coins;
        cin >> amount >> coins;

        vector<int> vals(coins);
        readVector(cin, vals, coins);

        cout << s.coinChange(vals, amount) << endl;
    }

    return 0;
}