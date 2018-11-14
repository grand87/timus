#include <iostream>

const unsigned int max_ranks = 3;

unsigned int ranks[max_ranks] = { 0, 0, 0 };

char maxIndex = 0;
unsigned int maxCount = 0;

void updateRanks(unsigned int pIndex)
{
	if (++ranks[pIndex] > maxCount)
	{
		maxCount = ranks[pIndex];
		maxIndex = pIndex;
	}
}

const std::string pNames[max_ranks] = { "Emperor Penguin", "Macaroni Penguin", "Little Penguin" };

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
#endif

   unsigned int pCount;

   std::cin >> pCount;

   char pName[40];

   while (std::cin >> pName) {
	   switch (pName[0])
	   {
	   case 'E':
		   updateRanks(0);
		   break;
	   case 'M':
		   updateRanks(1);
		   break;
	   case 'L':
		   updateRanks(2);
		   break;
	   }
   }
   
   std::cout << pNames[maxIndex].c_str();
}