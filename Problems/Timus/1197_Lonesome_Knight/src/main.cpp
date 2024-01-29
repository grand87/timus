/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>
#include <math.h>

//#define ONLINE_JUDGE

struct Point
{
    size_t x;
    size_t y;

    Point(size_t ax, size_t ay)
    {
        x = ax;
        y = ay;
    }
};

const Point v2[] = 
{
    Point(1,1),
    Point(1,8),
    Point(8,8),
    Point(8,1)
};

const Point v3[] = 
{
    Point(1,2), Point(2,1), 
    Point(1,7), Point(2,8),
    Point(7,8), Point(8,7),
    Point(7,1), Point(8,2)
};

const Point v4[] = 
{
    Point(2,2),
    Point(2,7),
    Point(7,7),
    Point(7,2)
};

bool operator== (const Point& left, const Point& right)
{
    return left.x == right.x && left.y == right.y;
}

size_t posibleMove(const char* position)
{
    const Point pos(position[0] - 'a' + 1, position[1] - '1' + 1);
    for(size_t i = 0; i < 4; ++i)
        if(pos == v2[i])
            return 2;
    for(size_t i = 0; i < 8; ++i)
        if(pos == v3[i])
            return 3;
    for(size_t i = 0; i < 4; ++i)
        if(pos == v4[i])
            return 4;
    if(pos.x == 1 || pos.x == 8 || pos.y == 1 || pos.y == 8)
        return 4;
    if(pos.x == 2 || pos.x == 7 || pos.y == 2 || pos.y == 7)
        return 6;
    return 8;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    size_t combinations = 0;
    scanf("%d", &combinations);

    for(size_t combination = 0; combination < combinations; ++combination)
    {
        char position[3];
        scanf("%s", position);
        printf("%d\n",posibleMove(position));
    }

    return 0;
}
