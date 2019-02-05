#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int array[100] = { 0 };

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int values[1001] = { 0 };

        int n, k;
        cin >> n >> k;

        
        for (int r = 0; r < n; r++) {
            cin >> array[r];
            ++values[array[r]];
        }

        int pairs = 0;
        for (int r = 0; r < n; r++) {
            if (values[array[r]] == 0)
                continue;
            bool pairLocated = false;
            int valueToLook = k + array[r];
            if (valueToLook > 0 && valueToLook <= 1000) {
                if (values[valueToLook] > 0) {
                    pairs += values[valueToLook] * values[array[r]];
                    --values[valueToLook];
                    pairLocated = true;
                }
            }

            if (array[r] > k) {
                valueToLook = array[r] - k;
                if (valueToLook > 0 && valueToLook <= 1000) {
                    if (values[valueToLook] > 0) {
                        pairs += values[valueToLook] * values[array[r]];
                        --values[valueToLook];
                        pairLocated = true;
                    }
                }
            }

            if (pairLocated)
                values[array[r]] = 0;
        }

        cout << pairs << endl;
    }
    return 0;
}