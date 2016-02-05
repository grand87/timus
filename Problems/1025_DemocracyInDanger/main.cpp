#include <iostream>
#include <algorithm>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

	unsigned int K;
	std::cin >> K;

	unsigned int groups[101];

	for (int i = 0; i < K; ++i)
	{
		std::cin >> groups[i];
	}
	
	for (int i = K; i < 101; ++i)
	{
		groups[i] = 10000;
	}
	std::sort(std::begin(groups), std::end(groups));

	const unsigned int groupsCount = ceil(K / 2.f);

	unsigned int result = 0;

	for (int i = 0; i < groupsCount; ++i)
	{
		result += ceil(groups[i] / 2.f);
	}

    std::cout << result;

    return 0;
}
