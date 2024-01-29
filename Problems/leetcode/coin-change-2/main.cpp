#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
    int countSets(int amount, const vector<int>& coins) {
#ifdef LOCAL_TEST
        printVector(cout, coins);
#endif
        int currentAmount = 0;
        vector<vector<int>> coinsToForm;
        vector<int> current_coins;
        for (auto coinValueIt = coins.rbegin(); coinValueIt != coins.rend(); ++coinValueIt) {
            int countOfCoinNominal = (amount - currentAmount) / (*coinValueIt);
            currentAmount += countOfCoinNominal * (*coinValueIt);
            current_coins.push_back(*coinValueIt);
            if (currentAmount == amount) {
                coinsToForm.push_back(current_coins);
                currentAmount = 0;
                current_coins.clear();
            }
        }
#ifdef LOCAL_TEST
        cout << " -- " << coinsToForm.size() << endl;
#endif
        return coinsToForm.size();
    }

    int changeHelper(int amount, const vector<int>& coins, int coinIndex, vector<int> currentSet) {
        if (coinIndex == coins.size()) {
            if (currentSet.size() > 0)
                return countSets(amount, currentSet);
            return 0;
        }
        else
        {
            int res = 0;
            
            int oldSize = currentSet.size();

            if (coins[coinIndex] <= amount) {
                if (coins[coinIndex] == amount) {
                    if (!test) {
                        test = true;
                        currentSet.push_back(coins[coinIndex]);
                    }
                } else
                    currentSet.push_back(coins[coinIndex]);
                res += changeHelper(amount, coins, coinIndex + 1, currentSet);
            }

            if (currentSet.size() > oldSize)
                currentSet.pop_back();

            res += changeHelper(amount, coins, coinIndex + 1, currentSet);
            
            return res;
        }
    }

    bool test;

public:


    int change(int amount, vector<int>& coins) {
        test = false;
        sort(coins.begin(), coins.end());
        vector<int> currentCoins;
        return changeHelper(amount, coins, 0, currentCoins);
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

        cout << s.change(amount, vals) << endl;
    }

    return 0;
}