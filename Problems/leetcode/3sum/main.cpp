#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i1 = 0, i3 = nums.size() - 1;

        vector<vector<int>> res;

        for (int i1 = 0; i1 < nums.size(); i1++) {
            i3 = nums.size() - 1;
            int i2 = i1 + 1;
            while (i2 < i3) {
                const int sum = nums[i1] + nums[i2] + nums[i3];
                if (sum < 0) {
                    i2++;
                } else if (sum > 0) {
                    i3--;
                } else {
                    //located zero sum
                    res.push_back(vector<int>{nums[i1], nums[i2], nums[i3]});
                    
                    while (nums[i2] == nums[i2 + 1] && i2 + 1 < i3)
                        i2++;
                    while (nums[i3] == nums[i3 - 1] && i2 < i3)
                        i3--;
                    
                    i2++;
                    i3--;
                    while (nums[i2 - 1] == nums[i2] && i2 < i3) {
                        i2++;
                    }
                }
            }
            while (i1 + 1 < nums.size() && nums[i1 + 1] == nums[i1])
                i1++;
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

       int n = 0;
       cin >> n;

       vector<int> numbers(n);
       for (int i = 0; i < n; i++)
           cin >> numbers[i];

       Solution s;
       auto res = s.threeSum(numbers);
       for (auto range = res.begin(); range != res.end(); range++) {
           for (auto j = range->begin(); j != range->end(); j++) {
               cout << *j << " ";
           }
           cout << endl;
       }
       cout << endl;
   }
}