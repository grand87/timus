#include <iostream>
#include <string>

const unsigned int max_range = 50;

unsigned int getMod(const char *value, unsigned int M)
{
	const unsigned int size = std::string(value).size();
	unsigned int r = -1;

	unsigned int rIndex[max_range] = {0};
	for (int i = 0; i < size; ++i)
	{
		rIndex[i] = 1;
	}

	unsigned int pos = 0;
	rIndex[pos] = 3;

	do
	{
		rIndex[++pos] = (10 * rIndex[pos - 1]) % 7;
	} while (rIndex[pos] != 1);


	unsigned int mod = value[size - 1] - 48;

	for (int i = 1; i < size; ++i)
	{
		const unsigned int a = value[size - 1 - i] - 48;
		const unsigned int rI = rIndex[(i-1) % (pos + 1)];
		mod += a * rI;
	}

	return mod % 7;
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
#endif

   char value[max_range] = "";

   std::cin >> value;

   std::cout << getMod(value, 7);

}