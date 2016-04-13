#include <iostream>
#include <algorithm>
#include <map>

const unsigned max_author_name = 30;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

	unsigned int submits;
	std::cin >> submits;

	std::map<std::string, unsigned int> queue;
	char autohor[max_author_name] = "";

	for (unsigned int i = 0; i < submits; ++i)
	{
		std::cin >> autohor;
		if (queue.find(autohor) == queue.end())
			queue[autohor] = 1;
		else
			++queue[autohor];
	}

	for (auto authorInfo = queue.begin(); authorInfo != queue.end(); ++authorInfo)
	{
		if (authorInfo->second > 1)
			std::cout << authorInfo->first.c_str() << std::endl;
	}
		
    return 0;
}
