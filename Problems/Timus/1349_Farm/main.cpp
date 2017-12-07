#include <iostream>

int main()
{
    bool valsExists = false;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    unsigned int n;
    std::cin >> n;

    //solved according to https://en.wikipedia.org/wiki/Fermat%27s_Last_Theorem

    switch (n)
    {
        case 1:
            std::cout << "1 2 3";
            break;

        case 2:
            std::cout << "3 4 5";
            break;

        default:
            std::cout << "-1";
    }
}
