#include <iostream>
#include <iomanip>

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
#endif
   long long value;

   char *buffer = new char[1024 * 1024];

   double *data = (double *)buffer;
   double *ptrData = data;
   unsigned int valCount = 0;


   std::cout << std::fixed << std::setprecision(4);
   while (std::cin >> value) {
	   (*ptrData++) = std::sqrt(value);
	   valCount++;
   }

   for (unsigned i = valCount; i != 0;) {
	   std::cout << data[--i] << std::endl;
   }
   
   delete[] buffer;
}