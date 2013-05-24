/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>

//#define ONLINE_JUDGE

size_t calculatePrice(const char *message)
{
    size_t res = 0;
    size_t i = 0;
    while(char c = message[i++])
    {
        switch(c)
        {
        case '.': res += 1;break;
        case ',': res += 2;break;
        case '!': res += 3;break;
        case ' ': res += 1;break;
        default:
            {
                size_t v = c - 'a' + 1;
                size_t ost = v % 3;
                if(ost == 0)
                    res += 3;
                else
                    res += ost;
            }
        }
    }
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    char message[1000+1] = "";
    gets(message);
    size_t res = calculatePrice(message);
    printf("%d", res);
    return 0;
}
