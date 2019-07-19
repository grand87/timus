#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <utils.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
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

        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        readVector<int>(cin, vec, n);

        Solution s;
        cout << s.findKthLargest(vec, k) << endl;
    }
}