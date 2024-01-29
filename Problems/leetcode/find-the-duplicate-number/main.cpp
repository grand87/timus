#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[nums[0]];
        int slow = nums[0];

        while (fast != slow) {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }

        slow = 0;
        while (slow != fast) {
            fast = nums[fast];
            slow = nums[slow];
        }

        return slow;
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
        cout << solution.findDuplicate(s) << endl;
        cout << endl;
    }
}