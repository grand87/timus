#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permuteHelper(string s, int pos, vector<string>& res) {
    if (pos == s.size()) {
        res.push_back(s);
    } else {
        for (int i = pos; i < s.size(); i++) {
            swap(s[pos], s[i]);
            permuteHelper(s, pos + 1, res);
            swap(s[pos], s[i]);
        }
    }
}

vector<string> permute(const string& s) {
    vector<string> res;

    permuteHelper(s, 0, res);

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
        string str;
        cin >> str;
        vector<string> res = permute(str);
        sort(res.begin(), res.end());

        for (auto& s : res)
            cout << s << " ";
        cout << endl;
    }
    return 0;
}