#include <iostream>

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
#endif
   unsigned int gShots, lShots;
   std::cin >> gShots >> lShots;

   const unsigned int MAX_CANS = gShots + lShots - 1;
   const unsigned int gRemain = MAX_CANS - gShots;
   const unsigned int lRemain = MAX_CANS - lShots;

   std::cout << gRemain << " " << lRemain << std::endl;
}