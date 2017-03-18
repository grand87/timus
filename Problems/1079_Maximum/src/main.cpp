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
        mProcessed = false;
    }

    size_t resolve(size_t primeIndex)
    {
        if(!mProcessed)
        {
            mPrimeValues[0] = 0;
            mPrimeValues[1] = 1;
            mPrimeValues[2] = 1;

            const size_t maxAn = mPrimeValues.rbegin()->first;

            for(size_t An = 3; An <= maxAn; ++An)
                mPrimeValues[An] = findAn(An);

            mProcessed = true;
        }

        size_t maxValue = 0;

        for(PrimeMap::iterator it = mPrimeValues.begin(); it != mPrimeValues.end(); ++it)
            if(it->first <= primeIndex)
            {
                if(it->second > maxValue)
                    maxValue = it->second;
            }
            else
                break;

        return maxValue;
    }

    void addPrimeIndex(size_t newPrimeIndex)
    {
        mPrimeValues[newPrimeIndex] = 0;
    }

private:

    size_t findAn(size_t an)
    {
        PrimeMap::iterator it = mPrimeValues.find(an);
        if(it != mPrimeValues.end() && it->second != 0)
            return it->second;

        const size_t a2i = an / 2;

        if(an % 2 == 0)
            return findAn(a2i);
        else
            return findAn(a2i) + findAn(a2i + 1);
    }

    bool mProcessed;
    typedef map<size_t, size_t> PrimeMap;
    PrimeMap mPrimeValues;
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    size_t value = 0;
    ProblemSolver solver;
    VectorInt requests;

    while(true)
    {
        scanf("%d", &value);
        if(value == 0)
            break;
        solver.addPrimeIndex(value);
        requests.push_back(value);
    }

    for(VectorInt::const_iterator it = requests.begin(); it != requests.end(); ++it)
        printf("%d\n", solver.resolve(*it));

    return 0;
}
