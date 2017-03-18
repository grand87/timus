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

    unsigned int k, n;
    scanf("%d%d", &k, &n);

    int totalCars = 0;
    unsigned int i = 0;
    while(i++ < n)
    {
        static unsigned int iCar = 0;
        scanf("%d", &iCar);
        int diff = k - iCar;
        if((diff > 0 && totalCars < 0) || diff < 0)
        {
            totalCars += diff;
            if(totalCars > 0)
                totalCars = 0;
        }
    }

    printf("%d", -totalCars);
    return 0;
}