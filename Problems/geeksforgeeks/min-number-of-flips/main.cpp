#include <iostream>
#include <unordered_map>
#include <vector>
#include <string.h>
#include <fstream>
#include <algorithm>

using namespace std;

constexpr unsigned int MAX_LEN = 1000;

unsigned int minFlips(const char* buf, int len) {
    //let's start from the assumption if first symbol is 0
    int countStart0 = 0;
    for (int i = 0; i < len; i+=2) {
        if (buf[i] != '0')
            countStart0++;
    }
    for (int i = 1; i < len; i += 2) {
        if (buf[i] != '1')
            countStart0++;
    }

    int countStart1 = 0;
    for (int i = 0; i < len; i += 2) {
        if (buf[i] != '1')
            countStart1++;
    }
    for (int i = 1; i < len; i += 2) {
        if (buf[i] != '0')
            countStart1++;
    }

    return min(countStart0, countStart1);
}

int main()
{
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif

    char buf[MAX_LEN];

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> buf;
        cout << minFlips(buf, strlen(buf)) << endl;
    }
    return 0;
}