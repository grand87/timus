#include <iostream>
#include <algorithm> 

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	__int64 n, k;

	std::cin >> n >> k;

	__int64 h = 0;

	//first load to PC
	--n;

	__int64 clonesCount = 1;
	
	while (n > 0)
	{
		if (clonesCount < k)
		{
			__int64 avalibleCopiesPerHour = std::min(clonesCount, k);
			clonesCount += avalibleCopiesPerHour;
			++h;
			n = n - std::min(n, avalibleCopiesPerHour);
		}
		else
		{
			// we reach max amount of clones
			// remains 
			clonesCount = k;
			h += n / clonesCount;
			if (n % clonesCount)
				++h;
			break;
		}
	}

	std::cout << h;

	return 0;
}
