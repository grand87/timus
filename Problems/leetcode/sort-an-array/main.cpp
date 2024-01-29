#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
    void selectionSort(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int smallestIndex = i;
            // locate for the smallest
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[smallestIndex])
                    smallestIndex = j;
            }
            swap(nums[i], nums[smallestIndex]);
        }
    }

    void insertionSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            int tmp = nums[i];
            int j = i;
            while (j > 0 && nums[j - 1] > tmp) {
                nums[j] = nums[j - 1];
                j--;
            }
            nums[j] = tmp;
        }
    }

    int parent(int i) {
        return i >> 1;
    }

    int left(int i) {
        return (i << 1) + 1;
    }

    int right(int i) {
        return (i << 1) + 2;
    }

    void heapify(vector<int>& nums, int i, int n) {
        int largest = i;

        if (left(i) < n && nums[left(i)] > nums[largest])
            largest = left(i);
        if (right(i) < n && nums[right(i)] > nums[largest])
            largest = right(i);

        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, largest, n);
        }
    }

    void build_heap(vector<int>& nums) {
        for (int i = nums.size() / 2; i > 0; i--) {
            heapify(nums, i, nums.size());
        }
    }

    void heapSort(vector<int>& nums) {
        build_heap(nums);
        for (int n = nums.size(); n > 2; n--) {
            heapify(nums, 0, n);
            swap(nums[0], nums[n - 1]);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
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
        s.sortArray(nums);

        printVector(cout, nums);
        cout << endl;
    }
}