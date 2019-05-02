#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0)
            return 1;

        int max = nums[0];
        for (int& val : nums) {
            if (val > max) {
                max = val;
            }
        }
        if (max <= 0)
            return 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0)
                nums[i] = max;
        }

        for (int i = 0; i < nums.size(); i++) {
            int originalValue = nums[i] <= 0 ? nums[i] + max : nums[i];

            if (originalValue > 0 && originalValue <= nums.size()) {
                if (nums[originalValue - 1] > 0)
                    nums[originalValue - 1] -= max;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                return i + 1;
        }

        return nums.size() + 1;
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

        vector<int> s(n);
        for(int j = 0; j < n; j++)
            cin >> s[j];

        Solution solution;
        cout << solution.firstMissingPositive(s) << endl;
    }
}