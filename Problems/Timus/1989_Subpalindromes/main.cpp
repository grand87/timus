#include <iostream>

using namespace std;

const int cMaxChars = 100100;
char word[cMaxChars];

const int cMaxOperationChars = 20;
char operation[cMaxOperationChars];

bool isPoly(const char* buf, int a, int b) {
    if (a == b)
        return true;

    if (b - a == 1)
        return buf[a - 1] == buf[a];

    const int l = (b - a + 1) / 2;

    for (int i = 0; i < l; ++i) {
        if (buf[a - 1 + i] != buf[b - 1 - i])
            return false;
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    
    cin >> word;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> operation;
        switch (operation[0]) {
        case 'p': 
        {
            int a, b;
            cin >> a >> b;
            cout << (isPoly(word, a, b) ? "Yes" : "No") << endl;
            break;
        }
        case 'c':
        {
            int a;
            char c;
            cin >> a >> c;
            word[a - 1] = c;
            break;
        }
        }
    }
}