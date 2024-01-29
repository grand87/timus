#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

bool suitesPallRules(const string& s, unordered_map<char, int>& freq) {
    // verify could generate pallindromes
    for (char c : s) {
        ++freq[c];
    }
    int oddCount = 0;
    for (auto& combo : freq) {
        if (combo.second & 1)
            ++oddCount;
    }

    if ((s.length() & 1) == 0) {
        // all letters should be even count
        if (oddCount)
            return false;
    } else {
        // only one letter should have odd count
        if (oddCount > 1)
            return false;
    }
    return true;
}

void permuteHelper(string s, set<string>& combs, int pos) {
    if (pos == s.length()) {
        combs.insert(s);
        return;
    }

    for (int i = pos; i < s.length(); i++) {
        swap(s[pos], s[i]);
        permuteHelper(s, combs, pos + 1);
        swap(s[pos], s[i]);
    }
}

void permute(const string& s, set<string>& combs) {
    permuteHelper(s, combs, 0);
}

vector<string> generatePallindroms(const string& s) {
    vector<string> res;
    unordered_map<char, int> freq;

    if (!suitesPallRules(s, freq))
        return res;

    // select half of even letters
    string letters;
    char oddSymbol = 0;
    for (auto& p : freq) {
        for (int i = 0; i < p.second / 2; i++)
            letters.push_back(p.first);
        // locate the odd symbol to put in the middle
        if (p.second & 1)
            oddSymbol = p.first;
    }

    // generate all combinations with letters
    set<string> uniqueCombinations;
    permute(letters, uniqueCombinations);
    
    for (auto& half : uniqueCombinations) {
        // reverse letters to form second half
        string halfReveres = half;
        reverse(halfReveres.begin(), halfReveres.end());

        // concatenate
        string resStr = half;
        if (oddSymbol)
            resStr.push_back(oddSymbol);
        resStr += halfReveres;
        res.push_back(resStr);
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

        vector<string> res = generatePallindroms(s);
        cout << "{ ";
        for (auto& s : res)
            cout << s << " ";
        cout << "}"<< endl;
    }
    return 0;
}