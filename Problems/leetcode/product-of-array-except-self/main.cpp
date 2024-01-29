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
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1;
        bool zero = false;
        for (int v : nums) {
            if (v == 0 && !zero) {
                zero = true;
            } else {
                total *= v;
            }
        }

        int i = 0;
        vector<int> res(nums.size());
        for (int v : nums) {
            if (v != 0) {
                if (zero)
                    res[i++] = 0;
                else
                    res[i++] = total / v;
            } else {
                res[i++] = total;
            }
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
  
        int n;
        cin >> n;
        vector<int> numbers(n);
        readVector<int>(cin, numbers, n);

        Solution s;
        vector<int> res = s.productExceptSelf(numbers);
        printVector(cout, res);
        cout << endl;
    }
}