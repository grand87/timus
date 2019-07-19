#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <utils.h>

using namespace std;

class Solution {

    struct element {
        element() {
            value = numeric_limits<int>::min();
            hasValue = false;
        }
        int value;
        bool hasValue;
    };

public:
    int thirdMax(vector<int>& nums) {
        int maxElementsCount = 0;
        element maxElements[3];

        for (int v : nums) {
            if (v >= maxElements[0].value) {
                if (v > maxElements[0].value || !maxElements[0].hasValue) {
                    maxElements[2] = maxElements[1];
                    maxElements[1] = maxElements[0];
                    maxElements[0].value = v;
                    maxElements[0].hasValue = true;
                    maxElementsCount++;
                }
            } else if (v >= maxElements[1].value) {
                if (v > maxElements[1].value || !maxElements[1].hasValue) {
                    maxElements[2] = maxElements[1];
                    maxElements[1].value = v;
                    maxElements[1].hasValue = true;
                    maxElementsCount++;
                }
            } else if (v >= maxElements[2].value) {
                if (v > maxElements[2].value || !maxElements[2].hasValue) {
                    maxElements[2].value = v;
                    maxElements[2].hasValue = true;
                    maxElementsCount++;
                }
            }
        }
        if (maxElementsCount < 3)
            return maxElements[0].value;
        return maxElements[2].value;
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
        int n;
        cin >> n;
        vector<int> vec(n);
        readVector<int>(cin, vec, n);

        Solution s;
        cout << s.thirdMax(vec) << endl;
    }
}