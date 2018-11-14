#include <iostream>
#include <vector>

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	unsigned int t1, t2;
	std::cin >> t1 >> t2;

	unsigned int t1AddTime = 0;

	for (char i = 0; i < 10; ++i)
	{
		unsigned int tryCount = 0;
		std::cin >> tryCount;
		t1AddTime += tryCount * 20;
	}

	if (t1 + t1AddTime <= t2 || (t1 == t2 && t1AddTime == 0))
		std::cout << "No chance.";
	else
		std::cout << "Dirty debug :(";

	return 0;
}
