#include <iostream>

using namespace std;

int countFor(int row) {
    return (1 + row) * row;
}

int length(int row) {
    return row * 2;
}

int first(int row) {
    return countFor(row - 1) + 1;
}

int last(int row) {
    return countFor(row);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        const int nStart = first(n);
        const int nEnd = last(n);

        //calculate sum from nStart + nEnd
        int theSum = (nStart + nEnd) * length(n) / 2;
        cout << theSum << endl;

    }
    return 0;
}