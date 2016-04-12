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

    
	unsigned int dayA, dayB;

	std::cin >> dayA >> dayB;

	unsigned int workDays = dayB - dayA;
	
	unsigned int orderSize = workDays / 2;

	if (dayA % 2)
		orderSize++;
	else if (dayB % 2)
		orderSize++;

	std::cout << orderSize;

}