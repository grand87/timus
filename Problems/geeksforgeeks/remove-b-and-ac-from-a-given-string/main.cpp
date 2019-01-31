#include<iostream>
#include<cstring>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        char buff[201] = { 0 };
        cin >> buff;
        int pos = 0;
        const int len = strlen(buff);

        while (buff[pos] != 0 && pos < len) {
            if (buff[pos] == 'a' && buff[pos + 1] == 'c') {
                pos += 2;
                continue;
            }
            if (buff[pos] == 'b') {
                pos++;
                continue;
            }
            putc(buff[pos], stdout);
            pos++;
        }
        cout << endl;
    }
    return 0;
}