#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2)
            return false;

        if (nums.size() == 2) {
            if (nums[0] + nums[1] == k)
                return true;

            if (k != 0) {
                int modul = (nums[0] + nums[1]) % k;
                if (modul == 0) {
                    return true;
                }
            }
        }

        int sumCur = 0;
        for (int i = 0; i < nums.size(); i++) {
            sumCur += nums[i];
        }
        if ((k == 0 && sumCur == 0) || (sumCur % k == 0))
            return true;

        unordered_map<int, int> sums;
        sumCur = 0;
        for (int i = 0; i < nums.size(); i++) {
            sumCur += nums[i];

            if (k != 0)
                sumCur %= k;

            if (sums.find(sumCur) != sums.end()) {
                const int index = sums.find(sumCur)->second;
                if (i - index > 1)
                    return true;
            } else
                sums[sumCur] = i;
        }

        return false;
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
       cout << s.checkSubarraySum(numbers, k) << endl;
   }
}