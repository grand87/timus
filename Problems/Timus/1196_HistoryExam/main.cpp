#include <iostream>
#include <list>
#include <map>
#include <algorithm>

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	std::map<std::string, unsigned int> dates;

	unsigned int tDates;
	std::cin >> tDates;

	for (unsigned int i = 0; i < tDates; ++i)
	{
		char date[21] = "";
		std::cin >> date;
		dates[date] = 0;
	}

	std::cin >> tDates;

	unsigned int repeats = 0;

	for (unsigned int i = 0; i < tDates; ++i)
	{
		char date[21] = "";
		std::cin >> date;
		std::map<std::string, unsigned int>::iterator commonDate = dates.find(date);
		if (commonDate != dates.end())
		{
			repeats++;
		}
	}

	std::cout << repeats;

	return 0;
}
