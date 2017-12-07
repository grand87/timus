#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    int n;
    int pages[MAX_N];
    
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> pages[i];


    sort(pages, pages + n);
    int bookWidth = pages[0] + pages[n - 1];

    for (int i = 1; i < n; ++i)
    {
        bookWidth += max(pages[i - 1], pages[i]);
    }

    cout << bookWidth;
}