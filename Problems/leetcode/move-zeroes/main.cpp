#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution2 {
    void reverse(vector<int>& nums, int startPos, int endPos) {
        while (startPos < endPos) {
            swap(nums[startPos], nums[endPos]);
            startPos++;
            endPos--;
        }
    }

    void rotate(vector<int>& nums, int startPos, int count) {
        reverse(nums, startPos, startPos + count - 1);
        reverse(nums, startPos + count, nums.size() - 1);
        reverse(nums, startPos, nums.size() - 1);
    }

public:
    void moveZeroes(vector<int>& nums) {
        int lastZeroPos = nums.size() - 1;
        for (; lastZeroPos >= 0; lastZeroPos--) {
            if (nums[lastZeroPos] != 0)
                break;
        }

        if (lastZeroPos < 0) {
            //all values are zeros already
            return;
        }
        
        int i = 0;
        while (i < lastZeroPos) {
            //search for zero
            if (nums[i] == 0) {
                //rotate all elements to the left & move zero to the lastZeroPos position & decrease lastZeroPos
                rotate(nums, i, 1);
                lastZeroPos--;
            }
            else
                i++;
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[pos] = nums[i];
                pos++;
            }
        }

        for (; pos < nums.size(); pos++) {
            nums[pos] = 0;
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

        int n;
        cin >> n;

        vector<int> arr(n);
        for (int j = 0; j < n; j++)
            cin >> arr[j];

        Solution s;
        s.moveZeroes(arr);

        for (int j = 0; j < n; j++)
            cout << arr[j] << " ";

        cout << endl;
    }
}