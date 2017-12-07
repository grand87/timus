#include <iostream>
#include <algorithm> 

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	__int64 x, y, c;

	std::cin >> x >> y >> c;

	__int64 a = 0, b = 0;

	// a + b == c
	// and
	// a <= x
	// b <= y


	__int64 diff = x - c + y;

	if (diff < 0)
	{
		std::cout << "Impossible";
	}
	else
	{
		if (c <= x && c <= y)
		{
			a = c;
			b = 0;
		}
		else
		if (diff <= x || diff <= y)
		{
			a = std::max(x, y) - diff;
			b = c - a;

			if (a > x)
			{
				if (b < y && b - x + a <= y)
				{
					a = x;
					b = c - a;
				}
			}
			
			if (b > y)
			{
				if (a < x && a - y + b <= x)
				{
					b = y;
					a = c - b;
				}
			}
		}
		else
		{
			a = diff;
			b = 0;
		}
		std::cout << a << " " << b;
	}

	return 0;
}
