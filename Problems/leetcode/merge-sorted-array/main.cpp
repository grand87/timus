#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <assert.h>
#include <utils.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int indexA = m - 1;
        int indexB = n - 1;
        int targetIndex = m + n - 1;
        //we will fill target array from the end
        while (indexA >= 0 && indexB >= 0) {
            int value;
            if (nums1[indexA] > nums2[indexB]) {
                value = nums1[indexA];
                indexA--;
            } else {
                value = nums2[indexB];
                indexB--;
            }
            nums1[targetIndex] = value;
            targetIndex--;
        }

        while (indexB >= 0) {
            nums1[targetIndex] = nums2[indexB];
            targetIndex--;
            indexB--;
        }
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

        int n = 0, m = 0;
        cin >> n >> m;

        vector<int> a(n + m);
        vector<int> b(m);
        readVector(cin, a, n);
        readVector(cin, b, m);

        Solution s;
        s.merge(a, m, b, n);

        printVector<int>(cout, a);

        cout << endl;
    }

}