#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int cMaxCount = 70000;

long long values[cMaxCount] = { 0 };
long long diffValues[cMaxCount] = { 0 };

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    long long n, k;
    cin >> n >> k;

    for (long long i = 0; i < n; ++i) {
        cin >> values[i];
    }

    sort(values, values + n);

    diffValues[0] = 0;
    for (long long i = 1; i < n; ++i) {
        diffValues[i] = values[i] - values[i - 1];
    }

    long long c = 0;

    for (long long i = 0; i < n - 1; ++i) {
        //looking for the next value which is greater than value[i] on k
        long long diff = 0;
        for (long long j = i + 1; j < n; ++j) {
            diff += diffValues[j];
            if (diff >= k) {
                c += n - j;
                break;
            }
        }
    }

    cout << c << endl;
}