/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

//#define ONLINE_JUDGE

typedef vector<size_t> VectorInt;

class ProblemSolver
{
public:
    ProblemSolver()
    {
    }

    size_t getValue(size_t index)
    {
        {
            map<size_t, size_t>::iterator it = mCached.find(index);
            if(it != mCached.end())
                return it->second;
        }

        PrimeMap::iterator it = mPrimeValues.begin();
        for(size_t i = 0; i < index - 1; ++i, ++it);

        mCached[index] = it->first;

        return it->first;
    }

    void addValue(size_t newPrimeIndex, size_t index)
    {
        mPrimeValues.insert(pair<size_t,size_t>(newPrimeIndex, index));
    }

private:

    typedef multimap<size_t, size_t> PrimeMap;
    PrimeMap mPrimeValues;
    map<size_t, size_t> mCached;
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    ProblemSolver solver;
    VectorInt requests;

    //reading db
    size_t dbSize = 0;
    scanf("%d", &dbSize);

    size_t i = 0;;
    while(i++ < dbSize)
    {
        size_t value = 0;
        scanf("%d", &value);
        solver.addValue(value, i);
    }

    char str[4];
    scanf("%s", str);

    size_t rCount = 0;
    scanf("%d", &rCount);

    while(rCount--)
    {
        size_t value = 0;
        scanf("%d", &value);
        printf("%d\n", solver.getValue(value));
    }

    return 0;
}
