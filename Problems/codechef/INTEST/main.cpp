#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //   freopen("output.txt", "wt", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned long requests;
    unsigned long k;
    cin >> requests >> k;

    unsigned long value;
    unsigned long passed = 0;;
    for (unsigned long i = 0; i < requests; ++i) {
        cin >> value;
        if (value % k == 0)
            ++passed;
    }

    cout << passed;
}