#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <utils.h>

using namespace std;

long solution(vector<long> prices) {
    // Type your solution here
    long minValue = prices[0];

    long diff = max((long)0, prices[1] - prices[0]);
    for (int i = 1; i < prices.size(); i++) {
        diff = max(diff, prices[i] - minValue);
        minValue = min(minValue, prices[i]);
    }

    return diff;
}

int main() {
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {

        int n;
        cin >> n;

        vector<long> s(n);
        readVector(cin, s, n);

        cout << solution(s) << endl;
    }

    return 0;
}