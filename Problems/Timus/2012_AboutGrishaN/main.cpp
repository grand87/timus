#include <iostream>

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
#endif
   
   const unsigned int TOTAL_TASKS = 12;
   const unsigned int REMAIN_TOTAL_TIME = 4 * 60;
   unsigned int fTasks;

   while (std::cin >> fTasks)
   {
	   unsigned int remainTasks = (TOTAL_TASKS - fTasks);
	   unsigned int timeForTasks = remainTasks * 45;
	   if (timeForTasks < REMAIN_TOTAL_TIME)
	   {
		   std::cout << "YES" << std::endl;
	   }
	   else
	   {
		   std::cout << "NO" << std::endl;
	   }
   }
}