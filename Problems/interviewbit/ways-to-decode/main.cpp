#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

const int LETTER_Z_CODE = 26;

bool isValid(char c) {
    return c - '0' > 0;
}

bool isValid(char c, char c2) {
    const int d1 = c - '0';
    if (d1 > 0) {
        const int d2 = c2 - '0';
        return d1 * 10 + d2 <= LETTER_Z_CODE;
    }
    return false;
}

int numDecodingsHelp(const string& s, vector<int>& dp, vector<int>& dp2, int startPos) {
    int res = 0;

    if (startPos == s.size() - 1) {
        return isValid(s[startPos]);
    }

    if (isValid(s[startPos])) {
        if (dp[startPos + 1] == 0)
            dp[startPos + 1] = numDecodingsHelp(s, dp, dp2, startPos + 1);
        res += dp[startPos + 1];
    }

    if (startPos < s.size() - 1) {
        if (isValid(s[startPos], s[startPos + 1])) {
            if (startPos + 2 < dp2.size()) {
                if (dp2[startPos + 2] == 0)
                    dp2[startPos + 2] = numDecodingsHelp(s, dp, dp2, startPos + 2);
                res += dp2[startPos + 2];
            }
            else
                res += 1;
        }
    }

    return res;
}

int numDecodings(string A) {
    vector<int> dp(A.size());
    vector<int> dp2(A.size());
    
    int res = numDecodingsHelp(A, dp, dp2, 0);
    return res;
}

int main() {
#ifdef LOCAL_TEST
    ifstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());

    assert(numDecodings("261105") == 2);
    assert(numDecodings("26110559717") == 4);
    assert(numDecodings("2611055971756562") == 4);
    assert(numDecodings("717") == 2);
    assert(numDecodings("26110") == 2);
    assert(numDecodings("2611") == 4);
    assert(numDecodings("10") == 1);
    assert(numDecodings("12913") == 4);
    assert(numDecodings("1267913") == 6);

    assert(numDecodings("913") == 2);
    assert(numDecodings("1291") == 2);
    assert(numDecodings("129") == 2);
    assert(numDecodings("126") == 3);
    assert(numDecodings("612") == 2);
    assert(numDecodings("87536") == 1);
    assert(numDecodings("875361") == 1);
    assert(numDecodings("8753612") == 2);
    assert(numDecodings("79131") == 2);
    assert(numDecodings("875361268549483279") == 3);
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string message;
        cin >> message;
        cout << numDecodings(message) << endl;
    }
}