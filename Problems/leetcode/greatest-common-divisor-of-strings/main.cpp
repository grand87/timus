#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <utils.h>

using namespace std;

class Solution {

    bool isDivideble(const string &str1, const string &str2) {
        //test if str1 could be made from x copies of str2
        if (str1.length() % str2.length() != 0)
            return false;

        const int s2Len = str2.length();

        const int substrCount = str1.length() / s2Len;
        for (int i = 0; i < substrCount; i++) {
            for (int p = 0; p < s2Len; p++) {
                if (str1[i * s2Len + p] != str2[p])
                    return false;
            }
        }
        return true;
    }

public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.length() < str2.length())
            swap(str1, str2);

        //base case
        if (str2.length() == 0)
            return "";

        if (str1.compare(str2) == 0)
            return str1;

        if(isDivideble(str1, str2))
            return str2;
        else {
            for (int i = 2; i < str2.length(); i++) {
                if (str2.size() % i == 0) {
                    if (isDivideble(str1, str2.substr(0, str2.size() / i)))
                        return str2.substr(0, str2.size() / i);
                }
            }
        }
        return "";
    }
};

int main()
{
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string a, b;
        cin >> a >> b;
        
        Solution s;
       
        cout << s.gcdOfStrings(a, b) << endl;
    }
}