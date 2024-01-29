#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];

        int prevMax = nums[0];
        int prevMin = nums[0];

        int currentMax = nums[0];
        int currentMin = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int localMax = prevMax * nums[i];
            int localMin = prevMin * nums[i];

            currentMax = max(localMax, max(localMin, nums[i]));
            currentMin = min(localMax, min(localMin, nums[i]));

            maxProduct = max(maxProduct, currentMax);

            prevMax = currentMax;
            prevMin = currentMin;
        }

        return maxProduct;
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

       int val;
       cin >> val;
       vector<int> buf(val);
       for (int j = 0; j < val; j++) {
           cin >> buf[j];
       }

       Solution s;
       cout << s.maxProduct(buf) << endl;
   }
}