#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>
#include "utils.h"

using namespace std;

int solve(vector<int> buffer) {

    const int sz = buffer.size();

    int jumps = 0;

    for (int i = 0; i < sz;) {
        //search for the first value which stands before it's position
        const int pos = sz - i - 1;
        const int v = buffer[pos] - 1;
        if (v > pos) {
            if (v == pos + 1) {
                //shift items on 1 to front
                swap(buffer[pos], buffer[pos + 1]);
                i = max(i - 1, 0);
                jumps += 1;
                continue;
            } else if (v == pos + 2) {
                buffer[pos] = buffer[pos + 1];
                buffer[pos + 1] = buffer[pos + 2];
                buffer[pos + 2] = v + 1;
                i = max(i - 2, 0);
                jumps += 2;
                continue;
            }
            return -1;
        }

        i++;
    }
    return jumps;
}

void minimumBribes(vector<int> buffer) {
    const int res = solve(buffer);
    if (res == -1)
        cout << "Too chaotic" << endl;
    else
        cout << res << endl;
}

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    int tests;
    cin >> tests;

    int size = 0;
    int ans = 0;
    vector<int> data;

    for (int t = 0; t < tests; ++t) {
        cin >> size;
        data.resize(size);
        readVector(cin, data, size);
        cin >> ans;

        const int res = solve(data);
        cout << res << (res == ans ? " - OK" : " - Fail") << endl;
    }
    return 0;
}