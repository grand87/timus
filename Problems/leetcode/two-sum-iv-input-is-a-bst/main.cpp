#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;

        for (int i = 0; i < numbers.size(); i++) {
            const int valueToSearch = target - numbers[i];
            if (valueToSearch == numbers[i]) {
                //due to array sorted - we are looking for next item in thids array
                result = { 1 + i, i + 2 };
                break;
            } else {
                //will use binary search to locate required index
                vector<int>::iterator it = lower_bound(numbers.begin() + i, numbers.end(), valueToSearch);
                if (it == numbers.end() || *it != valueToSearch)
                    continue;
                //calculate index based on distance

                result = { 1 + i, 1 + it - numbers.begin() };
                break;
            }

        }

        return result;
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