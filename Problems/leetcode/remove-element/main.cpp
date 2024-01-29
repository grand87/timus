#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0)
            return 0;
        
        if (nums.size() == 1 && nums[0] == val)
            return 0;

        
        //locate freePos from end
        int freePos = nums.size() - 1;
        for (; freePos >= 0; freePos--) {
            if (nums[freePos] != val)
                break;
        }
        if (freePos < 0)
            return 0;

        if (freePos == 0)
            return 1;

        for (int i = 0; i <= freePos; i++) {
            if (nums[i] == val) {
                swap(nums[i], nums[freePos]);
                //locate next acceptable free pos
                for (; freePos >= 0; freePos--) {
                    if (nums[freePos] != val)
                        break;
                }
            }
        }
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

        int n, v;
        cin >> n >> v;

        vector<int> nums(n);
        for (int j = 0; j < n; j++)
            cin >> nums[j];

        Solution s;
        cout << s.removeElement(nums, v) << endl;
    }
}