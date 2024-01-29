#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int product = 0;
        const int size = nums.size();
        if (size == 3) {
            product = nums[0] * nums[1] * nums[2];
        } else {

            sort(nums.begin(), nums.end());
            const int numOfNegative = count_if(nums.begin(), nums.end(), [](int a) { return a < 0; });
            if (numOfNegative >= 2) {
                const int maxProdOfNegative = nums[0] * nums[1];
                if (nums.size() > 4) {
                    if (nums[size - 3] > 0 && nums[size - 2] > 0) {
                        const int maxProdOfPos = nums[size - 3] * nums[size - 2];
                        product = max(maxProdOfNegative, maxProdOfPos) * nums[size - 1];
                    } else {
                        product = maxProdOfNegative * nums[size - 1];
                    }
                } else {
                    // size == 4 where at least 2 values are negative
                    product = maxProdOfNegative * nums[size - 1];
                }
            } else {
                product = nums[size - 1] * nums[size - 2] * nums[size - 3];
            }
        }

        return product;
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
       cout << s.maximumProduct(buf) << endl;
   }
}