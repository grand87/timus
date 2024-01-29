/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>

//#define ONLINE_JUDGE

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    size_t length = 0;
    scanf("%d", &length);

    size_t value = 0;
    size_t count = 1;

    scanf("%d", &value);

    for(int i = 1; i < length; ++i)
    {
        size_t nextValue = 0;
        scanf("%d", &nextValue);

        if(nextValue == value)
            count++;
        else
        {
            printf("%d %d ", count, value);
            value = nextValue;
            count = 1;
        }
    }
    printf("%d %d", count, value);

    return 0;
}
