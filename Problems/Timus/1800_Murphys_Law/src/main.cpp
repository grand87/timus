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

    long double breadLength;
    long double height;
    long double angleSpeed;

    scanf("%lf", &breadLength);
    scanf("%lf", &height);
    scanf("%lf", &angleSpeed);

    if(breadLength * 0.5f > height)
        printf("butter");
    else
    {
        const long double fallTime = sqrt(2 * (height - breadLength * 0.5) * 0.01f / 9.81);
        long double angle = angleSpeed / 60 * 360 * fallTime;

        while(angle > 360)
            angle -= 360;

        if(angle > 90 && angle < 270)
            printf("bread");
        else
            printf("butter");
    }
    return 0;
}