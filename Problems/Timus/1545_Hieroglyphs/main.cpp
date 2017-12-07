#include <iostream>
#include <algorithm>
#include <list>

const unsigned max_author_name = 30;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

	unsigned int dictSize;
	std::cin >> dictSize;

	std::list<std::string> userDict;

	char buf[3];

	for (unsigned int i = 0; i < dictSize; ++i)
	{
		std::cin >> buf;
		userDict.push_back(buf);
	}

	char userInput[2];
	std::cin >> userInput;

	for (auto dictItem = userDict.begin(); dictItem != userDict.end(); ++dictItem)
	{
		if (dictItem->c_str()[0] == userInput[0])
			std::cout << dictItem->c_str() << std::endl;
	}
		
    return 0;
}
