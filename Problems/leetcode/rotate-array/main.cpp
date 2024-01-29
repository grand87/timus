#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {

    void reverse(vector<int>& nums, int s, int count) {
        const int end = s + count - 1;
        for (int i = 0; i < count / 2; i++) {
            swap(nums[s + i], nums[end - i]);
        }
    }

public:
    void rotate(vector<int>& nums, int k) {
        const int n = nums.size();
        if (n <= 1)
            return;
        k = k % n;
        reverse(nums, n - k, k);
        reverse(nums, 0, n - k);
        reverse(nums, 0, n);
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
       for (int j = 0; j < n; j++)
           cin >> vec[j];

       Solution s;
       s.rotate(vec, k);
       for (int j = 0; j < n; j++)
           cout << vec[j] << " ";
       cout << endl;
   }
}