#include <iostream>

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
#endif
   int N, i;
   std::cin >> N;

   double v = 0;
   double sum = 0;
 
   std::cin.precision(19);

   for (int i = 0; i < N; ++i) {
	   std::cin >> v;
	   sum += v;
   }
   std::cout.precision(19);
   std::cout << std::scientific << sum;
   return 0;
}