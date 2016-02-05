#include <iostream>
#include <algorithm>

const int MAX_VALUE[9] =
{
	4,
	9,
	19,
	49,
	99,
	249,
	499,
	999,
	2000
};

const char* MAX_NAMES[9] =
{
	"few",
	"several",
	"pack",
	"lots",
	"horde",
	"throng",
	"swarm",
	"zounds",
	"legion"
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int value;

	while (std::cin >> value)
	{
		for (int i = 0; i < 9; ++i)
		{
			if (value <= MAX_VALUE[i])
			{
				std::cout << MAX_NAMES[i] << std::endl;
				break;
			}
		}
	}
    return 0;
}
