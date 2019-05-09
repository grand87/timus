#include<iostream>

using namespace std;

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        if (n == 1 && m == 1)
            cout << 1 << endl;
        else {
            if (m == 1)
                cout << 1 << endl;
            else if (n == 1)
                cout << 0 << endl;
            else {
                while (m % n == 0 && m != 1) {
                    m /= n;
                }

                if (m == 1)
                    cout << 1 << endl;
                else
                    cout << 0 << endl;
            }
        }
    }
    return 0;
}