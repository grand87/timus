/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

//#include <string>
#include <stdio.h>

//#define ONLINE_JUDGE

struct block
{
	block()
	{
		is_allocated = false;
		end_time = 0;
	}

	bool is_allocated;
	int end_time;
};

class memory_manager
{
protected:
	static const int max_block = 30000;
	static const int max_life_time = 10 * 60;
	block memory[max_block];

public:
	virtual int allocate(int time) = 0;
	virtual bool is_availible(int time, int block_id) = 0;
};

class manager : public memory_manager
{
public:

	manager()
	{
	
	}

	int allocate(int time)
	{
		// need to evaluate all requested blocks & free block where was no access for a period of time
		// and this block should be return
		block *block = 0;
		int block_id = 0;
		for (block_id = 0; block_id < max_block; ++block_id)
		{
			block = &memory[block_id];
			if (!block->is_allocated)
			{
				break;
			}
			else
			{
				if (block->end_time <= time)
				{
					break;
				}
			}
		}

		//get free block
		block->is_allocated = true;
		block->end_time = time + max_life_time;

		return block_id + 1;
	}

	bool is_availible(int time, int block_id)
	{
		block_id = block_id - 1;
		if (memory[block_id].is_allocated && memory[block_id].end_time > time)
		{
			memory[block_id].end_time = time + max_life_time;
			return true;
		}
		return false;
	}
};

template <typename T>
struct item
{
	item* next;
	T* data;
};

template <typename T>
struct list
{
	typedef item<T> list_item;
	list_item *head;

	list()
	{
		head = 0;
	}

	void add(T* data)
	{
		list_item* new_head = new list_item();
		new_head->data = data;
		new_head->next_item = head;
		head = new_head;
	}

	list_item* find_smaller(T* data)
	{
		//iterate over all items and find first smaller than data
		list_item* result = head;
		while (result)
		{
			if (is_smaller(result->data, data))
				return result;
			else
				result = result->next_item;
		}
		return 0;
	}

	list_item* find_equal(T* data)
	{
		//iterate over all items and find first smaller than data
		list_item* result = head;
		while (result)
		{
			if (is_equal(result->data, data))
				return result;
			else
				result = result->next_item;
		}
	}
};

template <typename K , typename T>
struct pair
{
	K key;
	T* value;
};


template <typename K, typename T>
struct map
{
	typedef pair<K, T> values;


	list<K> keys;
	list<values> data;

	map()
	{

	}
};

class manager2 : public memory_manager
{
	typedef list<block> blocks;
	map<int, blocks> blocks_map;

public:
	manager2()
	{

	}

	virtual int allocate(int time)
	{
//		blocks_map.find_equal()


	}

	virtual bool is_availible(int time, int block_id)
	{

	}
};


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
	manager manager;

	int time;
	char operation[5];
	int block_id;

	while (scanf("%d", &time) != EOF)
	{
		scanf("%s", operation);
		if (operation[0] == '+')
		{
			block_id = manager.allocate(time);
			printf("%d\n", block_id);
		}
		else
		{
			block_id;
			scanf("%d", &block_id);
			bool result = manager.is_availible(time, block_id);
			printf("%s\n", result ? "+" : "-");
		}
	}

	return 0;
}
