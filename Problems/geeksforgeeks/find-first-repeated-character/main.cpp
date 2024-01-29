#include <iostream>

using namespace std;

char buffer[100000];

char locate(char* str) {
    int flag = 0;

    for (int j = 0; buffer[j] != 0; j++) {
        const int bitNumber = buffer[j] - 'a';
        const int bitMask = 1 << bitNumber;
        if (flag & bitMask) {
            //located
            return buffer[j];
        }
        else
            flag |= bitMask;
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
        cin >> buffer;
        char res = locate(buffer);
        if (res == 0)
            cout << -1 << endl;
        else
            cout << res << endl; 
    }
    return 0;
}