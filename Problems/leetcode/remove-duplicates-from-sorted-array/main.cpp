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
        if (nums.size() < 2)
            return nums.size();

        int freePos = nums.size() - 1;
        int lastvalue = nums[freePos];

        for (int i = freePos - 1; i >= 0; i--) {
            if (nums[i] == lastvalue) {
                // dupliation located
                swap(nums[i], nums[freePos]);
                freePos--;
                continue;
            }
            lastvalue = nums[i];
        }

        sort(nums.begin(), nums.begin() + freePos + 1);
        return freePos + 1;
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