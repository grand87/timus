#include <iostream>
#include <algorithm>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int firstCode;
	int secondCode;

	std::cin >> firstCode;
	std::cin >> secondCode;

	if (firstCode % 2 == 0 || secondCode % 2 == 1)
	{
		std::cout << "yes";
	}
	else
	{
		std::cout << "no";
	}

    return 0;
}
