#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

struct transaction {
    long profit;
    int buyOnDay;
    int sellOnDay;
};

vector<transaction> maxProfitInRange(const vector<int>& A) {
    vector<transaction> res;
    res.reserve(A.size());

    int minPrice = A[0];
    int minPriceDay = 0;
    int maxProfit = 0;
    for (int i = 1; i < A.size(); i++) {
        if (A[i] <= minPrice) {
            // buy stock
            minPrice = A[i];
            minPriceDay = i;
        } else {
            // sell stock and buy again
            maxProfit += A[i] - minPrice;
            transaction t;
            t.buyOnDay = minPriceDay;
            t.profit = A[i] - minPrice;
            t.sellOnDay = i;
            res.push_back(t);
            minPrice = A[i];
            minPriceDay = i;
        }
    }

    return res;
}

int maxProfit(const vector<int>& A) {
    if (A.size() == 0)
        return 0;

    vector<transaction> ranges = maxProfitInRange(A);

    // find the biggest combination

    long maxProfit = 0;
    for (int i = 0; i < ranges.size(); i++) {
        maxProfit = max(maxProfit, ranges[i].profit);
    }

    sort(ranges.begin(), ranges.end(),
         [](const transaction& t1, const transaction& t2) -> bool { return t1.profit < t2.profit; });

    for (int i = 0; i < ranges.size(); i++) {
        for (int j = i; j < ranges.size(); j++) {
            if (ranges[i].sellOnDay <= ranges[j].buyOnDay) {
                // valid transactions
                maxProfit = max(maxProfit, ranges[i].profit + ranges[j].profit);
            }
        }
    }

    return maxProfit;
}

int main() {
#ifdef LOCAL_TEST
    ifstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int m;
        cin >> m;
        vector<int> stocks(m);

        readVector(cin, stocks, m);

        cout << maxProfit(stocks) << endl;
    }
}