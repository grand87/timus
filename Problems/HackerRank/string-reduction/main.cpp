#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#include <map>
#include <unordered_map>

using namespace std;

void mergeSymbols(const string& s, int pos, string& result) {
    //check if it 2 adjecent symbols are distinct
    //if (s[pos] != s[pos + 1]) {

        //locate missing symbol
        int mask[3] {0,0,0};
        mask[s[pos] - 'a'] = true;
        mask[s[pos + 1] - 'a'] = true;

        char replaceWith = 'a';
        if (mask[0] && mask[1] == false)
            replaceWith = 'b';
        else if (mask[2] == false)
            replaceWith = 'c';

        result.resize(s.size() - 1);
        if (pos != 0) {
            copy(s.begin(), s.begin() + pos, result.begin());
        }
        result[pos] = replaceWith;
        copy(s.begin() + pos + 2, s.end(), result.begin() + pos + 1);
        //return true;
    //}
    //return false;
}

int stringReductionHelp(const string &s, unordered_map<string, int> &table) {
    auto minLenLocated = table.find(s);
    if (minLenLocated != table.end())
        return minLenLocated->second;

    int minLength = s.size();
    for (int i = 0; i < s.size() - 1; i++) {
        string modifiedString;
        if (s[i] != s[i+1]) {
            if (s.size() == 2) {
                table[s] = 1;
                return 1;
            } else {
                mergeSymbols(s, i, modifiedString);
                minLenLocated = table.find(modifiedString);
                if (minLenLocated != table.end())
                    minLength = min(minLength, minLenLocated->second);
                else
                    minLength = min(minLength, stringReductionHelp(modifiedString, table));

                if (minLength == 1) {
                    table[s] = 1;
                    return 1;
                }
            }
        }
    }
    table[s] = minLength;
    return minLength;
}

int stringReduction(string s) {
    static unordered_map<string, int> table;
    sort(s.begin(), s.end());
    return stringReductionHelp(s, table);
}

int main()
{

#ifdef LOCAL_TEST
    ifstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
    ostream &fout = cout;
#elif
    ofstream fout(getenv("OUTPUT_PATH"));
#endif
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        int result = stringReduction(s);

        fout << result << "\n";
    }

#ifndef LOCAL_TEST
    fout.close();
#endif
    return 0;
}
