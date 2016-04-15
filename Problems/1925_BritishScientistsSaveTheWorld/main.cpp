#include <iostream>
#include <vector>

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int n, k;
	std::cin >> n >> k;

	typedef std::pair<int, int> histRecord;
	typedef std::vector<histRecord> history;
	history hist;
	hist.reserve(101);

	int sumSource = 0;
	int sumGenerated = 0;

	for (char i = 0; i < n; ++i)
	{
		histRecord rec;
		std::cin >> rec.first >> rec.second;
		hist.push_back(rec);

		sumSource += rec.first;
		sumGenerated += rec.second;
	}

	sumSource += k;
	const int expectedSum = sumSource - (n + 1) * 2;

	unsigned int result = 0;

	if (expectedSum - sumGenerated >= 0)
		std::cout << expectedSum - sumGenerated;
	else
		std::cout << "Big Bang!";

	return 0;
}
