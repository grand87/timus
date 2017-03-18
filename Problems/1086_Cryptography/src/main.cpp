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
            //fill mPrimeValues

            mPrimeValues[1] = 2;
            mPrimeValues[2] = 3;

            size_t nMax = mPrimeValues.rbegin()->first;
            size_t value = 3;
            size_t iValue = 2;

            while(mPrimeValues.rbegin()->second == 0)
            {
                ++value;

                PrimeMap::const_iterator it = mPrimeValues.find(value);

                if(it != mPrimeValues.end() && it->second != 0)
                {
                    ++iValue;
                    continue;
                }
                
                bool fnd = false;
                
                it = mPrimeValues.begin();
                for(; it != mPrimeValues.end(); ++it)
                {
                    if(it->second == 0)
                        break;

                    if(value % it->second == 0)
                    {
                        fnd = true;
                        break;
                    }
                }
                if(!fnd)
                    mPrimeValues[++iValue] = value;

            }
            mProcessed = true;
        }

        return mPrimeValues[primeIndex];
    }

    void addPrimeIndex(size_t newPrimeIndex)
    {
        mPrimeValues[newPrimeIndex] = 0;
    }

private:
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
    
    size_t ev = 0;
    scanf("%d", &ev);

    ProblemSolver solver;
    VectorInt requests;
    for(size_t cnt = 0; cnt < ev; ++cnt)
    {
        size_t value;
        scanf("%d", &value);
        solver.addPrimeIndex(value);
        requests.push_back(value);
    }
    
    for(VectorInt::const_iterator it = requests.begin(); it != requests.end(); ++it)
        printf("%d\n", solver.resolve(*it));

    return 0;
}
