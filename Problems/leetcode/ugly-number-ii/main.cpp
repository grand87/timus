#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <assert.h>
#include <utils.h>

using namespace std;

class Solution {

public:
    int nthUglyNumber(int n) {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;

        vector<int> unums(n);
        unums[0] = 1;

        int p2 = 0;
        int p3 = 0;
        int p5 = 0;

        for (int i = 1; i < n; i++) {
            //get next smallest ugly number

            unums[i] = min(unums[p2] * 2, min(unums[p3] * 3, unums[p5] * 5));
            if (unums[i] == unums[p2] * 2)
                p2++;
            if (unums[i] == unums[p3] * 3)
                p3++;
            if (unums[i] == unums[p5] * 5)
                p5++;
        }

        return unums[n - 1];
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
        int n = 0;
        cin >> n;
        Solution s;
        cout << s.nthUglyNumber(n) << endl;
    }
}