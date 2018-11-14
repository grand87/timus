#include <iostream>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    unsigned int m, n;
    std::cin >> m >> n;

	// amount of divisions is odd than wins first in other case - second
	// how to determine amount of divisions?
	// for example: 4x2 will have 1 (4x1 + 4x1), 2 (2x1 + 2x1 + 4x1), 3 (1x1 + 1x1 + 2x1 + 4x1) .... divisions
	// to win carlson must go first

	// need to determine amount of iterations to break M x N matrix

	const unsigned int totalChunks = m * n;
	const unsigned int totalIterations = m * n - 1;

	if (totalIterations % 2 != 0)
		std::cout << "[:=[first]";
	else
		std::cout << "[second]=:]";
	
}