#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    int marks;
    cin >> marks;

    bool has3 = false;
    bool only5 = true;
    float total = 0;

    for (int i = 0; i < marks; ++i)
    {
        int m;
        cin >> m;
        total += m;

        if (m != 5)
        {
            only5 = false;
            if (m == 3)
                has3 = true;
        }
    }

    if (only5)
        cout << "Named";
    else if (!has3)
    {
        if(total / marks >= 4.5f)
            cout << "High";
        else
            cout << "Common";
    }
    else
        cout << "None";
}