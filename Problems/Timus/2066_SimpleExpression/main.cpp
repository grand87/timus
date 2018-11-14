#include <iostream>
#include <algorithm>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int vals[3];

    std::cin >> vals[0] >> vals[1] >> vals[2];
    std::sort(std::begin(vals), std::end(vals));

    long rightPart = (vals[1] == 0 || vals[2] == 0 || vals[1] == 1) ? vals[1] + vals[2] : vals[1] * vals[2];

    long result = vals[0] - rightPart;

    std::cout << result;

    return 0;
}
