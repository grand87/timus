#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution {
public:
    int findMedianSortedArrays_helper(vector<int>& nums1, vector<int>& nums2, int midPos, bool isEven, int left, int right, double &res) {
        if (left <= right) {
            int guessMidIndex = left + (right - left) / 2;
            //is the item in first array at position midIndex could be general median?

            int amount_of_items_from_second_array = midPos - guessMidIndex;

            if (amount_of_items_from_second_array == 0) {
                if (nums2[0] >= nums1[guessMidIndex]) {
                    res = nums1[guessMidIndex];
                    if (isEven) {
                        if (guessMidIndex < nums1.size() - 1) {
                            res += min(nums2[0], nums1[guessMidIndex + 1]);
                        }
                        else
                            res += nums2[0];
                        res /= 2.0;
                    }
                    return guessMidIndex;
                } else if (nums1.size() == nums2.size() && nums2[0] < nums1[guessMidIndex] && guessMidIndex == nums1.size() - 1) {
                    if (nums2.size() > 1 && nums2[1] >= nums1[guessMidIndex]) {
                        res = nums1[guessMidIndex];
                        if (isEven) {
                            res += nums2[0];
                            res /= 2.0;
                            return guessMidIndex;
                        }
                    }
                }
                return findMedianSortedArrays_helper(nums1, nums2, midPos, isEven, left, guessMidIndex - 1, res);
            } else if (amount_of_items_from_second_array > 0 && amount_of_items_from_second_array <= nums2.size()) {
                int indexInSecondArray = amount_of_items_from_second_array - 1;
                if (nums1[guessMidIndex] > nums2[indexInSecondArray] && (indexInSecondArray == nums2.size() - 1 || nums1[guessMidIndex] <= nums2[indexInSecondArray + 1])) {
                    res = nums1[guessMidIndex];
                    if (isEven) {
                        //if (indexInSecondArray < nums2.size() - 1 && nums2[indexInSecondArray] < nums1[guessMidIndex])
                        //    indexInSecondArray++;

                        //here is 3 cases which value I should take to generate median
                        //a[m+1]
                        //b[i]
                        //b[i+1]
                        if (guessMidIndex < nums1.size() - 1) {
                            if (nums2[indexInSecondArray] > res && nums1[guessMidIndex + 1] > res)
                                res += min(nums2[indexInSecondArray], nums1[guessMidIndex + 1]);
                            else {
                                if (nums2[indexInSecondArray] > res)
                                    res += nums2[indexInSecondArray];
                                else
                                    if(indexInSecondArray + 1 < nums2.size())
                                        res += min(nums2[indexInSecondArray + 1], nums1[guessMidIndex + 1]);
                                    else
                                        res += nums1[guessMidIndex + 1];
                            }
                        } else {
                            if(nums2[indexInSecondArray] >= res)
                                res += nums2[indexInSecondArray];
                            else
                                res += nums2[indexInSecondArray + 1];
                        }
                        res /= 2.0;
                    }
                    return guessMidIndex;
                }
                //continue to search for a new potential median from the right part of left array
                //determine where to look - in the left or in the right part
                if (!(indexInSecondArray == nums2.size() - 1 || nums1[guessMidIndex] <= nums2[indexInSecondArray + 1])) {
                    return findMedianSortedArrays_helper(nums1, nums2, midPos, isEven, left , guessMidIndex - 1, res);
                }
            } if (amount_of_items_from_second_array < 0) {
                // median located in the left array only
                res = getItem(nums1, nums2, midPos);
                return true;
            }

            return findMedianSortedArrays_helper(nums1, nums2, midPos, isEven, guessMidIndex + 1, right, res);
        }
        return -1;
    }

    int getItem(const vector<int>& nums1, const vector<int>& nums2, int absPosition) {
        if (absPosition < nums1.size())
            return nums1[absPosition];
        else
            return nums2[absPosition - nums1.size()];
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res = 0;
        const int medianIndex = (nums1.size() + nums2.size() - 1) / 2;
        const bool isEven = (nums1.size() + nums2.size()) % 2 == 0;

        //test for some corner cases

        // case 0: some array is empty
        if (nums1.size() == 0 || nums2.size() == 0) {
            if (isEven)
                return (getItem(nums1, nums2, medianIndex) + getItem(nums1, nums2, medianIndex + 1)) / 2.0;
            else
                return getItem(nums1, nums2, medianIndex);
        }

        // case 1: both arrays are not intersects
        if (nums1[nums1.size() - 1] <= nums2[0]) {
            //second array will be located to the right of first array
            if (isEven)
                return (getItem(nums1, nums2, medianIndex) + getItem(nums1, nums2, medianIndex + 1)) / 2.0;
            else
                return getItem(nums1, nums2, medianIndex);
        }
        if (nums1[0] >= nums2[nums2.size() - 1]) {
            //second array will be loacted to the left of first array
            if (isEven)
                return (getItem(nums2, nums1, medianIndex) + getItem(nums2, nums1, medianIndex + 1)) / 2.0;
            else
                return getItem(nums2, nums1, medianIndex);
        }
        //case 2: arrays intersects in some way
        if (nums1.size() == nums2.size()) {
            int midInArray = medianIndex / 2;
            if (nums1[midInArray] == nums2[midInArray]) {
                if(nums1[midInArray + 1] == nums2[midInArray + 1])
                    return (min(nums1[midInArray], nums1[midInArray + 1]) + max(nums2[midInArray], nums2[midInArray + 1])) / 2.0;
                else
                    return (min(nums1[midInArray], nums1[midInArray + 1]) + min(nums2[midInArray], nums2[midInArray + 1])) / 2.0;
            }
        }
        
        //case 3- use binary search to locate potential median
        //TODO need to handle even sumary size 

        if (nums1.size() >= nums2.size()) {
            int located = findMedianSortedArrays_helper(nums1, nums2, medianIndex, isEven, 0, nums1.size() - 1, res);
            if (located == -1)
                located = findMedianSortedArrays_helper(nums2, nums1, medianIndex, isEven, 0, nums2.size() - 1, res);
        } else {
            int located = findMedianSortedArrays_helper(nums2, nums1, medianIndex, isEven, 0, nums2.size() - 1, res);
            if (located == -1)
                located = findMedianSortedArrays_helper(nums1, nums2, medianIndex, isEven, 0, nums1.size() - 1, res);
        }

        return res;
    }
};

void readArray(int* data, int size) {
    for (int i = 0; i < size; i++)
        cin >> data[i];
}

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

        vector<int> numbers1(n);
        vector<int> numbers2(m);
        if(n > 0)
            readArray(&numbers1[0], n);
        if(m > 0)
            readArray(&numbers2[0], m);
        double answer;
        cin >> answer;
        Solution s;
        auto res = s.findMedianSortedArrays(numbers1, numbers2);
        cout << "TEST " << i + 1 << " "<< res << endl;
        assert(answer == res);
    }
}