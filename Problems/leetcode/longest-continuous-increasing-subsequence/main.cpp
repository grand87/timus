#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxLen = nums.size() == 0 ? 0 : 1;
        int len = nums.size() == 0 ? 0 : 1;

        const int size = nums.size();
        for (int i = 1; i < size; i++) {
            if (nums[i] > nums[i - 1]) {
                len++;
                maxLen = max(maxLen, len);
            } else {
                len = 1;
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
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
        int n = 0;
        cin >> n;

        vector<int> numbers(n);
        if(n > 0)
            readArray(&numbers[0], n);
        int answer;
        cin >> answer;
        Solution s;
        auto res = s.findLengthOfLCIS(numbers);
        cout << "TEST " << i + 1 << " "<< res << endl;
        assert(answer == res);
    }
}