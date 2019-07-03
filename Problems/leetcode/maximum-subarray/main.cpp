#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int answer = nums[0];
        int maxCurrent = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            maxCurrent = max(maxCurrent + nums[i], nums[i]);
            answer = max(answer, maxCurrent);
        }

        return answer;
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
       cout << s.maxSubArray(buf) << endl;
   }
}