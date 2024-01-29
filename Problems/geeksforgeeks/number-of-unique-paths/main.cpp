#include <iostream>

using namespace std;

int amountOfUniquePathTo(int x, int y) {
    int table[15][15];
    // prefill part
    table[0][0] = 0;
    for (int i = 1; i < y; i++) {
        table[0][i] = 1;
    }
    for (int i = 1; i < x; i++) {
        table[i][0] = 1;
    }

    for (int i = 1; i < x; i++)
        for (int j = 1; j < y; j++)
            table[i][j] = table[i - 1][j] + table[i][j - 1];

    return table[x - 1][y - 1];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;

        cout << amountOfUniquePathTo(a, b) << endl;
    }
    return 0;
}