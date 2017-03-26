

/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>
#include <vector>

using namespace std;

//#define ONLINE_JUDGE

template <typename T>
struct item
{
	item* next;
	T data;
};

template <typename T>
struct stack
{
	typedef item<T> list_item;
	list_item *head;
	unsigned int _size;

	unsigned int size() const
	{
		return _size;
	}

	stack()
	{
		head = 0;
		_size = 0;
	}

	void push(T data)
	{
		list_item* new_head = new list_item();
		new_head->data = data;
		new_head->next = head;
		head = new_head;
		_size++;
	}

	bool is_empty()
	{
		return head == 0;
	}

	T pop()
	{
		T result = 0;
		if (head)
		{
			result = head->data;
			list_item* old_head = head;
			head = head->next;
			delete old_head;
			_size--;
		}
		return result;
	}

	T top()
	{
		return head->data;
	}
};

template <typename T>
class array_stack
{
	T* data;
	unsigned int size;
	unsigned int max_head;

	T* resize(unsigned int new_size)
	{
		T* new_data = new T[new_size];
		for (unsigned int i = 0; i < head; i++)
		{
			new_data[i] = data[i];
		}
		delete[] data;
		return new_data;
	}
public:
	unsigned int head;

	array_stack(unsigned int init_size)
	{
		size = init_size;
		data = new T[init_size];
		head = 0;
	}

	void push(T value)
	{
		if (head == size - 1)
		{
			unsigned int new_size = (unsigned int)(size * 32) + 1;
			if (new_size > 100000)
				new_size = 100000;
			data = resize(new_size);
			size = new_size;
		}
		data[head++] = value;
		if (head > max_head)
			max_head = head;
	}

	T pop()
	{
		T result = data[--head];
		//const unsigned int new_size = 8;
		//if (head < new_size && max_head > new_size * 16)
		//{
		//	data = resize(new_size);
		//	size = new_size;
		//	max_head = head;
		//}
		return result;
	}
};

const unsigned int MAX_ITEMS = 100000;

template <typename T>
class chank_stack
{
	typedef T* data;
	unsigned int chank_size;
	data* chanks;
	unsigned int chanks_count;
	unsigned int size;
public:

	bool is_empty() const
	{
		return size == 0;
	}

	chank_stack(unsigned int chank_size)
	{
		this->chank_size = chank_size;
		chanks_count = MAX_ITEMS / chank_size;
		chanks = new data[chanks_count];
		for (int i = 0; i < chanks_count; i++)
			chanks[i] = 0;
		size = 0;
	}

	void getAddress(unsigned int &chank_id, unsigned int &index_in_chank, unsigned int position)
	{
		chank_id = position / chank_size;
		index_in_chank = position % chank_size;
	}

	void push(T value)
	{
		unsigned int chank_id = 0;
		unsigned int index_in_chank = 0;

		getAddress(chank_id, index_in_chank, size);

		if (chanks[chank_id] == 0)
			chanks[chank_id] = new T[chank_size];
		chanks[chank_id][index_in_chank] = value;
		size++;
	}

	T pop()
	{
		unsigned int chank_id = 0;
		unsigned int index_in_chank = 0;

		size--;

		getAddress(chank_id, index_in_chank, size);
		T result = chanks[chank_id][index_in_chank];

		if (index_in_chank == 0 && chank_id > 0)
		{
			delete[] chanks[chank_id];
			chanks[chank_id] = 0;
		}
		return result;
	}
};

template <typename T>
class chank_list_stack
{
	unsigned int chank_size;
	stack<T*> chanks;
	unsigned int size;
public:

	chank_list_stack(unsigned int chank_size)
	{
		this->chank_size = chank_size;
		size = 0;
	}

	void push(T value)
	{
		if (chanks.size() * chank_size < size + 1)
		{
			chanks.push(new T[chank_size]);
		}
		unsigned int index_in_chank = size % chank_size;
		chanks.top()[index_in_chank] = value;
		size++;
	}

	T pop()
	{
		size--;
		unsigned int index_in_chank = size % chank_size;
		T result = chanks.top()[index_in_chank];
		if (index_in_chank == 0)
		{
			delete[] chanks.top();
			chanks.pop();
		}

		return result;
	}

	unsigned int getSize() const
	{
		return size;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

	unsigned int cls = sizeof(chank_list_stack<unsigned int>);

	typedef chank_list_stack<unsigned int> stack_int;
	static stack_int* stacks[1000];

	for (int i = 0; i < 1000; i++)
		stacks[i] = 0;

    unsigned int operationsCount = 0;
    scanf("%d", &operationsCount);

	unsigned int operation = 0;
    char cmd[5] = "";
    int index = 0;
	unsigned int value = 0;

    while(operation < operationsCount)
    {
        ++operation;

        scanf("%s", cmd);

        if(cmd[1] == 'U')
        {
            scanf("%d", &index);
            scanf("%d", &value);
			index = index - 1;
			if (stacks[index] == 0)
			{
				stacks[index] = new stack_int(64);
			}
			stacks[index]->push(value);
        }
        else
        {
            scanf("%d", &index);
			value = stacks[index - 1]->pop();
            printf("%d\n", value);
			if (stacks[index - 1]->getSize() == 0)
			{
				delete stacks[index - 1];
				stacks[index - 1] = 0;
			}
        }
    }

    return 0;
}