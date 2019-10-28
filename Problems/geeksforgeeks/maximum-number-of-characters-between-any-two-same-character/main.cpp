#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int findMax(const string& s) {
    int res = -1;

    unordered_map<char, int> symbolStart;
    for (int pos = 0; pos < s.length(); pos++) {
        unordered_map<char, int>::iterator loc = symbolStart.find(s[pos]);
        if (loc != symbolStart.end()) {
            res = max(res, pos - loc->second - 1);
        } else
            symbolStart[s[pos]] = pos;
    }

    return res;
}

int main() {
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;

        cout << findMax(s) << endl;
    }
    return 0;
}