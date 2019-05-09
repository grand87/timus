#include <iostream>

using namespace std;

int main()
{
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        if (n == 0) {
            cout << 0 << endl;
        }
        else {
            if (n & 0x1)
                cout << 1 << endl;
            else {
                int count = 1;
                if ((n & 0xFFFF) == 0) {
                    count += 16;
                    n >>= 16;
                }

                if ((n & 0xFF) == 0) {
                    count += 8;
                    n >>= 8;
                }

                if ((n & 0xF) == 0) {
                    count += 4;
                    n >>= 4;
                }

                if ((n & 0x3) == 0) {
                    count += 2;
                    n >>= 2;
                }

                count -= n & 0x1;

                cout << count + 1 << endl;
            }
        }
    }
    return 0;
}