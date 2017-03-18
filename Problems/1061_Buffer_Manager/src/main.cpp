/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>
#include <vector>
#include <string.h>
//#define ONLINE_JUDGE

struct BlocksSequence
{
    size_t position;
    size_t count;
    size_t worthiness;
    
    BlocksSequence()
    {
        position = 0;
        count = 0;
        worthiness = 0;
    }

    BlocksSequence(size_t aPosition, size_t aCount, size_t aWorthiness)
    {
        position = aPosition;
        count = aCount;
        worthiness = aWorthiness;
    }
};

bool operator < (const BlocksSequence& left, const BlocksSequence& right)
{
    return left.worthiness < right.worthiness;
}

BlocksSequence findOptimalLocation(const BlocksSequence &base, size_t request, const char* buffer)
{
    const char *localBuffer = buffer + base.position;
    
    size_t worthiness = 0;
    for(size_t lpos = 0; lpos < request; ++lpos)
        worthiness += localBuffer[lpos] - '0';

    BlocksSequence prev(0, request, worthiness);
    BlocksSequence best = prev;

    for(size_t pos = 1; pos < base.count - request + 1; ++pos)
    {
        size_t newOne = localBuffer[pos + request - 1] - '0';
        size_t oldOne = localBuffer[pos - 1] - '0';

        worthiness = prev.worthiness + newOne - oldOne;

        prev = BlocksSequence(pos, request, worthiness);

        if(worthiness < best.worthiness)
            best = BlocksSequence(pos, request, worthiness);
    }

    best.position += base.position;

    return best;
}

using namespace std;

typedef vector<BlocksSequence> Buffers;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    char bufferState[100001];

    size_t length = 0;
    scanf("%d", &length);

    size_t request = 0;
    scanf("%d", &request);

    if(request > length)
    {
        printf("0");
        return 0;
    }

    size_t scanned = 0;
    while(scanned != length)
    {
        scanf("%s", bufferState + scanned);
        scanned += strlen(bufferState + scanned);
    }
    bufferState[length] = 0;

    Buffers buffers;
    buffers.reserve(50);
    
    size_t pos = 0;

    size_t start = pos;
    size_t sequence = 0;

    while(char state = bufferState[pos++])
    {
        if(state == '*')
        {
            if(sequence >= 1)
            {
                BlocksSequence s(start, sequence, -1);
                buffers.push_back(s);
                start = pos;
                sequence = 0;
                continue;
            }
            else
            {
                ++start;
                continue;
            }
        }

        ++sequence;
    }
    if(sequence)
    {
        BlocksSequence s(start, sequence, -1);
        buffers.push_back(s);
    }

    size_t res = 0;
    BlocksSequence minimal(0,0,-1);

    for(Buffers::iterator it = buffers.begin(); it != buffers.end(); ++it)
    {
        if(it->count >= request)
        {
            BlocksSequence optimal = findOptimalLocation(*it, request, bufferState);
            if(optimal < minimal)
            {
                minimal = optimal;
                ++minimal.position;
            }
        }
    }

    printf("%d", minimal.position);

    return 0;
}
