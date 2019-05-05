#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    int getMiddleInRange(const vector<int>& nums, int start, int end) const {
        return nums[start + (end - start) / 2];
    }
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2, int offsetA, int offsetB, int endA, int endB, int len) {
        
        if (nums1[endA] < nums2[offsetA]) {
            // no more shuffles
            int middle = (nums1.size() + nums2.size()) / 2;
            middle -= nums1.size() - endA;

        }


        const int targetMiddle = len / 2;

        const int midA = offsetA + (endA - offsetA) / 2;
        auto it = lower_bound(nums2.begin() + offsetB, nums2.begin() + endB, nums1[midA]);

        if(it - nums2.begin() + midA >= targetMiddle) {
            //continue with A0..Amid + B0..Bend
            return findMedianSortedArrays(nums1, nums2, offsetA, offsetB, midA, nums2.size() - offsetB, len - offsetA - offsetB - midA);
        } else {
            return findMedianSortedArrays(nums1, nums2, midA + 1, offsetB + it - nums2.begin(), endA, endB - offsetB - (it - nums2.begin()), len - offsetA - offsetB - midA - 1);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int midIndex = (nums1.size() + nums2.size()) / 2;

        return findMedianSortedArrays(nums1, nums2, 0, 0, nums1.size(), nums2.size(), nums1.size() + nums2.size());
    }
};

void readArray(vector<int> &buf, int size) {
    for (int i = 0; i < size; i++) {
        cin >> buf[i];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        readArray(a, n);
        readArray(b, m);

        Solution s;
        double res = s.findMedianSortedArrays(a, b);

        cout << res << endl;
    }
    return 0;
}