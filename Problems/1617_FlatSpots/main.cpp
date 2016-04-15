#include <iostream>
#include <string>
#include <map>

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	unsigned int pairs = 0;
	unsigned int pairSize = 0;
	unsigned int count = 0;

	std::map<unsigned int, unsigned int> sizeDict;
	std::cin >> pairs;

	for (unsigned int p = 0; p < pairs; ++p)
	{

		std::cin >> pairSize;
		sizeDict[pairSize]++;

		std::map<unsigned int, unsigned int>::iterator it = sizeDict.find(pairSize);

		if (it->second == 4)
		{
			it->second = 0;
			count += 1;
		}
	}
	
	std::cout << count;

	return 0;
}
