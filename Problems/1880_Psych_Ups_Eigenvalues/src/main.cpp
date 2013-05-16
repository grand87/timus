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
    ProblemSolver(const VectorInt &v1, const VectorInt &v2, const VectorInt &v3) :
        mV1(v1),
        mV2(v2),
        mV3(v3)
    {

    }

    size_t resolve()
    {
        size_t common = 0;
        for(VectorInt::const_iterator it = mV1.begin(); it != mV1.end(); ++it)
            if(binSearch(mV2, *it) && binSearch(mV3, *it))
                ++common;
        return common;
    }

    bool binSearch(const VectorInt &v, size_t value) const
    {
        return binSearch(v, v.begin(), v.begin() + v.size() - 1, value);
    }

    bool binSearch(const VectorInt &v, VectorInt::const_iterator start, VectorInt::const_iterator end, size_t value) const
    {
        if(*start == value || *end == value)
            return true;

        if(start == end)
            return false;

        const size_t _distance = distance(start, end) / 2;

        if(_distance == 0)
            return false;

        VectorInt::const_iterator middle = start + _distance;

        if(*middle == value)
            return true;
        else
        if(*middle > value)
            return binSearch(v, start, middle, value);
        else
            return binSearch(v, middle, end, value);
    }

private:
    const VectorInt &mV1;
    const VectorInt &mV2;
    const VectorInt &mV3;
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    VectorInt v[3];

    for(char cnt = 0; cnt < 3; ++cnt)
    {
        size_t ev = 0;
        scanf("%d", &ev);    
        v[cnt].resize(ev);
        for(size_t iEv = 0; iEv < ev; ++iEv)
        {
            size_t value;
            scanf("%d", &v[cnt][iEv]);
        }
    }
    
    ProblemSolver var(v[0], v[1], v[2]);
    printf("%d", var.resolve());

    return 0;
}
