#include <iostream>
#include <string>

const unsigned int max_range = 7;

unsigned int getSum(const char* values, bool rigth)
{
	const int offset = 3 * rigth;
	return values[offset + 0] + values[offset + 1] + values[offset + 2];
}

unsigned int getSum(unsigned int value)
{
	return value % 10 + (value % 100) / 10 + (value % 1000) / 100;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	char value[max_range] = "";
	char iValues[max_range] = {0};

   std::cin >> value;

   for (int i = 0; i < 6; ++i)
   {
	   iValues[i] = value[i] - 48;
   }


   unsigned int leftValue = iValues[0] * 100 + iValues[1] * 10 + iValues[2];
   unsigned int rightValue = iValues[3] * 100 + iValues[4] * 10 + iValues[5];

   unsigned int leftSum = getSum(leftValue);
   unsigned int rigthSum = getSum(rightValue);

   if (getSum(rightValue + 1) == leftSum || getSum(rightValue - 1) == leftSum)
	   std::cout << "Yes";
   else
	   std::cout << "No";
}