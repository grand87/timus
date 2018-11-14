#include <iostream>
#include <string>
#include <map>

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	unsigned int shops = 0;
	unsigned int skipped = 0;

	std::map<std::string, unsigned int> visitedShop;
	std::string shopName;

	std::cin >> shops;
	std::getline(std::cin, shopName, '\n');

	for (unsigned int shop = 0; shop < shops; ++shop)
	{
		std::getline(std::cin, shopName, '\n');
		unsigned int value = visitedShop[shopName]++;
		if (value > 0)
			skipped++;
	}
	
	std::cout << skipped;

	return 0;
}
