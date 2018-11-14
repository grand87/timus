#include <iostream>
#include <algorithm>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int a1, a2, a3;
	int b1, b2, b3;

	std::cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
	
	
	std::cout << a1 - a3 << " " << a2 - a1;

    return 0;
}
