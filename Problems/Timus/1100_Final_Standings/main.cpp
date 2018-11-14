#include <iostream>
#include <algorithm>
#include <list>

const unsigned int max_teams = 150000;

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
#endif

    std::list<unsigned int> ranks[101];

   unsigned int teams;

   std::cin >> teams;
      
   unsigned int solved;
   unsigned int teamID;

   while (std::cin >> teamID)
   {
	   std::cin >> solved;

	   ranks[solved].push_back(teamID);
   }

   for (auto i = 100; i >= 0; --i)
   {
	   if (ranks[i].size() > 0)
	   for (auto teamId : ranks[i])
		   std::cout << teamId << " " << i <<std::endl;
   }

}