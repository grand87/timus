#include <iostream>
#include <algorithm>

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
#endif

   unsigned int left, right;

   std::cin >> left >> right;

   //for right leg 
   unsigned int timeForRigth = right * 2 + 40;
   unsigned int timeForLeft = 78 + 40 + (left - 40) * 2 + 1;


   std::cout << std::max(timeForLeft, timeForRigth);
}