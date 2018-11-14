#include <iostream>

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	unsigned int valCount, arrSize;

	std::cin >> arrSize >> valCount;

	std::cout << arrSize * (valCount + 1);
}