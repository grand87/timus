#include <iostream>


unsigned int binPow(unsigned int val, unsigned int power, unsigned int mod)
{
    if (val == 1)
    {
        return 1;
    }

    if (power == 1)
    {
        return val % mod;
    }

    if (power % 2 == 0)
    {
        unsigned int res = binPow(val, power / 2, mod);
        return res * res % mod;
    }
    else
    {
        return val * binPow(val, power - 1, mod) % mod;
    }
}


int main()
{
    bool valsExists = false;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    unsigned int n, m, y;
    std::cin >> n >> m >> y;

    //period for function == m
    //might to identify values in range 0 .. m/2 - after m/2 - values would be symmetric on graphics

    //refer http://mathhelpplanet.com/viewtopic.php?p=208830#p208830

    for (unsigned int x = 0; x < m; ++x)
    {
        unsigned int powValue = binPow(x, n, m);

        if (powValue % m == y)
        {
            std::cout << x << " ";
            valsExists = true;
        }
    }

    if (!valsExists)
    {
        std::cout << "-1";
    }
}
