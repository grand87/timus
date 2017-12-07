
/*
* @author v.sharayenko (grand87@yandex.ru)
*/

//#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>
#ifndef ONLINE_JUDGE
#include <assert.h>
#endif /*ONLINE_JUDGE*/

struct chank_16 //here could be stored 16 30 bit values
{
    static const char ITEMS_IN_CHANK = 16;

    chank_16()
    {
        reset();
    }

    void reset()
    {
        for (unsigned int i = 0; i < ITEMS_IN_CHANK - 1; ++i)
            v[i] = 0;
    }
    unsigned int v[ITEMS_IN_CHANK - 1];
};

void set30bits_into_chank_16(chank_16* chank_16, unsigned int index, unsigned int value)
{
    const short unsigned int start_bit = index * 30;
    const short start_member = start_bit / 8;
    const short start_member_offset = start_bit % 8;
    char* start_member_address = (char*)chank_16 + start_member;
    unsigned long long* value_in_chank = (unsigned long long*)start_member_address;

    //need to write 30 bits starting from start_member_offset offset in value_in_chank
    for (short i = 0; i < 28; ++i)
    {
        if (value & (1 << i))
        {
            //set bit in target
            *value_in_chank |= 1 << (start_member_offset + i);
        }
        else
        {
            //clear bit in target
            *value_in_chank &= ~(1 << (start_member_offset + i));
        }
    }
}

unsigned int get30bits_from_chank_16(chank_16* chank_16, unsigned int index)
{
    const short start_bit = index * 30;
    const short start_member = start_bit / 8;
    const short start_member_offset = start_bit % 8;
    char* start_member_address = (char*)chank_16 + start_member;
    unsigned long long * value_in_chank = (unsigned long long *)start_member_address;

    unsigned int result = 0;
    //need to read 30 bits starting from start_member_offset offset in value_in_chank
    for (short i = 0; i < 30; ++i)
    {
        if (*value_in_chank & (1 << (start_member_offset + i)))
        {
            //set bit in target
            result |= 1 << i;
        }
        else
        {
            //clear bit in target
            result &= ~(1 << i);
        }
    }

    return result;
}

void store_value_in_buffer(chank_16* buffer, unsigned int position, unsigned int value)
{
    //determine chunk & index in chank

    unsigned int chank_idx = position / chank_16::ITEMS_IN_CHANK;
    unsigned int chank_pos = position % chank_16::ITEMS_IN_CHANK;

    set30bits_into_chank_16(&buffer[chank_idx], chank_pos, value);
}

unsigned get_value_from_buffer(chank_16* buffer, unsigned int position)
{
    //determine chunk & index in chank

    unsigned int chank_idx = position / chank_16::ITEMS_IN_CHANK;
    unsigned int chank_pos = position % chank_16::ITEMS_IN_CHANK;

    return get30bits_from_chank_16(&buffer[chank_idx], chank_pos);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

    {
        unsigned int var[15];
        for (int i = 0; i < 15; i++)
            var[i] = 0;

        assert(get30bits_from_chank_16((chank_16*)var, 0) == 0);
        assert(get30bits_from_chank_16((chank_16*)var, 1) == 0);
        set30bits_into_chank_16((chank_16*)var, 0, 1000000000);
        assert(get30bits_from_chank_16((chank_16*)var, 0) == 1000000000);

        unsigned int bb = get30bits_from_chank_16((chank_16*)var, 1);

        assert(get30bits_from_chank_16((chank_16*)var, 1) == 0);
        set30bits_into_chank_16((chank_16*)var, 1, 3);
        assert(get30bits_from_chank_16((chank_16*)var, 0) == 1000000000);
    }
   
    unsigned int shift = 1 << 7;
    assert(shift == 128);

    chank_16 *test = new chank_16();

    set30bits_into_chank_16(test, 0, 1000000000);
    unsigned int v = get30bits_from_chank_16(test, 0);
    assert(get30bits_from_chank_16(test, 0) == 1000000000);
    set30bits_into_chank_16(test, 1, 4);
    //set30bits_into_chank_16(&test, 1, 2);
    v = get30bits_from_chank_16(test, 0);
    assert(get30bits_from_chank_16(test, 0) == 1000000000);
    set30bits_into_chank_16(test, 2, 3);
    set30bits_into_chank_16(test, 3, 4);
    set30bits_into_chank_16(test, 4, 13);
    set30bits_into_chank_16(test, 15, 1000000000);
    set30bits_into_chank_16(test, 14, 1000000000);

    assert(get30bits_from_chank_16(test, 0) == 1000000000);
    assert(get30bits_from_chank_16(test, 1) == 2);
    assert(get30bits_from_chank_16(test, 2) == 3);
    assert(get30bits_from_chank_16(test, 3) == 4);
    assert(get30bits_from_chank_16(test, 4) == 13);
    assert(get30bits_from_chank_16(test, 15) == 1000000000);
    assert(get30bits_from_chank_16(test, 14) == 1000000000);
        for(int i = 0; i < 16; i++)
        set30bits_into_chank_16(test, i, 1000000000 - i);
    for (int i = 0; i < 16; i++)
        assert(get30bits_from_chank_16(test, i) == 1000000000 - i);

    delete test;
#endif

	unsigned int operationsCount = 0;
	scanf("%d", &operationsCount);

    const unsigned int bits_in_chank = sizeof(chank_16) * 8;
    const unsigned int max_chanks_16 = (100000 * 30) / bits_in_chank + 1;
    
    //below buffer is enought to store 100 000 items with 30 bits each
    chank_16* values = new chank_16[max_chanks_16];
	unsigned short int *idx = new unsigned short int[operationsCount];
    
	char cmd[5] = "";
	unsigned int index = 0;
    unsigned int value = 0;
	unsigned int last_push = 0;

	for (unsigned int operation = 0; operation < operationsCount; ++operation)
	{
		scanf("%s", cmd);
		scanf("%u", &index);

		if (cmd[1] == 'U')
		{
            scanf("%u", &value);

            idx[last_push] = index;
            store_value_in_buffer(values, last_push, value);
			++last_push;
		}
		else
		{
			for (int i = last_push - 1; i >= 0; --i)
			{
				if (idx[i] == index)
				{
					idx[i] = 0;
                    value = get_value_from_buffer(values, i);
                    printf("%d\n", value);
					break;
				}
			}
		}
	}

	delete[] idx;
	return 0;
}
