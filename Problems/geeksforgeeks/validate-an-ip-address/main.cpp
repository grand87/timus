#include<fstream>
#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

const int MAX_STR_LEN = 50;

int stoi(char* str, int len) {
    int pos = 0;
    int res = 0;
    for (int c = 0; c < len; c++) {
        res *= 10;
        res += str[c] - '0';
        pos++;
    }
    return res;
}

int isValid(char *ip)
{
    const int MAX_SECTION_LEN = 3;
    const int MAX_SECTION_COUNT = 4;

    int pos = 0;
    int sectionsProcessed = 0;
    while (ip[pos]) {
        if (sectionsProcessed == 4)
            return 0;
        
        //start to validate sectin
        int sectionLen = 0;
        for (int s = 0; s < MAX_SECTION_LEN; s++) {
            if (ip[pos + s] == 0)
                break;

            if(ip[pos + s] == '.') {
                //located end of section pos..pos + s
                break;
            }

            if (ip[pos + s] < '0' || ip[pos + s] > '9')
                return 0;

            sectionLen++;
        }
        if (sectionLen == 0)
            return 0;

        //next must be '.'
        if (sectionsProcessed < 3 && ip[pos + sectionLen] != '.')
            return 0;

        //validate value
        if (ip[pos] == '0' && sectionLen > 1) // no leading zeros
            return 0;

        const int val = stoi(ip + pos, sectionLen);
        if (val > 255)
            return 0;
        //skipping following '.'
        pos += sectionLen;
        if(sectionsProcessed < 3)
            pos += 1;
        sectionsProcessed++;
    }

    return sectionsProcessed == MAX_SECTION_COUNT;
}

int main() {
#ifdef LOCAL_TEST
    fstream f("input.txt");
    cin.set_rdbuf(f.rdbuf());
#endif
    int t;
    cin >> t;

    char buf[MAX_STR_LEN + 1];

    for (int i = 0; i < t; i++) {
        cin >> buf;
        cout << isValid(buf) << endl;
    }
    return 0;
}