#include <iostream>

long getWeight(const long *s, const long *w, long size)
{
	long wsum = 0;
	for (long i = 0; i < size; ++i)
		wsum += s[i] * w[i];
	return wsum;
}

void dump(long c, long *s, long size, long *w)
{
	std::cout << c << " : ";
	for (long i = 0; i < size; ++i)
		std::cout << s[i] << " ";
	std::cout << " - " << getWeight(s, w, size) << std::endl;
}

long main()
{
#ifndef ONLINE_JUDGE
	long c = 0;
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	const long MAX_N = 20;
	long w[MAX_N] = { 0 };
	long s[MAX_N] = { 0 };

	long n;
	std::cin >> n;

	long total = 0;

	for (long i = 0; i < n; ++i)
	{
		std::cin >> w[i];
		total += w[i];
	}

	long minDiff = total;
	while (s[n] == 0)
	{
#ifndef ONLINE_JUDGE
		dump(c++, s, n, w);
#endif
		for (long i = 0; i < n + 1;++i)
		{
			if (s[i] == 0)
			{
				for (long j = 0; j < i; ++j)
				{
					s[j] = 0;
				}
				s[i] = 1;
				break;
			}
		}
		long currentWeight = getWeight(w, s, n);
		if (currentWeight != 0 && currentWeight != total)
		{
			long diff = total - currentWeight;
			if (abs(currentWeight - diff) < minDiff)
				minDiff = abs(currentWeight - diff);
		}

	}
	std::cout << minDiff;
}