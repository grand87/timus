#include <iostream>

const unsigned int max_ranks = 10000;

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
#endif

   unsigned int candidates = 0, voices = 0;

   std::cin >> candidates >> voices;

   float ranks[max_ranks];
   memset(ranks, 0, sizeof(float)* max_ranks);

   const float voiceWeight = 100.f / voices;

   unsigned int voice;

   while (std::cin >> voice) {
	   ranks[voice - 1] += voiceWeight;
   }

   std::cout.precision(2);
   
   for (auto rank = 0; rank < candidates; ++rank)
   {
	   std::cout << std::fixed << ranks[rank] << "%\n";
   }
}