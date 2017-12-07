/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>
#include <math.h>
#include <algorithm>

//#define ONLINE_JUDGE

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int x = 0;
    int y = 0;

    scanf("%d %d", &x, &y);
    --x;
    --y;

    if (x < y)
    {
        std::swap(x, y);
    }

    if (x == y)
    {
        printf("%d", x);
    }
    else if (x == 1)
    {
        printf("%d", y);
    }
    else if (y == 1)
    {
        printf("%d", x);
    }
    else if (x % y == 0) //checking GCD - Greatest common divisor 
    {
        printf("%d", x);
    }
    else 
    {
        //Bresenham's line algorithm
        int x1 = 0;
        int y1 = 0;
        int p = 1;

        int deltaX = x;
        int deltaY = y;

        int error = 0;
        int deltaerr = deltaY;

        for (int i = 0; i < x - 1; ++i)
        {
            //printf("%d %d\n", x1, y1);
            error += deltaerr;
            if (2 * error > deltaX)
            {
//                y1 += 1;
                error -= deltaX;
                if (error != 0)
                {
                    p++;
                }
            }
//            x1 += 1;
            p++;
        }
        printf("%d", p);
    }
    return 0;
}
