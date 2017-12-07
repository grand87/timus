#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    
    char guest[256];

    int guestsCount = 2;

    int feedbacks = 0;
    cin >> feedbacks;

    for(int f = 0; f < feedbacks; ++f)
    {
        ++guestsCount;
        cin >> guest;
        char* subGuestName = strchr(guest, '+');
        if (subGuestName != 0)
            ++guestsCount;
    }

    cout << guestsCount * 100 + (guestsCount == 13) * 100;;

    return 0;
}