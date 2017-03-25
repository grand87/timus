/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <string.h>
#include <iostream>

using namespace std;

//#define ONLINE_JUDGE

struct block
{
	bool is_allocated;
	int timer;
};

class manager
{
	static const int max_block = 80000;
	static const int max_life_time = 10 * 60;
	block memory[max_block];

	int free_block_counter;

public:

	manager()
	{
		free_block_counter = 0;
	}

	int allocate(int time)
	{
		memory[free_block_counter].is_allocated = true;
		memory[free_block_counter].timer = time;

		return free_block_counter++ + 1;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
	std::string line;
	while (std::getline(std::cin, line))
	{

	}




    return 0;
}
