#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <utils.h>

using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;
        for (size_t pos = 0; pos < nums.size(); pos += 2) {
            const size_t freq = nums[pos];
            const int val = nums[pos + 1];

            for (size_t rep = 0; rep < freq; ++rep) {
                result.push_back(val);
            }
        }

        return result;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif
    Solution s;
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        size_t count = 0;
        cin >> count;
        
        vector<int> data(count);
        readVector(cin, data, count);
        const auto result = s.decompressRLElist(data);
        printVector(cout, result);
        cout << endl;
    }

    return 0;
}