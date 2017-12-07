/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>
#include <vector>

using namespace std;

//#define ONLINE_JUDGE

typedef vector<size_t> VectorInt;
typedef vector<VectorInt> VectorInt2;

struct Index
{
    Index()
    {
        row = 0;
        col = 0;
    }

    Index(size_t aRow, size_t aCol)
    {
        row = aRow;
        col = aCol;
    }

    size_t row;
    size_t col;
};

bool operator == (const Index& aLeft, const Index& aRight)
{
    return aLeft.col == aRight.col && aLeft.row == aRight.row;
}

const Index TerminationCell(-1, -1);

Index nextIndex(const Index& current, const Index &maxIndex)
{
    if(current.col < maxIndex.col && current.row < maxIndex.row)
        return Index(current.row + 1, current.col + 1);
    else
        return TerminationCell;
}

Index nextDiagonal(const Index& prevDiagonal)
{
    if(prevDiagonal.col > 1)
        return Index(1, prevDiagonal.col - 1);
    else
        return Index(prevDiagonal.row + 1, 1);
}

void updateCell(VectorInt2 &aVec, const Index &aIndex, size_t aValue)
{
    aVec[aIndex.row - 1][aIndex.col - 1] = aValue;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    size_t dbsize = 0;
    scanf("%d", &dbsize);

    VectorInt2 result(dbsize);
    for(VectorInt2::iterator it = result.begin(); it != result.end(); ++it)
        it->resize(dbsize);

/*
    21
    11 22
    12

    31 
    21 32 
    11 22 33
    12 23
    13
*/

    size_t value = 1;
    Index cIndex(1, dbsize);
    Index previousStart(cIndex);
    const Index iMax(dbsize, dbsize);

    while(value < dbsize * dbsize + 1)
    {
        updateCell(result, cIndex, value);
        ++value;
        cIndex = nextIndex(cIndex, iMax);
        if(cIndex == TerminationCell)
        {
            previousStart = nextDiagonal(previousStart);
            cIndex = previousStart;
        }
    }

    for(VectorInt2::iterator row = result.begin(); row != result.end(); ++row)
    {
        for(VectorInt::iterator col = row->begin(); col != row->end(); ++col)
            printf("%d ", *col);
        printf("\n");
    }

    return 0;
}
