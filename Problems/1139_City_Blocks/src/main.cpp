/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>
#include <math.h>

//#define ONLINE_JUDGE

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int x = 0;
    int y = 0;

    scanf("%d %d", &x, &y);

    if(x == y)
    {
        printf("%d", x - 1);
        return 0;
    }

    const int deltaX = abs(x - 1);
    const int deltaY = abs(y - 1);

    size_t startx = 0;
    size_t starty = 0;
    size_t blocks = 0;

    int error = x - y;

    while(startx != x && starty != y)
    {
        ++blocks;
        
        const int error2 = error * 2;
        //
        if(error2 > -deltaY)
        {
            error -= deltaY;
            startx += 1;
        }
        if(error2 < deltaX)
        {
            error += deltaX;
            starty += 1;
        }
    }

    printf("%d", blocks);

    return 0;
}
