#include <iostream>
#include <algorithm>

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
        int n, k;
        cin >> n >> k;
        
        for (int r = 0; r < n; r++) {
            cin >> array[r];
        }

        int pairs = 0;
        sort(array, array + n);

        int l = 0, r = 0;
        while (r < n) {
            const int diff = array[r] - array[l];
            if (diff == k) {
                if (r != l)
                    pairs++;
                r++;
            }
            else if (diff > k) {
                l++;
                r = l;
            }
            else
                r++;

        }

        cout << pairs << endl;
    }
    return 0;
}