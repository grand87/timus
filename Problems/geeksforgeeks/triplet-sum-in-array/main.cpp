#include<iostream>
#include<algorithm>

using namespace std;

int a[1000000];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, x;
        cin >> n >> x;

        for (int j = 0; j < n; j++)
            cin >> a[j];

        sort(a, a + n);

        if (n < 3) {
            cout << "0" << endl;
        } else {
            int i1 = 0, i3 = n - 1;
            bool located = false;
            while (i1 < i3 - 1) {
                i3 = n - 1;
                int i2 = i1 + 1;
                while (i2 < i3) {
                    int sum = a[i1] + a[i2] + a[i3];
                    if (sum == x) {
                        located = true;
                        i1 = i3;
                        break;
                    } else {
                        if (sum < x)
                            i2++;
                        else
                            i3--;
                    }
                }
                i1++;
            }

            if(located)
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
    }
    return 0;
}