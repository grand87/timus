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
    vector<int> sortArrayByParityII(vector<int>& A) {
        // vector<int> res(A.size());

        // int evenPos = 0;
        // int oddPos = 0;

        // bool isEven = true;

        // for (int i = 0; i < A.size(); i++) {
        //    if (isEven) {
        //        // locate next even
        //        int pos = evenPos;
        //        while (A[pos] & 1) {
        //            pos++;
        //        }
        //        evenPos = pos + 1;
        //        res[i] = A[pos];
        //    } else {
        //        int pos = oddPos;
        //        while (!(A[pos] & 1)) {
        //            pos++;
        //        }
        //        oddPos = pos + 1;
        //        res[i] = A[pos];
        //    }

        //    isEven = !isEven;
        //}

        // return res;

        int j = 1;
        for (int i = 0; i < A.size(); i += 2) {
            if (A[i] & 1) {
                //locate for next even
                while (A[j] & 1)
                    j++;
                swap(A[i], A[j]);
            }
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
        vector<int> res = s.sortArrayByParityII(nums);

        printVector(cout, res);
        cout << endl;
    }
}