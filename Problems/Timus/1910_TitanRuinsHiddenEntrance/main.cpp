#include <iostream>
#include <algorithm>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int nSections;

	int b1, b2, b3;

	std::cin >> nSections;

	long currentMax = 0;
	long currentSum = 0;
	int currentMaxMid = 0;

	std::cin >> b1 >> b2;
	currentMax = b1 + b2;
	currentSum = b1 + b2;
	currentMaxMid = 1;

	for (int i = 2; i < nSections; ++i)
	{
		std::cin >> b3;
		if (currentSum + b3 > currentMax)
		{
			currentMax = currentSum + b3;
			currentMaxMid = i;
		}

		currentSum = currentSum + b3 - b1;

		b1 = b2;
		b2 = b3;
	}
		
	std::cout << currentMax << " " << currentMaxMid;

    return 0;
}
