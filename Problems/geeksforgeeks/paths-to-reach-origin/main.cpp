#include <iostream>

using namespace std;

int convertY(int y, int height) {
    return height - y - 1;
}

int convertX(int x, int width) {
    return x;
}

int amountOfUniquePathTo(int x, int y) {
    int table[26][26];
    // prefill part
    table[convertY(y - 1, y)][convertX(x - 1, x)] = 0;

    for (int i = 0; i < y - 1; i++) {
        table[convertY(i, y)][convertX(x - 1, x)] = 1;
    }
    for (int i = 0; i < x - 1; i++) {
        table[convertY(y - 1, y)][convertX(i, x)] = 1;
    }

    for (int i = 1; i < x; i++)
        for (int j = 1; j < y; j++) {
            int curX = convertX(x - i - 1, x);
            int curY = convertY(y - j - 1, y);
            table[curY][curX] = table[convertY(y - j, y)][curX] + table[curY][convertX(x - i, x)];
        }

    return table[convertY(0, y)][convertX(0, x)];
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

        cout << amountOfUniquePathTo(a + 1, b + 1) << endl;
    }
    return 0;
}