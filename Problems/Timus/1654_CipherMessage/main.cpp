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

	std::list<char> text;

	char c;

	char prev = 0;
	unsigned int repeat = 0;
	char prevInString = 0;

	while (std::cin >> c)
	{
		if (prev == 0)
		{
			//c can be unique symbol
			prev = c;
			repeat = 1;
		}
		else
		{
			if (prev != c)
			{
				if (repeat == 1 || (repeat > 1 && repeat % 2))
				{
					if (text.size() > 0)
						prevInString = *(++text.rend());

					if (prev == prevInString)
					{
						if (text.size() > 0)
						{
							text.pop_back();
							if (text.size() > 0)
								prevInString = *(++text.rend());
							else
								prevInString = 0;
						}
						prev = c;
						repeat = 1;
					}
					else
					{
						text.push_back(prev);
						prev = c;
						repeat = 1;
					}
				}
				else
				{
					prev = c;
					repeat = 1;
				}
			}
			else
			{
				repeat++;
			}
		}
	}

	if (repeat % 2)
	{
		if (text.size() > 0)
			prevInString = *(++text.rend());
		if (prev == prevInString)
			text.pop_back();
		else
			text.push_back(prev);
	}

	for (std::list<char>::const_iterator it = text.begin(); it != text.end(); ++it)
	{
		std::cout << *it;
	}
	
	return 0;
}
