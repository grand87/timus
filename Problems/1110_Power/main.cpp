#include <iostream>

const unsigned int maxM = 1000;

int main()
{
	bool valsExists = false;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int n,m,y;
    std::cin >> n >> m >> y;

	const unsigned int unknown = -1;
	unsigned int cache[maxM];
	for (unsigned int i = 0; i < maxM; ++i)
		cache[i] = unknown;


	//period for function == m
	//might to identify values in range 0 .. m/2 - after m/2 - values would be symmetric on graphics

	//refer http://mathhelpplanet.com/viewtopic.php?p=208830#p208830

	for (unsigned int i = 1; i < m; ++i)
	{
		unsigned int n1 = i % m;
		unsigned int m1 = n;
		unsigned int k = 1;

		if (n1 >= 2)
		{
			do
			{
				if (m1 % 2)
				{
					if (k == 1)
						k = n1 * n1;
					else
						k = k * k;
				}
				else
				{
					if (k == 1)
						k = n1;
					else
						k = k * k;
				}
				m1 /= 2;

				k = k % m;
			} while (k % 9 != k || m1 >= 2);
		}
		unsigned int p = std::pow(k, m1);
		unsigned int res = (n1 * p) % m;
		if (res == y)
		{
			std::cout << i << " ";
			valsExists = true;
		}
	}

	if (!valsExists)
		std::cout << "-1";
}
