#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> vals(nums.size());
        vector<int> res;

        int count = 0;

        for (vector<int>::reverse_iterator it = nums.rbegin(); it != nums.rend(); it++) {
            // search index to insert *it into vals to keep it sorted
            if (count == 0) {
                vals[count] = *it;
                res.push_back(count);
            } else {
                auto indexOfFirstBigger = lower_bound(vals.begin(), vals.begin() + count, *it);
                if (indexOfFirstBigger == vals.begin() + count) {
                    vals[count] = *it;
                    res.push_back(count);
                } else {
                    // shift on amount of positions to the right
                    int posShiftStart = distance(vals.begin(), indexOfFirstBigger);
                    const int countToShift = count - posShiftStart;

                    for (int i = 0; i < countToShift; i++) {
                        vals[count - i] = vals[count - i - 1];
                    }

                    vals[posShiftStart] = *it;
                    res.push_back(posShiftStart);
                }
            }
            count++;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
#ifdef LOCAL_TEST
    std::ifstream in("input.txt");
    cin.set_rdbuf(in.rdbuf());
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> data(n);
        readVector<int>(cin, data, n);

        Solution s;
        data = s.countSmaller(data);
        printVector(cout, data);
        cout << endl;
    }
    return 0;
}