#include <iostream>

unsigned int fact(unsigned int val)
{
	if (val == 1)
		return val;
	else
		return val * fact(val - 1);
}

unsigned int pow(unsigned int value, unsigned int power)
{
	unsigned int result = value;
	for (unsigned int step = 1; step <= power; ++step)
		result *= result;
	return result;
}

unsigned int placesForBlue(unsigned int lines)
{
	return lines - 2;
}

unsigned int combinations[46];

unsigned int getCombinations(unsigned int linesOnFlag)
{
	unsigned int res = 0;
	if (combinations[linesOnFlag] > 0)
		res = combinations[linesOnFlag];
	else
	{
		res = getCombinations(linesOnFlag - 1) + getCombinations(linesOnFlag - 2);
		combinations[linesOnFlag] = res;
	}
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
#endif

   combinations[1] = 2;
   combinations[2] = 2;
   combinations[3] = 4;
   combinations[4] = 6;
   combinations[5] = 10;

   for (int i = 6; i < 46; ++i)
	   combinations[i] = 0;

   const unsigned int colors = 3;
   unsigned int linesOnFlag = 0;

   std::cin >> linesOnFlag;

   unsigned int res = 0;

   if (combinations[linesOnFlag] > 0)
	   res = combinations[linesOnFlag];
   else
   {
	   res = getCombinations(linesOnFlag);
   }

   std::cout << res << std::endl;
}