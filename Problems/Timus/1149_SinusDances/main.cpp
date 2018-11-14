#include <iostream>
#include <string>

const std::string signPlus = "+";
const std::string signMinus = "-";

std::string getAn(int n)
{
    std::string res;

    for (int i = 1; i < n; ++i)
    {
        const std::string& sign = (i % 2 == 0) ? signPlus : signMinus;

        res += "sin(" + std::to_string(i) + sign;
    }

    res += "sin(" + std::to_string(n);

    for (int i = 0; i < n; ++i)
    {
        res += ")";
    }

    return res;
}

std::string getSn(int n)
{
    std::string res;

    for (int i = 0; i < n; ++i)
    {
        res += getAn(i + 1) + "+" + std::to_string(n - i);

        if (i != n - 1)
        {
            res = "(" + res + ")";
        }
    }

    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int n;

    std::cin >> n;

    std::string Sn = getSn(n);

    std::cout << Sn;

    return 0;
}
