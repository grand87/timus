#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        if (nums.size() == 1)
            return nums[0] < s ? 0 : 1;

        vector<int> sums(nums.size());
        sums[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            sums[i] = sums[i - 1] + nums[i];

        int minLength = nums.size() + 1;

        for (int rangeEnd = 0; rangeEnd < nums.size(); rangeEnd++) {
            if (sums[rangeEnd] >= s) {
                // need to check is there a range from 0 .. rangeEnd which forms sum == s
                // if yes - locate it's length
                // keep minimal length
                if (rangeEnd == 0) {
                    // we located the minimal range with length == 1
                    return 1;
                }
                const int extraSum = sums[rangeEnd] - s;
                // need to locate the value most closest to the rangeEnd which is not greater then extraSum
                auto lookupRangeEnd = sums.begin() + rangeEnd + 1;
                const auto it = upper_bound(sums.begin(), lookupRangeEnd, extraSum);
                if (it == lookupRangeEnd || it == sums.begin()) {
                    // no such range to form requored extraSum - full range is considered as acceptable
                    minLength = min(minLength, rangeEnd + 1);
                } else {
                    const int rangeSize = distance(it, sums.begin() + rangeEnd) + 1;
                    minLength = min(minLength, rangeSize);
                }
                /*
                for (int rangeStart = rangeEnd - 1; rangeStart >= 0; rangeStart--) {
                    const int rangeSum = sums[rangeEnd] - sums[rangeStart];
                    if (rangeSum >= s) {
                        minLength = min(minLength, rangeEnd - rangeStart);
                        break;
                        if (minLength == 1)
                            return 1;
                    }
                }
                minLength = min(minLength, rangeEnd + 1);
                */
            }
        }
        if (minLength == nums.size() + 1) {
            //no such subarray
            return 0;
        }
        return minLength;
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

        int n, sum;
        cin >> n >> sum;

        vector<int> nums(n);
        for (int j = 0; j < n; j++) {
            cin >> nums[j];
        }
        Solution s;
        cout << s.minSubArrayLen(sum, nums) << endl;
    }
}