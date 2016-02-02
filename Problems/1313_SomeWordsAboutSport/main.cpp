#include <iostream>

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	const unsigned int MaxFrameBufferSize = 100;
	const float PI = 3.1415926;
	const float ang45 = PI / 4;
	const float ang90 = PI / 2;
	const float ang270 = PI * 1.5;
	unsigned int frameBuffer[MaxFrameBufferSize][MaxFrameBufferSize];

	unsigned int screenSize;
	std::cin >> screenSize;

	for (int x = 0; x < screenSize; ++x)
		for (int y = 0; y < screenSize; ++y)
		{
			std::cin >> frameBuffer[x][y];
		}

	for (int x = 0; x < screenSize; ++x)
		for (int y = 0; y < screenSize; ++y)
		{
			float targetX = x * cos(ang45) + y * sin(ang45);
			float targetY = x * sin(ang45) + y * cos(ang45);

			unsigned int resX = (unsigned int)targetX;
			unsigned int resY = (unsigned int)targetY;

			std::cout << frameBuffer[resX][resY] << " ";
		}
}