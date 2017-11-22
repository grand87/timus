#include <iostream>

long getWeight(long c, const long *w, long size)
{
	long wsum = 0;
	for (long i = 0; i < size; ++i)
		wsum += ((c >> i) & 1) * w[i];
	return wsum;
}

void dump(long c, const long *w, long size)
{
	std::cout << c << " : ";
	for (long i = 0; i < size; ++i)
	{
		std::cout << ((c >> i) & 1);
	}
	std::cout << " - " << getWeight(c, w, size) << std::endl;
}

long main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	const long MAX_N = 21;
	long w[MAX_N] = { 0 };

	long n;
	std::cin >> n;

	long total = 0;

	for (long i = 0; i < n; ++i)
	{
		std::cin >> w[i];
		total += w[i];
	}

	long minDiff = total;
	const long totalCombination = 1 << n;
	for (long i = 1; i < totalCombination; ++i)
	{
		const long currentWeight1 = getWeight(i, w, n);
		const long currentWeight2 = total - currentWeight1;
		const long diff = abs(currentWeight2 - currentWeight1);
#ifndef ONLINE_JUDGE
		dump(i, w, n);
		std::cout << " - diff = " << diff << std::endl;
#endif
		if (diff < minDiff)
				minDiff = diff;
	}
	std::cout << minDiff;
}