#include<iostream>
#include<vector>

using namespace std;

int buffer[100];


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;
        for (int v = 0; v < n; v++)
            cin >> buffer[v];

        //built bitmap for buffer
        int bitmap[1001] = { 0 };
        for (int v = 0; v < n; v++)
            bitmap[buffer[v]]++;

        const int mid = n / 2;
        int counter = 0;
        for (int v = 0; v <= 1000; v++) {
            if (bitmap[v] > 0) {
                if (counter == mid)
                    break;
                counter++;
                cout << v << " ";
                if (bitmap[v] > 1) {
                    bitmap[v]--;
                    v--;
                }
            }
        }

        for (int v = 1000; v >= 0; v--) {
            if (bitmap[v] > 0) {
                if (counter == n)
                    break;
                counter++;
                cout << v << " ";
                if (bitmap[v] > 1) {
                    bitmap[v]--;
                    v++;
                }
            }
        }
        cout << endl;
    }

    return 0;
}