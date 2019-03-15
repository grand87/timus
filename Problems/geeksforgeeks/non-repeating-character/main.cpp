#include <iostream>

using namespace std;

char buffer[100000];

char locate(char* str, int /*len*/) {
    int flagFirstOqurance = 0;
    int flagSecondOqurance = 0;

    for (int j = 0; buffer[j] != 0; j++) {
        const int bitNumber = buffer[j] - 'a';
        const int bitMask = 1 << bitNumber;
        if (flagFirstOqurance & bitMask) {
            flagSecondOqurance |= bitMask;
        } else
            flagFirstOqurance |= bitMask;
    }

    //need to return element for which we do have 0 bit in the flag
    for (int j = 0; buffer[j] != 0; j++) {
        const int bitNumber = buffer[j] - 'a';
        const int bitMask = 1 << bitNumber;
        if (flagFirstOqurance & bitMask && !(flagSecondOqurance & bitMask))
            return buffer[j];
    }

    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cin >> buffer;
        char res = locate(buffer, n);
        if (res == 0)
            cout << -1 << endl;
        else
            cout << res << endl; 
    }
    return 0;
}