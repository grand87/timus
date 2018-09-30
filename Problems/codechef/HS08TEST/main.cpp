#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //   freopen("output.txt", "wt", stdout);
#endif

    unsigned int request;
    float balance;
    cin >> request >> balance;

    if (request % 5 == 0 && request + 0.5f < balance) {
        balance -= request + 0.5f;
    }

    printf("%.2f", balance);
}