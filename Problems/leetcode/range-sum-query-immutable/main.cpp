#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class NumArray {

private:
    vector<int> prefixSums;
public:
    NumArray(vector<int>& nums) : prefixSums(nums.size()) {
        prefixSums[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefixSums[i] = prefixSums[i - 1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        if(i > 0)
            return prefixSums[j] - prefixSums[i - 1];;
        return prefixSums[j];
    }
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray* obj = new NumArray(nums);
* int param_1 = obj->sumRange(i,j);
*/

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
#endif

   int t = 0;
   cin >> t;
   for (int i = 0; i < t; i++) {

       int n = 0, q = 0;
       cin >> n >> q;

       vector<int> numbers(n);
       for (int j = 0; j < n; j++)
           cin >> numbers[j];

       vector<pair<int, int>> queries(q);
       for (int j = 0; j < q; j++) {
           int a, b;
           cin >> a >> b;
           queries[j] = make_pair(a, b);
       }

       NumArray* obj = new NumArray(numbers);
       for (int j = 0; j < q; j++) {
           cout << obj->sumRange(queries[j].first, queries[j].second) << endl;
       }
   }
}