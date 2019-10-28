#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

int maxProfit(const vector<int>& A) {
    if (A.size() == 0)
        return 0;

    int minPrice = A[0];
    int maxProfit = 0;
    for (int i = 1; i < A.size(); i++) {
        if (A[i] <= minPrice) {
            // buy stock
            minPrice = A[i];
        } else {
            // sell stock and buy again
            maxProfit += A[i] - minPrice;
            minPrice = A[i];
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