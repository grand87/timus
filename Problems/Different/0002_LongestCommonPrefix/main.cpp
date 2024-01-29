#include <cctype>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <utils.h>

using namespace std;

string solution(const vector<string> &strings) {
    if (strings.size() == 0)
        return "";

    if (strings.size() == 1)
        return strings[0];

    int comonLen = 0;
    bool proceed = true;

    while (proceed) {
        for (int s = 1; s < strings.size(); s++) {
            if (strings[0][comonLen] != strings[s][comonLen]) {
                proceed = false;
                break;
            }
        }
        comonLen += proceed;
    }

    string res;
    if (comonLen > 0) {
        res.resize(comonLen);
        for (int i = 0; i < comonLen; i++) {
            res[i] = strings[0][i];
        }
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

        int n;
        cin >> n;

        vector<string> s(n);
        readVector(cin, s, n);

        cout << solution(s) << endl;
    }

    return 0;
}