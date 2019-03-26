#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //need to form a set to keep all values already seen, with an appropriate index stored in the map
        vector<int> res;
        unordered_map<int, int> items;

        for (int i = 0; i < nums.size(); i++) {
            const int lookForDiff = target - nums[i];
            if (items.find(lookForDiff) != items.end()) {
                res.push_back(items.find(lookForDiff)->second);
                res.push_back(i);
                break;
            }
            else
                items[nums[i]] = i;
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

       int n = 0, k = 0;
       cin >> n >> k;

       vector<int> numbers(n);
       for (int i = 0; i < n; i++)
           cin >> numbers[i];

       Solution s;
       auto res = s.twoSum(numbers, k);
       for (auto i = res.begin(); i != res.end(); i++)
           cout << *i << " ";
       cout << endl;
   }
}