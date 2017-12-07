#include <iostream>
#include <algorithm>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

	int pPrice, dPrice, pStep, dStep;

	std::cin >> pPrice >> pStep >> dPrice >> dStep;

	int finalPrice = pPrice;

	bool pStart = true;

	while (true) {
		if (dPrice == pPrice || pPrice > dPrice)
		{
			finalPrice = pPrice;
			break;
		}

		if (pStart)
			pPrice = std::min(pPrice + pStep, dPrice);
		else
			dPrice = std::max(dPrice - dStep, pPrice);
		pStart = !pStart;
	}

	std::cout << finalPrice;
    return 0;
}
