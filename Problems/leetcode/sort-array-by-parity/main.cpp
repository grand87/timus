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
    vector<int> sortArrayByParity(vector<int>& A) {
        int l = 0;
        int r = A.size() - 1;
        while(l < r) {
            if (A[l] & 1) {
                // locate first even from the right and swap
                while (r > l && (A[r] & 1))
                    r--;
                swap(A[l], A[r]);
                r--;
            }
            l++;
        }
    
        return A;
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
        vector<int> res = s.sortArrayByParity(nums);

        printVector(cout, res);
        cout << endl;
    }
}