

/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>
#include <vector>

using namespace std;

//#define ONLINE_JUDGE

typedef vector<size_t> VectorInt;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    static vector<VectorInt> stacks(1001);

    size_t operationsCount = 0;
    scanf("%d", &operationsCount);

    size_t operation = 0;
    char cmd[10] = "";
    size_t index = 0;
    size_t value = 0;

    while(operation < operationsCount)
    {
        ++operation;

        scanf("%s", cmd);

        if(cmd[1] == 'U')
        {
            scanf("%d", &index);
            scanf("%d", &value);
            stacks[index].push_back(value);
        }
        else
        {
            scanf("%d", &index);

            size_t value = *stacks[index].rbegin();
            stacks[index].pop_back();
            printf("%d\n", value);
            if(stacks[index].size() == 0)
            {
                VectorInt empty_vector;
                swap(stacks[index], empty_vector);
            }
        }
    }

    return 0;
}