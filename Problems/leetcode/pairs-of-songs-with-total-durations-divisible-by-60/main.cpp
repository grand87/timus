#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> freq;

        int pairs = 0;

        if (time[0] % 60 != 0) {
            freq[time[0] % 60] = 1;
        } else
            freq[0] = 1;
        
        for (int i = 1; i < time.size(); i++) {
            const int rem = time[i] % 60;

            if (rem == 0) {
                unordered_map<int, int>::iterator it = freq.find(0);
                if (it != freq.end()) {
                    pairs += it->second;
                    it->second++;
                } else
                    freq[0]++;
            } else {
                unordered_map<int, int>::iterator it = freq.find(60 - rem);
                if (it != freq.end()) {
                    pairs += it->second;
                }
                freq[rem]++;
            }
        }

        return pairs;
    }
};

int main() {
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int count;
        cin >> count;

        vector<int> nums(count);
        readVector(cin, nums, count);

        Solution s;
        s.numPairsDivisibleBy60(nums);

        printVector(cout, nums);
        cout << endl;
    }
}