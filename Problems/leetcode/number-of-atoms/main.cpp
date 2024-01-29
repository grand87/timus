#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

class Solution {

    typedef map<string, int> Elements;

    string readAtomName(const string& formula, int &pos) {
        char buf[255];
        int len = 0;
        do {
            buf[len++] = formula[pos++];
        } while (islower(formula[pos]));
        buf[len] = 0;
        return string(buf);
    }

    int readCount(string& formula, int &pos, int &count) {
        char buf[255];
        int len = 0;
        do {
            buf[len++] = formula[pos++];
        } while (isdigit(formula[pos]));
        buf[len] = 0;
        count = atoi(buf);
        return len;
    }

    Elements process(string& formula, int &pos) {
        Elements els;
        while (pos < formula.size()) {
            int count = 1;
            if (formula[pos] == ')') {
                pos++;
                return els;
            } else if (isupper(formula[pos])) { //read element name
                const string atomName = readAtomName(formula, pos);
                if (isdigit(formula[pos])) { //read element count
                    readCount(formula, pos, count);
                }
                els[atomName] += count;
            } else if (formula[pos] == '(') {
                pos++;
                Elements elsToMerge = process(formula, pos);
                if (isdigit(formula[pos])) { //read element count
                    readCount(formula, pos, count);
                }
                for (auto r : elsToMerge) {
                    r.second *= count;
                    els[r.first] += r.second;
                }
            }
        }
        return els;
    }

public:
    string countOfAtoms(string formula) {
        int pos = 0;
        Elements elements = process(formula, pos);

        stringstream res;

        for (auto r : elements) {
            res << r.first;
            if (r.second > 1)
                res << r.second;
        }
        return res.str();
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        char buf[255];
        cin >> buf;
        string str(buf);
        Solution s;
        cout << s.countOfAtoms(str).c_str() << endl;
    }
}