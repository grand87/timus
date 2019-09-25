#include <iostream>
#include <unordered_map>
#include <vector>
#include <string.h>
#include <fstream>
#include <algorithm>
#include <utils.h>

using namespace std;

int lis(const vector<int> &A) {
    if (A.size() == 1)
        return 1;

    vector<int> res(A.size(), 1);

    int maxVal = 1;
    res[0] = 1;

    for (int i = 1; i < A.size(); i++) {
        const int ref = A[i];
        for (int j = 0; j < i; j++) {
            if (A[j] < ref) {
                res[i] = max(res[i], res[j] + 1);
                maxVal = max(maxVal, res[i]);
            }
        }
    }

#ifdef LOCAL_TEST
    printVector(cout, A);
    cout << endl;

    printVector(cout, res);
    cout << endl;
#endif

    return  maxVal;
}


int main()
{
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> data(n);
        readVector(cin, data, n);
        cout << lis(data) << endl;
    }
    return 0;
}