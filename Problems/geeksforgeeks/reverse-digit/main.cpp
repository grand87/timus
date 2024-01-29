#include<iostream>
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        unsigned long value = 0;
        cin >> value;

        unsigned long result = 0;

        while (value != 0) {
            result = result * 10 + value % 10;
            value /= 10;
        }

        cout << result << endl;
    }
    return 0;
}