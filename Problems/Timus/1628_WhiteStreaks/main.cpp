#include <iostream>
#include <cstdint>

using namespace std;

const int MAX_K = 30000;
uint8_t callendar[MAX_K][MAX_K] = {};

const int HORIZONTAL_SCAN = 1 << 2;
const int VERTICAL_SCAN = 1 << 3;
const int BLACK = 1 << 4;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    /*freopen("output.txt", "wt", stdout);*/
#endif

    int m, n, k;
    cin >> n >> m >> k;

    for (int d = 0; d < k; d++) {
        int j, i;
        cin >> i >> j;
        callendar[j - 1][i - 1] = BLACK;
    }

    // scan grid to find spans of length > 1 in ny direction

    int spans = 0;

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (callendar[j][i] != BLACK) {
                int sh = 0;
                int sv = 0;
                if ((callendar[j][i] & HORIZONTAL_SCAN) == 0) {
                    sh = 1;
                    // if there is one more to the right - mark span as horizontal and increase span
                    callendar[j][i] |= HORIZONTAL_SCAN;
                    while (i + sh < n && callendar[j][i + sh] != BLACK) {
                        callendar[j][i + sh] |= HORIZONTAL_SCAN;
                        sh++;
                    }
                }

                if ((callendar[j][i] & VERTICAL_SCAN) == 0) {
                    sv = 1;
                    // if there is one more to the down - mark span as vertical and increase span
                    callendar[j][i] |= VERTICAL_SCAN;
                    while (j + sv < m && callendar[j + sv][i] != BLACK) {
                        callendar[j + sv][i] |= VERTICAL_SCAN;
                        sv++;
                    }
                }

                if (sv == 1 && sh == 1) {
                    // if it is just one cell - consider this as a span
                    spans += 1;
                } else {
                    if (sh > 1) {
                        spans += 1;
                    }
                    if (sv > 1) {
                        spans += 1;
                    }
                }
            }
        }
    }

    cout << spans << endl;
}