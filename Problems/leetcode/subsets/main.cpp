#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> selected;
        evaluate(nums, 0, selected, res);
        return res;
    }
private:
    void evaluate(vector<int>& nums, int itemIndex, vector<int>& selected, vector<vector<int>> &res) {
        if (itemIndex == nums.size()) {
            //we evaluated all values so far
            res.push_back(selected);
            return;
        }
        selected.push_back(nums[itemIndex]);
        evaluate(nums, itemIndex + 1, selected, res);
        selected.erase(selected.end() - 1);
        evaluate(nums, itemIndex + 1, selected, res);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> data(n);
        for (int b = 0; b < n; b++)
            cin >> data[b];

        Solution s;
        auto res = s.subsets(data);

        for (auto s : res) {
            for (auto i : s) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}