#include <iostream>
#include <math.h>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        // x (x + 1) / 2 + 1 = n
        // x (x + 1) / 2 + 1 - n = 0
        // (x^2 + x) / 2 + 1 - n = 0
        // 0.5 * x^2 + 0.5*x + 1 - n = 0

        long kI = 0;

        std:: cin >> kI;

        const double a = 0.5;
        const double b = 0.5;
        const double c = 1 - kI;
        const double d = b * b - 4 * a * c;

        const double _sqrt = sqrt(b * b - 4 * a * c);

        double x1 = abs((-b - _sqrt) / (2 * a));
        double x2 = abs((-b + _sqrt) / (2 * a));

        if (x1 - floor(x1) > 0 && x2 - floor(x2) > 0)
        {
            std:: cout << "0 ";
        }
        else
        {
            std:: cout << "1 ";
        }
    }
}
