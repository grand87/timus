#include <iostream>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    std::cin >> n;

    const int absN = abs(n);

    long result = (absN * (absN + 1)) / 2;

    if (n <= 0)
    {
        result = -result + 1;
    }

    std::cout << result;
}