#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3)
            return nums.size();

        int swapStart = nums.size() - 1;
        int lastValue = nums[swapStart];
        int copiesLocated = 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] == lastValue) {
                copiesLocated++;
                if (copiesLocated > 2) {
                    swap(nums[i], nums[swapStart]);
                    swapStart--;
                }
            } else {
                // we are at new unique value 
                copiesLocated = 1;
                lastValue = nums[i];
            }
        }
        sort(nums.begin(), nums.begin() + swapStart + 1);
        return swapStart + 1;
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

        vector<int> nums(n);
        for (int j = 0; j < n; j++)
            cin >> nums[j];

        Solution s;
        cout << s.removeDuplicates(nums) << endl;
    }
}