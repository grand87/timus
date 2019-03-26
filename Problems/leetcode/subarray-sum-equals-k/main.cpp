#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sums;

        sums[0] = 1;

        int sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (sums.find(sum - k) != sums.end()) {
                count += sums[sum - k];
            }
            sums[sum]++;
        }
        return count;
    }

    int subarraySum2(vector<int>& nums, int k) {
        vector<int> sums(nums.size());
        sums[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            sums[i] = sums[i - 1] + nums[i];
        }

        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (sums[i] == k)
                count++;
        }


        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (sums[j] - sums[i] == k)
                    count++;
            }
        }

        return count;
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
       const int res = s.subarraySum(numbers, k);
       cout << res << endl;
   }
}