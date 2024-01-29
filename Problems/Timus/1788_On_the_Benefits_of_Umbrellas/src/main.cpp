/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

//#define ONLINE_JUDGE

typedef vector<size_t> VectorInt;

size_t getSumOfUpset(const VectorInt& upSets, size_t boys, size_t k)
{
    size_t sum = 0;
    for(size_t b = 0; b < boys; ++b)
        sum += upSets[b] * k;
    return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    size_t girls = 0;
    scanf("%d", &girls);

    size_t boys = 0;
    scanf("%d", &boys);
    
    VectorInt girlUpset(girls); 
    VectorInt boyUpset(boys);

    for(size_t i = 0; i < girls; ++i)
        scanf("%d", &girlUpset[i]);
    for(size_t i = 0; i < boys; ++i)
        scanf("%d", &boyUpset[i]);

    sort(girlUpset.begin(), girlUpset.end());
    sort(boyUpset.begin(), boyUpset.end());

    size_t minUpset = getSumOfUpset(girlUpset, girls, 1) + getSumOfUpset(boyUpset, boys, 0);

    for(size_t g = 1; g <= girls; ++g)
    {
        if(g > boys)
            break;

        size_t gu = getSumOfUpset(girlUpset, girls - g, 1);
        size_t bu = 0;

        if(boys >= girls)
            bu = getSumOfUpset(boyUpset, boys - g, g);

        if(gu + bu < minUpset)
            minUpset = gu + bu;
    }

    printf("%d", minUpset);

    return 0;
}
