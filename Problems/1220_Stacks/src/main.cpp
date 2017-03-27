/*
* @author v.sharayenko (grand87@yandex.ru)
*/

//#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>

//#define ONLINE_JUDGE

template<typename T>
struct list
{
	typedef T* chank_type;
	chank_type* chanks;
	unsigned int chank_size;
	unsigned int size;

	list(unsigned int chank_size)
	{
		this->chank_size = chank_size;
		size = 0;
		unsigned int max_chanks = 100000 / chank_size;
		chanks = new chank_type[max_chanks];
		for (unsigned int i = 0; i < max_chanks; i++)
			chanks[i] = 0;
	}

	void push(unsigned int value)
	{
		unsigned int chank = size / chank_size;
		unsigned int index = size % chank_size;

		if (!chanks[chank])
			chanks[chank] = new T[chank_size];

		chanks[chank][index] = value;

		size++;
	}

	unsigned int pop()
	{
		size--;
		unsigned int chank = size / chank_size;
		unsigned int index = size % chank_size;

		return chanks[chank][index];
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	unsigned int operationsCount = 0;
	scanf("%d", &operationsCount);

	//unsigned short int *idx = new unsigned short int[operationsCount];
	//unsigned int *values = new unsigned int[operationsCount];

	list<short int> idx(128);
	list<unsigned int> values(128);

	char cmd[5] = "";
	unsigned int index = 0;
	unsigned int last_push = 0;

	for (unsigned int operation = 0; operation < operationsCount; ++operation)
	{
		scanf("%s", cmd);
		scanf("%u", &index);

		if (cmd[1] == 'U')
		{
			idx[last_push] = index;
			scanf("%u", &values[last_push]);
			++last_push;
		}
		else
		{
			for (int i = last_push - 1; i >= 0; --i)
			{
				if (idx[i] == index)
				{
					idx[i] = 0;
					printf("%d\n", values[i]);
					break;
				}
			}
		}
	}

	delete[] idx;
	delete[] values;
 
	return 0;
}
