#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <unordered_set>
#include <set>
#include <vector>

using namespace std;

void permuteHelper(vector<int> A, set<vector<int>> &result, int startPos, int endPos) {
    if (startPos == endPos) {
        if (result.find(A) == result.end())
            result.insert(A);
    } else {
        for (int i = startPos; i <= endPos; i++) {
            swap(A[startPos], A[i]);
            permuteHelper(A, result, startPos + 1, endPos);
            swap(A[startPos], A[i]);
        }
    }
}

vector<vector<int>> permute(vector<int>& A) {
    set<vector<int>> base;
    permuteHelper(A, base, 0, A.size() - 1);

    vector<vector<int>> res;
    res.reserve(base.size());
    for (auto r : base)
        res.push_back(r);

    return res;
}

int main() {
#ifdef LOCAL_TEST
    ifstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int m;
        cin >> m;
        vector<int> numbers(m);

        readVector(cin, numbers, m);

        vector<vector<int>> res = permute(numbers);

        for (const auto& v : res) {
            printVector(cout, v);
            cout << endl;
        }
    }
}