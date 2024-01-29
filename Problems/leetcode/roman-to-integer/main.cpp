#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

static const map<char, int> ROMAN_VALUES {
    { 'I', 1 },
    { 'V', 5 },
    { 'X', 10 },
    { 'L', 50 },
    { 'C', 100 },
    { 'D', 500 },
    { 'M', 1000 }
};

static const map<char, set<char> > RULES_FOR_SUBSTRACT{
    { 'I', { 'V', 'X' } },
    { 'X', { 'L', 'C' } },
    { 'C', { 'D', 'M' } },
};

static const map<char, map<char, int> > TO_NUMBER_TABLE{
    { 'I',{ {'V', 4}, {'X', 9} } },
    { 'X',{ {'L', 40}, {'C', 90} } },
    { 'C',{ {'D', 400}, {'M', 900} } },
};

bool isSubstract(char first, char second) {
    if (RULES_FOR_SUBSTRACT.find(first) != RULES_FOR_SUBSTRACT.end()) {
        const auto options = RULES_FOR_SUBSTRACT.find(first)->second;
        return options.find(second) != options.end();
    }
    return false;
}

int toNumber(char first, char second) {
    return TO_NUMBER_TABLE.find(first)->second.find(second)->second;
}

class Solution {

public:
    int romanToInt(string s) {
        int result = 0;
        const int size = s.length();
        for (int i = 0; i < size; i++) {
            const char current = s[i];
            if (i + 1 < size) {
                if (isSubstract(current, s[i + 1])) {
                    result += toNumber(current, s[i + 1]);
                    i++;
                }
                else
                    result += ROMAN_VALUES.find(current)->second;
            } else 
                result += ROMAN_VALUES.find(current)->second;
        }
        return result;
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
       char buf[100];
       cin >> buf;
       Solution s;
       cout << s.romanToInt(string(buf)) << endl;
   }
}