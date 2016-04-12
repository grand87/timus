#include <iostream>

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
#endif

   unsigned int nBlocks, nDroidsInBlock;

   std::cin >> nBlocks >> nDroidsInBlock;

   unsigned int leftDroids = 0;
   unsigned int leftBombs = 0;

   unsigned int bombsForBlock;

   while (std::cin >> bombsForBlock) {
	   if (bombsForBlock < nDroidsInBlock)
		   leftDroids += nDroidsInBlock - bombsForBlock;
	   else
		   leftBombs += bombsForBlock - nDroidsInBlock;
   }
   
   std::cout << leftBombs << " " << leftDroids;
}