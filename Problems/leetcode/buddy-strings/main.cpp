#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return nums;

        vector<int> res;
        
        const int maxValue = *max_element(nums.begin(), nums.end()) + 1;

        for (int i = 0; i < nums.size(); i++) {
            int index = nums[i] % maxValue - 1;
            nums[index] += maxValue;
        }

        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxValue * 2)
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
        auto res = solution.findDuplicates(s);
        for (auto p : res)
            cout << p << " ";
        cout << endl;
    }
}