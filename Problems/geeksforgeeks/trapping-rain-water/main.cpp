#include <iostream>
#include <algorithm>

using namespace std;

int barsArray[10000001];
int barsMapLeft[10000001];
int barsMapRight[10000001];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int bars;
        cin >> bars;
        for (int b = 0; b < bars; b++)
            cin >> barsArray[b];

        barsMapLeft[0] = barsArray[0];
        for (int j = 1; j < bars; j++) {
            if (barsArray[j] < barsMapLeft[j - 1])
                barsMapLeft[j] = barsMapLeft[j - 1];
            else
                barsMapLeft[j] = barsArray[j];
        }

        barsMapRight[bars-1] = barsArray[bars-1];
        for (int j = bars - 2; j >= 0; j--) {
            if (barsArray[j] > barsMapRight[j + 1])
                barsMapRight[j] = barsArray[j];
            else
                barsMapRight[j] = barsMapRight[j + 1];
        }

        int s = 0;
        for (int j = 0; j < bars; j++) {
            s += min(barsMapLeft[j], barsMapRight[j]) - barsArray[j];
        }

        cout << s << endl;
    }
    return 0;
}