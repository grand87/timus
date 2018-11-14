#include <iostream>
#include <string>

const unsigned int max_teams = 150000;

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
#endif

    char place[4];

	std::cin >> place;

	std::string sPlace(place);

	unsigned int row = atoi(place);
	unsigned int column = place[sPlace.length() - 1] - 'A';

	std::string sit;

	if (row <= 2)
	{
		sit = column == 0 || column == 3 ? "window" : "aisle";
	}
	else if (row <= 20)
	{
		sit = column == 0 || column == 5 ? "window" : "aisle";
	}
	else
	{
		switch (column)
		{
		case 0:
		case 10:
			sit = "window";
			break;
		case 2:
		case 3:
		case 6:
		case 7:
			sit = "aisle";
			break;
		default:
			sit = "neither";
		}
	}

	std::cout << sit;

}