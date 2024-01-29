#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0)
            return res;

        const int maxValue = *max_element(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            const int originalValue = nums[i] > maxValue ? nums[i] - maxValue : nums[i];
            if (nums[originalValue - 1] <= maxValue) {
                nums[originalValue - 1] += maxValue;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= maxValue)
                res.push_back(i + 1);
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

        vector<int> s(n);
        for(int j = 0; j < n; j++)
            cin >> s[j];

        Solution solution;
        auto res = solution.findDisappearedNumbers(s);
        for (auto p : res)
            cout << p << " ";
        cout << endl;
    }
}