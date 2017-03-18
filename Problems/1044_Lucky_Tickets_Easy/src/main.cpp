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

    size_t resolve(size_t length)
    {
        size_t res = findCominations(length, 9);
        return res;
    }

private:

    size_t findCominations(size_t length, size_t maxValue)
    {
        size_t result = 1;
        if(length > 2)
        {
            for(size_t s = 0; s <= maxValue; ++s)
                result += findCominations(length - 1, maxValue - s);
        }
        else
            return maxValue + 1;
        return result;
    }

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
    
    scanf("%d", &value);
    printf("%d\n", solver.resolve(value));

    return 0;
}
